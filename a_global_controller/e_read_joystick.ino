void setXActuation() {    //turns the analog input into actuation values from 0-100
  xPotValue = analogRead(xPotPin);                                
  if(xPotValue < xPotMidUpper && xPotValue > xPotMidLower) {      //values within upper and lower become 0
    xLeftActuation = 0;
    xRightActuation = 0;
  }
  else if(xPotValue > 950){                                       //values above max and min become 100, requried for PWM pressing of the keys
    xLeftActuation = 100;
    xRightActuation = 0;
  }
  else if(xPotValue < 50){
    xRightActuation = 100;
    xLeftActuation = 0;
  }
  else if(xPotValue <= xPotMidLower) {                            //for other values, map the input to 0-100
    xRightActuation = map(xPotValue, 0, xPotMid, 100, 0);
    xLeftActuation = 0;
  }
  else if(xPotValue >= xPotMidUpper) {
    xLeftActuation = map(xPotValue, xPotMid, 1023, 0, 100);
    xRightActuation = 0;
  }
}

//-----------------------------------------------------------------------------------------------------------

void setYActuation() {
  yPotValue = analogRead(yPotPin);                                
  if(yPotValue < yPotMidUpper && yPotValue > yPotMidLower) {
    yDownActuation = 0;
    yUpActuation = 0;
  }
  else if(yPotValue > 950){
    yDownActuation = 100;
    yUpActuation = 0;
  }
  else if(yPotValue < 50){
    yUpActuation = 100;
    yDownActuation = 0;
  }
  else if(yPotValue <= yPotMidLower) {
    yUpActuation = map(yPotValue, 0, yPotMid, 100, 0);
    yDownActuation = 0;
  }
  else if(yPotValue >= yPotMidUpper) {
    yDownActuation = map(yPotValue, yPotMid, 1023, 0, 100);
    yUpActuation = 0;
  }
}

//-----------------------------------------------------------------------------------------------------------

void setZActuation() {
  zPotValue = analogRead(zPotPin);                                
  if(zPotValue < zPotMidUpper && zPotValue > zPotMidLower) {
    zLeftActuation = 0;
    zRightActuation = 0;
  }
  else if(zPotValue > 950){
    zLeftActuation = 100;
    zRightActuation = 0;
  }
  else if(zPotValue < 50){
    zRightActuation = 100;
    zLeftActuation = 0;
  }
  else if(zPotValue <= zPotMidLower) {
    zRightActuation = map(zPotValue, 0, zPotMid, 100, 0);
    zLeftActuation = 0;
  }
  else if(zPotValue >= zPotMidUpper) {
    zLeftActuation = map(zPotValue, zPotMid, 1023, 0, 100);
    zRightActuation = 0;
  }
}

//-----------------------------------------------------------------------------------------------------------

void setWActuation() {
  wPotValue = analogRead(wPotPin);                                
  if(wPotValue < wPotMidUpper && wPotValue > wPotMidLower) {
    wDownActuation = 0;
    wUpActuation = 0;
  }
  else if(wPotValue > 950){
    wDownActuation = 100;
    wUpActuation = 0;
  }
  else if(wPotValue < 50){
    wUpActuation = 100;
    wDownActuation = 0;
  }
  else if(wPotValue <= wPotMidLower) {
    wUpActuation = map(wPotValue, 0, wPotMid, 100, 0);
    wDownActuation = 0;
  }
  else if(wPotValue >= wPotMidUpper) {
    wDownActuation = map(wPotValue, wPotMid, 1023, 0, 100);
    wUpActuation = 0;
  }
}
