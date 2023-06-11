#ifndef VIDEO
#define VIDEO

#include <string>
#include <vector>

using namespace std;

class Video{
    protected:
        string id;
        string name;
        int length;
        string genre;
        int rating;

    public:
        Video(string, string);
        Video(string, string, int, string, int);
        virtual void setId(string) = 0;
        string getId();
        void setName(string);
        string getName();
        void setLength(int);
        float getLength();
        void setGenre(string);
        string getGenre();
        void setRating(int);
        int getRating();
};

#endif