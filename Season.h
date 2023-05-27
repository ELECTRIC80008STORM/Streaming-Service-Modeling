#ifndef SEASON
#define SEASON

#include "Episode.h"
#include <string>

using namespace std;

class Season{
    private:
        string title;
        /* It will be a dynamic array in the future */
        Episode episodes;
    
    public:
    Season();
    void setTitle(string);
    string getTitle();
    void setEpisode(string, string, float, int);
    Episode getEpisodes();

};

#endif