#ifndef MOVIE
#define MOVIE

#include "Video.h"

class Movie : public Video{
    public:
        Movie(string, string, float, string[], int);
        void setId(string) override;

};

#endif