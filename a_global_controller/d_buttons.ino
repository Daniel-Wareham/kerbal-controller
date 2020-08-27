void loopAllButtons() {               //function to loop all buttons, needs to be called regularly
  modeSwitch.loop();
  sasSwitch.loop();
  rcsSwitch.loop();
  gearsSwitch.loop();
  lightsSwitch.loop();
  
  AGbin1In.loop();
  AGbin2In.loop();
  AGbin4In.loop();
  AGbin8In.loop();
  
  JBSbin1In.loop();
  JBSbin2In.loop();
  
  resetButton.loop();
}

//-----------------------------------------------------------------------------------------------------------

void checkSwitches() {
  sasSwitchValue = sasSwitch.getState();
  if(sasSwitchValue != sasGameValue) { //if it's different, press the sas Key and update the game value
    Keyboard.write(sasKey);
    sasGameValue = sasSwitchValue;
  }

  rcsSwitchValue = rcsSwitch.getState();
  if(rcsSwitchValue != rcsGameValue) {
    Keyboard.write(rcsKey);
    rcsGameValue = rcsSwitchValue;
  }

  gearsSwitchValue = gearsSwitch.getState();
  if(gearsSwitchValue != gearsGameValue) {
    Keyboard.write(gearsKey);
    gearsGameValue = gearsSwitchValue;
  }

  lightsSwitchValue = lightsSwitch.getState();
  if(lightsSwitchValue != lightsGameValue) {
    Keyboard.write(lightsKey);
    lightsGameValue = lightsSwitchValue;
  }

  planeMode = modeSwitch.getState();
  
}

//-----------------------------------------------------------------------------------------------------------

void checkAGButtons() {
  //calculate binary value with the common way
  int AGvalue = 8*AGbin8In.getState() + 4*AGbin4In.getState() + 2*AGbin2In.getState() + AGbin1In.getState();

  for(int i=1; i<=15; i++) {          //cycle through all possible controls, if at value, press, else release
    if(i == AGvalue) {
      Keyboard.press(controlsAG[i]);
    }
    else{
      Keyboard.release(controlsAG[i]);
    }
  }
}

//-----------------------------------------------------------------------------------------------------------

void checkJBSButtons() {
  //calculate binary value with the common way
  int JBSvalue = 2*JBSbin2In.getState() + JBSbin1In.getState();
  for(int i=1; i<=3; i++) {
    if(i == JBSvalue) {
      Keyboard.press(controlsJBS[i]);
    }
    else{
      Keyboard.release(controlsJBS[i]);
    }
  }
}

//-----------------------------------------------------------------------------------------------------------

void checkReset() {
  if(resetButton.getState() == HIGH) {
    if (isResetLast == false) {           //start reset if only button is high and not high last time
      isResetLast = true;
      
      sasGameValue = false;
      rcsGameValue = false;
      lightsGameValue = false;
      
      if(planeMode == true) {     //in plane mode, gears are up by default, opposite in rocket mode
        gearsGameValue = true;
      }
      else {
        gearsGameValue = false;
      }  
    }
  }
  else {                          //if button not presssed, store it as so
    isResetLast = false;
  }
}
