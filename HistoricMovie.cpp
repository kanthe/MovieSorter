/**********************************************************************/
// File:    HistoricMovie.cpp
// Summary:	Historic movie class. Implements the movie interface. 
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
/**********************************************************************/
#include "HistoricMovie.h"

// Constructor: Initializes the member variables
HistoricMovie::HistoricMovie(int ID, char* title, int year, MyTime runTime, char* description, char* subgenre, char* historicFigure, int timePeriod) {
    _genre = "Historic";
    setID(ID);
    setTitle(title);
    setYear(year);
    setRunTime(runTime);
    setDescription(description);
    setSubgenre(subgenre);
    setTimePeriod(timePeriod);
    setHistoricFigure(historicFigure);
}

// Destructor: Deleting dynamic variables
HistoricMovie::~HistoricMovie() {
    delete _title;
    _title = 0;
    delete _description;
    _description = 0;
    delete _subGenre;
    _subGenre = 0;
    delete _historicFigure;
    _historicFigure = 0;
}
// Writes all info about the movie to console.
void HistoricMovie::show() {
    cout << endl;
    cout << "ID: " << _ID << endl;
    cout << "Title: " << _title << endl;
    cout << "Genre: " << _genre << endl;
    cout << "Release year: " << _year << endl;
    cout << "Total runtime: " << _runTime << endl;
    cout << "Subgenre: " << _subGenre << endl;
    cout << "Historic figure: " << _historicFigure << endl;
    cout << "Time period movie takes place: " << _timePeriod << endl;
    cout << "Description: " << _description << endl;
}

char* HistoricMovie::_subgenres[10] = { "War", "Biography", "Adventure", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty" };