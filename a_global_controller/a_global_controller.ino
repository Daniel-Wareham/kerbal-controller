#include<Keyboard.h>    //library to send keyboard inputs
#include<ezButton.h>    //library to debounce buttons

const int loopDelay = 100;

const int xPotMid = 550;        //POT values
const int xPotMidUpper = 580;
const int xPotMidLower = 520;

const int yPotMid = 520;
const int yPotMidUpper = 550;
const int yPotMidLower = 490;

const int zPotMid = 520;
const int zPotMidUpper = 550;
const int zPotMidLower = 490;

const int wPotMid = 515;        //bigger dead zone for throttle
const int wPotMidUpper = 545;
const int wPotMidLower = 485;


//

const int xPotPin = A0;     //pins
const int yPotPin = A1;
const int zPotPin = A3;     //swapped because I connected it wrong
const int wPotPin = A2;

const int modePin = 2;
const int sasPin = 3;
const int rcsPin = 4;
const int gearsPin = 5;
const int lightsPin = 6;

const int AGbin1Pin = 7;
const int AGbin2Pin = 8;
const int AGbin4Pin = 9;
const int AGbin8Pin = 10;

const int JBSbin1Pin = 14;
const int JBSbin2Pin = 15;

const int resetPin = 16;



const char dirPlane[5] = "qead";    //direction chars
const char dirRocket[5] = "adqe";

const char pitchDown = 'w';
const char pitchUp = 's';
const char throttleUp = KEY_LEFT_SHIFT;
const char throttleDown = KEY_LEFT_CTRL;

const char sasKey = 't';        //toggle chars
const char rcsKey = 'r';
const char gearsKey = 'g';
const char lightsKey = 'u';

char controlsAG[20] = "*1234567890**,.m";   //AG + control chars (the rest in setup), "*" is a placeholder
char controlsJBS[5] = "* xz";               //JB + stage chars



ezButton modeSwitch(modePin);    //make objects to debounce inputs with ezButton library
ezButton sasSwitch(sasPin);
ezButton rcsSwitch(rcsPin);
ezButton gearsSwitch(gearsPin);
ezButton lightsSwitch(lightsPin);

ezButton AGbin1In(AGbin1Pin);
ezButton AGbin2In(AGbin2Pin);
ezButton AGbin4In(AGbin4Pin);
ezButton AGbin8In(AGbin8Pin);

ezButton JBSbin1In(JBSbin1Pin);
ezButton JBSbin2In(JBSbin2Pin);

ezButton resetButton(resetPin);



bool sasGameValue = false;        //variables used for toggle switches
bool rcsGameValue = false;
bool gearsGameValue = false;
bool lightsGameValue = false;

bool sasSwitchValue;
bool rcsSwitchValue;
bool gearsSwitchValue;
bool lightsSwitchValue;

bool planeMode = true;

bool isResetLast = false; //variable to only detect rising edge of reset



int xPotValue;               //variables for value of inputs
int yPotValue;
int zPotValue;
int wPotValue;


float xLeftActuation = 0.0;        //variables to control motion of Pots
long xLeftLastReleased = 0;
float xRightActuation;
long xRightLastReleased = 0;

float yDownActuation;
long yDownLastReleased = 0;
float yUpActuation;
long yUpLastReleased = 0;

float zLeftActuation;
long zLeftLastReleased = 0;
float zRightActuation;
long zRightLastReleased = 0;

float wDownActuation;
long wDownLastReleased = 0;
float wUpActuation;
long wUpLastReleased = 0;
