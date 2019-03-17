#include <Servo.h>
#include <TimerOne.h>
#include <math.h>
#include "pt1.h"
#include "pta.h"

//definations
#define l1 230
#define l2 230

#define angle(val,sign,off) ((180+((sign)*(val))+offset[off])%180)
#define pi 3.14159265
#define toD(a) ((a)*pi/180)
#define s(a) (((a)*(a)))


