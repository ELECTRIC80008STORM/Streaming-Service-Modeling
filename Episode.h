#ifndef EPISODE
#define EPISODE

#include <string>

using namespace std;

class Episode{
    private:
        string id;
        string name;
        int lenght;
        int rating;

    public:
        Episode(string, string, int, int);
        void setId(string);
        string getId();
        void setName(string);
        string getName();
        void setLenght(int);
        float getLenght();
        void setRating(int);
        int getRating();
};

#endif