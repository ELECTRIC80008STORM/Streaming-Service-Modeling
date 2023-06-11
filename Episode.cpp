/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
* Definition of Episode class
*/

#include "Episode.h"

/**
 * Constructor for the Episode class.
 * @param string id: the ID of the episode
 * string name: the name of the episode
 * int length: the length of the episode
 * int rating: the rating of the episode
 * @return Episode object
*/
Episode::Episode(string id, string name, int length, int rating){
    setId(id);
    setName(name);
    setLength(length);
    setRating(rating);
}

/**
 * Sets the ID of the episode.
 * @param string id_: the ID of the episode
 * @return
*/
void Episode::setId(string id_){
    id = "E" + id_;
}

/**
 * Retrieves the ID of the episode.
 * @param
 * @return string: the ID of the episode
*/
string Episode::getId(){
    return id;
}

/**
 * Sets the name of the episode.
 * @param string name: the name of the episode
 * @return
*/
void Episode::setName(string name){
    this->name = name;
}

/**
 * Retrieves the name of the episode.
 * @param
 * @return string: the name of the episode
*/
string Episode::getName(){
    return name;
}

/**
 * Sets the length of the episode.
 * @param int length: the length of the episode
 * @return
*/
void Episode::setLength(int length){
    this->length = length;
}

/**
 * Retrieves the length of the episode.
 * @param
 * @return float: the length of the episode
*/
float Episode::getLength(){
    return length;
}

/**
 * Sets the rating of the episode.
 * @param int rating: the rating of the episode
 * @return
*/
void Episode::setRating(int rating){
    this->rating = rating;
}

/**
 * Retrieves the rating of the episode.
 * @param
 * @return int: the rating of the episode
*/
int Episode::getRating(){
    return rating;
}

/**
 * Overloads the + operator to increase the length of the episode.
 * @param int timeToAdd: the time to add to the episode length
 * @return
*/
void Episode::operator+(int timeToAdd){
    this->length += timeToAdd;
}

/**
 * Overloads the - operator to reduce the length of the episode.
 * Ensures that the resulting length is not negative.
 * @param int timeToReduce: the time to reduce from the episode length
 * @return
*/

void Episode::operator-(int timeToReduce){
    if((this->length - timeToReduce) > 0){
        this->length -= timeToReduce;
    }
}
