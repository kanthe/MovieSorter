/**********************************************************************/
// File:	IOcontrol.h 
// Summary:	Receives keyboard input and checks if it is valid, before
//          returning it. Can validate char*, char, int and double
// Version: Version 1.1 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// ------------------------------------------------
// Log:	2015-04-14	Created the file. Robin Kanthe
//      2015-06-03  Changing some methods.
//                  Bug fixes.
//                  Adding methods: getChoice, getMAX_INPUT_LENG
//                  Adding property: MAX_INPUT_LENG
// ------------------------------------------------
//
//	@properties _input, _inputPtr, _correctInput
//
//	@methods    Constructor, Destructor, checkNewInput, checkNumeric,
//              pressEnterToContinue, getLineInput, getCharInput,
//              getIntInput, getDoubleInput, getCharInputYorN, 
//              getChoice, getMAX_INPUT_LENG
/**********************************************************************/
#ifndef IOCONTROL_H
#define IOCONTROL_H

class IOcontrol {
    public:
        IOcontrol();
        ~IOcontrol();
        bool checkNewInput(char* input);
        bool checkNumeric(char* input, char* type);
        void pressEnterToContinue(const char* message);
        char* getLineInput(const char* errorMessage);
        int getIntInput(const char* errorMessage);
        double getDoubleInput(const char* errorMessage);
        char getCharInput(const char* errorMessage);
        char getCharInputYorN(const char* errorMessage);
        int getChoice(const int numberOfChoices, const char* errorMessage);
        int getMAX_INPUT_LENG() { 
            return MAX_INPUT_LENG;  // returns constant: maximum number
                                    // of characters in input
        }
    private:
        static const int MAX_INPUT_LENG = 1000;
};

#endif