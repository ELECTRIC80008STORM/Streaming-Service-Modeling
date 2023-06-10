#include "Episode.h"

Episode::Episode(string id, string name, int lenght, int rating){
    setId(id);
    setName(name);
    setLenght(lenght);
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

void Episode::setLenght(int lenght){
    this->lenght = lenght;
}

float Episode::getLenght(){
    return lenght;
}

void Episode::setRating(int rating){
    this->rating = rating;
}

int Episode::getRating(){
    return rating;
}
