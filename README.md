# CSC 415 - Project 4 - Thread Racing

## Student Name: Carlos Lopez

## Student ID :  918559153

## Build Instructions
Assuming you have cloned the project, the steps needed would be to go to the project directory and type 'make'. Once done, build has completed.


## Run Instructions
After make has been entered, you will type './threadracer'. This will run the project.

## Explain why your program produces the wrong output
Because we have multiple threads working on the same variable and the time that those threads
are completing is different. Therefore resulting in the variable being thrown around loosely.