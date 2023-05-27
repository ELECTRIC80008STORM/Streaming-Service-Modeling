#ifndef VIDEO
#define VIDEO

#include <string>
using namespace std;

class Video{
    protected:
        string id;
        string name;
        float lenght;
        /* The "genre" attribute will be a dynamic array in the
        future but for now it can't be correctly declare */
        string genre;
        int rating;

    public:
        Video();
        Video(string, string);
        /* The forth parameter will be a dynamic array in the future */
        Video(string, string, float, string, int);
        void setId(int);
        int getId();
        void setName(string);
        string getName();
        void setLenght(float);
        float getLenght();
        /* Because "setGenre" and "getGenre" will need to deal with the dynamic array
        they can't be correctly declare either */
        void setGenre(string);
        string getGenre();
        void setRating(int);
        int getRating();
};

#endif