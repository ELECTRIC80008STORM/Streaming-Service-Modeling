/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
* Movie class, child of Video class
*/

#ifndef MOVIE
#define MOVIE

#include "Video.h"

// Declaration of class Movie
class Movie : public Video{
    public:
        Movie(string, string, int, string, int);
        void setId(string) override;
        void operator+(int);
        void operator-(int);
};

#endif
