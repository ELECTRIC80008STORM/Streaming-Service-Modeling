#include "Movie.h"

Movie::Movie(string id_, string name_, float lenght_, string genres_[], int rating_):Video("M" + id_, name_, lenght_, genres_, rating_){
    setId(id_);
    setName(name_);
    setLenght(lenght_);
    setGenre(genres_);
    setRating(rating_);
}

void Movie::setId(string id){
    this->id = "M" + id;
}