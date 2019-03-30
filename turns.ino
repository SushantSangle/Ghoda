void left()
{
  Lm[0]=0.9f;
  Lm[2]=0.9f;
  Lm[1]=1.1f;
  Lm[3]=1.1f;
}
void right()
{
  Lm[1]=0.7f;
  Lm[3]=0.7f;
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
  Lm[0]=-0.3f;
  Lm[2]=-0.3f;
//  Hm[0]=0.0f;
//  Hm[2]=0.0f;
  Lm[1]=1.0f;
  Lm[3]=1.0f;
}

void rightEx()
{
  Lm[0]=1.0f;
  Lm[2]=1.0f;
  Lm[1]=-0.2f;
  Lm[3]=-0.2f;
//  Hm[1]=0.0f;
//  Hm[3]=0.0f;
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
