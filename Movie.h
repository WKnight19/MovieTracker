#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

using namespace std;
class Movies;

class Movie
{
  friend Movies;

private:
  string name;
  string rating;
  int watch_count;
  static int total_watch_count;

public:

/************************************************************
  Constructors and Destructors
*************************************************************/
  Movie(string name_arg = "None", string rating_arg = "NR", int watch_count_arg = 1);
  ~Movie();

  
  /************************************************************
    Getters and Setters
  *************************************************************/
  void set_name(string name);
  string get_name();
  void set_rating(string rating);
  string get_rating();
  int get_watch_count();
  void increment_watch_count();

  /************************************************************
    Extended Movie Class Functionality:
    - Display Movie
  *************************************************************/
  void DisplayMovie(int ct = -1); // Displays the movie object
  void watchMovie(int n = 1);


  /************************************************************
    Static Methods that do not need an instance to be accessed
  *************************************************************/
  static int get_total_watch_count();
};




#endif