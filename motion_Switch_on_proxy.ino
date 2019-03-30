void proxy(){
  pf = digitalRead(fp);
  pr = digitalRead(rp);
  if(!(pf || pMode1) && gobi){
    staticG();
    Hm[0]=1.0;
    Hm[1]=1.0;
    turn(0);
    getangle(4);
    pMode1++;
  }
  if(!(pr || pMode) && gobi){
    Hm[0]=1.5;
    Hm[1]=1.5;
    pMode=1;
  }

  if( !((i-46)%90) )
  {
    if(els[0][1]== -100 && els[1][1]== -100) pMode++;
    else if(els[0][1]==0 && els[1][1]==0 && pMode>=7)      pMode++;

    if(roll>10 && els[0][1]==0 &&els[1][1]==0)
    {
      els[0][1]==-100;
      els[1][1]==-100;
      getangle(1);
      getangle(0);
    }
    if(pMode==1){       //INTITAL SWITCH OF LEGS
      if(LEG==1 && els[1][1]==0)
      {
        els[1][1]= -100;
        Hm[1]=0.8f;
        getangle(1);
      }
      else if(LEG==0 && els[0][1]==0)
      {
        els[0][1]= -100;
        Hm[0]=0.8f;
        getangle(0);
      }
    }

    //Increasing height of leg after
    else if(LEG==0 && els[0][1]==-100 && pMode>=7){
      els[0][1] = 0;
      getangle(0);
    }
    else if(LEG==1 && els[1][1]==-100 && pMode>=7){
      els[1][1] = 0;
      getangle(1);
    }
//    //raise both legs up if pitch drops
//    if((els[0][1]==-100 || els[1][1]==-100) && roll<-6)
//    {
//      els[1][1]=0;
//      els[0][1]=0;
//      getangle(1);
//      getangle(0);
//    }

    //switch to alternate pMode
    else if(els[1][1]==0 && els[0][1]==0 && pMode==20 && S==7000){
      alternate();
      turn(0);
      startC=1;
      baseY = yaw;
      Step=300;
      getangle(4);
    }
  }
//  if(steps>=20 && steps<=30)
//  {
//    turnX(0);
//    getangle(4);
//    steps=100;
//  }
  else if(steps>=126 && steps<=130)
  {
    staticG();
    getangle(4);
    steps=200;
  }
}
void stepCount(){
  if(Step==17){
//    leftEx();
//    getangle(4);
//    Step=100;
//    baseY = yaw;
  }
  else if(Step>11 && Step<200){
    if(yaw-(baseY-360)>40 || yaw-baseY>40 || Step>107){
      gobi=true;
      alternate();
      getangle(4);
      Step=200;
    }
  }
  else if(Step>305 && Step<400){
    rightEx();
    getangle(4);
    Step=400;
  }
  else if(Step>399 && Step<500){
    if(baseY-yaw>39 || baseY-(yaw-360)>39){
      straight();
      staticG();
      getangle(4);
      Step=500;
    }
  }
}

