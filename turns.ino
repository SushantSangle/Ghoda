void left()
{
  Lm[0]=0.77f;
  Lm[2]=0.77f;
  Lm[1]=1.095f;
  Lm[3]=1.095f;
}
void right()
{
  Lm[1]=0.85f;
  Lm[3]=0.85f;
  Lm[0]=1.1f;
  Lm[2]=1.1f;
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
  Lm[0]=0.0f;
  Lm[2]=0.0f;
  Lm[1]=1.0f;
  Lm[3]=1.0f;
}

void rightEx()
{
  Lm[0]=1.0f;
  Lm[2]=1.0f;
  Lm[1]=0.0f;
  Lm[3]=0.0f;
}

