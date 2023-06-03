#ifndef VIDEO
#define VIDEO

#include <string>
#include <vector>

using namespace std;

class Video{
    protected:
        string id;
        string name;
        float lenght;
        vector<string*> genre;
        int rating;

    public:
        Video(string, string);
        Video(string, string, float, string[], int);
        virtual void setId(string) = 0;
        string getId();
        void setName(string);
        string getName();
        void setLenght(float);
        float getLenght();
        void setGenre(string[]);
        vector<string*> getGenre();
        void setRating(int);
        int getRating();
};

#endif