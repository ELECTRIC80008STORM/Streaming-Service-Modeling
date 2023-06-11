/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
* Definition of Video class
*/

#include "Video.h"

/**
 * Constructor for the Video class with two parameters
 *
 * @param string id: the ID of the video, string name_: the name of the video
 * @return Video object
 */

Video::Video(string id, string name_){
    this->id = id;
    setName(name_);
}

/**
 * Constructor for the Video class with five parameters.
 * @param string id: the ID of the video, string name_: the name of the video
 * int length_: the length of the video
 * string genres_: the genre of the video
 * int rating_: the rating of the video
 * @return Video object
*/
Video::Video(string id, string name_, int length_, string genres_, int rating_){
    this->id = id;
    setName(name_);
    setLength(length_);
    setGenre(genres_);
    setRating(rating_);
}

/**
 * Retrieves the ID of the video.
 * @param
 * @return string: the ID of the video
*/
string Video::getId(){
    return id;
}

/**
 * Sets the name of the video.
 * @param string name: the name of the video
 * @return
*/
void Video::setName(string name){
    this->name = name;
}

/**
 * Retrieves the name of the video.
 * @param
 * @return string: the name of the video
*/
string Video::getName(){
    return name;
}

/**
 * Sets the length of the video.
 * @param int length: the length of the video
 * @return
*/
void Video::setLength(int length){
    this->length = length;
}

/**
 * Retrieves the length of the video.
 * @param
 * @return float: the length of the video
*/
float Video::getLength(){
    return length;
}

/**
 * Sets the genre of the video.
 * @param string genre: the genre of the video
 * @return
*/
void Video::setGenre(string genre){
    this->genre = genre;
}

/**
 * Retrieves the genre of the video.
 * @param
 * @return string: the genre of the video
*/
string Video::getGenre(){
    return genre;
}

/**
 * Sets the rating of the video.
 * @param int rating: the rating of the video
 * @return
*/
void Video::setRating(int rating){
    this->rating = rating;
}

/**
 * Retrieves the rating of the video.
 * @param
 * @return int: the rating of the video
*/
int Video::getRating(){
    return rating;
}
