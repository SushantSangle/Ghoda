#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 mpu;
//MPU6050 mpu(0x69); // <-- use for AD0 high

#define OUTPUT_READABLE_YAWPITCHROLL

#define INTERRUPT_PIN 3  // use pin 2 on Arduino Uno & most boards
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };



// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}



// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
  Serial.println('Q');
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.begin(38400);
//    while (!Serial); // wait for Leonardo enumeration, others continue immediately

    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);
    mpu.testConnection();

    devStatus = mpu.dmpInitialize();

    mpu.setXGyroOffset(224);
    mpu.setYGyroOffset(11);
    mpu.setZGyroOffset(-116);
    mpu.setXAccelOffset(-3491);
    mpu.setYAccelOffset(-1705);
    mpu.setZAccelOffset(4362); 
    
    if (devStatus == 0) {
        mpu.setDMPEnabled(true);

        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    }

    // configure LED for output
    pinMode(LED_PIN, OUTPUT);
}
int yaw,pitch,roll;
char ypr1[6];
int yaw2,pitch2,roll2;

/* ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ==============================================================*/
char e;
float tn=0,tp=0;
void loop() {

    // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize);

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
//        Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {

        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        fifoCount -= packetSize;


        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            e='y';
            if(Serial.available())  e=Serial.read();    
            if(e=='y')
            {
              yaw   = ypr[0] * 180/M_PI;
              pitch = ypr[1] * 180/M_PI;
              roll  = ypr[2] * 180/M_PI;
              ypr1[0] = (yaw   & 255);
              ypr1[1] = (yaw   & (255<<8))>>8;
              ypr1[4] = (pitch & 255);
              ypr1[5] = (pitch & (255<<8))>>8;
              ypr1[2] = (roll  & 255);
              ypr1[3] = (roll  & (255<<8))>>8;

              yaw2  = ypr1[0] | (ypr1[1]<<8);
              pitch2= ypr1[4] | (ypr1[5]<<8);
              roll2 = ypr1[2] | (ypr1[3]<<8);
              tn=millis();
              if(tn-tp>40)
              {
                Serial.print('H');
                Serial.print(" ");
                Serial.print(yaw);
                Serial.print(" ");
                Serial.print(pitch);
                Serial.print(" ");
                Serial.println(roll);
                tp=tn;
              }
            }
        #endif

        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
    }
}
