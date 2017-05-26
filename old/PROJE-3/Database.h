#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <time.h>
#include <ctime>
#include "Interface.h"
#include "Comment.h"
#include "Movie.h"
#include "Rating.h"
#include "Studio.h"
#include "User.h"

using namespace std;

class Database
{
public:
	Database();
	~Database();

	//Datas
	list<Comment*> Comments;
	list<Movie*> Movies;
	list<Rating*> Ratings;
	list<Studio*> Studios;
	list<User*> Users;

	Comment * FindTheComment(int id);
	Movie * FindTheMovie(int id);
	Rating * FindTheRating(int id);
	Studio * FindTheStudio(int id);
	User * FindTheUser(int id);

	void FillLists();
	void FillLists(string commentPath, string moviePath, string ratingPath, string studioPath, string userPath);

	bool SaveFiles();
	bool SaveFiles(string commentPath, string moviePath, string ratingPath, string studioPath, string userPath);

private:
	
	void ReadComment(string path);
	void ReadMovie(string path);
	void ReadRating(string path);
	void ReadStudio(string path);
	void ReadUser(string path);

	bool SaveComment(string path);
	bool SaveMovie(string path);
	bool SaveRating(string path);
	bool SaveStudio(string path);
	bool SaveUser(string path);

	list<int> CommentsHaveUsers;
	list<int> RatingsHaveUsers;
	list<int> MoviesHaveStudios;
	list<int> CommentsHaveMovies;
	list<int> RatingsHaveMovies;

	void RelationCommentsHaveUsers();
	void RelationRatingsHaveUsers();
	void RelationMoviesHaveStudios();
	void RelationCommentsHaveMovies();
	void RelationRatingsHaveMovies();
	
public:
	void RemoveRelationCommentsHaveUsers(User * deleteThis);
	void RemoveRelationRatingsHaveUsers(User * deleteThis);
	void RemoveRelationMoviesHaveStudios(Studio * deleteThis);
	void RemoveRelationCommentsHaveMovies(Movie * deleteThis);
	void RemoveRelationRatingsHaveMovies(Movie * deleteThis);
};
