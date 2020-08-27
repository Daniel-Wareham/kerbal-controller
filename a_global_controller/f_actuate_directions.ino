void actuateJoystick(int actuation, char key, long lastReleased) {
  if(actuation == 100) {
    Keyboard.press(key);
  }
  else if(actuation == 0) {
    Keyboard.release(key);
  }
  else {
    int releasedTime = millis() - lastReleased;
    float holdTime = releasedTime*actuation/(100-actuation);
    /*
     * There is a bug where the holdTime will be calculated as negative for some reason
     * I have no idea why this is because all the inputs are normal. Maybe it's something
     * to do with variable structures or weirdness of arduino calculations that I don't
     * know, so in the meantime the only thing I can think to do is crudely avoid the problem
     * good solution? no. works? yes.
     */
    if(holdTime < 0) {    
      holdTime = 0;
      Serial.println("was negative for some reason");
    }
    Keyboard.press(key);
    Serial.println("holding key");
    Serial.println(holdTime);
    Serial.println(releasedTime);
    Serial.println(actuation);
    delay(holdTime);
    Keyboard.release(key);
  }
}
