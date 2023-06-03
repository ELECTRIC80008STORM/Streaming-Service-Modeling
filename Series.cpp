#include "Series.h"

Series::Series(string id_, string name_, float lenght_, string genres_[], int rating_):Video("SS" + id_, name_, lenght_, genres_, rating_){
    setId(id_);
    setName(name_);
    setLenght(lenght_);
    setGenre(genres_);
    setRating(rating_);
}

void Series::setId(string id){
    this->id = "SRS" + id;
}

void Series::setSeason(string id, string title, string ids[], string names[], float lenghts[], int ratings[]){
    seasons.push_back(new Season(id, title));
    lenght = sizeof(ids) / sizeof(string);
    for(int i = 0; i < lenght; i++){
        seasons.back()->setEpisode(ids[i], names[i], lenghts[i], ratings[i]);
    }
}

vector<Season*> Series::getSeasons(int){
    return seasons;
}