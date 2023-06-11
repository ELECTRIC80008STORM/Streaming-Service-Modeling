#ifndef EPISODE
#define EPISODE

#include <string>

using namespace std;

class Episode{
    private:
        string id;
        string name;
        int length;
        int rating;

    public:
        Episode(string, string, int, int);
        void setId(string);
        string getId();
        void setName(string);
        string getName();
        void setLength(int);
        float getLength();
        void setRating(int);
        int getRating();
        void operator+(int);
        void operator-(int);
};

#endif