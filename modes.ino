void afterDune(){
  alternate();
  startC=1;
  baseY = yaw;
  Step=300;
  pMode=1000;
  getangle(4);
  Serial.println("5");
}
void mountain(){
  Step = 2000;
  pMode1 = 10000;
  pMode= 10000;
  DUNE = true;
}
