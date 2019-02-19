#include "stdInc.h"

Servo up[4],down[4];//SERVO

//time interval
int S = 2;
//-----------PROXY---------------

//-------------------------------

//----------FOR_MPU--------------

int yaw2=0,pitch2=0,roll2=0;
float yaw,pitch,roll;
float yp=0,pp=0,rp=0;
byte ypr1[6];

//-------------------------------

/*-------------------PINS-------------------------*/
const uint16_t upS[4]   = {38,30,26,40}; //{34,36,30,32}
const uint16_t downS[4] = {36,28,32,34}; //{40,38,28,26}
/*------------------------------------------------*/

/*-------------------OFFSET-----------------------*/
const int offset[8]={0,-3,10,-12,-15,-5,-7,-10};
/*------------------------------------------------*/

/*---------------------MULTIPLIERS----------------*/
float Hm[4];
float Lm[4];
const int upB[4]={1,-1,-1,1};
const int downB[4]={1,-1,-1,1};
int m;
/*------------------------------------------------*/

/*------------POSITION_MANIPULATION---------------*/
const int elb[2]={0,450};      //elbow co-ordinates
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
//  alternate();
  staticG();
  getangle(4);
  initial();
  delay(3000);
  Timer1.initialize(50000);
  Timer1.attachInterrupt(checkMPU);
}

void loop()
{
//  checkMPU();
  RUN(0);
  shift();
}

/*------------------------------POINTS----------------------------*/
double pt[72][2];
/*----------------------------------------------------------------*/
