void left()
{
  Lm[0]=0.60f;
  Lm[2]=0.60f;
  Lm[1]=1.0f;
  Lm[3]=1.0f;
}
void right()
{
  Lm[0]=1.00f;
  Lm[2]=1.00f;
  Lm[1]=0.65f;
  Lm[3]=0.65f;
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
  Lm[0]=-0.35f;
  Lm[2]=-0.35f;
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
  Lm[0]=1.0f;
  Lm[2]=1.0f;
  Lm[1]=-0.1f;
  Lm[3]=-0.1f;
  
  pDiff[0] = 0;
  pDiff[1] = 36;
  pDiff[2] = 41;
  pDiff[3] = 6;
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
