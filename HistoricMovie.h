/**********************************************************************/
// File:	HistoricMovie.h 
// Summary:	Historic movie class. Implements the movie interface. 
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// ------------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/**********************************************************************/
#ifndef HISTORICMOVIE_H
#define HISTORICMOVIE_H

#include "Movie.h"

class HistoricMovie : public Movie {
    public:
        HistoricMovie(int ID, char* title, int year, MyTime runTime, char* description, 
            char* subgenre, char* historicFigure, int timePeriod);
        ~HistoricMovie();
        Movie* clone() const { return new HistoricMovie(*this); }
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
        // Methods specific for HistoricMovie ///////////////////////////
        void setHistoricFigure(char* historicFigure) {
            _historicFigure = new char[strlen(historicFigure) + 1];
            strcpy(_historicFigure, historicFigure);
        }
        void setTimePeriod(int timePeriod) { _timePeriod = timePeriod; }
        char* getSubgenre() { return _subGenre; }
        char* getHistoricFigure() { return _historicFigure; }
        int getTimePeriod() { return _timePeriod; }
        /////////////////////////////////////////////////////////////////
        static char* _subgenres[10];
        void show();
    private:
        char* _subGenre;
        char* _historicFigure;
        int _timePeriod;
        
};

#endif