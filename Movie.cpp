/**********************************************************************/
// File:    Movie.cpp
// Summary:	Baseclass for classes representing different movie genres.
//          Implements the interface created in class BaseMedia.
//          Sets up movie specific information, including
//          director, length, alternative genres
// Version: Version 1.0 - 2015-06-03
// Author:	Robin Kanthe
// Email	kanthe.robin@gmail.com
// -------------------------------------------
// Log:	2015-04-14	Created the file. Robin Kanthe
/**********************************************************************/
#include "Movie.h"

char* Movie::_genres[10] = { "Sci-Fi", "Historic", "Drama", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty" };