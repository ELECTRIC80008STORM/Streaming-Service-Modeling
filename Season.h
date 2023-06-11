/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
* Definition of Season class
*/

#ifndef SEASON
#define SEASON

#include "Episode.h"
#include <string>
#include <vector>

using namespace std;

// Declaration of class Season
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
        void setEpisode(string, string, int, int);
        vector<Episode*> getEpisodes();
};

#endif
