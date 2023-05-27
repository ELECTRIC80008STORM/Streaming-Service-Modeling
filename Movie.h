#ifndef MOVIE
#define MOVIE

#include "Video.h"

class Movie : public Video{
    public:
        Movie();
        /* The forth parameter will be a dynamic array in the future */
        Movie(string, string, float, string, int);

};

#endif