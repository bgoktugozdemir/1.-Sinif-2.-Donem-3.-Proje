#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Studio.h"
#include "Comment.h"
#include "Rating.h"


using namespace std;
class Comment;
class Rating;
class Studio;

class Movie
{
public:
	int MovieId;
	string MovieTitle;
	string MovieGenre;
	string MovieReleaseYear;
	string MovieLanguage;
	float MovieRating;
	string MovieCensorship;
	string MovieStory;
	unsigned int MovieBudget;
	Studio *studio;
	list <Comment*> comments;
	list <Rating*> ratings;
	int studio_id;


	Movie(int MovieId, string MovieTitle, string MovieGenre, string MovieReleaseYear, string MovieLanguage, float MovieRating, string MovieCensorship, string MovieStory, unsigned int MovieBudget, int studio_id);
    Movie();
	~Movie();

};

