/**********************************************************************/
// File:	BaseMedia.h 
// Summary:	Abstract base class. Interface for all media types.
//          Interface: Methods for handling basic information:
//          ID, title, release year, description
//          Also: show method, which shows all info about a ceartain movie.
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email:	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/**********************************************************************/
#ifndef BASEMEDIA_H
#define BASEMEDIA_H

class BaseMedia {
    public:
        // Implementing interface
        virtual void setID(int ID) = 0;
        virtual void setTitle(char* title) = 0;
        virtual void setYear(int year) = 0;
        virtual void setDescription(char* description) = 0;
        virtual void show() = 0;
        virtual int getID() = 0;
        virtual char* getTitle() = 0;
        virtual int getYear() = 0;
        virtual char* getDescription() = 0;
};

#endif