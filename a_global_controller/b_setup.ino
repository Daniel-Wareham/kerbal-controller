void setup() {
  pinMode(xPotPin, INPUT);
  pinMode(yPotPin, INPUT);
  pinMode(zPotPin, INPUT);
  pinMode(wPotPin, INPUT);
  
  pinMode(modePin, INPUT);
  pinMode(sasPin, INPUT);
  pinMode(rcsPin, INPUT);
  pinMode(gearsPin, INPUT);
  pinMode(lightsPin, INPUT);
  
  pinMode(AGbin1Pin, INPUT);
  pinMode(AGbin2Pin, INPUT);
  pinMode(AGbin4Pin, INPUT);
  pinMode(AGbin8Pin, INPUT);
  
  pinMode(JBSbin1Pin, INPUT);
  pinMode(JBSbin2Pin, INPUT);
  
  pinMode(resetPin, INPUT);
  
  Keyboard.begin();           //begin Keyboard and Serial
  Serial.begin(115200);

  int debounceTime = 75;

  modeSwitch.setDebounceTime(debounceTime);    //set debounce times for all buttons
  sasSwitch.setDebounceTime(debounceTime);
  rcsSwitch.setDebounceTime(debounceTime);
  gearsSwitch.setDebounceTime(debounceTime);
  lightsSwitch.setDebounceTime(debounceTime);
  
  AGbin1In.setDebounceTime(debounceTime);
  AGbin2In.setDebounceTime(debounceTime);
  AGbin4In.setDebounceTime(debounceTime);
  AGbin8In.setDebounceTime(debounceTime);
  
  JBSbin1In.setDebounceTime(debounceTime);
  JBSbin2In.setDebounceTime(debounceTime);
  
  resetButton.setDebounceTime(debounceTime);
  
  //set remaining of char array:
  controlsAG[11] = KEY_F9;
  controlsAG[12] = KEY_F5;

  
}
