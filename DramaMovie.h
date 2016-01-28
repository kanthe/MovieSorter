/**********************************************************************/
// File:	DramaMovie.h 
// Summary:	Drama movie class. Implements the movie interface. 
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// ------------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/**********************************************************************/
#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "Movie.h"

class DramaMovie : public Movie {
    public:
        DramaMovie(int ID, char* title, int year, MyTime runTime, char* description);
        ~DramaMovie();
        Movie* clone() const { return new DramaMovie(*this); }
        // Implementing interface
        void setID(int ID) { _ID = ID; }
        void setTitle(char* title) {
            _title = new char[strlen(title) + 1];
            strcpy(_title, title);
        }
        void setYear(int year) { _year = year; }
        void setRunTime(MyTime runTime) { _runTime = runTime; }
        void setDescription(char* description) {
            _description = new char[strlen(description) + 1];
            strcpy(_description, description);
        }
        
        int getID() { return _ID; }
        char* getGenre() { return _genre; }
        char* getTitle() { return _title; }
        int getYear() { return _year; }
        MyTime getRunTime() { return _runTime; }
        char* getDescription() { return _description; }

        void show();
};

#endif