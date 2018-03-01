# 1859X-in-the-zone-robotC
the robotC code for 1859X

## Info for devs
when chaining motors the right or bottom motor is always the slave to the reciprocal  
## Autonomas Docs
## Meta
### resetEncoders
```cpp
resetEncoders();
// (void) resets all encoders on the bot
```
---
## Lift
### core
```cpp
core(int amt, bool wait);
// (void) moves the core lift
// amt (int): amount to move; positive to move up, negative to move down
// wait (bool): determines if the action will finish before continuing the program
```
### claw
```cpp
claw(int amt, bool wait);
// (void) moves the claw
// amt (int): number of sec to move; positive to outtake, negative to intake
// wait (bool): determines if the action will finish before continuing the program
```
### claw
```cpp
claw(int amt, bool wait);
// (void) moves the claw
// amt (int): positive to move up, negative to move down
// wait (bool): determines if the action will finish before continuing the program
```
---
## Mobile Base Manipulator
### manipulate
```cpp
manipulate(int dir, bool wait [, int amt]);
// dir (int): positive to move down, negative to move up
// wait (bool): determines if the action will finish before continuing the program
// amt (int): optional determines the amount the manipulator moves
```
## Drive Train
### moveCenter
```cpp
moveCenter(int amt [, int speed, bool wait]);
// amt (int): amount to move, positive to move forward, negative to move backward
// speed (int): optional determines the amount the manipulator moves, if specified pid will not be used
// wait (bool): determines if the action will finish before continuing the program, if specified pid will not be used
```
### turn
```cpp
turn(int amt [, int speed, bool wait]);
// amt (int): amount to turn, positive to move clockwise, negative to move widdershins
// speed (int): optional determines the amount the manipulator moves, if specified pid will not be used
// wait (bool): determines if the action will finish before continuing the program, if specified pid will not be used
```
