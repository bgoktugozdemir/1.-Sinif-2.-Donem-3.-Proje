#pragma once
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <time.h>
#include "User.h"
#include "Movie.h"




using namespace std;

class Comment
{
public:
	int CommentId;
	time_t CommentTime;
	User* UserId;
	Movie* MovieId;
	string comment;
	int movie_id;
	int user_id;

    Comment();
	Comment(int CommentId, time_t CommentTime, string comment, int movie_id, int user_id);
	~Comment();
};


