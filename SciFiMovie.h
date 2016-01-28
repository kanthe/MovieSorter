/**********************************************************************/
// File:	SciFiMovie.h 
// Summary:	Sci-fi-movie class. Implements the movie interface. 
//          Implements special methods: setSubGenre, setSciFiPeriod.
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/**********************************************************************/
#ifndef SCIFIMOVIE_H
#define SCIFIMOVIE_H

#include "Movie.h"

class SciFiMovie : public Movie {
    public:
        SciFiMovie(int ID, char* title, int year, MyTime runTime, char* description, 
            char* subGenre, char* sciFiPeriod);
        ~SciFiMovie();
        Movie* clone() const { return new SciFiMovie(*this); }
        // Implementing interface ///////////////////////////////////////
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
        void setSubgenre(char* subgenre) {
            _subGenre = new char[strlen(subgenre) + 1];
            strcpy(_subGenre, subgenre);
        }
        /////////////////////////////////////////////////////////////////
        int getID() { return _ID; }
        char* getGenre() { return _genre; }
        char* getTitle() { return _title; }
        int getYear() { return _year; }
        MyTime getRunTime() { return _runTime; }
        char* getDescription() { return _description; }
        // Methods specific for SciFiMovie //////////////////////////////
        void setSciFiPeriod(char* sciFiPeriod) {
            _sciFiPeriod = new char[strlen(sciFiPeriod) + 1];
            strcpy(_sciFiPeriod, sciFiPeriod);
        }
        char* getSubgenre() { return _subGenre; }
        char* getSciFiPeriod() { return _sciFiPeriod; }
        /////////////////////////////////////////////////////////////////
        void show();
        static char* _subgenres[10];
        static char* _sciFiPeriods[10];
    private:
        char* _subGenre;
        char* _sciFiPeriod;
        
};

#endif