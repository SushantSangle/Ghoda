#include "stdInc.h"
//36 switch 37,38,39 push
Servo up[4],down[4];      //SERVO
Servo UK;
//use time limit in while for input form mpu
//time interval
int S = 2;
int b11=0,b=0;
//-----------PROXY---------------
bool pr,pf,pR;
int pMode=0,pMode1=0;
int fp=A2;
int rp=A0;
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
//-------------------------------

/*-------------------PINS-------------------------*/

const uint16_t upS[4]   = {49,42,47,40};  
//{38,22,26,40}  
const uint16_t downS[4] = {48,43,46,41}; 
//{34,28,24,36}
const uint16_t UKK = 44;
/*------------------------------------------------*/

/*-------------------OFFSET-----------------------*/
const uint16_t offset[8]={-5,2,12,-4,0,13,-3,6}; 
/*------------------------------------------------*/
/*---------------------MULTIPLIERS----------------*/
float Hm[4];
float Lm[4];
const int upB[4]=  {1 ,-1 ,-1 ,1  };
const int downB[4]={1 ,-1 ,-1 ,1  };
int m;
/*------------------------------------------------*/

/*------------POSITION_MANIPULATION---------------*/
const int elb[2]={0,400};      //elbow co-ordinates
int els[4][2];
bool mode=0;
int LEG,LEGP; 
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
int Step=0;
int startC=0;
bool runMode=0,pstate=1 ;
bool gobi=0;
/*------------------------------------------------*/

void setup()
{
  pinmode();

//  staticG();
  test();
//  alternate();
//  left();

//  initial();
//  getangle(4);
//  initial();
  
  Serial.println("RUN START");
  while(digitalRead(fp));
  while(digitalRead(rp));
  delay(400);

  q=true;
  gobi = true;
  baseY = yaw;
}

void loop()
{
//  stepCount();
//  MPU();
//  RUN(0);
//  proxy();
//  duneMode();
}

/*----------------------POINTS_FOR_ALTERNATE----------------------*/

double pt[72][2];
/*----------------------------------------------------------------*/
