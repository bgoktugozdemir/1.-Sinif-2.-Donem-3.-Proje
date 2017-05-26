#include "Rating.h"

Rating::Rating(int RatingId, float rating, int user_id, int movie_id)
{
	this->RatingId = RatingId;
	this->rating = rating;
	this->user_id = user_id;
	this->movie_id = movie_id;
}

Rating::Rating()
{
    this->RatingId = 0;
	this->rating = 0;
	this->user_id = 0;
	this->movie_id = 0;
}


Rating::~Rating()
{
}
