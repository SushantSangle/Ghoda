void left()
{
  Lm[0]=0.60f;
  Lm[2]=0.60f;
  Lm[1]=1.0f;
  Lm[3]=1.0f;
}
void right()
{
  Lm[0]=1.0f;
  Lm[2]=1.0f;
  Lm[1]=0.50f;
  Lm[3]=0.50f;
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
  Lm[0]=-0.1f;
  Lm[2]=-0.1f;
  Lm[1]=1.0f;
  Lm[3]=1.0f;
  pDiff[0] = 6;
  pDiff[1] = 41;
  pDiff[2] = 36;
  pDiff[3] = 0;
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
