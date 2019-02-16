void alternate()
{
  for(int i=0 ;i<72;i++)
  {
    for(int j=0;j<2;i++) pt[i][j] = pta[i][j];
  }
  mode = 0;
}

void staticG()
{
  for(int i=0 ;i<72;i++)
  {
    for(int j=0;j<2;i++) pt[i][j] = pt1[i][j];
  }  
  mode = 1;
}

