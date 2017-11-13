#ifndef _PROTOTYPE_LCD_
#define _PROTOTYPE_LCD_

#define LEFT_BUTTON 1
#define CENTER_BUTTON 2
#define RIGHT_BUTTON 4

#define AUTON_NUMBER 4

const string LCD_STRINGS[AUTON_NUMBER] = { "RIGHT 22", "LEFT 22",
                                           "RIGHT 7",  "LEFT 7"
                                         };


// void *autonFuncs[AUTON_NUMBER] = { &auton22ptRight, &auton22ptLeft,
//                                    &auton7ptRight,  &auton7ptLeft
// };


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
  lcdPane *lSibling;
  lcdPane *rSibling;

  int data;
  string lines[2];

} lcdPane;

typedef struct {

  int count;
  lcdPane *active;

} LCD;

LCD lcd;
lcdPane panes[AUTON_NUMBER];

void lcdInit() {
  for(int i = 0; i < AUTON_NUMBER; i++) {
    panes[i].data     = i;
    panes[i].lines[0] = "<     Enter    >";
    panes[i].lSibling = &panes[i > 0 ? i + 1 : AUTON_NUMBER - 1];
    panes[i].rSibling = &panes[i < AUTON_NUMBER ? i - 1 : 0];

    panes[i].lines[1] = LCD_STRINGS[i];
  }

  clearLCD();

}




void selectAuton() {

  while(nLCDButtons != CENTER_BUTTON) {
    displayLCDCenteredString(0, lcd.active->lines[0]);
    displayLCDCenteredString(1, lcd.active->lines[1]);
    waitForPress();

    if(nLCDButtons == LEFT_BUTTON) {
      waitForRelease();
      *lcd.active = lcd.active->lSibling;
    } else if(nLCDButtons == RIGHT_BUTTON) {
      waitForRelease();
      *lcd.active = lcd.active->rSibling;
    }
  }



}


void runAuton() {
  for(int i = 0; i < AUTON_NUMBER; i++) {
    if(i == lcd.active->data == i) {
      displayLCDCenteredString(0, LCD_STRINGS[i]);
      displayLCDCenteredString(1, "is running");

    }
  }

  if(lcd.active->data == 0) {
    auton22ptRight();
  } else if(lcd.active->data == 1) {
    auton22ptRight();
  } else if(lcd.active->data == 2) {
    auton22ptRight();
  } else if(lcd.active->data == 3) {
    auton22ptRight();
  } else {
    displayLCDCenteredString(0, "somehting's fucky");

  }

}


#endif
