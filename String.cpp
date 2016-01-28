/**********************************************************************/
// File:    String.cpp
// Summary:	Methods for string manipulation and creation
// Version: Version 1.0 - 2015-04-26
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-04-26	Created the file. Robin Kanthe
//      2015-05-13  Using dynamic arrays for _strPtr
/**********************************************************************/
#include "String.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::strcat;
using std::strcpy;
using std::istream;
using std::ostream;
/**
*	Constructors for no, char and string parameters
*/
String::String() {
    _strPtr = new char[1];
    _strPtr = "";
    _strLen = 0;
}

String::String(const String& s) {
    _strLen = s._strLen;
    _strPtr = new char[_strLen + 1];

    strcpy(_strPtr, s._strPtr);
}

String::String(const char* c) {
    _strLen = strlen(c);
    _strPtr = new char[_strLen + 1];
    strcpy(_strPtr, c);
}
/**
*	Deconstructor. Removes _strPtr from memory
*/
String::~String() {
    delete[] _strPtr;
    _strPtr = 0;
}
///////////////////////////////////////////////////////
// OPERATOR FUNCTIONS
// They create a temporary String object and copies(=) or 
// combines(+) input string to it
// Returns the temp String
///////////////////////////////////////////////////////
/**
*	= operator for String objects
*/
String String::operator= (const String& s) {
    delete[] _strPtr;
    _strLen = s._strLen;
    _strPtr = new char[_strLen + 1];
    strcpy(_strPtr, s._strPtr);

    return *this;
}
/**
*	= operator for String and c-string objects
*/
String String::operator= (const char* c) {
    delete[] _strPtr;
    _strLen = strlen(c);
    _strPtr = new char[_strLen + 1];
    strcpy(_strPtr, c);

    return *this;
}
/**
*	+ operator for String objects
*/
String String::operator+ (const String& s) const {
	String temp;	
    temp._strLen = _strLen + s._strLen;		
    temp._strPtr = new char[temp._strLen + 1];	
    strcpy(temp._strPtr, _strPtr);	
    strcat(temp._strPtr, s._strPtr);

    return temp;
}
/**
*	+ operator for String and c-string objects
*/
String String::operator+ (const char* c) const {
    String temp;
    temp._strLen = _strLen + strlen(c);
    temp._strPtr = new char[temp._strLen + 1];
    strcpy(temp._strPtr, _strPtr);
    strcat(temp._strPtr, c);

    return temp;
}
/**
*	Getting length of _strPtr
*/
int String::getLength() {
    return _strLen;
}
/**
*	Tranforming Sting to c-string
*/
const char* String::toC_str() {
    return _strPtr;
}