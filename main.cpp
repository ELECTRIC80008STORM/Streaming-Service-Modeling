#include "Video.cpp"
#include "Movie.cpp"
#include "Series.cpp"
#include "Season.cpp"
#include "Episode.cpp"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void catalogInfo(vector<Video*>);

int main(){
    printf("\e[1;1H\e[2J");

    vector<Video*> catalog;
    string movie1[1] = {"Superhero"};
    catalog.push_back(new Movie("000", "Spider-Man: Into the Spider-Verse", 120, movie1,5));
    string movie2[1] = {"Superhero"};
    catalog.push_back(new Movie("001", "Guardians of the Galaxy Vol. 3", 149, movie2,5));
    string movie3[2] = {"Terror","Gore"};
    catalog.push_back(new Movie("002", "The Boogeyman", 98, movie3,3));
    string movie4[3] = {"Musical","Fantasy", "Live Action"};
    catalog.push_back(new Movie("003", "The Little Mermaid", 136, movie4,4));
    string movie5[2] = {"Action", "Spies"};
    catalog.push_back(new Movie("004", "Fast X", 141, movie5,3));


    cout << "Welcome to this streaming service model.\n\n"
    << "The current catalog of movies is as follows:" << endl << endl;

    catalogInfo(catalog);


    return 0;
}

void catalogInfo(vector<Video*> catalog){
    vector<Video*>::const_iterator i;
    for(i = catalog.begin(); i != catalog.end(); i++){
        
        Movie* movie = dynamic_cast<Movie*> (*i);
        if(movie != nullptr){
            cout << "Movie Title: " << (*i)->getName() << endl << endl;
            cout << "Lenght: " << (*i)->getName() << endl;
            /* Genre couldn't be put do to mistakes on the array parameters.
            I'll change all of the array parameters for the next deadline.
            */
            cout << "Rating: " << (*i)->getRating() << endl << endl;
        };

        // Series* series = dynamic_cast<Series*> (*i);
        // if(series != nullptr){
        //     cout << "Series Title: " << (*i)->getName() << endl << endl;
        //     cout << "Lenght: " << (*i)->getName() << endl;
        //     /* Genre couldn't be put do to mistakes on the array parameters.
        //     I'll change all of the array parameters for the next deadline.
        //     */
        //     cout << "Rating: " << (*i)->getRating() << endl << endl;
        // };


    };
}