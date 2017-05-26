#pragma once

#include <iostream>
#include <string>
#include <list>

#include "Database.h"

using namespace std;

class Comment;
class Movie;
class Rating;
class User;
class Studio;
class Database;

class Background
{
public:
    Background();
    ~Background();

    Background(Database *Datas);
    Database *Datas;

    bool SaveNewComment(Comment *newComment);
    bool SaveNewMovie(Movie *newMovie);
    bool SaveNewRating(Rating *newRating);
    bool SaveNewStudio(Studio *newStudio);
    bool SaveNewUser(User *newUser);

    bool RemoveTheComment(int CommentId);
    bool RemoveTheMovie(int MovieId);
    bool RemoveTheRating(int RatingId);
    bool RemoveTheStudio(int StudioId);
    bool RemoveTheUser(int UserId);

    Comment * ControlCommentId (int id);
    Movie * ControlMovieId(int id);
    Rating * ControlRatingId(int id);
    Studio * ControlStudioId(int id);
    User * ControlUserId(int id);
    /*
    //?L??K?LER
    bool SaveCommentInUser(Comment *comment, User *user);
    bool SaveCommentInMovie(Comment *comment, Movie *movie);
    bool SaveMovieInStudio(Movie *movie, Studio *studio);
    bool SaveRatingInUser(Rating *rating, User *user);
    bool SaveRatingInMovie(Rating *rating, Movie *movie);

    bool RemoveCommentInUser(Comment *comment, User *user);
    bool RemoveCommentInMovie(Comment *comment, Movie *movie);
    bool RemoveMovieInStudio(Movie *movie, Studio *studio);
    bool RemoveRatingInUser(Rating *rating, User *user);
    bool RemoveRatingInMovie(Rating *rating, Movie *movie);
    */
};

