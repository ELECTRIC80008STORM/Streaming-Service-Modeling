#ifndef SERIES
#define SERIES

#include "Video.h"
#include "Season.h"
#include <vector>

class Series : public Video{
    private:
        vector<Season*> seasons;

    public:
        Series(string, string, float, string[], int);
        void setId(string) override;
        void setSeason(string, string, string[], string[], float[], int[]);
        vector<Season*> getSeasons(int);

};

#endif