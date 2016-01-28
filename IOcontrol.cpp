/**********************************************************************/
// File:    IOcontrol.cpp
// Summary:	Receives keyboard input and checks if it is valid, before
//          returning it. Can validate char*, char, int and double
// Version: Version 1.1 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
/**********************************************************************/
#include "IOcontrol.h"
#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;
using std::cin;
using std::flush;
using std::strcpy;
using std::strlen;
using std::strcpy;

// Default constructor
IOcontrol::IOcontrol() { }
// Default destructor
IOcontrol::~IOcontrol() { }
/**
*	Returning 'true' if input is not empty or contains errors.
*
*	@param  char*
*
*	@return bool
*/
bool IOcontrol::checkNewInput(char* input) {
    
    if (input == "" || !cin.good()) {
        return false;
    }
    else {
        return true;
    }
}
/**
*	Checking if input is numeric. Parameter type decides if it is an
*   int or a double. Returns 'true' if it is numeric.
*
*	@param  char*
*
*	@return bool
*/
bool IOcontrol::checkNumeric(char* input, char* type) {
    char* inputPtr = input;

    while (*inputPtr != '\0') {

        if (!(*inputPtr == '-' || *inputPtr == '0' || *inputPtr == '1' || *inputPtr == '2' || *inputPtr == '3' || *inputPtr == '4'
            || *inputPtr == '5' || *inputPtr == '6' || *inputPtr == '7' || *inputPtr == '8' || *inputPtr == '9'
            || ((strcmp(type, "double") == 0) && (*inputPtr == '.')))) { // also checking for '.' characters if type is set to double.
            return false;
        }
        inputPtr++;
    }
    return true; // 'True' is returned if only integers are found in the char string.
}
/**
*	Displays message and removes residual characters.
*   Used to stop program execution until user presses a key.
*
*	@param  char*
*
*	@return bool
*/
void IOcontrol::pressEnterToContinue(const char* message) {
    cout << endl << message << flush;
    cin.ignore(INT_MAX, '\n');
}
/**
*	Calling "checkNewInput", which takes keyboard input, and returning
*   it if "checkNewInput" returns 'true'. Otherwise displays error message
*   and calling the function again.
*
*	@param  char*
*
*	@return bool
*/
char* IOcontrol::getLineInput(const char* errorMessage) {
    char input[MAX_INPUT_LENG];
    bool correctInput = false;
    int i = 0;

    while (true) {
        cin.getline(input, MAX_INPUT_LENG);

        if (checkNewInput(input)) {
            break;
        }
        cout << errorMessage;
    }
    char output[MAX_INPUT_LENG];
    strcpy(output, input);

    return output;
}
/**
*	Calling "checkNewInput()" and "getIntInput('int')", which takes keyboard input, and returning
*   it as int type if both returns 'true'. Otherwise displays error message
*   and calling the functions again.
*
*	@param  char*
*
*	@return bool
*/
int IOcontrol::getIntInput(const char* errorMessage) {
    int output = 0;
    char input[11];
    
    while (true) {
        cin.getline(input, 10);

        if (checkNewInput(input)) {

            if (checkNumeric(input, "int")) {
                break;
            }
        }
        cout << errorMessage << endl;
    }
    output = atoi(input);

    return output;
}
/**
*	Calling "checkNewInput()" and "getIntInput('double')", which takes keyboard input, and returning
*   it as a double type if both returns 'true'. Otherwise displays error message
*   and calling the functions again.
*
*	@param  char*
*
*	@return bool
*/
double IOcontrol::getDoubleInput(const char* errorMessage) {
    double output = 0;
    char input[16];

    while (true) {
        cin.getline(input, 15);

        if (checkNewInput(input)) {

            if (checkNumeric(input, "double")) {
                cout << errorMessage << endl;
                break;
            }
        }
    }
    output = atof(input);

    return output;
}
/**
*	Using getChar to get a character from keyboard. Returning it if
*   it is not empty or contains errors. Otherwise displays error message
*   and takes keyboard input again.
*
*	@param  char*
*
*	@return bool
*/
char IOcontrol::getCharInput(const char* errorMessage) {
    char output;
    cin.get(output); // Reading input
    cin.clear();
    
    return output;
}
/**
*	Using getCharInput and checking if the char is 'y' or 'n'
*
*	@param  char*
*
*	@return char
*/
char IOcontrol::getCharInputYorN(const char* errorMessage) {
    char output;
    char* errMessage = "Y/N Invalid input!";

    while (true) {
        cin.get(output);
        cin.clear();
        // Breaks while loop only if input is 'y' or 'n' 
        if (output == 'y' || output == 'n') {
            break;
        }
        else {
            cout << errorMessage;
        }
    }
    return output;
}
/*
 *  Used in menus to get menu choices.
 *  Takes user input returns it if it is between 1 and 
 *  numberOfChoices (highest menu choice).
 */
int IOcontrol::getChoice(int numberOfChoices, const char* errorMessage) {
    int choice;

    while (true) {
        choice = getIntInput(errorMessage);

        if (choice < 1 || choice > numberOfChoices) {
            cout << "Input must be between 1 and " << numberOfChoices << ". Please try again: " << endl;
        }
        else {
            break;
        }
    }
    return choice;
}