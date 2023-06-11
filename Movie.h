#ifndef MOVIE
#define MOVIE

#include "Video.h"

class Movie : public Video{
    public:
        Movie(string, string, int, string, int);
        void setId(string) override;
        void operator+(int);
        void operator-(int);

};

#endif