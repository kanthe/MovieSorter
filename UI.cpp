/*************************************************************************/
// File:    UI.cpp
// Summary:	Handles user interface (input in console and output to console
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
/*************************************************************************/
#include "UI.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Constructor
UI::UI() : ERROR_MESSAGE("Invalid input. Please try again: "), genericTime(0, 0),
            genericSciFiMovie(0, "", 0, genericTime, "", "", ""), 
            genericHistoricMovie (0, "", 0, genericTime, "", "", "", 0) {
}

// Default empty destructor
UI::~UI() {
    
}
// Describes the app to user
void UI::appDescription() {
    cout << "-----------" << endl;
    cout << "DESCRIPTION" << endl;
    cout << "-----------" << endl;
    cout << "This application saves a register of movie data, " << endl;
    cout << "such as title, genre and release year." << endl;
    cout << "Different genres contains different types of data" << endl;
    cout << "specific to the particular genre." << endl;
    cout << "The user may also input data for new movies into" << endl;
    cout << "the register. In addition there are some functions" << endl;
    cout << "for sorting and searching for specific key data." << endl;
    cout << "The app can easily be expanded to contain movies" << endl;
    cout << "in other genres, as well as other media, i.e." << endl;
    cout << "books and games." << endl;
    cout << endl;
}
// Displays menu. Uses method getChoice to get menu choice from user,
// which´it returns.
int UI::mainMenu() {
    cout << "------------------------------" << endl;
    cout << "MENU" << endl;
    cout << "------------------------------" << endl;
    cout << "1. Add movie" << endl;
    cout << "2. Remove movie" << endl;
    cout << "3. Search for movie" << endl;
    cout << "4. Show all movies" << endl;
    cout << "5. Sort movies" << endl;
    cout << "6. Save movie register to file" << endl;
    cout << "   (Sorts the items w.r.t ID, ascending order.)" << endl;
    cout << "7. Empty movie register" << endl;
    cout << "8. Save and exit" << endl;
    cout << "9. Exit without saving" << endl;
    cout << endl;
    const int numberOfChoices = 9;

    return iocontrol.getChoice(numberOfChoices, ERROR_MESSAGE);
}
// Menu for the sort and search function. Returns user input.
int UI::sortMediaMenu() {
    cout << endl;
    cout << "Enter key choice: " << endl;
    cout << "--------------" << endl;
    cout << "1. ID" << endl;
    cout << "2. Title" << endl;
    cout << "3. Genre" << endl;
    cout << "4. Release year" << endl;
    cout << endl;
    const int numberOfChoices = 4;
    
    return iocontrol.getChoice(numberOfChoices, ERROR_MESSAGE);
}
// Menu for choosing sort order (ascending or descending)
// Returns input (choice) from user.
int UI::sortingOrder() {
    cout << endl;
    cout << "Choose sorting order: " << endl;
    cout << "---------------------" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    const int numberOfChoices = 2;

    return iocontrol.getChoice(numberOfChoices, ERROR_MESSAGE);
}
// Message in remove media function
void UI::removeMediaText() {
    cout << "Please type ID of the movie you want to remove." << endl;
    cout << "Use search function in main menu to get the ID." << endl;
    cout << endl;
}
// Message in empty register function
void UI::emptyRegisterText() {
    cout << "You are about to delete all items in the register." << endl;
    cout << "Are you sure?" << endl << endl;
}
// Presebting alternatives, yes or no to user.
// Yes means you can be more engagerad.
bool UI::pressYorN() {
    cout << "Continue? (y/n): ";
    char input = iocontrol.getCharInputYorN(ERROR_MESSAGE);

    if (input == 'y') {
        return true;
    }
    else {
        return false;
    }
}
// Waiting for user to press a key to go forward in the app.
void UI::pressEnter() {
    iocontrol.pressEnterToContinue("Press ENTER to continue");
}
// Returns ID, typed by user.
int UI::askID() {
    cout << "ID: ";
    int ID = iocontrol.getIntInput(ERROR_MESSAGE);

    return ID;
}
// Returns title, typed by user.
char* UI::askTitle() {
    cout << endl << "Title: ";
    char title[MAX_LENGTH];
    strcpy(title, iocontrol.getLineInput(ERROR_MESSAGE));

    return title;
}
// Returns release year, typed by user.
int UI::askYear() {
    cout << "Year: ";
    int year = 0;
    // 
    while (year = iocontrol.getIntInput(ERROR_MESSAGE)) {
        // Repeates until a number (a year) between 1800-2100 is typed
        if (year < 1800 || year > 2100) {
            cout << "You need to type a valid year between 1800-2100. Try again." << endl;
            cout << "Year: ";
        }
        else {
            break;
        }
    }
    return year;
}
// Returns release year, typed by user.
MyTime UI::askRunTime() {
    MyTime runTimef(0, 0);
    cout << "Runtime hours: ";
    int hours;

    while (!(hours = iocontrol.getIntInput(ERROR_MESSAGE)) || hours < 0) { 
        cout << "Runtime hours: "; 
    }

    if (hours < 0) {
        cout << "Hours cannot be negative." << endl;
        return runTimef;
    }
    cout << "Runtime minutes: ";
    int minutes;

    while (!(minutes = iocontrol.getIntInput(ERROR_MESSAGE)) || minutes < 0 || minutes > 59) { 
        cout << "Runtime minutes: "; 
    }

    if (minutes < 0 || minutes > 59) {
        cout << "Minutes has to be between 0 - 59." << endl;
        return runTimef;
    }
    MyTime runTime(hours, minutes);

    return runTime;
}
// Returns description, typed by user.
char* UI::askDescription() {
    cout << endl << "Write movie description (max 1000 characters): " << endl << endl;
    char description[1000];
    strcpy(description, iocontrol.getLineInput(ERROR_MESSAGE));

    return description;
}
// Presents menu to choose genre with the printList method. Returns users menu choice.
// The array of strings "_genres" in an object, which is inherited from Movie class,
// are used to get the names of the genres, presented in the menu.
int UI::askGenre() {
    int numberOfChoices = printList(genericSciFiMovie._genres);
    cout << "Choose a genre: ";
    int genreNumber = iocontrol.getChoice(numberOfChoices, ERROR_MESSAGE);
    
    return genreNumber;
}
// Converts genre number given in the method above to genre as a string.
char* UI::genreNumberToGenre(int genreNumber) {
    char genre[MAX_LENGTH] = "";
    strcpy(genre, (genericSciFiMovie._genres)[genreNumber - 1]);

    return genre;
}
// Presents menu for info specific for sci-fi time periods.
// printList are called with the array _sciFiPeriods in a SciFiMovie 
// class object to do this.
// User can choose a number from the menu and the corresponding 
// time perion is returned.
char* UI::askSciFiPeriod() {
    int numberOfChoices = printList(genericSciFiMovie._sciFiPeriods);
    cout << "Choose time movie take place: ";
    int choice = iocontrol.getChoice(numberOfChoices, ERROR_MESSAGE);
    char sciFiPeriod[MAX_LENGTH];
    strcpy(sciFiPeriod, (genericSciFiMovie._sciFiPeriods)[choice - 1]);

    return sciFiPeriod;
}
// Menu for subgenre to Sci-Fi movies. 
// Returns users choice of sub genre.
char* UI::askSciFiSubGenre() {
    int numberOfChoices = printList(genericSciFiMovie._subgenres);
    cout << "Choose a subgenre: ";
    int choice = iocontrol.getChoice(numberOfChoices, ERROR_MESSAGE);
    char sciFiSubGenre[MAX_LENGTH];
    strcpy(sciFiSubGenre, (genericSciFiMovie._subgenres)[choice - 1]);

    return sciFiSubGenre;
}
// Using similar method to get subgenre for movie of type "Historic"
char* UI::askHistoricSubGenre() {
    int numberOfChoices = printList(genericHistoricMovie._subgenres);
    cout << "Choose a subgenre: ";
    int choice = iocontrol.getChoice(numberOfChoices, ERROR_MESSAGE);
    char historicSubGenre[MAX_LENGTH];
    strcpy(historicSubGenre, (genericHistoricMovie._subgenres)[choice - 1]);

    return historicSubGenre;
}
// Returns user input: historic figure
char* UI::askHistoricFigure() {
    cout << "Type historic figure: ";
    char historicFigure[MAX_LENGTH];
    strcpy(historicFigure, iocontrol.getLineInput(ERROR_MESSAGE));
    return historicFigure;
}
// Returns historic time period.
// Number is cheched so that it is within the range of -9999 - 2015
int UI::askTimePeriod() {
    cout << "Type time movie take place: ";

    while (true) {
        int historicTime = iocontrol.getIntInput(ERROR_MESSAGE);

        if (historicTime < -9999 || historicTime > 2015) {
            continue;
        }
        else {
            return historicTime;
        }
    }
}
// Takes an array of strings as input and prints it until
// the word "Empty" is encountered.
// Returns the index of the string before first "Empty" in the array
int UI::printList(char* arrayItems[10]) {
    int i;
    cout << endl;

    for (i = 0; i < 10; i++) {

        if (strcmp("Empty", arrayItems[i]) == 0) {
            break;
        }
        cout << i + 1 << ". " << arrayItems[i] << endl;
    }
    cout << endl;
    return i;
}

bool UI::askToAdd() {
    cout << "Add movie with this info to register? ";
    
    return pressYorN();
}