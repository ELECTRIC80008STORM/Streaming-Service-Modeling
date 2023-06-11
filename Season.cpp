/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
* Definition of Season class
*/

#include "Season.h"

/**
 * Constructor for the Season class.
 * @param string id: the ID of the season
 * string title: the title of the season
 * @return Season object
*/
Season::Season(string id, string title){
    setId(id);
    setTitle(title);
}

/**
 * Sets the ID of the season.
 * @param string id_: the ID of the season
 * @return
*/
void Season::setId(string id_){
    id = "SSN" + id_;
}

/**
 * Retrieves the ID of the season.
 * @param
 * @return string: the ID of the season
*/
string Season::getId(){
    return id;
}

/**
 * Sets the title of the season.
 * @param string title: the title of the season
 * @return
*/
void Season::setTitle(string title){
    this->title = title;
}

/**
 * Retrieves the title of the season.
 * @param
 * @return string: the title of the season
*/
string Season::getTitle(){
    return title;
}

/**
 * Sets the episode information for the season.
 * @param string id: the ID of the episode
 * string name: the name of the episode
 * int length: the length of the episode
 * int rating: the rating of the episode
 * @return
*/
void Season::setEpisode(string id, string name, int length, int rating){
    episodes.push_back(new Episode(id,name,length,rating));
}

/**
 * Retrieves the episodes of the season.
 * @param
 * @return vector<Episode*>: the episodes of the season
*/
vector<Episode*> Season::getEpisodes(){
    return episodes;
}
