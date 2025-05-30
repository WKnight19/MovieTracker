#include <iostream>
#include <fstream>
#include <sstream>
#include "Movies.h"


/************************************************************
  Constructors and Destructors
*************************************************************/

Movies::Movies() {
  vector<Movie>* newVec = new vector<Movie>;
  movies_list = *newVec;
}

vector<Movie> Movies::get_movies_list(){
  return movies_list;
}

void Movies::display_movies(){
  for (size_t i = 0; i < movies_list.size(); i++){
    (movies_list.at(i)).DisplayMovie(i);
  }
  cout << endl
       << endl;
}

void Movies::add_movie(string name, string rating, int watch_count){
  if (unable_to_add(name) == true)
  {
  Movie new_movie{name, rating, watch_count};
  movies_list.push_back(new_movie);
  }

}

void Movies::watched_movie(string name){
  if (does_not_exist(name) == false){
  for (size_t i = 0; i < movies_list.size(); i++)
  {
    if (name == (movies_list.at(i)).name){
      (movies_list.at(i)).watchMovie();
      return;
    }
  }
}
  
}


void Movies::display_total_watch_count(){
  cout << "Total Watch Count: " << Movie::get_total_watch_count() << endl;
  
}

bool Movies::unable_to_add(string name){
  bool check = check_if_exists(name);

  if (check==true){
    cout << "\nThe Movie " << name << " already exists, so it cannot be added\n" << endl;
    return false;
  }
  else {
    cout << "\nThe Movie " << name << " was added!" << endl;
    return true;
  }
}

bool Movies::does_not_exist(string name){
  bool check = check_if_exists(name);

  if (check == true)
  {
cout << name << " found in our database\n" << endl;

    return false;
  }
  else
  {
cout << name << " does not exist in our database yet, sorry.\n" << endl;

    return true;
  }
}


bool Movies::check_if_exists(string name){
  for (size_t i = 0; i < movies_list.size(); i++)
  {
    if (name == (movies_list.at(i)).name)
    {
      return true;
    }
  }

  return false;
}


void Movies::write_movie_to_file(ofstream& outFile, string userid){
  for(const auto& var : movies_list) { // check every movie in list
      outFile << userid << "," << var.name << "," << var.rating << "," << var.watch_count << endl;
  }
}