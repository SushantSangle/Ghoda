void pinmode()
{
  Serial3.begin(38400);
  Serial.begin(38400);
  while(Serial.available()) Serial.read();
  
  for(int i=0;i<4;i++)
  {
    pinMode(upS[i],OUTPUT);
    up[i].attach(upS[i]);
    
    pinMode(downS[i],OUTPUT);
    down[i].attach(downS[i]);
  }
  Angle[0][0][0]=102;
  Angle[0][0][1]=156;
  Angle[1][0][0]=102;
  Angle[1][0][1]=156;
  Angle[2][0][0]=102;
  Angle[2][0][1]=156;
  Angle[3][0][0]=102;
  Angle[3][0][1]=156;
}
void initial(){

  phaseAngle(0,0);
  phaseAngle(1,0);
  phaseAngle(2,0);
  phaseAngle(3,0);
}

