#include "Comment.h"


Comment::Comment(int CommentId, time_t CommentTime, string comment, int movie_id, int user_id)
{
	this->CommentId = CommentId;
	this->CommentTime = CommentTime;
	this->comment = comment;
	this->movie_id = movie_id;
	this->user_id = user_id;
}

Comment::Comment()
{
    this->CommentId = 0;
	this->CommentTime = NULL;
	this->comment = "";
}


Comment::~Comment()
{
}
