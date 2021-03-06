#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Comment.h"
#include "Rating.h"


using namespace std;

class Comment;
class Rating;

class User
{
public:
	int UserId;
    string UserType;
	string UserName;
	string UserPassword;
	string UserEmail;
	list <Comment*> comments;
	list <Rating*> ratings;

    User(int UserId, string UserType, string UserName, string UserPassword, string UserEmail);
    User();
	~User();

};

