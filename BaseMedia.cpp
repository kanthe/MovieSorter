/**********************************************************************/
// File:    BaseMedia.cpp
// Summary:	Abstract baseclass which serves as interface for creating 
//          media items. 
//          Setting up basic information for media items, including
//          item ID, title, language, description and rating.
// Version: Version 1.0 - 2015-04-14
// Author:	Robin Kanthe
// Email:	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-04-14	Created the file. Robin Kanthe
/**********************************************************************/
#include "BaseMedia.h"
#include <iostream>
#include <iomanip>
#include <limits.h>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::setprecision;
using std::fixed;
using std::setw;

// Default empty constructor
BaseMedia::BaseMedia() {

}

// Default empty destructor
BaseMedia::~BaseMedia() {

}
