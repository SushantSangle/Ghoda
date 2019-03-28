void proxy(){
  pf = digitalRead(fp);
  pr = digitalRead(rp);
  if(!(pf || pMode1)){
    staticG();
    Hm[0]=1.0;
    Hm[1]=1.0;
    turn(0);
    getangle(4);
    pMode1++;
  }
  if(!(pr || pMode)){
    Hm[0]=1.5;
    Hm[1]=1.5;
    pMode=1;
  }

  if( !((i-46)%90) )
  {
    if(els[0][1]== -100 && els[1][1]== -100) pMode++;
    else if(els[0][1]==0 && els[1][1]==0 && pMode>=8)      pMode++;

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

    //switch to alternate pMode
    else if(els[1][1]==0 && els[0][1]==0 && pMode==20 && S==7000){
      alternate();
      turn(0);
      startC=1;
      getangle(4);
    }
  }
  if(steps>=20 && steps<=30)
  {
    turnX(0);
    getangle(4);
    steps=100;
  }
  else if(steps>=126 && steps<=130)
  {
    staticG();
    getangle(4);
    steps=200;
  }
}
void stepCount(){
  if(Step==9){
    leftEx();
    getangle(4);
    Step=100;
    baseY = yaw;
  }
  else if(Step>99 && Step<200){
    if(yaw-baseY>45){
      straight();
      alternate();
      getangle(4);
      Step=200;
    }
  }
}

