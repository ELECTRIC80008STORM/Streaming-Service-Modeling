#ifndef SEASON
#define SEASON

#include "Episode.h"
#include <string>
#include <vector>

using namespace std;

class Season{
    private:
        string id;
        string title;
        vector<Episode*> episodes;
    
    public:
        Season(string, string);
        void setId(string);
        string getId();
        void setTitle(string);
        string getTitle();
        void setEpisode(string, string, float, int);
        vector<Episode*> getEpisodes();

};

#endif