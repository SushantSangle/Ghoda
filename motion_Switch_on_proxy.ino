void proxy()
{
  p1 = digitalRead(3);
  p0 = digitalRead(2);
  if(p0==0 && !pMode1)
  {
    staticG();
    getangle(4);
    pMode1++;
  }
  if(p1==0 &&  !pMode) pMode++ ;
  if(p1==1 && pMode==1 && (els[0][1]==-100 && els[1][1]==-100))  pMode++;  
  
  if((i-46)%90==0)
  {
    if(pMode>=3 && (LEG==0 || LEG==1))  pMode++;
    if(p1==1 &&  pMode>=1 && (els[0][1]==-100 && els[1][1]==-100) && (LEG==0 || LEG==1)) pMode++ ;
    
    if(LEG==0 && els[0][1]==0 && pMode==1){
      straight();
      els[0][1]=-100;
      Hm[0]=0.8f;
      getangle(0);
    }
    if(LEG==1 && els[1][1]==0 && pMode==1){
      straight();
      els[1][1]=-100;
      Hm[1]=0.8f;
      getangle(1);
    }
  
    if(LEG==0 && els[0][1]==-100 && pMode>=5){
      els[0][1]=0;
      Hm[0]=1.5f;
      getangle(0);
    }
    if(LEG==1 && els[1][1]==-100 && pMode>=5){
      els[1][1]=0;
      Hm[1]=1.5f;
      getangle(1);
    }
    if(els[1][1]==0 && els[0][1]==0 && pMode==10 && S==7000){
      alternate();
      right();
      getangle(4);
    }
    if(pMode==15 && S==1500){
      staticG();
      getangle(4);
    }
  }
}

