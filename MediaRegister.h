/**********************************************************************/
// File:	MediaRegister.h 
// Summary:	Handles media register file, including loading file and 
//          saving to file
//          Puts items from register file in list
//          Adding, removing, searching, showing, sorting items in list
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/**********************************************************************/
#ifndef MEDIAREGISTER_H
#define MEDIAREGISTER_H

#include "UI.h"
#include "FileHandler.h"
#include "Movie.h"
#include <list>

class MediaRegister {
    public:
        MediaRegister();
        ~MediaRegister();
        bool addMedia();
        bool removeMedia();
        bool findMedia();
        bool showMedia(Movie* movie);
        bool sortMedia(int sortKey = 0);
        void switchPositions(Movie* temp);
        bool emptyReg();
        bool saveReg();
        bool loadReg();
        list<Movie*>getList() { return _pMediaRegister; }
    private:
        UI ui;                          // Handles all output and input 
        FileHandler fileHandler;        // Loads and saves files
        const char* _fileName;          // Name of the register file
        int _count;                     // Number of media items
        static const int MAX_ITEMS = 10000;    // Maximum number of media items
        static const int MAX_LENGTH = 100;     // Standard max length of strings
        list<Movie*>_pMediaRegister;	// Contains all media items
        list<Movie*>_pTempRegister;     // Used to store newly added media items until 
                                        // all items are saved to the register file
        list<Movie*>::iterator _it;		// Iterator for elements in list
        list<Movie*>::iterator _it2;	// Iterator used in sort algorthm
};

#endif


