char dir2key(int value) {   //0: xleft, 1: xright, 2: zleft, 3: zright
  if(planeMode == true) {
    return dirPlane[value];
  }
  else {
    return dirRocket[value];
  }
}

//-----------------------------------------------------------------------------------------------------------

void loop() {

  loopAllButtons();
 
  setXActuation();
  actuateJoystick(xLeftActuation, dir2key(0), xLeftLastReleased);
  xLeftLastReleased = millis();
  actuateJoystick(xRightActuation, dir2key(1), xRightLastReleased);
  xRightLastReleased = millis();

  loopAllButtons();
  
  setYActuation();
  actuateJoystick(yDownActuation, pitchDown, yDownLastReleased);
  yDownLastReleased = millis();
  actuateJoystick(yUpActuation, pitchUp, yUpLastReleased);
  yUpLastReleased = millis();

  loopAllButtons();

  setZActuation();
  actuateJoystick(zLeftActuation, dir2key(2), zLeftLastReleased);
  zLeftLastReleased = millis();
  actuateJoystick(zRightActuation, dir2key(3), zRightLastReleased);
  zRightLastReleased = millis();

  loopAllButtons();

  setWActuation();
  actuateJoystick(wDownActuation, throttleUp, wDownLastReleased);
  wDownLastReleased = millis();
  actuateJoystick(wUpActuation, throttleDown, wUpLastReleased);
  wUpLastReleased = millis();

  loopAllButtons();

  checkSwitches();
  checkAGButtons();
  checkJBSButtons();
  checkReset();
  


  delay(loopDelay);        //delay so PWM direction control doesn't activate 1000 times/second
  }
