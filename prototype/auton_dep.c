//  //Loop while center button is not pressed
//  while(nLCDButtons != centerButton)
//  {
//    //Switch case that allows the user to choose from 4 different options
//    switch(count){
//    case 0:
//      //Display first choice
//      displayLCDCenteredString(0, "RIGHT 22");
//      displayLCDCenteredString(1, "<     Enter    >");
//      waitForPress();
//      //Increment or decrement "count" based on button press
//      if(nLCDButtons == leftButton)
//      {
//        waitForRelease();
//        count = 3;
//      }
//      else if(nLCDButtons == rightButton)
//      {
//        waitForRelease();
//        count++;
//      }
//      break;
//    case 1:
//      //Display second choice
//      displayLCDCenteredString(0, "RIGHT 7");
//      displayLCDCenteredString(1, "<     Enter    >");
//      waitForPress();
//      //Increment or decrement "count" based on button press
//      if(nLCDButtons == leftButton)
//      {
//        waitForRelease();
//        count--;
//      }
//      else if(nLCDButtons == rightButton)
//      {
//        waitForRelease();
//        count++;
//      }
//      break;
//    case 2:
//      //Display third choice
//      displayLCDCenteredString(0, "LEFT 22");
//      displayLCDCenteredString(1, "<     Enter    >");
//      waitForPress();
//      //Increment or decrement "count" based on button press
//      if(nLCDButtons == leftButton)
//      {
//        waitForRelease();
//        count--;
//      }
//      else if(nLCDButtons == rightButton)
//      {
//        waitForRelease();
//        count++;
//      }
//      break;
//    case 3:
//      //Display fourth choice
//      displayLCDCenteredString(0, "LEFT 7");
//      displayLCDCenteredString(1, "<     Enter    >");
//      waitForPress();
//      //Increment or decrement "count" based on button press
//      if(nLCDButtons == leftButton)
//      {
//        waitForRelease();
//        count--;
//      }
//      else if(nLCDButtons == rightButton)
//      {
//        waitForRelease();
//        count = 0;
//      }
//      break;
//    default:
//      count = 0;
//      break;
//    }

















// //Switch Case that actually runs the user choice
//   switch(count){
//   case 0:
//     //If count = 0, run the code correspoinding with choice 1
//     displayLCDCenteredString(0, "RIGHT 22");
//     displayLCDCenteredString(1, "is running!");
//
//     auton22ptRight();
//
//
//   break;
//   case 1:
//     auton7ptRight();
//
//     //If count = 1, run the code correspoinding with choice 2
//     displayLCDCenteredString(0, "RIGHT 7");
//     displayLCDCenteredString(1, "is running!");
//
//
//     break;
//   case 2:
//
//
//     displayLCDCenteredString(0, "LEFT 22");
//     displayLCDCenteredString(1, "is running!");
//
//
//     auton22ptLeft();
//
//
//
//     break;
//   case 3:
//
//   auton7ptLeft();
//
//     displayLCDCenteredString(0, "LEFT 7");
//     displayLCDCenteredString(1, "is running!");
//
//
//
//
//     break;
//     default:
//     displayLCDCenteredString(0, "No valid choice");
//     displayLCDCenteredString(1, "was made!");
//     break;
//   }
