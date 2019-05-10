#include "stdInc.h"
//36 switch 37,38,39 push
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
int timen=0,timep=0;
//-------------------------------

/*-------------------PINS-------------------------*/

const uint16_t upS[4]   = {46,48,41,42};  
//{38,22,26,40}  
const uint16_t downS[4] = {47,49,40,43}; 
//{34,28,24,36}
const uint16_t UKK = 44;
/*------------------------------------------------*/

/*-------------------OFFSET-----------------------*/
const uint16_t offset[8]={0,10,-2,15,0,10,18,-4}; //-6,15
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
  
  /*walking modes*/{
//  staticG();
  test();
//    alternate();
//    left();
  }
  /*INITIAL*/{
//    initial();
//    getangle(4);
//    initial();
  }
  while(digitalRead(fp)){
//    checkMPU();
  }
  q=true;
  delay(300);
  baseY = yaw;
  UK.write(30);
}

void loop()
{
//  stepCou0nt();
//  MPU();
//  RUN(0);
//  proxy();
//  duneMode();
}

/*----------------------POINTS_FOR_ALTERNATE----------------------*/

double pt[72][2];
/*----------------------------------------------------------------*/
