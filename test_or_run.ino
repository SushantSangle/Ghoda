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
        phaseAngle(0,i+270,0);
        phaseAngle(1,i+90,0);
        phaseAngle(2,i+0,0);
        phaseAngle(3,i+180,0);
        break;
    }
    delay(S);
}
/*--------------------------------------------------*/
/*--------------------------------------------------*/
void shift(){
  if((i-45)%90==0)
  {
    
    switch(LEG){
      case 0: xnow[0]=-30;
              xnow[1]=-30;
              xnow[2]= 30;
              xnow[3]= 30;
              break;
      case 1: xnow[0]=-30;
              xnow[1]=-30;
              xnow[2]= 30;
              xnow[3]= 30;
              break;
      case 2: xnow[0]= 30;
              xnow[1]= 30;
              xnow[2]=-30;
              xnow[3]=-30;
              break;
      case 3: xnow[0]= 30;
              xnow[1]= 30;
              xnow[2]=-30;
              xnow[3]=-30;
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
    if(roll > 8) bow();
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
