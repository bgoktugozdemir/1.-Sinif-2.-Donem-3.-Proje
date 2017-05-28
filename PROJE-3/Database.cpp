#include "Database.h"

Database::Database()
{
}


Database::~Database()
{
}

Comment * Database::FindTheComment(int id)
{
	Comment * found = NULL;
	list<Comment*>::iterator i;
	for (i = Comments.begin(); i != Comments.end(); i++)
	{
		if ((*i)->CommentId == id)
		{
			found = *i;
			break;
		}
	}
	
	return found;
}

Movie * Database::FindTheMovie(int id)
{
	Movie * found = NULL;
	list<Movie*>::iterator i;
	for (i = Movies.begin(); i != Movies.end(); i++)
	{
		if ((*i)->MovieId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

Rating * Database::FindTheRating(int id)
{
	Rating * found = NULL;
	list<Rating*>::iterator i;
	for (i = Ratings.begin(); i != Ratings.end(); i++)
	{
		if ((*i)->RatingId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

Studio * Database::FindTheStudio(int id)
{
	Studio * found = NULL;
	list<Studio*>::iterator i;
	for (i = Studios.begin(); i != Studios.end(); i++)
	{
		if ((*i)->StudioId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

User * Database::FindTheUser(int id)
{
	User * found = NULL;
	list<User*>::iterator i;
	for (i = Users.begin(); i != Users.end(); i++)
	{
		if ((*i)->UserId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

void Database::FillLists()
{
	string directory = "db/";
	string commentPath = directory + "comment.txt";
	string moviePath = directory + "movie.txt";
	string ratingPath = directory + "rating.txt";
	string studioPath = directory + "studio.txt";
	string userPath = directory + "user.txt";
	
    FillLists(commentPath, moviePath, ratingPath, studioPath, userPath);
}

void Database::FillLists(string commentPath, string moviePath, string ratingPath, string studioPath, string userPath)
{
	ReadComment(commentPath);
    ReadMovie(moviePath);
    ReadRating(ratingPath);
    ReadStudio(studioPath);
    ReadUser(userPath);

    RelationCommentsHaveUsers();
    RelationRatingsHaveUsers();
    RelationMoviesHaveStudios();
    RelationCommentsHaveMovies();
    RelationRatingsHaveMovies();

}

bool Database::SaveFiles()
{
	string directory = "db/";
	string commentPath = directory + "comment.txt";
	string moviePath = directory + "movie.txt";
	string ratingPath = directory + "rating.txt";
	string studioPath = directory + "studio.txt";
	string userPath = directory + "user.txt";

	bool isSaved = SaveFiles(commentPath, moviePath, ratingPath, studioPath, userPath);
	return isSaved;
}

bool Database::SaveFiles(string commentPath, string moviePath, string ratingPath, string studioPath, string userPath)
{
	bool isSavedComment = SaveComment(commentPath);
	bool isSavedMovie = SaveMovie(moviePath);
	bool isSavedRating = SaveRating(ratingPath);
	bool isSavedStudio = SaveStudio(studioPath);
	bool isSavedUser = SaveUser(userPath);
	bool result = isSavedComment && isSavedMovie && isSavedRating && isSavedStudio && isSavedUser;

	return result;
}

void Database::ReadComment(string path)
{
	ifstream file;
	file.open(path);

	if (file.is_open())
	{
		char line[1000];
		file.getline(line, 1000);

		int CommentId;
		time_t CommentTime;
		string comment;
		int movie_id;
		int user_id;

		bool isFirstRow = true;
		while (!file.eof())
		{
			if (isFirstRow)
			{
				isFirstRow = false;
				continue;
			}
			file >> CommentId >> CommentTime >> comment >> movie_id >> user_id;
			Comment * addThis = new Comment(CommentId, CommentTime, comment, movie_id, user_id);
			Comments.push_back(addThis);
			CommentsHaveMovies.push_back(movie_id);
			CommentsHaveUsers.push_back(user_id);
		}
		file.close();
	}
}

void Database::ReadMovie(string path)
{
	ifstream file;
	file.open(path);

	if (file.is_open())
	{
		char line[1000];
		file.getline(line, 1000);

		int MovieId;
		string MovieTitle;
		string MovieGenre;
		string MovieReleaseYear;
		string MovieLanguage;
		float MovieRating;
		string MovieCensorship;
		string MovieStory;
		unsigned int MovieBudget;
		int studio_id;


		bool isFirstRow = true;
		while (!file.eof())
		{
			if (isFirstRow)
			{
				isFirstRow = false;
				continue;
			}
			file >> MovieId >> MovieTitle >> MovieGenre >> MovieReleaseYear >> MovieLanguage >> MovieRating >> MovieCensorship >> MovieStory >> MovieBudget >> studio_id;
			Movie * addThis = new Movie(MovieId, MovieTitle, MovieGenre, MovieReleaseYear, MovieLanguage, MovieRating, MovieCensorship, MovieStory, MovieBudget,studio_id);
			Movies.push_back(addThis);
            MoviesHaveStudios.push_back(studio_id);
		}
		file.close();
	}
}

void Database::ReadRating(string path)
{
	ifstream file;
	file.open(path);

	if (file.is_open())
	{
		char line[1000];
		file.getline(line, 1000);

		int RatingId;
		float rating;
		int user_id;
		int movie_id;

		bool isFirstRow = true;
		while (!file.eof())
		{
			if (isFirstRow)
			{
				isFirstRow = false;
				continue;
			}
			file >> RatingId >> rating >> user_id >> movie_id;
			Rating * addThis = new Rating(RatingId, rating, user_id, movie_id);
			Ratings.push_back(addThis);


			RatingsHaveUsers.push_back(user_id);
			RatingsHaveMovies.push_back(movie_id);
		}
		file.close();
	}
}

void Database::ReadStudio(string path)
{
	ifstream file;
	file.open(path);

	if (file.is_open())
	{
		char line[1000];
		file.getline(line, 1000);

		int StudioId;
		string StudioName;
		string StudioInfo;

		bool isFirstRow = true;
		while (!file.eof())
		{
			if (isFirstRow)
			{
				isFirstRow = false;
				continue;
			}
			file >> StudioId >> StudioName >> StudioInfo;
			Studio * addThis = new Studio(StudioId, StudioName, StudioInfo);
			Studios.push_back(addThis);
		}
		file.close();
	}
}

void Database::ReadUser(string path)
{
	ifstream file;
	file.open(path);

	if (file.is_open())
	{
		char line[1000];
		file.getline(line, 1000);

		int UserId;
        string UserType="Member";
		string UserName;
		string UserPassword;
		string UserEmail;
		
		bool isFirstRow = true;
		while (!file.eof())
		{
			if (isFirstRow)
			{
				isFirstRow = false;
				continue;
			}
            file >> UserId >> UserType >> UserName >> UserPassword >> UserEmail;
            User * addThis = new User(UserId, UserType, UserName, UserPassword, UserEmail);
			Users.push_back(addThis);
		}
		file.close();
	}
}

bool Database::SaveComment(string path)
{
	ofstream file;
	file.open(path);
	if (file.is_open())
	{
		file << "Comment_Id	Comment_Time	Comment	Movie_Id	User_Id";
		string tab = "	";
		list<Comment*>::iterator i;
		for (i = Comments.begin(); i != Comments.end(); i++)
		{
			int CommentId = (*i)->CommentId;
			time_t CommentTime = (*i)->CommentTime;
			string comment = (*i)->comment;
			int movie_id = (*i)->movie_id;
			int user_id = (*i)->user_id;

			file << endl << CommentId << tab << CommentTime << tab << comment << tab << movie_id << tab << user_id;
		}
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::SaveMovie(string path)
{
	ofstream file;
	file.open(path);
	if (file.is_open())
	{
		file << "Movie_Id	Movie_Title	Movie_Genre	Movie_Release_Year	Movie_Language	Movie_Rating	Movie_Censorship	Movie_Story	Movie_Budget	Studio_Id";
		string tab = "	";
		list<Movie*>::iterator i;
		for (i = Movies.begin(); i != Movies.end(); i++)
		{
			int MovieId = (*i)->MovieId;
			string MovieTitle = (*i)->MovieTitle;
			string MovieGenre = (*i)->MovieGenre;
			string MovieReleaseYear = (*i)->MovieReleaseYear;
			string MovieLanguage = (*i)->MovieLanguage;
			float MovieRating = (*i)->MovieRating;
			string MovieCensorship = (*i)->MovieCensorship;
			string MovieStory = (*i)->MovieStory;
			unsigned int MovieBudget = (*i)->MovieBudget;
			int studio_id = (*i)->studio_id;
			file << endl << MovieId << tab << MovieTitle << tab << MovieGenre << tab << MovieReleaseYear << tab << MovieLanguage << tab << MovieRating << tab << MovieCensorship << tab << MovieStory << tab << MovieBudget << tab << studio_id;
		}
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::SaveRating(string path)
{
	ofstream file;
	file.open(path);
	if (file.is_open())
	{
file << "Rating_Id	Rating	User_Id	Movie_Id";
string tab = "	";
list<Rating*>::iterator i;
for (i = Ratings.begin(); i != Ratings.end(); i++)
{
	int RatingId = (*i)->RatingId;
	float rating = (*i)->rating;
	int user_id = (*i)->user_id;
	int movie_id = (*i)->movie_id;

	file << endl << RatingId << tab << rating << tab << user_id << tab << movie_id;
}
file.close();
return true;
	}
	else
	{
		return false;
	}
}

bool Database::SaveStudio(string path)
{
	ofstream file;
	file.open(path);
	if (file.is_open())
	{
		file << "Studio_Id	StudioName	StudioInfo";
		string tab = "	";
		list<Studio*>::iterator i;
		for (i = Studios.begin(); i != Studios.end(); i++)
		{
            int StudioId = (*i)->StudioId;
            string StudioName = (*i)->StudioName;
            string StudioInfo = (*i)->StudioInfo;

			file << endl << StudioId << tab << StudioName << tab << StudioInfo;
		}
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::SaveUser(string path)
{
	ofstream file;
	file.open(path);
	if (file.is_open())
	{
		file << "User_Id	User_Type	User_Name	User_Password	User_Email";
		string tab = "	";
		list<User*>::iterator i;
		for (i = Users.begin(); i != Users.end(); i++)
		{
			int UserId = (*i)->UserId;
            string UserType = (*i)->UserType;
			string UserName = (*i)->UserName;
			string UserPassword = (*i)->UserPassword;
			string UserEmail = (*i)->UserEmail;

			file << endl << UserId << tab << UserType << tab << UserName << tab << UserPassword << tab << UserEmail;
		}
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

void Database::RelationCommentsHaveUsers()
{
	list<int>::iterator i;
	for (i = CommentsHaveUsers.begin(); i != CommentsHaveUsers.end(); i++)
	{
		User * user = FindTheUser(*i);

		if (user != NULL)
		{
			list<Comment*>::iterator j;
			for (j = Comments.begin(); j != Comments.end(); j++)
			{
				if ((*j)->user_id == user->UserId)
				{
					(*j)->UserId = user;
				}
				user->comments.push_back(*j);
			}
		}
	}
}

void Database::RelationRatingsHaveUsers()
{
	list<int>::iterator i;
	for (i = RatingsHaveUsers.begin(); i != RatingsHaveUsers.end(); i++)
	{
		User * user = FindTheUser(*i);

		if (user != NULL)
		{
			list<Rating*>::iterator j;
			for (j = Ratings.begin(); j != Ratings.end(); j++)
			{
				if ((*j)->user_id == user->UserId)
				{
					(*j)->UserId = user; //UserId mi user mý?(Eþitlikten öncesi)
				}
				user->ratings.push_back(*j);
			}
		}
	}
}

void Database::RelationMoviesHaveStudios()
{
	list<int>::iterator i;
	for (i = MoviesHaveStudios.begin(); i != MoviesHaveStudios.end(); i++)
	{
		Studio * studio = FindTheStudio(*i);

		if (studio != NULL)
		{
			list<Movie*>::iterator j;
			for (j = Movies.begin(); j != Movies.end(); j++)
			{
				if ((*j)->studio_id == studio->StudioId)
				{
					(*j)->studio = studio;
				}
				studio->movies.push_back(*j);
			}
		}
	}
}

void Database::RelationCommentsHaveMovies()
{
	list<int>::iterator i;
	for (i = CommentsHaveMovies.begin(); i != CommentsHaveMovies.end(); i++)
	{
		Movie * movie = FindTheMovie(*i);

		if (movie != NULL)
		{
			list<Comment*>::iterator j;
			for (j = Comments.begin(); j != Comments.end(); j++)
			{
				if ((*j)->movie_id == movie->MovieId)
				{
					(*j)->MovieId = movie;
				}
				movie->comments.push_back(*j);
			}
		}
	}
}

void Database::RelationRatingsHaveMovies()
{
	list<int>::iterator i;
	for (i = RatingsHaveMovies.begin(); i != RatingsHaveMovies.end(); i++)
	{
		Movie * movie = FindTheMovie(*i);

		if (movie != NULL)
		{
			list<Rating*>::iterator j;
			for (j = Ratings.begin(); j != Ratings.end(); j++)
			{
				if ((*j)->movie_id == movie->MovieId)
				{
					(*j)->MovieId = movie;
				}
				movie->ratings.push_back(*j);
			}
		}
	}
}

void Database::RemoveRelationCommentsHaveUsers(User * deleteThis)
{
    //CommentsHaveUsers.erase(find(CommentsHaveUsers.begin(), CommentsHaveUsers.end(), deleteThis->UserId));
	CommentsHaveUsers.remove(deleteThis->UserId);
}

void Database::RemoveRelationRatingsHaveUsers(User * deleteThis)
{
	//RatingsHaveUsers.erase(find(RatingsHaveUsers.begin(), RatingsHaveUsers.end(), deleteThis->UserId));
	RatingsHaveUsers.remove(deleteThis->UserId);
}

void Database::RemoveRelationMoviesHaveStudios(Studio * deleteThis)
{
	//MoviesHaveStudios.erase(find(MoviesHaveStudios.begin(), MoviesHaveStudios.end(), deleteThis->StudioId));
	MoviesHaveStudios.remove(deleteThis->StudioId);
}

void Database::RemoveRelationCommentsHaveMovies(Movie * deleteThis)
{
	//CommentsHaveMovies.erase(find(CommentsHaveMovies.begin(), CommentsHaveMovies.end(), deleteThis->MovieId));
	CommentsHaveMovies.remove(deleteThis->MovieId);
}

void Database::RemoveRelationRatingsHaveMovies(Movie * deleteThis)
{
	//RatingsHaveMovies.erase(find(RatingsHaveMovies.begin(), RatingsHaveMovies.end(), deleteThis->MovieId));
	RatingsHaveMovies.remove(deleteThis->MovieId);
}
