#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Movie.h"
#include "User.h"



using namespace std;
class User;
class Movie;
class Rating
{
public:
	int RatingId;
	User *UserId;
	Movie* MovieId;
	float rating;
	int user_id;
	int movie_id;

	Rating(int RatingId, float rating, int user_id, int movie_id);
    Rating();
	~Rating();

};

