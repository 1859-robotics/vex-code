#ifndef _PROTOTYPE_LCD_
#define _PROTOTYPE_LCD_

#define LEFT_BUTTON 1
#define CENTER_BUTTON 2
#define RIGHT_BUTTON 4

#define AUTON_NUMBER 4

const string LCD_STRINGS[AUTON_NUMBER] = { "RIGHT 22", "LEFT 22",
                                           "RIGHT 7",  "LEFT 7"
                                         };



// forward declaration
typedef struct lcdPane;

void waitForPress() {
 while(nLCDButtons == 0) {}
 wait1Msec(20);
}

void waitForRelease() {
 while(nLCDButtons != 0) {}
 wait1Msec(20);
}

void clearLCD() {
  clearLCDLine(0);
  clearLCDLine(1);
}

typedef struct {

  int data;
  string lines[2];

} lcdPane;

typedef struct {

  int count;
  int active;

} LCD;

LCD lcd;
lcdPane panes[AUTON_NUMBER];

void lcdInit() {
  for(int i = 0; i < AUTON_NUMBER; i++) {
    panes[i].data     = i;
    panes[i].lines[0] = LCD_STRINGS[i];
    panes[i].lines[1] = "<     Enter    >";


  }
  lcd.active = 0;
  clearLCD();

}




void selectAuton() {

  while(nLCDButtons != CENTER_BUTTON) {
    displayLCDCenteredString(0, panes[lcd.active].lines[0]);
    displayLCDCenteredString(1, panes[lcd.active].lines[1]);
    waitForPress();

    if(nLCDButtons == LEFT_BUTTON) {
      waitForRelease();
      lcd.active = lcd.active == 0 ? AUTON_NUMBER - 1 : lcd.active -= 1;

    } else if(nLCDButtons == RIGHT_BUTTON) {
      waitForRelease();
      lcd.active = lcd.active == AUTON_NUMBER - 1 ? 0 : lcd.active += 1;

    }
  }



}


void runAuton() {
  for(int i = 0; i < AUTON_NUMBER; i++) {
    if(i == panes[lcd.active].data == i) {
      displayLCDCenteredString(0, LCD_STRINGS[i]);
      displayLCDCenteredString(1, "is running");

    }
  }

  if(panes[lcd.active].data == 0) {
    auton22ptRight();
  } else if(panes[lcd.active].data == 1) {
    auton7ptRight();
  } else if(panes[lcd.active].data == 2) {
    auton22ptLeft();
  } else if(panes[lcd.active].data == 3) {
    auton7ptLeft();
  } else {
    displayLCDCenteredString(0, "somehting's screwy");

  }

}


#endif
