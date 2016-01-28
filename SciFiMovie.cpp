/**********************************************************************/
// File:    SciFiMovie.cpp
// Summary:	Sci-fi-movie class. Implements the movie interface. 
//          Implements special methods: setSubGenre, setSciFiPeriod.
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -----------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
/**********************************************************************/
#include "SciFiMovie.h"

// Constructor: Initializes the member variables
SciFiMovie::SciFiMovie(int ID, char* title, int year, MyTime runTime, char* description, char* subGenre, char* sciFiPeriod) {
    _genre = "Sci-Fi";
    setID(ID);
    setTitle(title);
    setYear(year);
    setRunTime(runTime);
    setDescription(description);
    setSubgenre(subGenre);
    setSciFiPeriod(sciFiPeriod);
}
// Destructor: Deleting dynamic variables
SciFiMovie::~SciFiMovie() {
    delete _title;
    _title = 0;
    delete _description;
    _description = 0;
    delete _subGenre;
    _subGenre = 0;
    delete _sciFiPeriod;
    _sciFiPeriod = 0;
}
// Writes all info about the movie to console.
void SciFiMovie::show() {
    cout << endl;
    cout << "ID: " << _ID << endl;
    cout << "Title: " << _title << endl;
    cout << "Genre: " << _genre << endl;
    cout << "Release year: " << _year << endl;
    cout << "Total runtime: " << _runTime << endl;
    cout << "Subgenre: " << _subGenre << endl;
    cout << "Time period movie takes place: " << _sciFiPeriod << endl;
    cout << "Description: " << _description << endl;
}

char* SciFiMovie::_subgenres[10] = { "Aliens", "Space", "Robots", "Computers", "Time travel", "Alternate realities", "Post apocalypse", "Empty", "Empty", "Empty" };
char* SciFiMovie::_sciFiPeriods[10] = { "Past", "Present", "Near future", "Far future", "Different times", "Unknown", "Empty", "Empty", "Empty", "Empty" };
