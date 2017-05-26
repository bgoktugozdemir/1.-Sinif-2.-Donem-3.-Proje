#include "User.h"

User::User(int UserId, userType UserType, string UserName, string UserPassword, string UserEmail)
{
	this->UserId = UserId;
	this->UserType = UserType;
	this->UserName = UserName;
	this->UserPassword = UserPassword;
	this->UserEmail = UserEmail;
}

User::User()
{
    this->UserId = 0;
	this->UserType = Member;
	this->UserName = "";
	this->UserPassword = "";
	this->UserEmail = "";
}

User::~User()
{
}
