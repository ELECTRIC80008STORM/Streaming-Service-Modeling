#include "Series.h"

Series::Series(string id_, string name_, int length_, string genres_, int rating_):Video("SS" + id_, name_, length_, genres_, rating_){
    setId(id_);
    setName(name_);
    setLength(length_);
    setGenre(genres_);
    setRating(rating_);
}

void Series::setId(string id){
    this->id = "SRS" + id;
}

void Series::setSeason(string id, string title, vector<string*> ids, vector<string*> names, vector<int*>  lengths, vector<int*> ratings){
    seasons.push_back(new Season(id, title));
    for(int i = 0; i < ids.size(); i++){
        seasons.back()->setEpisode(*ids[i], *names[i], *lengths[i], *ratings[i]);
    }
}

vector<Season*> Series::getSeasons(){
    return seasons;
}