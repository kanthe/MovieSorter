/*************************************************************************/
// File:	UI.h 
// Summary:	Handles user interface (input in console and output to console
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
/*************************************************************************/
#ifndef UI_H
#define UI_H

#include "IOcontrol.h"
#include "MyTime.h"
#include "SciFiMovie.h"
#include "HistoricMovie.h"

class UI {
    public:
        UI();
        ~UI();
        void appDescription();
        int mainMenu();
        void removeMediaText();
        void emptyRegisterText();
        int sortMediaMenu();
        int sortingOrder();
        bool pressYorN();
        void pressEnter();
        int askID();
        char* askTitle();
        int askGenre();
        char* UI::genreNumberToGenre(int genreNumber);
        int askYear();
        MyTime askRunTime();
        char* askDescription();
        char* askSciFiPeriod();
        char* askSciFiSubGenre();
        char* askHistoricSubGenre();
        char* askHistoricFigure();
        int askTimePeriod();
        int printList(char* arrayItems[10]);
        bool askToAdd();
        int getMaxLength() { return MAX_LENGTH; }

    private:
        const char* ERROR_MESSAGE;
        IOcontrol iocontrol;
        static const int MAX_LENGTH = 100;    // Standard max length of strings
        MyTime genericTime;
        SciFiMovie genericSciFiMovie; 
        HistoricMovie genericHistoricMovie;
};

#endif