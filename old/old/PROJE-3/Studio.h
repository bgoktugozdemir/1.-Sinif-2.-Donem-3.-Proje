#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Movie.h"


using namespace std;
class Movie;
class Studio
{
public:
	int StudioId;
	string StudioName;
	string StudioInfo;
	list <Movie*> movies;

	Studio(int StudioId, string StudioName, string StudioInfo);
    Studio();
	~Studio();

};

