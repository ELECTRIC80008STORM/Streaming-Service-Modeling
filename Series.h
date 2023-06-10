#ifndef SERIES
#define SERIES

#include "Video.h"
#include "Season.h"
#include <vector>

class Series : public Video{
    private:
        vector<Season*> seasons;

    public:
        Series(string, string, int, string, int);
        void setId(string) override;
        void setSeason(string, string, vector<string*>, vector<string*>, vector<int*>, vector<int*>);
        vector<Season*> getSeasons();

};

#endif