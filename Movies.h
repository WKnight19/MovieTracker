#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <iostream>
#include <vector>
#include <string>
#include "Movie.h"

using namespace std;

/************************************************************
  This class has access to private members of movie, however only this class interacts with main, encapsulating Movie

  This class stores the vector of movies
*************************************************************/
class Movies
{
private:
  vector<Movie> movies_list;
public:

/************************************************************
  These are the constructors and destructors
*************************************************************/
  Movies();

  /************************************************************
    These are the core functions of the class
    - Display the movies
    - add a movie to the list
    - indicate that you have watched a movie
  *************************************************************/
  void display_movies();
  void add_movie(string name = "None", string rating = "NR");
  void watched_movie(string name);


  
  /************************************************************
    These are the error message methods for failures to add to the vector and failure to find the movie in the vector
  *************************************************************/
  bool unable_to_add(string name);
  bool does_not_exist(string name);

  bool check_if_exists(string name);

  void display_total_watch_count();
};

#endif