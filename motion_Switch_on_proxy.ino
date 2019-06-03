int hval=-90;
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
  

  if( !((i-9)%18) && gobi)
  {
    if(els[0][1]== hval && els[1][1]== hval)               pMode++;
    else if(els[0][1]==0 && els[1][1]==0 && pMode>=6)      pMode++;
    
    //INTITAL SWITCH OF LEGS  
    if(pMode==1){       
      if(LEG==1 && els[1][1]==0)
      {
        els[1][1]= hval;
        Hm[1]=1.5f;
        Lm[1]=1.2f;
        getangle(1);
      }
      else if(LEG==0 && els[0][1]==0)
      {
        els[0][1]= hval;
        Hm[0]=1.5f;
        Lm[0]=1.2f;
        getangle(0);
      }
    }
    //Increasing height of leg after
    //switch to alternate pMode
    else if(els[1][1]==0 && els[0][1]==0 && pMode==20 && S==35){
      alternate();
      startC=1;
      baseY = yaw;
      Step=300;
      pMode=1000;
      getangle(4);
    }
  }
  if(!(i%18)){
    if(LEGP==0 && els[0][1]==hval && (pMode>=6 || (pr&&pf && pMode>4) ) ){
      els[0][1] = 0;
      Hm[0] = 0.6;
      Lm[0] = 0.7;
      getangle(0);
      pMode = 6;
    }
    else if(LEGP==1 && els[1][1]==hval && (pMode>=6 || (pr&&pf && pMode>4) ) ){
      els[1][1] = 0;
      Hm[1] = 0.6;
      Lm[1] = 0.7;
      getangle(1);
      pMode = 6;
    }
  }
}
void stepCount(){
  int diff = baseY-yaw;
  int idiff = diff*-1;
  if(Step==12){
//    leftEx();
    getangle(4);
    Step=200;
    gobi = true;
  }
//  else if(Step>100 && Step<200){
//    if((diff>150 && diff<315) || idiff>45 || Step>106){
//      gobi=true;
//      alternate();
//      left();
//      getangle(4);
//      Step=200;
//    }
//  }
  else if(Step<400 && Step>305){
    initial();
    rightEx();
    getangle(4);
    Step=400;
  }
  else if(Step>399 && Step<500){
    if(diff>35 || (idiff>150 && idiff<320) || Step>405)
//    if(Step>41)
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
