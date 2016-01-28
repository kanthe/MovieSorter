/**********************************************************************/
// File:	App.h
// Summary:	Main class which activates the application
//          and creates the other main objects.
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-06-03	Created the file. Robin Kanthe
// ------------------------------------------------
//
//	@properties
//
//	@methods    Constructor, Destructor
//
/**********************************************************************/
#include "Mediaregister.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class App
{
    public:
        App();
        ~App();
        void run();
    private:
};
// Default empty constructor
App::App()
{
}

// Default empty destructor This object
// destroys itself when main method has run.
App::~App()
{
}
//
//	Runs the application.
//
//	@param  none
//
//	@return undefined
//
void App::run() {
    try {
        MediaRegister myMediaRegister;
    }
    catch (char* error) {
        cout << "Error occured: " << endl;
        cout << error << endl;
    }
    catch (...) {
        cout << "Unknown error occured." << endl;
    }
}
//
//  Startup method
//	Activates run
//
//	@param  none
//
//	@return 0
//
int main()
{
    App myApp;
    myApp.run();

    return 0;
}
