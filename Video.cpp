#include "Video.h"

Video::Video(string id, string name_){
    this->id = id;
    setName(name_);
}

Video::Video(string id, string name_, int length_, string genres_, int rating_){
    this->id = id;
    setName(name_);
    setLength(length_);
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

void Video::setLength(int length){
    this->length = length;
}

float Video::getLength(){
    return length;
}

void Video::setGenre(string genre){
    this->genre = genre;
}

string Video::getGenre(){
    return genre;
}

void Video::setRating(int rating){
    this->rating = rating;
}

int Video::getRating(){
    return rating;
}
