#ifndef SERIES
#define SERIES

#include "Video.h"
#include "Season.h"

class Series : public Video{
    private:
        // It will be a dynamic array in the future
        Season seasons;

    public:
        Series();
        /* Second, third, forth and fifth parameters are going to be
        dynamic arrays in the future */
        void setSeason(string, string, string, float, int);
        Season getSeason(int);


};

#endif