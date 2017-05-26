#include "Movie.h"

Movie::Movie(int MovieId, string MovieTitle, string MovieGenre, string MovieReleaseYear, string MovieLanguage, float MovieRating, string MovieCensorship, string MovieStory, unsigned int MovieBudget, int studio_id)
{
	this->MovieId = MovieId;
	this->MovieTitle = MovieTitle;
	this->MovieGenre = MovieGenre;
	this->MovieReleaseYear = MovieReleaseYear;
	this->MovieLanguage = MovieLanguage;
	this->MovieRating = MovieRating;
	this->MovieCensorship = MovieCensorship;
	this->MovieStory = MovieStory;
	this->MovieBudget = MovieBudget;
	this->studio_id = studio_id;
}

Movie::Movie()
{
    this->MovieId = 0;
	this->MovieTitle = "";
	this->MovieGenre = "";
	this->MovieReleaseYear = "";
	this->MovieLanguage = "";
	this->MovieRating = 0;
	this->MovieCensorship = "";
	this->MovieStory = "";
	this->MovieBudget = 0;
	this->studio_id = 0;
}


Movie::~Movie()
{

}

