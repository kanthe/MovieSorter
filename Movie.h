/**********************************************************************/
// File:	Movie.h 
// Summary:	Movie class which inherit from BaseMedia and implements its 
//          interface, as well as building other methods specific  for 
//          movies. It provides an interface for the different movie 
//          genre classes.
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/**********************************************************************/
#ifndef MOVIE_H
#define MOVIE_H

#include "BaseMedia.h"
 #include "MyTime.h"
#include <iostream>
using std::strlen;
using std::strcpy;
using std::strcat;

class Movie : BaseMedia {
    public:
        // Implementing interface
        virtual Movie* clone() const = 0;
        virtual void setID(int ID) = 0;
        virtual void setTitle(char* title) = 0;
        virtual void setYear(int year) = 0;
        virtual void setRunTime(MyTime runTime) = 0;
        virtual void setDescription(char* description) = 0;
        virtual void show() = 0;
        virtual int getID() = 0;
        virtual char* getGenre() = 0;
        virtual char* getTitle() = 0;
        virtual int getYear() = 0;
        virtual MyTime getRunTime() = 0;
        virtual char* getDescription() = 0;
        virtual char* getSubgenre() { return ""; }
        // Methods specific for SciFiMovie //////////////////////////////
        virtual void setSciFiPeriod(char* sciFiPeriod) {}
        virtual char* getSciFiPeriod() { return ""; }
        // Methods specific for HistoricMovie ///////////////////////////
        virtual void setHistoricFigure(char* historicFigure) {}
        virtual void setTimePeriod(int timePeriod) {}
        virtual char* getHistoricFigure() { return ""; }
        virtual int getTimePeriod() { return 0; }
        /////////////////////////////////////////////////////////////////
        static char* _genres[10];
    protected:
        int _ID;
        char* _title;
        int _year;
        char* _description;
        char* _genre;
        MyTime _runTime;
        
};

#endif