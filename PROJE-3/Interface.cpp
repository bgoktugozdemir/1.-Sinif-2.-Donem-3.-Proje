#include "Interface.h"

Interface::Interface()
{
}

Interface::Interface(Database * data, Background * background)
{
	Datas = data;
	Backgrounds = background;
}

Interface::~Interface()
{
}

void Interface::Start()
{
	while (true)
	{
		system("CLS");
		MainMenu();
        char Selection = _getch();
        //char Selection;
        //cin >> Selection;
		switch (Selection)
		{
		case 'a':
			Comments();
			break;
		case 'b':
			Movies();
			break;
		case 'c':
			Ratings();
			break;
		case 'd':
			Studios();
			break;
		case 'e':
			Users();
			break;
		case '0':
			exit(0);
			break;
		default:
			Start();
			break;
		}
        system("CLS");
	}
}

void Interface::MainMenu()
{
    //char yazi[60];
    //sprintf_s(yazi, "title Welcome back to Movie System (v%.2f)", Version);
    //system(yazi);
	cout << "Main Menu" << endl
		 << "a - Comments Menu" << endl
		 << "b - Movies Menu" << endl
		 << "c - Ratings Menu" << endl
		 << "d - Studios Menu" << endl
		 << "e - Users Menu" << endl
	 	 << "0 - Exit" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options: ";
}

void Interface::Comments()
{
	cout << "Comment Menu" << endl;

	ListComments();
}

void Interface::Movies()
{
	cout << "Movies Menu" << endl;
		 
	ListMovies();
}

void Interface::Ratings()
{
	cout << "Rating Menu" << endl;
		
	ListRatings();
}

void Interface::Studios()
{
	cout << "Studio Menu" << endl;
	
	ListStudios();
}

void Interface::Users()
{
	cout << "User Menu" << endl;

	ListUsers();
}

void Interface::ListComments()				//EDÝTLERDEKÝ SORUNU ÇÖZ
{
	system("CLS");
	ShowComments(Datas->Comments);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit Comment " << endl
		<< "2 - Add Comment " << endl
		<< "3 - Delete Comment " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int CommentId;
		cout << "Please enter the comment's id: ";
		cin >> CommentId;
		if (Backgrounds->ControlCommentId(CommentId) != false)
		{
			EditComments(Datas->FindTheComment(CommentId));  //DÜZELT
		}
		else
			cout << "This id->'" << CommentId << "' not found! " << endl;
			system("pause");
		break;
	case '2':
		AddComments();
		break;
	case '3':
		DeleteComments();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditComments(Comment * comment)
{
	//ID
	cout << "Comment's Id: " << comment->CommentId << endl
		 << "Please enter a new id: ";

	int newCommentId = -1;
	cin >> newCommentId;
	if (Backgrounds->ControlCommentId(newCommentId) != false)
	{
		cout << "We already have this id! ";
		system("pause");
		Start();
	}
	//TIME


	//MOVIE_ID
	cout << "Comment's Movie Id: " << comment->movie_id <<endl
		 << "Please enter a new movie id: ";
	int newmovie_id = -1;
	cin >> newmovie_id;

	//USER_ID
	cout << "Comment's User Id: " << comment->user_id << endl
		 << "Please enter a new user id: ";
	int newuser_id = -1;
	cin >> newuser_id;

	//COMMENT
	cout << "Comment's Comment: " << comment->comment << endl
		 << "Please enter a new comment: ";
	string newcomment = "";
	cin >> newcomment;

	comment->CommentId = newCommentId;
	comment->movie_id = newmovie_id;
	comment->user_id = newuser_id;
	comment->comment = newcomment;

	Datas->SaveFiles();
}

void Interface::AddComments()										 //CommentTime'a çözüm bul!++++++
{
	cout << "You will add a new comment..." << endl;
	Comment * newComment = new Comment(-1, time(NULL), "", -1, -1);

	EditComments(newComment);

	Datas->Comments.push_back(newComment);
	Datas->SaveFiles();
}

void Interface::DeleteComments()
{
	cout << "Please enter the comment's id -> ";
	int id;
	cin >> id;
	if (id == 0)
	{
		Start();
	}
	else
	{
		if (Backgrounds->RemoveTheComment(id) == false)
		{
			cout << "Operation failed!. Please, make sure the comment's id is correct. Please try again. " << endl;
			DeleteComments();
		}
		else
		{
			cout << id << "Operation successful!" << endl;

			Datas->SaveFiles();
		}
	}
}

void Interface::ListMovies()
{
	system("CLS");

	ShowMovies(Datas->Movies);

	//Screen
	cout << endl
		 << "-----------------------------------" << endl
		 << "1 - Edit Movie " << endl
		 << "2 - Add Movie " << endl
		 << "3 - Delete Movie " << endl << endl
	 	 << "0 - Return to Main Menu" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int MovieId;
		cout << "Please enter the movie's id: ";
		cin >> MovieId;
		if (Backgrounds->ControlMovieId(MovieId) != false)
		{
		EditMovies(Datas->FindTheMovie(MovieId));
		}
		else
		{
			cout << "This id->'" << MovieId << "' not found! " << endl;
			system("pause");
		}
		break;
	case '2':
		AddMovies();
		break;
	case '3':
		DeleteMovies();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditMovies(Movie * movie)
{
	//ID
	cout << "Movie's Id: " << movie->MovieId << endl
		 << "Please enter a new id: ";
	int newMovieId = -1;
	cin >> newMovieId;

	if (Backgrounds->ControlMovieId(newMovieId) != false)
	{
		cout << "We already have this id! ";
		system("pause");
		Start();
	}

	//TITLE
	cout << "Movie's Title: " << movie->MovieTitle << endl
		 << "Please enter a new title: ";
	string newMovieTitle = "";
	cin >> newMovieTitle;

	//GENRE
	cout << "Movie's Genres: " << movie->MovieGenre << endl
		 << "Please enter new genres: ";
	string newMovieGenre = "";
	cin >> newMovieGenre;

	//RELEASE YEAR
	cout << "Movie's Release Year: " << movie->MovieReleaseYear << endl
		 << "Please enter a new release year: ";
	string newMovieReleaseYear = "";
	cin >> newMovieReleaseYear;

	//LANGUAGE
	cout << "Movie's Language: " << movie->MovieLanguage << endl
		 << "Please enter a new language: ";
	string newMovieLanguage = "";
	cin >> newMovieLanguage;

	//RATING
	cout << "Movie's Rating: " << movie->MovieRating << endl
		 << "Please enter a new rating: ";
	float newMovieRating = -1;
	cin >> newMovieRating;

	//CENSORSHIP
	cout << "Movie's Censorship: " << movie->MovieCensorship << endl
		 << "Please enter a new cencorship: ";
	string newMovieCensorship = "";
	cin >> newMovieCensorship;

	//STORY
	cout << "Movie's Story: " << movie->MovieStory << endl
		 << "Please enter a new story: ";
	string newMovieStory = "";
	cin >> newMovieStory;

	//BUDGET
	cout << "Movie's Budget: " << movie->MovieBudget << endl
		 << "Please enter a new budget: ";
	unsigned int newMovieBudget = 1;
	cin >> newMovieId;

	//STORY
	cout << "Movie's Studio Id: " << movie->studio_id << endl
		 << "Please enter a new studio id: ";
	int newstudio_id = 1;
	cin >> newstudio_id;
	
	//Changes
	movie->MovieId = newMovieId;
	movie->MovieTitle = newMovieTitle;
	movie->MovieGenre = newMovieGenre;
	movie->MovieReleaseYear = newMovieReleaseYear;
	movie->MovieLanguage = newMovieLanguage;
	movie->MovieRating = newMovieRating;
	movie->MovieCensorship = newMovieCensorship;
	movie->MovieStory = newMovieStory;
	movie->MovieBudget = newMovieBudget;
	movie->studio_id = newstudio_id;

	Datas->SaveFiles();
}

void Interface::AddMovies()
{
	cout << "You will add a new movie..." << endl;

	Movie *newMovie = new Movie(-1, "", "", "", "", -1, "", "", 1, -1);

	EditMovies(newMovie);

	Datas->Movies.push_back(newMovie);

	Datas->SaveFiles();
}

void Interface::DeleteMovies()						//ÖðrenciÝþleri Classýna alternatif bul. 
{
	cout << "Please enter the movie's id -> ";
	int id;
	cin >> id;
	if (id = 0)
	{
		Start();
	}
	else
	{

		if (Backgrounds->RemoveTheMovie(id) == false)
		{
			cout << "Operation failed! Please, make sure the movie's id is correct. " << endl;
			DeleteMovies();
		}
		else
		{
			cout << id << "Operation successful!" << endl;

			Datas->SaveFiles();
		}
	}
}

void Interface::ListRatings()
{
	system("CLS");

	ShowRatings(Datas->Ratings);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit Rating " << endl
		<< "2 - Add Rating " << endl
		<< "3 - Delete Rating " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int RatingId;
		cout << "Please enter the rating's id: ";
		cin >> RatingId;
		if (Backgrounds->ControlRatingId(RatingId) != false)
		{
		EditRatings(Datas->FindTheRating(RatingId));
		}
		else
		{
			cout << "This id->'" << RatingId << "' not found! " << endl;
			system("pause");
		}
		break;
	case '2':
		AddRatings();
		break;
	case '3':
		DeleteRatings();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditRatings(Rating * rating)
{
	//ID
	cout << "Rating's Id: " << rating->RatingId << endl
		 << "Please enter a new id: ";
	int newRatingId = -1;
	cin >> newRatingId;

	if (Backgrounds->ControlRatingId(newRatingId) != false)
	{
		cout << "We already have this id! ";
		system("pause");
		system("cls");
		Start();
	}

	//RATING
	cout << "Rating's Rating: " << rating->rating << endl
		 << "Please enter a new rating: ";
	float newrating = -1;
	cin >> newrating;

	//USER ID
	cout << "Rating's User Id: " << rating->user_id << endl
		<< "Please enter a new user id: ";
	int newuser_id = 1;
	cin >> newuser_id;

	//MOVIE ID
	cout << "Rating's Movie Id: " << rating->movie_id << endl
		<< "Please enter a new movie id: ";
	int newmovie_id = 1;
	cin >> newmovie_id;

	//CHANGES

	rating->RatingId = newRatingId;
	rating->rating = newrating;
	rating->user_id = newuser_id;
	rating->movie_id = newmovie_id;

	Datas->SaveFiles();
}

void Interface::AddRatings()
{
	cout << "You will add a new rating..." << endl;

	Rating *newRating = new Rating(-1, -1, -1, -1);

	EditRatings(newRating);

	Datas->Ratings.push_back(newRating);

	Datas->SaveFiles();
}

void Interface::DeleteRatings()
{
	cout << "Please enter the rating's id -> ";
	int id;
	cin >> id;
	if (id == 0)
	{
		Start();
	}
	else
	{
		if (Backgrounds->RemoveTheRating(id) == false)
		{
			cout << "Operation failed! Please, make sure the rating's id is correct. " << endl;
			DeleteRatings();
		}
		else
		{
			cout << id << "Operation successful!" << endl;

			Datas->SaveFiles();
		}
	}
}

void Interface::ListStudios()
{
	system("CLS");

	ShowStudios(Datas->Studios);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit Studio " << endl
		<< "2 - Add Studio " << endl
		<< "3 - Delete Studio " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int StudioId;
		cout << "Please enter the studio's id: ";
		cin >> StudioId;
		if (Backgrounds->ControlStudioId(StudioId) != false)
		{
		EditStudios(Datas->FindTheStudio(StudioId));
		}
		else
		{
			cout << "This id->'" << StudioId << "' not found! " << endl;
			system("pause");
		}
		break;
	case '2':
		AddStudios();
		break;
	case '3':
		DeleteStudios();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditStudios(Studio * studio)
{
	//ID
	cout << "Studio's Id: " << studio->StudioId << endl
		 << "Please enter a new id: ";
	int newStudioId = -1;
	cin >> newStudioId;

	if (Backgrounds->ControlStudioId(newStudioId) != false)
	{
		cout << "We already have this id! ";
		system("pause");
		system("cls");
		Start();
	}

	//NAME
	cout << "Studio's Name: " << studio->StudioName << endl
		 << "Please enter a new name: ";
	string newStudioName = "";
	cin >> newStudioName;

	//INFO
	cout << "Studio's Info: " << studio->StudioInfo << endl
		<< "Please enter a new info: ";
	string newStudioInfo = "";
	cin >> newStudioInfo;

	studio->StudioId = newStudioId;
	studio->StudioName = newStudioName;
	studio->StudioInfo = newStudioInfo;

	Datas->SaveFiles();
}

void Interface::AddStudios()
{
	cout << "You will add a new studio..." << endl;

	Studio *newStudio = new Studio(-1, "", "");

	EditStudios(newStudio);

	Datas->Studios.push_back(newStudio);

	Datas->SaveFiles();
}

void Interface::DeleteStudios()
{
	cout << "Please enter the studio's id -> ";
	int id;
	cin >> id;
	if (id == 0)
	{
		Start();
	}
	else
	{
		if (Backgrounds->RemoveTheStudio(id) == false)
		{
			cout << "Operation failed! Please, make sure the studio's id is correct. " << endl;
			DeleteStudios();
		}
		else
		{
			cout << id << "Operation successful!" << endl;

			Datas->SaveFiles();
		}
	}

}

void Interface::ListUsers()
{
	system("CLS");

	ShowUsers(Datas->Users);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit User " << endl
		<< "2 - Add User " << endl
		<< "3 - Delete User " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int UserId;
		cout << "Please enter the user's id: ";
		cin >> UserId;
		if (Backgrounds->ControlUserId(UserId) != false)
		{
		EditUsers(Datas->FindTheUser(UserId));
		}
		else
		{
			cout << "This id->'" << UserId << "' not found! " << endl;
			system("pause");
		}
		break;
	case '2':
		AddUsers();
		break;
	case '3':
		DeleteUsers();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditUsers(User * user)
{
	//ID
	cout << "User's Id: " << user->UserId << endl
		 << "Please enter a new id: ";
	int newUserId = -1;
	cin >> newUserId;

	if (Backgrounds->ControlUserId(newUserId) != false)
	{
		cout << "We already have this id! ";
		system("pause");
		system("cls");
		Start();
	}

	//USERTYPE
	cout << "User's Type: " << user->UserType << endl;
	userType newUserType = Member;
	cout << "a - Administrator" << endl << "b - Writer" << endl <<"c - Movie Critic" << endl << "d - Member" << endl << "Please select a user type: ";
	char Selection = _getch();
	switch (Selection)
	{
	case 'a':
		newUserType = Administrator;
		break;

	case 'b':
		newUserType = Writer;
		break;

	case 'c':
		newUserType = MovieCritic;
		break;

	case 'd':
		newUserType = Member;
		break;

	default:
		newUserType = Member;
		break;
	}

	cout << endl;

	//NAME
	cout << "User's Name: " << user->UserName << endl
		 << "Please enter a new name: ";
	string newUserName = "";
	cin >> newUserName;

	//PASSWORD
	cout << "User's Password: " << user->UserPassword << endl
		 << "Please enter a new password: ";
	string newUserPassword = "";
	cin >> newUserPassword;

	//MAIL
	cout << "User's Mail: " << user->UserEmail << endl
		 << "Please enter a new email: ";
	string newUserEmail = "";
	cin >> newUserEmail;

	//CHANGES
	user->UserId = newUserId;
	user->UserType = newUserType;
	user->UserName = newUserName;
	user->UserPassword = newUserPassword;
	user->UserEmail = newUserEmail;

	Datas->SaveFiles();
}

void Interface::AddUsers()
{
	cout << "You will add a new user..." << endl;

	User *newUser = new User(-1, Member, "", "", "");

	EditUsers(newUser);

	Datas->Users.push_back(newUser);

	Datas->SaveFiles();
}

void Interface::DeleteUsers()
{
	cout << "Please enter the user's id -> ";
	int id;
	cin >> id;
	if (id == 0)
	{
		Start();
	}
	else
	{
		if (Backgrounds->RemoveTheUser(id) == false)
		{
			cout << "Operation failed! Please, make sure the user's id is correct. " << endl;
			DeleteUsers();
		}
		else
		{
			cout << id << "Operation successful!" << endl;

			Datas->SaveFiles();
		}
	}
}

void Interface::ShowComments(list<Comment*>& list)
{
	//CommentId >> CommentTime >> comment >> movie_id >> user_id;
	cout << "Comment_Id\tComment_Time\tComment\tmovie_id\tuser_id" << endl;
	//list<Comment*>::iterator i;
	for (auto i=list.begin(); i != list.end(); i++)
	{
		cout << (*i)->CommentId
			 << "	"
			 << (*i)->CommentTime
			 << "	"
			 << (*i)->comment
			 << "	"
			 << (*i)->movie_id
			 << "	"
			 << (*i)->user_id
			 << endl;
	}
	if (list.size()<1)
	{
		cout << "404: Not Found!" << endl;
	}
}

void Interface::ShowMovies(list<Movie*>& list)
{
	//MovieId >> MovieTitle >> MovieGenre >> MovieReleaseYear >> MovieLanguage >> MovieRating >> MovieCensorship >> MovieStory >> MovieBudget >> studio_id;
	cout << "Movie_Id\tMovie_Title\tMovie_Genre\tRelease_Year\tMovie_Language\tRating\tCensorship\tMovie_Story\tMovie_Budget\tStudio_Id" << endl;
	for (auto i = list.begin(); i != list.end(); i++)
	{
		cout << (*i)->MovieId
			 << "	"
			 << (*i)->MovieTitle
			 << "	"
			 << (*i)->MovieGenre
			 << "	"
			 << (*i)->MovieReleaseYear
			 << "	"
			 << (*i)->MovieLanguage
			 << "	"
			 << (*i)->MovieRating
			 << "	"
			 << (*i)->MovieCensorship
			 << "	"
			 << (*i)->MovieStory
			 << "	"
			 << (*i)->MovieBudget
			 << "	"
			 << (*i)->studio_id
			 << endl;
	}
	if (list.size()<1)
	{
		cout << "404: Not Found!" << endl;
	}
}

void Interface::ShowRatings(list<Rating*> &list)
{
	//RatingId >> rating >> user_id >> movie_id;
	cout << "Rating_Id\tRating\tUser_Id\tMovie_Id" << endl;
	for (auto i = list.begin(); i != list.end(); i++)
	{
		cout << (*i)->RatingId
			 << "	"
			 << (*i)->rating
			 << "	"
			 << (*i)->user_id
			 << "	"
			 << (*i)->movie_id
			 << endl;
	}
	if (list.size()<1)
	{
		cout << "404: Not Found!" << endl;
	}

}

void Interface::ShowStudios(list<Studio*>& list)
{
	//StudioId >> StudioName >> StudioInfo
	cout << "Studio_Id\tStudio_Name\tStudio_Info" << endl;
	for (auto i = list.begin(); i != list.end(); i++)
	{
		cout << (*i)->StudioId
			 << "	"
			 << (*i)->StudioName
			 << "	"
			 << (*i)->StudioInfo
			 << endl;
	}
	if (list.size()<1)
	{
		cout << "404: Not Found!" << endl;
	}
}

void Interface::ShowUsers(list<User*>& list)
{
	//UserId >> usertype_id >> UserName >> UserPassword >> UserEmail
	cout << "User_Id\tUserType\tUser_Name\tUser_Password\tUser_Email" << endl;
	for (auto i = list.begin(); i != list.end(); i++)
	{
		cout << (*i)->UserId
			 << "	"
			 << (*i)->UserType
			 << "	"
			 << (*i)->UserName
			 << "	"
			 << (*i)->UserPassword
			 << "	"
			 << (*i)->UserEmail
			 << endl;
	}
}
