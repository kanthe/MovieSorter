/**********************************************************************/
// File:    DramaMovie.cpp
// Summary:	Drama movie class. Implements the movie interface. 
// Version: Version 1.0 - 2015-06-03
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
/**********************************************************************/

#include "DramaMovie.h"

// Constructor: Initializes the member variables
DramaMovie::DramaMovie(int ID, char* title, int year, MyTime runTime, char* description) {
    _genre = "Drama";
    setID(ID);
    setTitle(title);
    setYear(year);
    setRunTime(runTime);
    setDescription(description);
}

// Default empty destructor
DramaMovie::~DramaMovie() {

}
// Writes all info about the movie to console.
void DramaMovie::show() {
    cout << endl;
    cout << "ID: " << _ID << endl;
    cout << "Title: " << _title << endl;
    cout << "Genre: " << _genre << endl;
    cout << "Release year: " << _year << endl;
    cout << "Total runtime: " << _runTime << endl;
    cout << "Description: " << _description << endl;
}