/**********************************************************************/
// File:	String.h 
// Summary:	Creates string objects capable of adding string with +,
//          creating an identical string with =, a string from a 
//          c-string with =, cin, cout, compare with == and more
// Version: Version 1.0 - 2015-04-26
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-04-26	Created the file. Robin Kanthe
//      2015-05-13  Using dynamic arrays for _strPtr
//                  Removing constant MAX_LENGTH
// ------------------------------------------------
//
//	@properties _strPtr, _strLen, MAX_LENGTH
//
//	@methods    Constructor x3, Destructor, operator= x2, operator+ x3
//              operator<<, operator>>, operator==, toC_str, getLength
//
/**********************************************************************/
#ifndef STRING_H
#define STRING_H

#include <iostream>
using std::ostream;
using std::istream;
using std::strcat;
using std::strcpy;
#include "Compare.h"

class String
{
    // Friend methods
    friend inline ostream& operator<< (ostream& os, const String& s);
    friend inline String operator+ (const char* c, const String s);
    friend inline bool& operator== (const String s, const char* c);
public:
    // Constructors
    String();
    String(const String& s);
    String(const char* c);
    ~String();
    // Operator methods
    String operator= (const String& s);
    String operator= (const char*);
    String operator+ (const String& s) const;
    String operator+ (const char* c) const;
    // Methods
    const char* toC_str(); 
    int getLength();
private:
    // Properties
    char* _strPtr; // The characters of the string
    int _strLen; // Length of string
};

/////////////////////////////////////
//  Inline methods
/////////////////////////////////////
/**
*	Cout operator with <<
*/
inline ostream& operator<< (ostream& os, const String& s) {
    os << s._strPtr;
    return os; // Return output stream
}
/**
*	+ operator for c-string and String object
*/
inline String operator+ (const char* c, const String s) {
    String temp;
    temp._strLen = s._strLen + strlen(c);
    temp._strPtr = new char[temp._strLen + 1];
    strcpy(temp._strPtr, c);
    strcat(temp._strPtr, s._strPtr);

    return temp;
}
/**
*	== operator for c-string and String object
*/
inline bool& operator== (const String s, const char* c) {
    // Compare object will compare the two strings
    Compare* compare = new Compare;
    bool result;
    // Compares them
    result = compare->equal(s._strPtr, c);
    // Removes compare object
    delete compare;
    compare = 0;

    return result;
}

#endif