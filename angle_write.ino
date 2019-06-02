/*------------------FOR-SLOPE---------------------*/
float Y(float x){return (x*tan(toD(slope)));}
/*------------------------------------------------*/

/*-----------------CALCULATE-ANGLE----------------*/
void getangle(int leg){
  if(leg==4)
  {
    getangle(0);
    getangle(1);
    getangle(2);
    getangle(3);
  }
  else{
    int Ex=elb[0]+els[leg][0];
    int Ey=elb[1]+els[leg][1];
    for(int i=0;i<72;i++)
    {
      if(leg == 2 || leg == 3)  m=-1;
      else                      m =1;

      double x=pt[i][0]*Lm[leg]*m;
      double y=pt[i][1]*Hm[leg];
      if(y==0) y=Y(x);

      float r = sqrt(s(Ex-x) + s(Ey-y));

      //  calculations for upper angle
      double th1 = acos((s(l1) + s(r) - s(l2)) / (2*l1*r) );
      th1 = (th1*180)/pi;
      double th2;
      if(Ex==x) th2=90;
      else{
        th2 = atan( (Ey-y)/(x-Ex) );
        th2 = (th2*180)/pi;
        if(th2<0){
          th2=180+th2;
        }
      }
      double a2 = acos((s(l2) + s(r) - s(l1)) / (2*l2*r) );
      a2 = (a2*180)/pi;
      double al =( 180 - th1 - a2);
      double th=th1+th2;

      Angle[leg][i][0] = th;
      Angle[leg][i][1] = al;
    }
  }
}
/*------------------------------------------------*/

/*-----------------------PHASE--------------------*/
void phaseAngle(int leg,int p,int dir=0){
  p=p%72;
  if(p==26){
    if(startC)  steps++; //for counting steps
    switch(leg)
    {
      case 0: LEG = 0; break;
      case 1: LEG = 1; break;
      case 2: LEG = 2; break;
      case 3: LEG = 3; break;
    }
  }
  if(p==52){
    switch(leg)
    {
      case 0: LEGP = 0; break;
      case 1: LEGP = 1; break;
      case 2: LEGP = 2; break;
      case 3: LEGP = 3; break;
    }
  }
  usWrite(leg,Angle[leg][p][0]);
  dsWrite(leg,Angle[leg][p][1]);
}
/*------------------------------------------------*/

/*----------------angles_to_servo-----------------*/
void usWrite(int i,int ang) //for giving angle to upper servo
{
  if(i<2)
    up[i].write(angle(ang+rot,upB[i],i));
  else
    up[i].write(angle(ang-rot,upB[i],i));
}
void dsWrite(int i,int ang)//for giving angle to lower servo
{
  down[i].write(angle(ang,downB[i],i+4));
}
/*------------------------------------------------*/
