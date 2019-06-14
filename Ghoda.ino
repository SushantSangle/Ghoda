#include "stdInc.h"
//36 switch 37,38,39 push
Servo up[4],down[4];      //SERVO
int ukkhai_m1 = 8;
int ukkhai_m2 = 10;
int ukkhai_pwm = 9;
//use time limit in while for input form mpu
//time interval
//switch(36) left 1 right 0
//after step(37) 
//dune(38)
int S = 2;
int b11=0,b=0;
//-----------PROXY---------------
bool pr,pf,pR;
int pMode=0,pMode1=0;
int fp=A0;//A2
int rp=A2;
int RP=A1;

//-------------------------------

//----------FOR_MPU--------------

int yaw2=0,pitch2=0,roll2=0;
float yaw,pitch,roll;
float yp=0,pp=0,rpr=0;
char ypr1[6];
int baseY=0;
bool q=0;
int timen=0,timep=0;
int pDiff[4] = {0,36,36,0};
int ARENA;
//-------------------------------

/*-------------------PINS-------------------------*/

const uint16_t upS[4]   = {49,47,40,43};  
//{38,22,26,40}  {49,42,47,40}
const uint16_t downS[4] = {48,46,41,42}; 
//{34,28,24,36}{48,43,46,41}
/*------------------------------------------------*/

/*-------------------OFFSET-----------------------*/
const uint16_t offset[8]={-6,0,-1,7,8,-8,0,-34}; 
/*-----------------------------------------------*/
/*---------------------MULTIPLIERS----------------*/
float Hm[4];
float Lm[4];
const int upB[4]=  {1 ,-1 ,-1 ,1  };
const int downB[4]={1 ,-1 ,-1 ,1  };
int m;
bool I_increment = false;
/*------------------------------------------------*/

/*------------POSITION_MANIPULATION---------------*/
const int elb[2]={0,410};      //elbow co-ordinates
int els[4][2];
bool mode=0;
int LEG,LEGP; 
double xpriv[4]= {0,0,0,0};
double xnow[4] = {0,0,0,0};
/*------------------------------------------------*/

/*---------------ANGLE_MANIPULATION---------------*/
int rot[4]={0,0,0,0},rot1=0,i=0;             //Rotation of axis
float slope=0;
int Angle[4][72][2];
/*------------------------------------------------*/
/*-------------------STEP-COUNT-------------------*/
int steps =0;
int Step=0;
int startC=0;
bool runMode=0,pstate=1 ;
bool gobi=0;
/*------------------------------------------------*/

void setup()
{
  pinmode();

  staticG();

  test();
//  alternate();
  gerejeStop();
//  initial();
//  getangle(4);
//  initial();
  
//  while(digitalRead(2))
//  {
//    ARENA = digitalRead(36);
//    Serial.println(ARENA);
//    if(digitalRead(37))  afterDune();
//    if(digitalRead(39))  test();
//  }
  while(digitalRead(fp)){
    ARENA = digitalRead(36);
    Serial.println(ARENA);
    if(digitalRead(37))  afterDune();
    if(digitalRead(38))  mountain();
    if(digitalRead(39))  test();
  }
  while(digitalRead(rp));
  delay(400);
//  turn(ARENA);
//  getangle(4);
  mountain();
  Serial.println("RUN START");
  q=true;
  baseY = yaw;
//  gobi = true;
}
bool DUNE= false;
void loop() 
{
//  stepCount();
//  MPU();
//  stepCount();
  RUN(0);
//  proxy();
 duneMode();
//  shift();

}

/*----------------------POINTS_FOR_ALTERNATE----------------------*/

double pt[72][2];
/*----------------------------------------------------------------*/
