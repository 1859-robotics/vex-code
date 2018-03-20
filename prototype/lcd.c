#ifndef _PROTOTYPE_LCD_
#define _PROTOTYPE_LCD_

// LCD button combonations for a single button being pressed
// 3 bit bin value converted to dec
#define LEFT_BUTTON 1
#define CENTER_BUTTON 2
#define RIGHT_BUTTON 4

// the number of auton programs the lcd should run through
#define AUTON_NUMBER 10


// the names of the auton programs
const string LCD_STRINGS[AUTON_NUMBER] = { "2 in 20 | R", "2 in 20 L",
                                           "2 in 5 | R",  "2 in 5 | L",
                                           "3 in 5 | R",  "3 in 5 L",
                                           "2 on stat | R", "2 on stat | L",
                                           "16 on stat | R", "16 on stat | L"};




// requires: null
// modifies: null
// affects:  waits until an lcd button is pressed
void waitForPress() {

 while(nLCDButtons == 0) {}
 wait1Msec(20);


}

// requires: null
// modifies: null
// affects:  waits until an lcd button is released
void waitForRelease() {

 while(nLCDButtons != 0) {}
 wait1Msec(20);

}


// requires: null
// modifies: null
// affects:  clears the lcd
void clearLCD() {
  clearLCDLine(0);
  clearLCDLine(1);
}


typedef struct {

  int data;        // may be able to be removed consider refactoring
  string lines[2]; // the data to be printed to the lcd

} lcdPane;

typedef struct {

  int active; // the active pane (index of panes array)

} LCD;

LCD lcd;                     // the global lcd
lcdPane panes[AUTON_NUMBER]; // the panes of the lcd

void lcdInit() {
  for(int i = 0; i < AUTON_NUMBER; i++) {

    panes[i].data     = i; // consider refactoring
    panes[i].lines[0] = LCD_STRINGS[i]; // sets the auton name
    panes[i].lines[1] = "<     Enter    >"; // can be changed

  }

  lcd.active = 0;
  clearLCD();

}
// requires: null
// modifies: null
// affects:  allows the user to select auton from the LCD
void selectAuton() {
  wait1Msec(200)
  while(nLCDButtons != CENTER_BUTTON) {
    // continue until the user selects the auton

    displayLCDCenteredString(0, panes[lcd.active].lines[0]);
    displayLCDCenteredString(1, panes[lcd.active].lines[1]);

    waitForPress();

    if(nLCDButtons == LEFT_BUTTON) {
      waitForRelease();
      lcd.active = lcd.active == 0 ? AUTON_NUMBER - 1 : lcd.active - 1;
      // wraps around if the active is 0

    } else if(nLCDButtons == RIGHT_BUTTON) {
      waitForRelease();
      lcd.active = lcd.active == AUTON_NUMBER - 1 ? 0 : lcd.active + 1;
      // wraps to prevent bad index of array
    }
  }
}

// requires: null
// modifies: null
// affects:  runs the selected auton
void runAuton() {
  for(int i = 0; i < AUTON_NUMBER; i++) {
    if(i == panes[lcd.active].data) {

      displayLCDCenteredString(1, "is running");

    }
  }

  // unfortunately robotC does not allow function pointers
  // so we are left with this mess
  displayLCDCenteredString(0, panes[lcd.active].lines[0]);
  if(panes[lcd.active].data == 0) {
    autonFuncTest();
    // autonRight22();
  } else if(panes[lcd.active].data == 1) {
    // autonLeft22();
  } else if(panes[lcd.active].data == 2) {
    // autonRight9()
  } else if(panes[lcd.active].data == 3) {
    // autonLeft9()
  } else if(panes[lcd.active].data == 4) {
    // autonRight11();
  } else if(panes[lcd.active].data == 5) {
    // autonLeft11();
  } else if(panes[lcd.active].data == 6) {
    // auton6StatRight();
  } else if(panes[lcd.active].data == 7) {
    // auton6StatLeft();
  } else if(panes[lcd.active].data == 8) {
    // autonSabatogeRight();
  } else if(panes[lcd.active].data == 9) {
    // autonSabatogeLeft();
  } else {
    displayLCDCenteredString(0, "somehting's screwy");
  }
}
const string LCD_STRINGS[AUTON_NUMBER] = { "2 in 20 | R", "2 in 20 L",
                                           "2 in 5 | R",  "2 in 5 | L",
                                           "3 in 5 | R",  "3 in 5 | L",
                                           "2 on stat | R", "2 on stat | L",
                                           "16 on stat | R", "16 on stat | L"};


#endif
