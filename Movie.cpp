#include "Movie.h"

Movie::Movie(string id_, string name_, int length_, string genres_, int rating_):Video("M" + id_, name_, length_, genres_, rating_){
    setId(id_);
    setName(name_);
    setLength(length_);
    setGenre(genres_);
    setRating(rating_);
}

void Movie::setId(string id){
    this->id = "M" + id;
}

void Movie::operator+(int timeToAdd){
    this->length += timeToAdd;
}

void Movie::operator-(int timeToReduce){
    if((this->length - timeToReduce) > 0){
        this->length -= timeToReduce;
    }
}