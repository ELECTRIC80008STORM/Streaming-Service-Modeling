/*
* Streaming Service Modeling Proyect
* Rommel T.
*/

/*
* Definition of Series class
*/

#include "Series.h"

/**
 * Constructor for the Series class.
 * @param string id_: the ID of the series
 * string name_: the name of the series
 * int length_: the length of the series
 * string genres_: the genres of the series
 * int rating_: the rating of the series
 * @return Series object
*/
Series::Series(string id_, string name_, int length_, string genres_, int rating_):Video("SS" + id_, name_, length_, genres_, rating_){
    setId(id_);
    setName(name_);
    setLength(length_);
    setGenre(genres_);
    setRating(rating_);
}

/**
 * Sets the ID of the series.
 * @param string id: the ID of the series
 * @return
*/
void Series::setId(string id){
    this->id = "SRS" + id;
}

/**
 * Sets the season information for the series.
 * @param string id: the ID of the season
 * string title: the title of the season
 * vector<string*> ids: the IDs of the episodes in the season
 * vector<string*> names: the names of the episodes in the season
 * vector<int*> lengths: the lengths of the episodes in the season
 * vector<int*> ratings: the ratings of the episodes in the season
 * @return
*/
void Series::setSeason(string id, string title, vector<string*> ids, vector<string*> names, vector<int*>  lengths, vector<int*> ratings){
    seasons.push_back(new Season(id, title));
    for(int i = 0; i < ids.size(); i++){
        seasons.back()->setEpisode(*ids[i], *names[i], *lengths[i], *ratings[i]);
    }
}

/**
 * Retrieves the seasons of the series.
 * @param
 * @return vector<Season*>: the seasons of the series
*/
vector<Season*> Series::getSeasons(){
    return seasons;
}
