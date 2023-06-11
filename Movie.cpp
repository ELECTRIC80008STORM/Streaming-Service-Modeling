/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
* Definition of Movie class
*/

#include "Movie.h"

/**
 * Constructor for the Movie class.
 * @param string id_: the ID of the movie
 * string name_: the name of the movie
 * int length_: the length of the movie
 * string genres_: the genres of the movie
 * int rating_: the rating of the movie
 * @return Movie object
*/
Movie::Movie(string id_, string name_, int length_, string genres_, int rating_):Video("M" + id_, name_, length_, genres_, rating_){
    setId(id_);
    setName(name_);
    setLength(length_);
    setGenre(genres_);
    setRating(rating_);
}

/**
 * Sets the ID of the movie.
 * @param string id: the ID of the movie
 * @return
*/
void Movie::setId(string id){
    this->id = "M" + id;
}

/**
 * Overloads the + operator to add time to the movie's length.
 * @param int timeToAdd: the time to add to the movie's length
 * @return
*/
void Movie::operator+(int timeToAdd){
    this->length += timeToAdd;
}

/**
 * Overloads the - operator to reduce time from the movie's length.
 * @param int timeToReduce: the time to reduce from the movie's length
 * @return
*/

void Movie::operator-(int timeToReduce){
    if((this->length - timeToReduce) > 0){
        this->length -= timeToReduce;
    }
}
