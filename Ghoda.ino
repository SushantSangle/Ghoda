#include "stdInc.h"

Servo up[4],down[4];      //SERVO
Servo UK;

//time interval
int S = 2;
//-----------PROXY---------------
bool pr,pf;
int pMode=0,pMode1=0;
int fp=A2;
int rp=A0;
//-------------------------------

//----------FOR_MPU--------------

int yaw2=0,pitch2=0,roll2=0;
float yaw,pitch,roll;
float yp=0,pp=0,rpr=0;
char ypr1[6];
int baseY=0;
bool q=0;

//-------------------------------

/*-------------------PINS-------------------------*/
const uint16_t upS[4]   = {46,48,41,42};  
//{38,22,26,40}  
const uint16_t downS[4] = {47,49,40,43}; 
//{34,28,24,36}
/*------------------------------------------------*/

/*-------------------OFFSET-----------------------*/
const uint16_t offset[8]={0,-8,-2,15,-25,13,18,-4};
/*------------------------------------------------*/

/*---------------------MULTIPLIERS----------------*/
float Hm[4];
float Lm[4];
const int upB[4]=  {1 ,-1 ,-1 ,1  };
const int downB[4]={1 ,-1 ,-1 ,1  };
int m;
/*------------------------------------------------*/

/*------------POSITION_MANIPULATION---------------*/
const int elb[2]={0,430};      //elbow co-ordinates
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
int Step=0;
int startC=0;
bool runMode=0,pstate=1 ;
bool gobi=0;
/*------------------------------------------------*/

void setup()
{
  pinmode();
//  test();
//  staticG();
  alternate();
//  left();
  initial();
////  rightEx();
////  dune();
//  {//start from above mountain
//    els[0][1]=-100;
//    els[1][1]=-100;
//  }
  getangle(4);
  initial();
////  delay(2000);
//  while(digitalRead(9))
//  {
//    checkMPU();
//  }
//  baseY = yaw;
  q=true;
  gobi  = true;
  while(digitalRead(fp));
  while(digitalRead(rp));
  delay(300);
}
int timen=0,timep=0;
void loop()
{
  timen=millis();
//  if(timen-timep>50)
//  {
//    Serial.println(Step);
//    checkMPU();
//    timep=timen;
//  }
//  stepCount();
  RUN(0);
  proxy();
//  duneMode();
}

/*----------------------POINTS_FOR_ALTERNATE----------------------*/

double pt[72][2];
/*----------------------------------------------------------------*/
