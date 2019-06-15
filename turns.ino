void left()
{
  Lm[0]=0.60;
  Lm[2]=0.60;
  Lm[1]=0.90;
  Lm[3]=0.90;
}
void right()
{
  Lm[0]=0.95f;
  Lm[2]=0.95f;
  Lm[1]=0.60f;
  Lm[3]=0.60f;
}
void straight() 
{
  Lm[0]=1.0f;
  Lm[2]=1.0f;
  Lm[3]=1.0f;
  Lm[1]=1.0f;
  

}
void leftEx()
{
  staticG();
  Lm[0]=-0.70f;
  Lm[2]=-0.70f;
  els[2][0] = 50;
  Lm[1]=1.0f;
  Lm[3]=1.0f;
  Hm[0]=1.0f;
  Hm[1]=1.0f;
  Hm[2]=1.0f;
  Hm[3]=1.0f;
  S = 35;
//  els[2][0] = 50;
//  pDiff[0] = 0;
//  pDiff[1] = 36;
//  pDiff[2] = 41;
//  pDiff[3] = 6;
}

void rightEx()
{
  alternate();
  S=15;
  Lm[1] = 0.1;
  Lm[3] = 0.1;
  Lm[0] = 0.8;
  Lm[1] = 0.8;
}
void rev(){
  Lm[0] =-0.6;
  Lm[1] =-0.6;
  Lm[2] =-0.6;
  Lm[3] =-0.6;
  Hm[0] =0.6;
  Hm[1] =0.6;
  Hm[2] =0.6;
  Hm[3] =0.6;
  
  pDiff[0] = 0;
  pDiff[1] = 36;
  pDiff[2] = 36;
  pDiff[3] = 0;
}
void turn(bool arena) //0 for left 1 for right
{
  if(arena) left();
  else      right();
}
void turnX(bool arena)
{
  if(arena) rightEx();
  else      leftEx();
}
