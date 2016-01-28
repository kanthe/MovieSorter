/**********************************************************************/
// File:    DramaMovie.cpp
// Summary:	
// Version: Version 1.0 - 2015-04-14
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-04-14	Created the file. Robin Kanthe
/**********************************************************************/
#include "ComedyMovie.h"
#include <iostream>
using std::strcpy;

// Default empty constructor
ComedyMovie::ComedyMovie(int ID, char* title, int year, char* description) {
    _genre = "Comedy";
    setID(ID);
    setTitle(title);
    setYear(year);
    // setRunTime(runTime);
    setDescription(description);
    cout << _genre << endl;
    cout << _ID << endl;
    cout << _title << endl;
    cout << _year << endl;
    // cout << _runTime << endl;
    cout << _description << endl;
}

// Default empty destructor
ComedyMovie::~ComedyMovie() {

}


