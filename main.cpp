#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>


#include "Movies.h"



using namespace std;

/************************************************************
  - Create a movies object
  - Ask the movies object to add a movie
  - ask the movie object to increment the watched count
  - ask the movie object to display all of the movies

  - cannot add a movie that is already in the collection
  - cannot ask the count of a movie that doesn't exist

  - provide base implementation first, then add a menu-driven user interface
*************************************************************/
int main() {

  Movies movies;
  movies.add_movie("No Country For Old Men", "R");
  movies.add_movie("Mulholland Drive", "R");
  movies.add_movie("Eternal Sunshine", "PG-13");
  movies.add_movie("8 1/2", "PG");
  movies.add_movie("Paris, Texas", "R");
  movies.add_movie("Better Call Saul", "TV-M");
  movies.add_movie("Breaking Bad", "TV-M");
  movies.add_movie("GoodFellas", "NR");
  movies.add_movie("The Big Short", "R");
  movies.add_movie("The Room", "R");

  movies.display_total_watch_count();

  movies.watched_movie("GoodFellas");
  movies.watched_movie("Mulholland Drive");
  movies.watched_movie("Better Call Saul");
  movies.watched_movie("Better Call Saul");
  movies.watched_movie("GoodFellas");
  movies.watched_movie("Mulholland Drive");
  movies.watched_movie("Mulholland Drive");
  movies.watched_movie("Paris, Texas");
  movies.watched_movie("The Room");
  movies.watched_movie("The Room");
  movies.watched_movie("The Room");

  movies.display_movies();

  movies.add_movie("The Room");

  movies.display_total_watch_count();

  cout << endl;
  return 0;
}