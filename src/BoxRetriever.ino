#include <Dobot.h>

const int buttonPinA = 7;
const int buttonPinB = 8;
const int buttonPinC = 9;

int buttonStateA = 0;
int buttonStateB = 0;
int buttonStateC = 0;

bool instructionAExecuted = false;
bool instructionBExecuted = false;
bool instructionCExecuted = false;

Dobot dobot = Dobot();

byte zUp[] = {170, 170, 4, 73, 1, 0, 5, 177};
byte zDown[] = {170, 170, 4, 73, 1, 0, 6, 176};
byte homing[] = {170, 170, 6, 31, 3, 0, 0, 0, 0, 222};
byte commandStop[] = {170, 170, 4, 73, 1, 0, 0, 182};
byte pickup[] = {170, 170, 4, 62, 3, 1, 1, 189};
byte dropdown[] = {170, 170, 4, 62, 3, 1, 0, 190};

// Block 1
byte pos0[] = {170,170,19,84,3,1,109,250,74,67,172,14,138,192,204,63,50,194,0,0,0,0,177};
byte pos1[] = {170,170,19,84,3,1,144,234,130,66,255,30,109,195,110,24,44,66,0,0,0,0,41};
byte pos2[] = {170,170,19,84,3,1,88,117,28,66,217,88,104,195,166,90,64,194,0,0,0,0,31};
byte pos2_5[] = {170,170,19,84,3,1,241,241,44,66,132,123,104,195,182,240,102,66,0,0,0,0,224};

// Block 2
byte pos3[] = {170,170,19,84,3,1,215,83,84,67,255,126,169,66,128,88,156,65,0,0,0,0,202};
byte pos4[] = {170,170,19,84,3,1,156,157,84,67,86,76,174,66,176,211,51,194,0,0,0,0,206};
byte pos5[] = {170,170,19,84,3,1,60,134,28,66,129,217,101,195,64,121,133,65,0,0,0,0,135};
byte pos6[] = {170,170,19,84,3,1,153,86,43,66,34,138,106,195,120,151,144,193,0,0,0,0,19};

// Block 3
byte pos7[] = {170,170,19,84,3,1,111,21,133,67,153,39,7,195,120,113,66,193,0,0,0,0,230};
byte pos8[] = {170,170,19,84,3,1,38,105,133,67,196,186,8,195,29,235,47,194,0,0,0,0,15};

void setup() {
  dobot.begin();
  Serial.begin(115200);
  pinMode(buttonPinA, INPUT_PULLUP);
  pinMode(buttonPinB, INPUT_PULLUP);
  pinMode(buttonPinC, INPUT_PULLUP);
  dobot.commandFrame(homing);
}

void loop() {
  buttonStateA = digitalRead(buttonPinA);
  if (buttonStateA == HIGH && !instructionAExecuted) {
    dobot.commandFrame(pos0); delay(1500);
    dobot.commandFrame(pickup); delay(1500);
    dobot.commandFrame(pos1); delay(1500);
    dobot.commandFrame(pos2); delay(1500);
    dobot.commandFrame(dropdown); delay(1500);
    dobot.commandFrame(pos1);
    instructionAExecuted = true;
  }
  if (buttonStateA == LOW) instructionAExecuted = false;

  buttonStateB = digitalRead(buttonPinB);
  if (buttonStateB == HIGH && !instructionBExecuted) {
    dobot.commandFrame(pos3); delay(1500);
    dobot.commandFrame(pos4); delay(1500);
    dobot.commandFrame(pickup); delay(1500);
    dobot.commandFrame(pos5); delay(1500);
    dobot.commandFrame(pos2); delay(1500);
    dobot.commandFrame(dropdown); delay(1500);
    dobot.commandFrame(pos2_5); delay(1500);
    instructionBExecuted = true;
  }
  if (buttonStateB == LOW) instructionBExecuted = false;

  buttonStateC = digitalRead(buttonPinC);
  if (buttonStateC == HIGH && !instructionCExecuted) {
    dobot.commandFrame(pos7); delay(1500);
    dobot.commandFrame(pos8); delay(1500);
    dobot.commandFrame(pickup); delay(1500);
    dobot.commandFrame(pos5); delay(1500);
    dobot.commandFrame(pos2); delay(1500);
    dobot.commandFrame(dropdown); delay(1500);
    dobot.commandFrame(pos1);
    instructionCExecuted = true;
  }
  if (buttonStateC == LOW) instructionCExecuted = false;
}
