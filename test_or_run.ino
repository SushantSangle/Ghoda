/*--------------------------------------------------*/
int tn_run=0,tp_run=0;
void RUN(int p){
  tn_run = millis();
  if(tn_run-tp_run>=S)
  {
    if(!p){ 
      i++; 
      i=i%72;
      Step+=(i==1?1:0);   
    }
    switch(mode)
    {
      case 0:
        phaseAngle(0,i+0,0);
        phaseAngle(1,i+36,0);
        phaseAngle(2,i+36,0);
        phaseAngle(3,i+0,0);
        break;
      case 1:
        phaseAngle(0,i+00,0);
        phaseAngle(1,i+36,0);
        phaseAngle(2,i+18,0);
        phaseAngle(3,i+54,0);
        break;
    }
    tp_run = tn_run;
  }
}
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void shift(){
//    if(roll  < -6   && els[3][1]< 0 && els[1][1]==0 ) stand();
//-ve -> / and +ve -> \0
//  if(roll  >  7   && els[3][1]==0 && els[0][1]==0 ) Raise();
  if((i-9)%18==0)
  {
    int Sh = 40;
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
    delay(150);
  }
  if(roll  >  6   && els[0][1]< 0 && els[3][1]==0 ) stand();
  if(roll  < -6   && els[0][1]==0 && els[3][1]==0 ) bow();
}
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void test(){
  dsWrite(0,90);
  usWrite(0,90);

  dsWrite(1,90);
  usWrite(1,90);

  dsWrite(2,90);
  usWrite(2,90);

  dsWrite(3,90);
  usWrite(3,90);

//  down[0].write(90);
//  up[0].write(90);
//  down[1].write(90);
//  up[1].write(90);
//  down[2].write(90);
//  up[2].write(90);
//  down[3].write(90);
//  up[3].write(90);
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
    case 3 ... 4: dune();
                  getangle(4);
                  Step=100;
                  break;
    case 124:    staticG();
                  getangle(4);
                  Step=200;
                  break;
    case 201  :   initial();
                 Step=300;
                 break;
    case 301 :   initial();
                 break;
  }
}
