#include "stdInc.h"

Servo up[4],down[4];      //SERVO

//time interval
int S = 2;
//-----------PROXY---------------
bool p1,p0;
int pMode=0,pMode1=0;
//-------------------------------

//----------FOR_MPU--------------

int yaw2=0,pitch2=0,roll2=0;
float yaw,pitch,roll;
float yp=0,pp=0,rp=0;
byte ypr1[6];

//-------------------------------

/*-------------------PINS-------------------------*/
const uint16_t upS[4]   = {36,40,24,28}; //{38,22,26,40}    //32 is ukkhai servo
const uint16_t downS[4] = {34,38,22,26}; //{34,28,24,36}
/*------------------------------------------------*/

/*-------------------OFFSET-----------------------*/
const uint16_t offset[8]={-3,-1,8,-7,-3,-2,15,4};
/*------------------------------------------------*/

/*---------------------MULTIPLIERS----------------*/
float Hm[4];
float Lm[4];
const int upB[4]=  {1 ,-1 ,-1 ,1  };
const int downB[4]={1 ,-1 ,-1 ,1  };
int m;
/*------------------------------------------------*/

/*------------POSITION_MANIPULATION---------------*/
const int elb[2]={0,420};      //elbow co-ordinates
int els[4][2]; 
bool mode=0;
int LEG;
double xpriv[4]= {0,0,0,0};
double xnow[4] = {0,0,0,0};
/*------------------------------------------------*/

/*---------------ANGLE_MANIPULATION---------------*/
int rot=0,rot1,i=0;             //Rotation of axis
float slope=0;
int Angle[4][72][2];
/*------------------------------------------------*/

void setup()
{
  pinmode();
//  test();
  initial();
  alternate();
//  staticG();
  getangle(4);
  initial();
  delay(3000);
  
//  Timer1.initialize(50000);
//  Timer1.attachInterrupt(checkMPU);
}

void loop()
{
//  checkMPU();
  proxy();
  RUN(0);
//  shift();
}

/*----------------------POINTS_FOR_ALTERNATE----------------------*/

double pt[72][2];
/*----------------------------------------------------------------*/
