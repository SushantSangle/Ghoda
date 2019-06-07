void pinmode()
{
  pinMode(fp,INPUT);
  pinMode(rp,INPUT);
  pinMode(RP,INPUT);
  pinMode(9,INPUT);
  
  pinMode(ukkhai_m1,OUTPUT);
  pinMode(ukkhai_m2,OUTPUT);
  pinMode(ukkhai_pwm,OUTPUT);
  digitalWrite(ukkhai_m1,LOW);
  digitalWrite(ukkhai_m2,LOW);
  analogWrite(ukkhai_pwm,0);
  
  Serial3.begin(38400);
  Serial.begin(38400);
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
void init(int i){
  if(i)  initial();
  getangle(4);
  initial();
}
void gerejeStop(){
  digitalWrite(ukkhai_m1,HIGH);
  digitalWrite(ukkhai_m2,HIGH);
  analogWrite(ukkhai_pwm,255);
  
}
