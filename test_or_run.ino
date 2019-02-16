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

void RUN(int p){
    if(p<2){ i++; i=i%360; }
    p=p%2;
    switch(p)
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
