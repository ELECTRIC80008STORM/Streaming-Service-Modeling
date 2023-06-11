#include "Episode.h"

Episode::Episode(string id, string name, int length, int rating){
    setId(id);
    setName(name);
    setLength(length);
    setRating(rating);
}

void Episode::setId(string id_){
    id = "E" + id_;
}

string Episode::getId(){
    return id;
}

void Episode::setName(string name){
    this->name = name;
}

string Episode::getName(){
    return name;
}

void Episode::setLength(int length){
    this->length = length;
}

float Episode::getLength(){
    return length;
}

void Episode::setRating(int rating){
    this->rating = rating;
}

int Episode::getRating(){
    return rating;
}

void Episode::operator+(int timeToAdd){
    this->length += timeToAdd;
}

void Episode::operator-(int timeToReduce){
    if((this->length - timeToReduce) > 0){
        this->length -= timeToReduce;
    }
}