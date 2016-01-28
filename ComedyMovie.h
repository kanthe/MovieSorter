/**********************************************************************/
// File:	DramaMovie.h 
// Summary:	
// Version: Version 1.0 - 2015-04-14
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-04-14	Created the file. Robin Kanthe
// ------------------------------------------------
//
//	@properties
//
//	@methods    Constructor, Destructor
//
/**********************************************************************/
#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "Movie.h"
#include "String.h"

class ComedyMovie {
    public:
        ComedyMovie(int ID, char* title, int year, char* description);
        ComedyMovie::~ComedyMovie();
        // Implementing interface
        void setID(int ID) { _ID = ID; }
        void setTitle(char* title) { _title = title; }
        void setYear(int year) { _year = year; }
        // void setRunTime(MyTime runTime) { _runTime = runTime; }
        void setDescription(char* description) { _description = description; }
        char* getGenre() { return _genre; }
        int getID() { return _ID; }
        char* getTitle() { return _title; }
        int getYear() { return _year; }
        char* getDescription() { return _description; }
    private:
        int _ID;
        char* _title;
        char* _description;
        int _year;
        char* _genre;
};

#endif