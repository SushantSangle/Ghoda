int hval=-90;
void proxy(){
  pf = digitalRead(fp);
  pr = digitalRead(rp);
  if(!(pf || pMode1) && gobi){
    staticG();
    Hm[0]=1.0;
    Hm[1]=1.0;
    Hm[2]=1.7;
    Hm[3]=1.7;
    getangle(4);
    pMode1++;
    Serial.println("1");
  }
  if(!(pr || pMode) && gobi){
    Hm[0]=1.5;
    Hm[1]=1.5;
    pMode=1;
    
    Serial.println("2");
  }
  

  if( !((i-9)%18) && gobi && I_increment)
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
        
        Serial.println("3");
      }
      else if(LEG==0 && els[0][1]==0)
      {
        els[0][1]= hval;
        Hm[0]=1.5f;
        Lm[0]=1.2f;
        getangle(0);
        Serial.println("4");
      }
    }
    
    //switch to alternate pMode
    else if(els[1][1]==0 && els[0][1]==0 && pMode>=16 && S==35 && pMode<500){
      alternate();
      startC=1;
      baseY = yaw;
      Step=300;
      pMode=1000;
      getangle(4);
      Serial.println("5");
    }
  }
  //Increasing height of leg after
  if(!(i%18)&& I_increment){
    if(LEGP==0 && els[0][1]==hval && (pMode>=6 ||(pr&&pf && pMode>4) ) ){
      els[0][1] = 0;
      Hm[0] = 0.8;
      Lm[0] = 1.0;
      getangle(0);
      pMode = 6;
      Serial.println("6");
    }
    else if(LEGP==1 && els[1][1]==hval && (pMode>=6 ||(pr&&pf && pMode>4) ) ){
      els[1][1] = 0;
      Hm[1] = 0.8;
      Lm[1] = 1.0;
      getangle(1);
      pMode = 6;
      Serial.println("7");
    }
  }
}
void stepCount(){
  int diff = baseY-yaw;
  int idiff = diff*-1;
  if(Step==13){
    Serial.println("9");
    getangle(4);
    Step=200;
    gobi = true;
  }
  else if(Step<400 && Step>304){
    Serial.println("10");
    initial();
    turnX(ARENA);
    getangle(4);
    Step=400;
  }
  else if(Step>399 && Step<500){
    if(diff>35 || (idiff>150 && idiff<320) || Step>406)
    {
      Serial.println("11");
      alternate();
      S=15;
      Hm[0] = 1.7;
      Hm[1] = 1.7;
      Hm[2] = 1.7;
      Hm[3] = 1.7;
      getangle(4);
      Step=500;
    }
  }
}
