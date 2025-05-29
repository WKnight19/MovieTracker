#include <iostream>
#include "Movie.h"

int Movie::total_watch_count{0};


/************************************************************
  Delegated Movie Constructor, Provides Three Parameters for Default Arguments and displays message when a movie is added
*************************************************************/
Movie::Movie(string name_arg, string rating_arg, int watch_count_arg) : name{name_arg}, rating{rating_arg}, watch_count{watch_count_arg}{
  total_watch_count += watch_count;
  cout << "Movie Added\nName: " << name << "\nRating: " << rating << "\nTimes Watched: " << watch_count << endl << endl;
}

Movie::~Movie() {
}



/************************************************************
  Getters and Setters
*************************************************************/

void Movie::set_name(string name){
  this->name = name;
}
string Movie::get_name(){
  return this->name;
}

void Movie::set_rating(string rating){
  this->rating = rating;
}

string Movie::get_rating(){
  return this->rating;
}

int Movie::get_watch_count(){
  return this->watch_count;
}

void Movie::increment_watch_count(){
  watch_count++;
}


void Movie::DisplayMovie(int ct) {
  if(ct != -1) {
    cout << ct + 1 << ".) " << this->name << " (Rated " << this->rating << ") - Watched " << watch_count << " times" << endl;
  }
  else
  {
    cout << this->name << " (Rated " << this->rating << ") - Watched " << watch_count << " times" << endl;
  }
}

void Movie::watchMovie(int n) {
  this->watch_count += n;
  total_watch_count += n;
}


int Movie::get_total_watch_count() {
  return total_watch_count;
}