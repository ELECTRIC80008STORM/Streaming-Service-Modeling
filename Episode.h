#ifndef EPISODE
#define EPISODE

#include <string>

using namespace std;

class Episode{
    private:
        string id;
        string name;
        float lenght;
        int rating;

    public:
        Episode();
        Episode(string, string, float, int);
        void setId(int);
        int getId();
        void setName(string);
        string getName();
        void setLenght(float);
        float getLenght();
        void setRating(int);
        int getRating();
};

#endif