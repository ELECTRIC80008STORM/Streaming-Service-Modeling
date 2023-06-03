#include "Video.h"

Video::Video(string id, string name_){
    this->id = id;
    setName(name_);
}

Video::Video(string id, string name_, float lenght_, string genres_[], int rating_){
    this->id = id;
    setName(name_);
    setLenght(lenght_);
    setGenre(genres_);
    setRating(rating_);
}

string Video::getId(){
    return id;
}

void Video::setName(string name){
    this->name = name;
}

string Video::getName(){
    return name;
}

void Video::setLenght(float lenght){
    this->lenght = lenght;
}

float Video::getLenght(){
    return lenght;
}

void Video::setGenre(string genres[]){
    int genreListLenght = sizeof(genres) / sizeof(string);
    for(int i = 0; i < genreListLenght; i++){
        genre.push_back(&genres[i]);
    }
}

vector<string*> Video::getGenre(){
    return genre;
}

void Video::setRating(int rating){
    this->rating = rating;
}

int Video::getRating(){
    return rating;
}
