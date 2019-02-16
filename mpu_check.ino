/*-----------------------MPU-check----------------------*/
void checkMPU(){
  if(Serial3.available()){
    while(Serial3.read()!='H');
    Serial3.readBytes(ypr1,6);
    yaw2  = ypr1[0] | (ypr1[1]<<8);
    pitch2= ypr1[2] | (ypr1[3]<<8);
    roll2 = ypr1[4] | (ypr1[5]<<8);
  }
  if(abs(yaw2)   > 10) yaw2   = yp;
  if(abs(pitch2) > 10) pitch2 = pp;
  if(roll2  > 20 || roll2 < -20) roll2  = rp;

  yaw   = 0.4*yaw2   + 0.6*yp;
  pitch = 0.4*pitch2 + 0.6*pp;
  roll  = 0.4*roll2  + 0.6*rp;
  
  Serial.print("ypr\t");
  Serial.print(yaw);
  Serial.print("\t");
  Serial.print(pitch);
  Serial.print("\t");
  Serial.println(roll);
  yp = yaw;
  pp = pitch;
  rp = roll;
}
/*------------------------------------------------*/

/*------------------STAND-OR-BOW------------------*/
void bow(){
  Hm[0] = 0.8f;
  Hm[1] = 0.8f;
  int ypriv[4] = {els[0][1],els[1][1],els[2][1],els[3][1]};
  int ynow[4]  = {-100,-100,0,0};
//  els[0][1] = -100;
//  els[1][1] = -100;
  if(ypriv[0]!=ynow[0])
  {
    for(int i=0;i<3;i++)
    {
      for(int y=0 ; y<4 ; y++)
        els[y][1] = map(i,0,2,ypriv[y],ynow[y]);
      getangle(1);
      getangle(0);
      RUN(1);
    }
  }
}
/*------------------------------------------------*/
void stand()
{
  Hm[0]     = 1.5f;
  Hm[1]     = 1.5f;
  els[0][1] = 0;
  els[1][1] = 0;
}
/*------------------------------------------------*/
