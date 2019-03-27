/*-----------------------MPU-check----------------------*/
void checkMPU(){
  if(Serial3.available()){
    while(Serial3.read()!='H');
//    yaw2  = ypr1[0] | (ypr1[1]<<8);
//    pitch2= ypr1[4] | (ypr1[5]<<8);
//    roll2 = ypr1[2] | (ypr1[3]<<8);
    yaw2  = Serial3.parseInt();
    pitch2= Serial3.parseInt();
    roll2 = Serial3.parseInt();  
  }
 
  float d1=1.0f,d2=0.0f;
  yaw   = d1*yaw2   + d2*yp;
  pitch = d1*pitch2 + d2*pp;
  roll  = d1*roll2  + d2*rpr;
  yaw   = 180 + yaw;
  Serial.print("ypr\t");
  Serial.print(yaw);
  Serial.print("\t");
  Serial.print(pitch);
  Serial.print("\t");
  Serial.println(roll);
  yp = yaw;
  pp = pitch;
  rpr = roll;
 
}
/*------------------------------------------------*/

/*------------------STAND-OR-BOW------------------*/
void bow(){
  Hm[0] = 0.8f;
  Hm[1] = 0.8f;
  
  Serial.println("bow");
  els[2][1] = 0;
  els[3][1] = 0;
  int ypriv[4] = {els[0][1],els[1][1],els[2][1],els[3][1]};
  int ynow[4]  = {-100,-100,0,0};
//  els[0][1] = -100;
//  els[1][1] = -100;
  if(ypriv[0]!=ynow[0])
  {
    for(int i=0;i<5;i++)
    {
      for(int y=0 ; y<4 ; y++)
        els[y][1] = map(i,0,4,ypriv[y],ynow[y]);
      getangle(0);
      getangle(1);
      RUN(1);
    }
  }
}
/*------------------------------------------------*/
void stand()
{
  Hm[0]     = 1.5f;
  Hm[1]     = 1.5f;
  Hm[2]     = 1.5f;
  Hm[3]     = 1.5f;
  els[0][1] = 0;
  els[1][1] = 0;
  els[2][1] = 0;
  els[3][1] = 0;
  Serial.println("Stand");
  getangle(4);
}
/*------------------------------------------------*/
void Raise()
{
  Hm[2]     = 0.8f;
  Hm[3]     = 0.8f;
  Hm[0]     = 1.5f;
  Hm[1]     = 1.5f;
  els[0][1] = 0;
  els[1][1] = 0;
  els[2][1] = -100;
  els[3][1] = -100;
  getangle(4);
}

