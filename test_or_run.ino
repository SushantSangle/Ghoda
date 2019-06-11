/*--------------------------------------------------*/
int tn_run=0,tp_run=0;
void RUN(int p){
  tn_run = millis();
  I_increment = false;
  if(tn_run-tp_run>=S)
  {
    I_increment = true;
    if(!p){ 
      i++; 
      i=i%72;
      Step+=(i==1?1:0);   
    }
    phaseAngle(0,i+pDiff[0],0);
    phaseAngle(1,i+pDiff[1],0);
    phaseAngle(2,i+pDiff[2],0);
    phaseAngle(3,i+pDiff[3],0);

    tp_run = tn_run;
  }
}
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void shift(){
//    if(roll  < -6   && els[3][1]< 0 && els[1][1]==0 ) stand();
//-ve -> / and +ve -> \0
//  if(roll  >  7   && els[3][1]==0 && els[0][1]==0 ) Raise();
  if((i-9)%18==0 && mode==1)
  {
    int Sh = 20;
    switch(LEG){
      case 0: xnow[0]= Sh*-1;
              xnow[1]= Sh*-1;
              xnow[2]= Sh;
              xnow[3]= Sh;
              break;
      case 1: xnow[0]= Sh*-1;
              xnow[1]= Sh*-1;
              xnow[2]= Sh;
              xnow[3]= Sh;
              break;
      case 2: xnow[0]= Sh;
              xnow[1]= Sh;
              xnow[2]= Sh*-1;
              xnow[3]= Sh*-1;
              break;
      case 3: xnow[0]= Sh;
              xnow[1]= Sh;
              xnow[2]= Sh*-1;
              xnow[3]= Sh*-1;
              break;
    }
    RUN(1);

    if(xpriv[0]!=xnow[0])
    {
      for(int t=0 ; t<3 ; t++)
      {
        for(int y=0 ; y<4 ; y++)
          els[y][0] = map(t,0,2,xpriv[y],xnow[y]);
        getangle(4);
        RUN(1);
      }
      delay(20);
    }
    xpriv[0] = xnow[0];
    xpriv[1] = xnow[1];
    xpriv[2] = xnow[2];
    xpriv[3] = xnow[3];
    delay(50);
  }
}
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void test(){
  bool up_or_down = true;
  if(digitalRead(36))
  {
    down[0].write(90);
    up[0].write(90);
    down[1].write(90);
    up[1].write(90);
    down[2].write(90);
    up[2].write(90);
    down[3].write(90);
    up[3].write(90);
  }
  else{
    dsWrite(0,90);
    usWrite(0,90);
  
    dsWrite(1,90);
    usWrite(1,90);
  
    dsWrite(2,90);
    usWrite(2,90);
  
    dsWrite(3,90);
    usWrite(3,90);
  }
  while(1){
    if(digitalRead(37)){ up_or_down = true;  break;}
    if(digitalRead(38)){ up_or_down = false; break;}
  }
  while(1){
    if(up_or_down){
      for(int i=90;i<110;i++)
      {
        usWrite(0,i);
        usWrite(1,i);
        usWrite(2,i);
        usWrite(3,i);
        delay(10);
      }
      for(int i=110;i>90;i--)
      {
        usWrite(0,i);
        usWrite(1,i);
        usWrite(2,i);
        usWrite(3,i);
        delay(10);
      }
    }
    else{
      for(int i=90;i<110;i++)
      {
        dsWrite(0,i);
        dsWrite(1,i);
        dsWrite(2,i);
        dsWrite(3,i);
        delay(10);
      }
      for(int i=110;i>90;i--)
      {
        dsWrite(0,i);
        dsWrite(1,i);
        dsWrite(2,i);
        dsWrite(3,i);
        delay(10);
      }
      
    }
  }
  
  while(1);
}
/*--------------------------------------------------*/
void pausePlay(){
  if(digitalRead(3)==0 && pstate==1)
  {
    runMode=!runMode;
    pstate=0;
  }
  RUN(runMode);
  pstate=digitalRead(3);
}
void duneMode(){
  switch(Step)
  {
    case 2003 ... 2004: dune();
                  getangle(4);
                  Step=2100;
                  break;
    case 2124:    alternate();
                  getangle(4);
                  Step=2200;
                  break;
    case 2201  : initial();
                 Step=2300;
                 break;
    case 2301 :  UKKHAI(); 
                 initial();
                 break;
  }
}
void UKKHAI(){
  digitalWrite(ukkhai_m1,LOW);
  digitalWrite(ukkhai_m2,HIGH);
  analogWrite(ukkhai_pwm,150);
  delay(400);
  gerejeStop();
}
