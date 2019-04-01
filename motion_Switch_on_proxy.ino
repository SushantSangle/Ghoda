void proxy(){
  pf = digitalRead(fp);
  pr = digitalRead(rp);
  if(!(pf || pMode1) && gobi){
    staticG();
    Hm[0]=1.0;
    Hm[1]=1.0;
    getangle(4);
    pMode1++;
  }
  if(!(pr || pMode) && gobi){
    Hm[0]=1.5;
    Hm[1]=1.5;
    pMode=1;
  }

  if( !((i-46)%90) && gobi)
  {
    if(els[0][1]== -100 && els[1][1]== -100) 
      pMode++;
    else if(els[0][1]==0 && els[1][1]==0 && pMode>=7)      
      pMode++;

//    if(roll>10 && els[0][1]==0 &&els[1][1]==0)
//    {
//      els[0][1]==-100;
//      els[1][1]==-100;
//      getangle(1);
//      getangle(0);
//    }
    if(pMode==1){       //INTITAL SWITCH OF LEGS
      if(LEG==1 && els[1][1]==0)
      {
        els[1][1]= -100;
        Hm[1]=1.5f;
        Lm[1]=1.2f;
        getangle(1);
      }
      else if(LEG==0 && els[0][1]==0)
      {
        els[0][1]= -100;
        Hm[0]=1.5f;
        Lm[0]=1.2f;
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
    //raise both legs up if pitch drops
    if((els[0][1]==-100 || els[1][1]==-100) && roll<-6)
    {
      els[1][1]=0;
      els[0][1]=0;
      getangle(1);
      getangle(0);
    }

    //switch to alternate pMode
    else if(els[1][1]==0 && els[0][1]==0 && pMode==16 && S==7000){
      alternate();
      left();
      Lm[0]=0.65f;
      Lm[2]=0.65f;
      startC=1;
      baseY = yaw;
      Step=300;
      pMode=1000;
      getangle(4);
    }
//    else if(steps>=126 && steps<=130)
//    {
//      staticG();
//      getangle(4);
//      steps=200;
//    }
  }
}
void stepCount(){
  int diff = baseY-yaw;
  int idiff = diff*-1;
  if(Step==11){
//    leftEx();
//    getangle(4);
    Step=100;
//    baseY = yaw;
  }
  else if(Step>11 && Step<200){
    if((diff>150 && diff<315) || idiff>45 || Step>103){
      gobi=true;
      alternate();
      left();
      getangle(4);
      Step=200;
    }
  }
  else if(Step<400 && Step>302){
    initial();
    rightEx();
    getangle(4);
    Step=400;
  }
  else if(Step>399 && Step<500){
//    if(diff>40 || (idiff>150 && idiff<320) || Step>411)
    if(Step>412)
    {
//      right();
      staticG();
      Hm[0] = 1.7;
      Hm[1] = 1.7;
      Hm[2] = 1.7;
      Hm[3] = 1.7;
      getangle(4);
      Step=500;
    }
  }
}
