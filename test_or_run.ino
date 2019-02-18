/*--------------------------------------------------*/
void RUN(int p){
    if(!p){ i++; i=i%360; }
    switch(mode)
    {
      case 0:
        phaseAngle(0,i+0,0);
        phaseAngle(1,i+180,0);
        phaseAngle(2,i+180,0);
        phaseAngle(3,i+0,0);
        break;
      case 1:
        phaseAngle(0,i+0,0);
        phaseAngle(1,i+180,0);
        phaseAngle(2,i+90,0);
        phaseAngle(3,i+270,0);
        break;
    }
    delay(S);
}
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void shift(){
    if(roll  >  9   && els[0][1]< 0 && els[3][1]==0 ) stand();
    if(roll  < -6   && els[0][1]==0 && els[3][1]==0 ) bow();
    if(roll  < -6   && els[3][1]< 0 && els[1][1]==0 ) stand();
//-ve -> / and +ve -> \0
//  if(roll  >  7   && els[3][1]==0 && els[0][1]==0 ) Raise();
  if((i-45)%90==0)
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
      for(int y=0 ; y<4 ; y++)
        els[y][0] = xnow[y];
      getangle(4);
      RUN(1);
      delay(20);
    }
    xpriv[0] = xnow[0];
    xpriv[1] = xnow[1];
    xpriv[2] = xnow[2];
    xpriv[3] = xnow[3];
  }
  

}
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void test(){
  dsWrite(3,90);
  usWrite(3,90);
  dsWrite(1,90);
  usWrite(1,90);
  dsWrite(2,90);
  usWrite(2,90);
  dsWrite(0,90);
  usWrite(0,90);
//  down[0].write(90);
//  up[0].write(90);
//  down[1].write(90);
//  up[1].write(90);
//  down[2].write(90);
//  up[2].write(90);
//  down[3].write(90);
//  up[3].write(80);
}
/*--------------------------------------------------*/
