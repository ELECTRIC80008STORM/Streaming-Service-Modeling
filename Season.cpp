#include "Season.h"

Season::Season(string id, string title){
    setId(id);
    setTitle(title);
}

void Season::setId(string id_){
    id = "SSN" + id_;
}

string Season::getId(){
    return id;
}

void Season::setTitle(string title){
    this->title = title;
}

string Season::getTitle(){
    return title;
}

void Season::setEpisode(string id, string name, int lenght, int rating){
    episodes.push_back(new Episode(id,name,lenght,rating));
}

vector<Episode*> Season::getEpisodes(){
    return episodes;
}