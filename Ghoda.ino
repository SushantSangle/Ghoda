#include "stdInc.h"

Servo up[4],down[4];      //SERVO
Servo UK;

//time interval
int S = 2;
//-----------PROXY---------------
bool pr,pf;
int pMode=0,pMode1=0;
int fp=2;
int rp=3;
//-------------------------------

//----------FOR_MPU--------------

int yaw2=0,pitch2=0,roll2=0;
float yaw,pitch,roll;
//float yp=0,pp=0,rp=0;
byte ypr1[6];

//-------------------------------

/*-------------------PINS-------------------------*/
const uint16_t upS[4]   = {36,40,24,28}; //{38,22,26,40}    //32 is ukkhai servo
const uint16_t downS[4] = {34,38,22,26}; //{34,28,24,36}
/*------------------------------------------------*/

/*-------------------OFFSET-----------------------*/
const uint16_t offset[8]={-10,0,-6,-12,-30,-7,-15,-3};
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
int rot=0,rot1=0,i=0;             //Rotation of axis
float slope=0;
int Angle[4][72][2];
/*------------------------------------------------*/
/*-------------------STEP-COUNT-------------------*/
int steps =0;
int startC=0;
bool runMode=0,pstate=1 ;
/*------------------------------------------------*/

void setup()
{
  pinmode();
//  test();
  alternate();  turn(0);
  initial();
//  dune();
  getangle(4);
  initial();
  while(digitalRead(2));
  delay(300);
}

void loop()
{
//  proxy();
  RUN(0);
}

/*----------------------POINTS_FOR_ALTERNATE----------------------*/

double pt[72][2];
/*----------------------------------------------------------------*/
