/*------------------------------------------------*/
//battery in center is best cg and els2y = 20 is best currently
void alternate(){  
  double ptm = (double(l1)+double(l2))/490;
  for(int i=0 ;i<72;i++)
  {
    for(int j=0;j<2;j++) pt[i][j] = (pta[i][j]);
  }
  mode = 0;
  Hm[0]= 0.7f;
  Hm[1]= 0.7f;
  Hm[2]= 0.7f;
  Hm[3]= 0.7f;
  Lm[0]= 0.70f;
  Lm[1]= 0.70f;
  Lm[2]= 0.70f;
  Lm[3]= 0.70f;
  els[0][0] = 0;
  els[0][1] = 0;
  els[1][0] = 0;
  els[1][1] = 0;
  els[2][0] = 0;
  els[2][1] = 20;
  els[3][0] = 0;
  els[3][1] = 0;
  pDiff[0] = 0;
  pDiff[1] = 36;
  pDiff[2] = 36;
  pDiff[3] = 0; 
  S=12; 
}
/*------------------------------------------------*/

/*------------------------------------------------*/
void staticG(){
  double ptm = (double(l1)+double(l2))/490;
  for(int i=0 ;i<72;i++)
  {
    for(int j=0;j<2;j++) pt[i][j] = (pt1[i][j]*ptm);
  }  
  mode = 1;
  Hm[0]= 1.0;
  Hm[1]= 1.0;
  Hm[2]= 1.0;
  Hm[3]= 1.0;
  Lm[0]= 1.0;
  Lm[1]= 1.0;
  Lm[2]= 1.0;
  Lm[3]= 1.0;
  els[0][0] = 0;
  els[0][1] = 0;
  els[1][0] = 0;
  els[1][1] = 0;
  els[2][0] = 0;
  els[2][1] = 20;
  els[3][0] = 0;
  els[3][1] = 0;
  pDiff[0] = 0;
  pDiff[1] = 36;
  pDiff[2] = 18;
  pDiff[3] = 54;
  S=35;
}
void dune(){
  alternate();
  S=20;
  Hm[0]= 1.2;
  Hm[1]= 1.2;
  Hm[2]= 1.2;
  Hm[3]= 1.2;
  Lm[0]= 1.0;
  Lm[1]= 1.0;
  Lm[2]= 1.0;
  Lm[3]= 1.0;
  els[0][1]=-70;
  els[1][1]= -70;
  els[2][0]=   0;
  els[3][0]=   0;
  els[2][1]= -10;
  els[3][1]= -10;
  slope=14;
  rot  =12;
}
/*------------------------------------------------*/
