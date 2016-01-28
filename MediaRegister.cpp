/**********************************************************************/
// File:    MediaRegister.cpp
// Summary:	Handles media register file, including loading file and 
//          saving to file
//          Puts items from register file in list
//          Adding, removing, searching, showing, sorting items in list
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
/**********************************************************************/
#include "MediaRegister.h"
#include "FileHandler.h"
#include "MyTime.h"
#include "SciFiMovie.h"
#include "HistoricMovie.h"
#include "DramaMovie.h"
#include <iostream>
using std::cout;
using std::endl;
#include <list>

// Constructor: Loads register file and presents main menu.
// Enebles user to start the methods connected to the main menu.
MediaRegister::MediaRegister() : _fileName("MediaRegister.txt") {
    try {
        
        ui.appDescription(); // Displays description
        bool exitApp = false;
        fileHandler.clearFile("tempRegister.txt");

        cout << "Load movie register";
        ui.pressEnter();
        // Loads register. Regster data are put in the list container, _pMediaRegister
        if (!loadReg()) { throw "Error occured when loading file."; }
        
        // Do until exitApp = true, that is, when user chooses alternative 8 or 9: Exit
        while (exitApp == false) {
            int choice = ui.mainMenu();

            switch (choice) {
            case 1: // Add
                if (!addMedia()) { cout << "Maximum number of items is reached."; }
                break;
            case 2: // Remove
                if (!removeMedia()) { cout << "Error occured when removing item."; }
                break;
            case 3: // Search
                findMedia();
                break;
            case 4: // Show
                // Goes through all members in list container _pMediaRegister
                // Uses method showMedia to display their content
                if (!_pMediaRegister.empty()) {
                    for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++) {
                        if (!showMedia(*_it)) { throw "Error occured when showing item."; }
                    }
                }
                else {
                    cout << "No items to show." << endl << endl;
                }
                break;
            case 5: // Sort
                if (!sortMedia()) { cout << "Error occured when sorting register."; }
                break;
            case 6: // Save
                if (!saveReg()) { cout << "Error occured when saving register."; }
                break;
            case 7: // Empty (delete file content)
                if (!emptyReg()) { throw "Error occured when deleting register."; }
                break;
            case 8: // Save and exit
                cout << "Exiting program and saving register to file." << endl;
                cout << "Do you wish to continue?" << endl << endl;

                if (!ui.pressYorN()) { break; } // User is able to go back to menu

                if (!saveReg()) { throw "Error occured when saving register."; }
                exitApp = true;
                break;
            case 9: // Exit without saving
                cout << "Exiting program without saving register to file." << endl;
                cout << "Do you wish to continue and not save your data?" << endl << endl;
                if (!ui.pressYorN()) { break; }
                exitApp = true;
                break;
            default:
                throw "Error occured when chosing from menu.";
            }
            // After option has been chosen, when user presses ENTER,
            // display is cleared and new menu is displayed
            ui.pressEnter();
            system("cls");
        }
    }
    catch (char* error) {
        throw error;
    }
    catch (...) {
        throw 0;
    }
}
// Destructor: Removes the members of the list container
MediaRegister::~MediaRegister() {

    for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++)
    {
        delete (*_it);
        *_it = 0;
    }
}
// Adds an item to _pMediaRegister. 
// The items are objects of classes SciFiMovie, HistoricMovie etc,
// which implements the interface of base class Movie.
// Items in _pMediaRegister are pointers to this base class.
bool MediaRegister::addMedia() {
    // Goes back to menu if maximum number of items, is reached.
    if (_count + 1 > MAX_ITEMS) {
        return false;
    }
    // Initalizing members of _pMediaRegister items,
    // using methods in UI
    int ID = _count + 1; // ID: next number after the previous item was added
    char title[MAX_LENGTH] = "";

    while (strcmp(title, "") == 0) {
        strcpy(title, ui.askTitle());
    }
    int year;

    while (!(year = ui.askYear())) {}
    MyTime runTime(0, 0);

    while (runTime.getHours() == 0 && runTime.getMinutes() == 0) {
       runTime = ui.askRunTime();
    }
    int genreNumber = ui.askGenre();
    char description[1000] = "";

    while (strcmp(description, "") == 0) {
        strcpy(description, ui.askDescription());
    }
    Movie* movie; // The Movie item which will be put in _pMediaRegister
    // Initializing members specific to each genre and creating item.
    if (genreNumber == 1) { // 1: Sci-Fi movie
        char sciFiSubGenre[MAX_LENGTH];
        strcpy(sciFiSubGenre, ui.askSciFiSubGenre());
        char sciFiPeriod[MAX_LENGTH];
        strcpy(sciFiPeriod, ui.askSciFiPeriod());
        // Creating SciFiMovie item
        if (ui.askToAdd()) {
            movie = new SciFiMovie(ID, title, year, runTime, description,
                sciFiSubGenre, sciFiPeriod);
        }
        else {
            return true;
        }
    }
    else if (genreNumber == 2) { // 2: Historic movie
        char subGenre[MAX_LENGTH];
        strcpy(subGenre, ui.askHistoricSubGenre());
        char historicFigure[MAX_LENGTH] = "";

        while (strcmp(historicFigure, "") == 0) {
            strcpy(historicFigure, ui.askHistoricFigure());
        }
        int historicTime;

        while (!(historicTime = ui.askTimePeriod())) {}
        // Creating HistoricMovie item
        if (ui.askToAdd()) {
            movie = new HistoricMovie(ID, title, year, runTime, description,
                subGenre, historicFigure, historicTime);
        }
        else {
            return true;
        }
    }
    else if (genreNumber == 3) { // 3. Drama movie
        // Creating DramaMovie item
        if (ui.askToAdd()) {
            movie = new DramaMovie(ID, title, year, runTime, description);
        }
        else {
            return true;
        }
    }
    _pMediaRegister.push_back(movie); //Putting items in list
    _count++; // Increases counter which will be used for the ID of the next item.
    // Using a temporary file to store newly added items.
    // At end of session (when user exits application) the contents of this file will be removed and 
    // data will be put in the permanent file "MediaRegister.txt"
    _pTempRegister = fileHandler.loadRegister("tempRegister.txt");
    _pTempRegister.push_back(movie);
    fileHandler.saveRegister(_pTempRegister, "tempRegister.txt");
    cout << "A new movie with ID: " << ID << " and title: " << title
        << "has been added." << endl << endl;
    return true;
}
// Removes a _pMediaRegister item with ID specified by user.
bool MediaRegister::removeMedia() {
    ui.removeMediaText();
    cout << "Type 0 to return." << endl;
    int ID = ui.askID();

    if (ID == 0) {
        return true;
    }
    for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++)
    {
        if ((*_it)->getID() == ID) {
            _it = _pMediaRegister.erase(_it);
            cout << "Item with ID " << ID << " has successfully been removed!" << endl << endl;
            return true;
        }
    }
    cout << "No item with that ID" << endl << endl;
    return false;
}
// Method for searching for items, using certain keywords
bool MediaRegister::findMedia() {
    bool success = false; // Indicates that one or more item has been found
    int searchKey = ui.sortMediaMenu(); // Uses method in UI to enable user to enter search keyword
    char genre[MAX_LENGTH] = "";
    // Performs different actions depending on which search key user has entered 
    switch (searchKey) {
    case 1: // ID: Searches items by ID
        int ID;
        int findID;
        findID = ui.askID(); // ID entered by user

        for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++)
        {
            ID = (*_it)->getID(); // ID of current item

            if (ID == findID) { // If ID of current item matches ID entered by user:
                showMedia(*_it); // Shows the content of this item
                return true; // Goes back to menu
            }
        }
        cout << "Did not find any movie with that ID." << endl;
        return false;
    case 2: // Title: Searches items by title. Same method as with ID above is used
        char title[MAX_LENGTH];
        char findTitle[MAX_LENGTH];
        strcpy(findTitle, ui.askTitle());

        for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++)
        {
            strcpy(title, (*_it)->getTitle());

            if (strcmp(title, findTitle) == 0) {
                showMedia(*_it);
                return true;
            }
        }
        cout << "Did not find any movie with that title." << endl;
        return false;
    case 3: // Genre: Searches items by genre
        int findGenreNumber;
        char findGenre[MAX_LENGTH]; // Genre user is searching for
        findGenreNumber = ui.askGenre(); // User chooses a genre number from a list
        // findGenre is set to the genre corresponding to the chosen genre number
        strcpy(findGenre, ui.genreNumberToGenre(findGenreNumber)); 
        success = false;

        for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++)
        {
            strcpy(genre, (*_it)->getGenre());
            // Displays the content of the items which has the particular genre
            // Can display more than one item. success = true indicates that an item has been found
            if (strcmp(genre, findGenre) == 0) {
                success = true;
                showMedia(*_it);
            }
        }
        // Returns true if an item with searched genre has been found. Else false.
        if (!success) {
            cout << "Did not find find any movie with that genre." << endl;
            return false;
        }
        else {
            return true;
        }
    case 4: // Year: Searches items by release year
        int year;
        int findYear;
        findYear = ui.askYear();
        success = false;

        for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++)
        {
            year = (*_it)->getYear();

            if (year == findYear) {
                success = true;
                showMedia(*_it);
            }
        }
        // Returns true if an item with searched genre has been found. Else false.
        if (!success) {
            cout << "Did not find find any movie with that genre." << endl;
            return false;
        }
        else {
            return true;
        }
    default: // If app impletation is incorrect, resulting in that user is able to 
             //enter a nonexisting search key number 
        cout << "Invalid search key";
        return false;
    }
}
// Shows all data of an item
bool MediaRegister::showMedia(Movie* movie) {
    movie->show();
    
    return true;
}
// Sorting items in different ways
bool MediaRegister::sortMedia(int sortKey) { 
    Movie* temp = 0; // Used to temporary store items in sort algorithm
    int sortOrder = 1;
    // Default value of sortKey is 0, which means the user chooses key for sorting
    // Setting sortkey to 1 on function call is used to automatically sort by ID before saving register
    if (sortKey == 0) {
        sortKey = ui.sortMediaMenu(); // Displays menu and user can choose sort key
        sortOrder = ui.sortingOrder(); // Displaying menu and user can specify if sorting is done in 
                                       // ascending of descending order
    }
    // Sorting algorithm:
    // Steps through all items and compares it to  all preceding items
    for (_it = _pMediaRegister.begin(); _it != prev(_pMediaRegister.end()); _it++) {

        for (_it2 = next(_it); _it2 != _pMediaRegister.end(); _it2++) {
            // Implementing for the search key user specified:
            // Compares key values of two items and switches positions in list container
            // if first value is higher or lower than the second, depending on which
            // value of sorting order was chosen
            switch (sortKey) {
            case 1: // ID
                if ((*_it)->getID() > (*_it2)->getID() && sortOrder == 1) {
                    switchPositions(temp);
                }
                else if ((*_it)->getID() < (*_it2)->getID() && sortOrder == 2) {
                    switchPositions(temp); // Function to switch positions of items
                }
                break;
            case 2: // Title
                
                if (strcmp((*_it)->getTitle(), (*_it2)->getTitle()) > 0 && sortOrder == 1) {
                    switchPositions(temp);
                }
                else if (strcmp((*_it)->getTitle(), (*_it2)->getTitle()) < 0 && sortOrder == 2) {
                    switchPositions(temp);
                }
                break;
            case 3: // Genre
                if (strcmp((*_it)->getGenre(), (*_it2)->getGenre()) > 0 && sortOrder == 1) {
                    switchPositions(temp);
                }
                else if (strcmp((*_it)->getGenre(), (*_it2)->getGenre()) < 0 && sortOrder == 2) {
                    switchPositions(temp);
                }
                break;
            case 4: // Year
                if ((*_it)->getYear() > (*_it2)->getYear() && sortOrder == 1) {
                    switchPositions(temp);
                }
                else if ((*_it)->getYear() < (*_it2)->getYear() && sortOrder == 2) {
                    switchPositions(temp);
                }
                break;
            }
        }
    }
    delete[] temp; // Removing temporary item from memory

    if (!_pMediaRegister.empty()) {
        cout << "Register has been succesfully sorted. " << endl;
        cout << "Choose 4. Search for movie or 5. Show all movies, to view them." << endl << endl;
        return true;
    }
    else {
        return false;
    }
}
// Method to switch positions of items, used in soring algorthm
// temp is used to store first item temporarily
void MediaRegister::switchPositions(Movie* temp) {
    temp = (*_it)->clone();
    *_it = (*_it2)->clone();
    *_it2 = temp->clone();
}
// Removes all data from register file
bool MediaRegister::emptyReg() {
    ui.emptyRegisterText(); // Displays info
    // User is asked to confirm
    if (!ui.pressYorN()) {
        return true;
    }   
    _pMediaRegister.clear(); // Clears list container
    fileHandler.clearFile("MediaRegister.txt"); // Clears register file

    if (_pMediaRegister.empty()) {
        return true;
    }
    else {
        return false;
    }
}
// Saves list container items to register file
bool MediaRegister::saveReg() {
    // Returns false if no items in the list
    if (_pMediaRegister.empty()) {
        cout << "Register is empty." << endl;
        return false;
    }
    sortMedia(1); // Sorts list after ID in ascending order
    // Saves list in register file and in a backup file using method in fileHandler class
    if (fileHandler.saveRegister(_pMediaRegister, _fileName)) {
        fileHandler.saveRegister(_pMediaRegister, "backup.txt");
        cout << "Register has been saved to " << _fileName << endl << endl;
        return true;
    }
    else {
        return false;
    }
}
// Loading items from register class and puts them into list container
bool MediaRegister::loadReg() {
    _pMediaRegister = fileHandler.loadRegister(_fileName);
    // Returns false if file did not contain any items
    if (_pMediaRegister.empty()) {
        return false;
    }
    else {
        _count = 0;
        // Setting _count to last item ID
        for (_it = _pMediaRegister.begin(); _it != _pMediaRegister.end(); _it++) {
            _count = (*_it)->getID();
        }
        cout << endl << "Movie register successfully loaded!" << endl << endl;
        return true;
    }
}


