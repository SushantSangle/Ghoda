void left()
{
  Lm[0]=0.9f;
  Lm[2]=0.9f;
  Lm[1]=1.1f;
  Lm[3]=1.1f;
}
void right()
{
  Lm[1]=0.9f;
  Lm[3]=0.9f;
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

