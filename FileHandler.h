/**********************************************************************/
// File:	FileHandler.h 
// Summary:	Loading file and saving register list to/from file
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// ------------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/**********************************************************************/
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include "Movie.h"
#include "IOcontrol.h"
#include <list>
using std::list;
#include <fstream>
using std::ifstream;
using std::ofstream;

class FileHandler {
    public:
        FileHandler();
        ~FileHandler();
        list<Movie*> loadRegister(const char* fileName);
        bool saveRegister(list<Movie*> pRegister, const char* fileName);
        bool clearFile(const char* fileName);
        void checkItemInfo(char* itemInfo);
        int convertToInt(char* str);
        MyTime extractRuntime(char* itemInfo);
        char* checkGenre(char* str);
        char* getFromArray(char* itemInfo, char* arrayItems[10]);
    private:
        static const int MAX_INPUT_LENGTH = 1500;
        ifstream _infile;
        ofstream _outfile;
        char* _errorMessage;
        IOcontrol iocontrol;	
        list<Movie*>::iterator _it;		// Iterator for elements in list
};

#endif