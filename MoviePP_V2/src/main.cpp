#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <chrono>
#include <thread>
#include <sstream>
#include <limits>
#include <ios>

#include "data.h"
#include "Movies.h"

using namespace std;

// Load The Program
void Load();
// Start Menu and Sign-In
string start_menu();
// Header for Appliction
void header(const string &, Data &);
// Function to search for UserID in System
bool search_userid(const string &, Data &);
//  The Main Menu Functionality
void mainmenu(const string &, Data &);

Movies create_movies_list(const string &, Data &);
void display_menu(Movies &);
void addition_menu(Movies &);
void watch_menu(Movies &);
void proceed();

int main()
{

  /************************************************************
    This will be the menu implementation for the main program:
    - Will Open with the Introduction To The System
    - Ask For the UserID of the User
    - Display the Menu with the User ID On The Top Right and the Name of the Application on the top of the console, and the total movie watches on top

    Menu:
    - Display Movies Watched
    - Add Movie
    - Add a Watch to a Movie

  *************************************************************/
  Load();
  cout << "GoodBye!" << endl;
  return 0;
}

// Load The Program
void Load()
{

  /************************************************************
    FUNCTION:
      Single Point of Entry to program
      - initializes new data object
      - assigns the user id from the input to the start menu
      - if userid exists from search call, set the user id an open the program
  *************************************************************/
  Data newData;
  string user_id = start_menu();
  char choice{};
  if (search_userid(user_id, newData) == 1)
  {
    newData.set_user_id(user_id);
    system("clear");
    mainmenu(user_id, newData);
  }
  else
  {
    cout << "\n\nSorry, we couldn't find your userID in our system, would you like to create a new one? (Y/N)" << endl;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
      system("clear");
      newData.set_user_id(user_id);
      mainmenu(user_id, newData);
    }
    else
    {
      return;
    }
  }
}
// Start Menu and Sign-In
string start_menu()
{

  /************************************************************
    FUNCTION:
      - Authenticates the User
      - Returns the UserID
  *************************************************************/
  system("clear");
  string userid{};
  cout << "*****************************************************" << "\n\nWELCOME TO MOVIE++, BY FILM FANS FOR FILM FANS (est. 2025)\n\n"
       << "*****************************************************" << endl;

  cout << "\nPlease Enter Your UserID in the field below (case sensitive)\n"
       << "*****************************************************\n"
       << "Enter: ";
  cin >> userid;
  return userid;
}
// Header for Appliction
void header(const string &userid, Data &newData)
{
  system("clear");
  /************************************************************
    FUNCTION:
      Header for the program;
  *************************************************************/
  cout << "MOVIE++\t\t\t\tUser ID:  " << newData.get_user_id() << endl;
  cout << "********************************************************\n"
       << "Total Watch Count: " << Movie::get_total_watch_count() << endl
       << endl;
}
// Function to search for UserID in System
bool search_userid(const string &userid, Data &newData)
{
  bool check{false};
  for (auto &var : newData.get_csv_data())
  {
    if (userid == var.at(0))
    {
      check = true;
      return check;
    }
  }
  return check;
}
//  The Main Menu Functionality
void mainmenu(const string &userid, Data &newData)
{
  char choice{};
  Movies movie_list = create_movies_list(userid, newData);
  system("clear");
  cout << "You're in!\n"
       << endl;
  do
  {

    header(userid, newData);
    cout << "MAIN MENU:\nD - Display Movies Watched\nA - Add a Movie\nW - Add a Movie Watch\nS - Save Your Data\nQ - Quit\n\nEnter: ";
    cin >> choice;

    switch (choice)
    {
    case 'd':
    case 'D':
      // code
      header(userid, newData);
      display_menu(movie_list);
      break;
    case 'A':
    case 'a':
      // code
      header(userid, newData);
      addition_menu(movie_list);
      break;
    case 'W':
    case 'w':
      header(userid, newData);
      watch_menu(movie_list);
      break;
    case 'Q':
    case 'q':
      system("clear");
      cout << "Quitting the program and Saving Data...\n";
      newData.write_to_csv(movie_list);
      break;
    case 'S':
    case 's':
      header(userid, newData);
      cout << "\n\nSaving Data...\n";
      newData.write_to_csv(movie_list);
      proceed();
      break;
    default:
      cout << "invalid Input, please try again...\n\n";
    }

  } while (choice != 'Q' && choice != 'q');
}

Movies create_movies_list(const string &userid, Data &newData)
{
  Movies *movie_list = new Movies();
  for (auto &movie : newData.get_csv_data())
  {
    if (movie.at(0) == userid && movie.at(0) != "userid")
    {
      movie_list->add_movie(movie.at(1), movie.at(2), stoi(movie.at(3)));
    }
  }
  return *movie_list;
}

void display_menu(Movies &movie_list)
{
  cout << "Movies List: \n";
  movie_list.display_movies();
  proceed();
  return;
}

void addition_menu(Movies &movie_list)
{

  cout << "\n***********************************************************\n\n";
  string moviename{};

  cout
      << "What is the name of the movie you would like to add?\nEnter: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, moviename);

  string movierating{};
  cout << "\n\nWhat is the Rating of the Movie? (G, PG, PG-13, R, NR, X, TV-G, TV-PG, TV-MA, TV-NR, etc.)\nEnter: ";
  getline(cin, movierating);

  if (!moviename.empty() && !movierating.empty())
  {
    cout << "\n****************************************************";
    cout << "\n\nAdding Movie..." << endl;
    movie_list.add_movie(moviename, movierating);
  }
  else
  {
    cout << "\n\nFailed to Add Movie, try Again\n"
         << endl;
  }

  proceed();
  return;
}

void watch_menu(Movies &movie_list)
{
  string moviename{};
  cout << "\n***********************************************";
  cout << "\n\nWhat is the name of the movie you have watched?\nEnter: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, moviename);
  cout << "Adding a Watch to " << moviename << "..." << endl;
  movie_list.watched_movie(moviename);
  proceed();
  return;
}

void proceed()
{
  string arg{};

  cout << "\n\n\nClick any key to proceed...\n";
  cin >> arg;

  if (!arg.empty())
  {
    system("clear");
    return;
  }
}
