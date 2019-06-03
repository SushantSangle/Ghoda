void left()
{
  Lm[0]=0.62f;
  Lm[2]=0.62f;
  Lm[1]=0.9f;
  Lm[3]=0.9f;
}
void right()
{
  Lm[1]=0.85f;
  Lm[3]=0.85f;
  Lm[0]=1.0f;
  Lm[2]=1.0f;
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
//  Hm[0]=0.0f;
//  Hm[2]=0.0f;
  Lm[1]=0.9f;
  Lm[3]=0.9f;
}

void rightEx()
{
  Lm[0]=0.9f;
  Lm[2]=0.9f;
  Lm[1]=-0.1f;
  Lm[3]=-0.1f;
}

void turn(bool arena) //0 for left 1 for right
{
  if(!arena) left();
  else      right();
}
void turnX(bool arena)
{
  if(!arena) rightEx();
  else        leftEx();
}
