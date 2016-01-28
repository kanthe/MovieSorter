/**********************************************************************/
// File:    FileHandler.cpp
// Summary:	Loading file and saving register list to/from file
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
/**********************************************************************/
#include "FileHandler.h"
#include "SciFiMovie.h"
#include "HistoricMovie.h"
#include "DramaMovie.h"
#include "MyTime.h"
#include <iostream>
using std::cout;
using std::endl;
using std::strlen;
using std::strtok;
using std::strcpy;
using std::strcat;

// Constructor
FileHandler::FileHandler() {
    _errorMessage = "\nUnspecified error\n";
}

// Default empty destructor
FileHandler::~FileHandler() {

}

// Loads register file and extracts data from it. Puts data in a list
// container and returns this container
list<Movie*> FileHandler::loadRegister(const char* fileName) {
    try {
        int i = 0;
        char itemInfo[100]; // string to extract the info to
        char row[MAX_INPUT_LENGTH]; // string to put rows when reading text file.
        _infile.open(fileName); // Opens file
        list<Movie*> pRegister; // list container with Movie object pointers
        Movie* movie; // Movie object pointer create to put in the list container.
        // Creating empty SciFiMovie and HistoricMovie objects which are used 
        // to get the string arrays _genres, _subgenres and _sciFiPeriods.
        MyTime genericTime(0, 0);
        SciFiMovie genericSciFiMovie(0, "", 0, genericTime, "", "", "");
        HistoricMovie genericHistoricMovie(0, "", 0, genericTime, "", "", "", 0);
        // If file cannot be red
        if (!_infile.is_open()) {
            throw "\nError occured when reading file\n";
        }
        // Reads file linewise
        while (_infile.getline(row, MAX_INPUT_LENGTH)) {
            // Retuns list if empty row is reached (at end of file).
            if (strcmp(row, "") == 0) { 
                _infile.close();
                return pRegister; 
            }
            // ID ----------------------------------------------------------------
            // Extracts ID and puts in an int variable
            strcpy(itemInfo, strtok(row, "¤"));
            int ID = convertToInt(itemInfo);
            // Checking that ID is a number between 1 - 10000
            if (ID < 1 || ID > 10000) {
                _errorMessage = "\nID is not between 1 - 10000. \n";
                throw _errorMessage;
            }
            // Genre --------------------------------------------------------------
            // Extracts genre and puts in a char* variable.
            // Does this by using the _genres array in a SciFiMovie object
            // and compares its strings with the itemInfo string
            strcpy(itemInfo, strtok(NULL, "¤"));
            char genre[21];
            strcpy(genre, getFromArray(itemInfo, genericSciFiMovie._genres));

            // Title ----------------------------------------------------------------
            // Extracts title and puts in a char* variable
            strcpy(itemInfo, strtok(NULL, "¤"));
            checkItemInfo(itemInfo);
            char title[100];
            strcpy(title, itemInfo);
            // Year -----------------------------------------------------------------
            // Extracts year and puts in an int variable
            strcpy(itemInfo, strtok(NULL, "¤"));
            int year = convertToInt(itemInfo);
            // Checking that year is a number between 1800 - 2100
            if (year < 1800 || year > 2100) {
                _errorMessage = "\nThe release year is not between 1800 - 2100. \n";
                throw _errorMessage;
            }
            // Runtime ---------------------------------------------------------------
            // Extracts runtime and puts in an MyTime object using method extractRunTime
            strcpy(itemInfo, strtok(NULL, "¤"));
            MyTime runTime = extractRuntime(itemInfo);

            // Description -----------------------------------------------------------
            // Extracts description and puts in an char* variable
            char description[1001];
            strcpy(description, strtok(NULL, "¤"));
            checkItemInfo(itemInfo);
            //
            // Special info for the different genres ---------------------------------
            //
            char subgenre[21] = "";
            char sciFiTimePeriod[21] = "";
            char historicPerson[100] = "";

            // Sci-Fi ----------------------------------------------------------------
            if (strcmp(genre, "Sci-Fi") == 0) {
                // Subgenre 
                // Extracts subgenre and puts in a char* variable.
                // Does this by using the _subgenres array in a SciFiMovie object
                // and compares its strings with the itemInfo string
                strcpy(itemInfo, strtok(NULL, "¤"));
                strcpy(subgenre, getFromArray(itemInfo, genericSciFiMovie._subgenres));
                // Sci-Fi timeperiod 
                // Extracts time period with the _sciFiPeriods array.
                strcpy(itemInfo, strtok(NULL, "¤"));
                strcpy(sciFiTimePeriod, getFromArray(itemInfo, genericSciFiMovie._sciFiPeriods));
                // Uses the data to create a SciFiMovie object
                movie = new SciFiMovie(ID, title, year, runTime, description,
                    subgenre, sciFiTimePeriod);
            }
            // Historic --------------------------------------------------------------
            else if (strcmp(genre, "Historic") == 0) {
                // Subgenre 
                // Extracts subgenre and puts in a char* variable.
                // Does this by using the _subgenres array in a HistoricMovie object
                // and compares its strings with the itemInfo string
                strcpy(itemInfo, strtok(NULL, "¤"));
                strcpy(subgenre, getFromArray(itemInfo, genericHistoricMovie._subgenres));
                // Historic person or event 
                strcpy(itemInfo, strtok(NULL, "¤"));
                checkItemInfo(itemInfo);
                strcpy(historicPerson, itemInfo);
                // Historic time period
                strcpy(itemInfo, strtok(NULL, "¤"));
                int historicTime = convertToInt(itemInfo);
                // Checks historicTime if it is between -9999 - 2015.
                if (historicTime < -9999 || historicTime > 2015) {
                    _errorMessage = "\nTime period is not between -10000 - 2015. \n";
                    throw _errorMessage;
                }
                // Uses the data to create a HistoricMovie object
                movie = new HistoricMovie(ID, title, year, runTime, description,
                    subgenre, historicPerson, historicTime);
            }
            // Drama ------------------------------------------------------------------
            // Drama has no specific info. A DramaMovie object is created if
            // genre is Drama.
            else if (strcmp(genre, "Drama") == 0) {
                movie = new DramaMovie(ID, title, year, runTime, description);
            }
            // A SciFiMovie, HistoricMovie or DramaMovie object has been created.
            // It is put in the list container as last item. 
            pRegister.push_back(movie);
        }
        _infile.close(); // File is closed.
        return pRegister; // list container is returned.
    }
    catch (char* error) {
        throw error;
    }
    catch (...) {
        throw 0;
    }
}

// Saves list items to file
bool FileHandler::saveRegister(list<Movie*> pMediaRegister, const char* fileName) {

    try {
        if (pMediaRegister.empty()) {
            _errorMessage = "Cannot save. List is empty!";
            throw _errorMessage;
            return false;
        }
        _outfile.open(fileName);
        // If file cannot be red
        if (!_outfile.is_open()) {
            throw "Error occured when reading file";
            return false;
        }
        int i = 0;
        MyTime runTime;
        char* genre;
        // Stepping through all list items. Extracts data from them.
        // Putting data in the register file according to format specification
        // (one row for one item and one ¤ between every data member
        for (_it = pMediaRegister.begin(); _it != pMediaRegister.end(); _it++) {

            _outfile << (*_it)->getID() << "¤";
            genre = (*_it)->getGenre();
            _outfile << genre << "¤";
            _outfile << (*_it)->getTitle() << "¤";
            _outfile << (*_it)->getYear() << "¤";
            runTime = (*_it)->getRunTime();
            _outfile << runTime.getHours() << "," << runTime.getMinutes() << "¤";
            _outfile << (*_it)->getDescription() << "¤";
            // Specific data for genres
            if (strcmp(genre, "Sci-Fi") == 0) {
                _outfile << (*_it)->getSubgenre() << "¤";
                _outfile << (*_it)->getSciFiPeriod() << "¤";
            }
            else if (strcmp(genre, "Historic") == 0) {
                _outfile << (*_it)->getSubgenre() << "¤";
                _outfile << (*_it)->getHistoricFigure() << "¤";
                _outfile << (*_it)->getTimePeriod() << "¤";
            }
            _outfile << endl;
        }
    }
    catch (char* error) {
        throw error;
    }
    catch (...) {
        throw 0;
    }
    _outfile.close();
    return true;
}

// Clears all text from file
bool FileHandler::clearFile(const char* fileName) {
    _outfile.open(fileName);
    // If file cannot be red
    if (!_outfile.is_open()) {
        throw "Error occured when reading file";
        return false;
    }
    _outfile << "";
    _outfile.close();
}

// Checks if a string is empty.
void FileHandler::checkItemInfo(char* itemInfo) {
    if (itemInfo == NULL) {
        _errorMessage = "\nError: Data could not be extracted.\n";
        throw _errorMessage;
    }
}

// Checking string and converts it to int
int FileHandler::convertToInt(char* str) {
    // Checking if str is valid, numeric and has not more than 5 characters
    if (str == NULL || strlen(str) > 5 || !iocontrol.checkNewInput(str) || !iocontrol.checkNumeric(str, "int")) {
        _errorMessage = "\nThe item is invalid. \n";
        throw _errorMessage;
    }
    return atoi(str);
}

// Extracts runtime from string with format h(h),m(m) and puts in a MyTime object
// First checks the string,
// then extracts the first 1 or 2 characters (hours),
// then extracts the last 1 or 2 characters (minutes)
// then puts hours and minutes into a MyTime object and returns it.
MyTime FileHandler::extractRuntime(char* itemInfo) {
    // Checking if runtime is valid, numeric and has not more than 5 characters (it should be in the form h(h),m(m) )
    if (itemInfo == NULL || strlen(itemInfo) > 5 || !iocontrol.checkNewInput(itemInfo)) {
        _errorMessage = "\nThe runtime is invalid. \n";
        throw _errorMessage;
    }
    // Extracting hours (should be before ',' in the string)
    char chours[3];
    char* itemInfoPtr; // Pointer to extracted string
    itemInfoPtr = itemInfo;
    int i = 0;
    // Stepping through time string with pointer until ',' is reached
    // Using values pointed to, to construct the chours string
    while (*itemInfoPtr != ',') {
        chours[i] = *itemInfoPtr;
        i++;
        itemInfoPtr++;
        // Hours should not have more than 2 characters
        if (i == 3) {
            _errorMessage = "\nThe runtime hours have too many characters. \n";
            throw _errorMessage;
        }
    }
    chours[i] = '\0';
    itemInfoPtr++; // Stepping to first character of the minutes
    int hours = convertToInt(chours); // Hours are converted to int values

    if (hours < 0) {
        _errorMessage = "\nThe runtime hours are negative. \n";
        throw _errorMessage;
    }
    char cmin[3];
    i = 0;
    // Stepping through remaining time string with pointer.
    // Using values pointed to, to construct the cmin string
    while (*itemInfoPtr != '\0') {
        cmin[i] = *itemInfoPtr;
        i++;
        itemInfoPtr++;

        if (i == 3) {
            _errorMessage = "\nThe runtime minutes are invalid. \n";
            throw _errorMessage;
        }
    }
    cmin[i] = '\0';
    int min = convertToInt(cmin); // Minutes are converted to int values

    if (min < 0 || min > 59) {
        _errorMessage = "\nThe runtime minutes are not between 0 - 59. \n";
        throw _errorMessage;
    }
    // Constructing and returning a MyTime object from the hours and min numbers.
    MyTime runTime(hours, min);

    return runTime;
}

// Input: A string and an array of strings.
// Method determines if the string is located in the string array.
// Then it returns a copy of the string.
char* FileHandler::getFromArray(char* str, char* arrayItems[10]) {
    char returnStr[21];
    bool validStr = false;
    int i;

    for (i = 0; i < 10; i++) {
        if (strcmp(str, arrayItems[i]) == 0) {
            validStr = true;
            strcpy(returnStr, str);
            break;
        }
    }
    if (!validStr) {
        _errorMessage = "\nNo string in the array matches.\n";
        throw _errorMessage;
    }

    return returnStr;
}

