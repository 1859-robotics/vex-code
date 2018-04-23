#ifndef _PROTOTYPE_LCD_
#define _PROTOTYPE_LCD_

// LCD button combonations for a single button being pressed
// 3 bit bin value converted to dec
#define LEFT_BUTTON 1
#define CENTER_BUTTON 2
#define RIGHT_BUTTON 4

// the number of auton programs the lcd should run through
#define AUTON_NUMBER 7


// the names of the auton programs
tStringArray dirSelection;
const string DIR_VALUES[2] = { "right", "left" };

tStringArray autonSelection;
const string LCD_STRINGS[AUTON_NUMBER] = { "3 in 20 | S", "2 in 20",
                                           "2 in 10", "4 in 10 | S",
                                           "2 in 5", "5 in 5 | S",
                                           "equalizer", "do nothing"};

int sideValue;
int autonValue;

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


void lcdInit() {

  // unfortunately robotC is fucky with its arrays so we
  // can't farm this out to a function
  // fortunately there are only 2 of these
  for(int i = 0; i < sizeofArr(DIR_VALUES); i++) {
    dirSelection.arr[i] = DIR_VALUES[i];
  }
  for(int i = 0; i < sizeofArr(LCD_STRINGS); i++) {
    autonSelection.arr[i] = LCD_STRINGS[i];
  }


  clearLCD();
}

int LCDSelectInt(tStringArray selection, int length) {
  int active = 0;

  while(nLCDButtons != CENTER_BUTTON) {

    displayLCDCenteredString(0, selection.arr[active]);
    displayLCDCenteredString(1, "<     Enter    >");

    waitForPress();

    if(nLCDButtons == LEFT_BUTTON) {
      waitForRelease();
      active = active == 0 ? length - 1 : active - 1;
      // wraps around if the active is 0

    } else if(nLCDButtons == RIGHT_BUTTON) {
      waitForRelease();
      active = active == length - 1 ? 0 : active + 1;
      // wraps to prevent bad index of array
    }
  }
  return active;
}





// requires: null
// modifies: null
// affects:  allows the user to select auton from the LCD
void selectAuton() {
  long liAtTargetTime = nPgmTime;
  bool bExitEarly = false;
  while(!bExitEarly) {
    if(nLCDButtons == CENTER_BUTTON) {
      wait1Msec(400);
      sideValue = LCDSelectInt(dirSelection, 2);
      wait1Msec(400);
      autonValue = LCDSelectInt(autonSelection, AUTON_NUMBER);
      clearLCD();
      return;
    }
    if(nPgmTime - liAtTargetTime > 5000) {
      bExitEarly = true;
    }
    string str = "";
    stringFormat(str, "%f", (nPgmTime - liAtTargetTime));
    displayLCDCenteredString(1, str);
  }

}

// requires: null
// modifies: null
// affects:  runs the selected auton
void runAuton() {
  displayLCDCenteredString(1, autonSelection.arr[autonSelection]);
  sideValue = sideValue == 0 ? -1 : 1;

  // unfortunately robotC does not allow function pointers
  // so we are left with this mess
  if(autonValue == 0) {
    auton20Short(sideValue);
  } else if(autonValue == 1) {
    auton20(sideValue);
  } else if(autonValue == 2) {
    auton10(sideValue);
  } else if(autonValue == 3) {
    auton10Short(sideValue);
  } else if(autonValue == 4) {
    auton5(sideValue);
  } else if(autonValue == 5) {
    auton5Short(sideValue);
  } else if(autonValue == 6) {
    autonSabatoge(sideValue);
  } else if(autonValue == 7) {
    return;
  } else {
    displayLCDCenteredString(0, "somehting's screwy");
  }
}


#endif
