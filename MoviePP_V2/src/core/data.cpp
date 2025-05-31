#include "data.h"
#include "Movies.h"

using namespace std;

Data::Data(string filename) : file{filename}
{
  if (check_file_open(file) != 1)
  {
    if (add_data(filename, file, line, csvData) == 1)
    {
      if (close_file(file) == 1)
      {
        print_data_test(csvData);
      }
    }
  }
}

void Data::set_user_id(string arg)
{
  user_id = arg;
}

string Data::get_user_id()
{
  return user_id;
}

vector<vector<string>> Data::get_csv_data()
{
  return csvData;
}

bool Data::check_file_open(const ifstream &file)
{
  if (!file.is_open())
  {
    cerr << "Error Opening File." << endl;
    return 1;
  }
  else
  {
    return 0;
  }
}

bool Data::add_data(const string &filename, ifstream &file, string &line, vector<vector<string>> &csvData)
{
  getline(file, line);
  string col1{}, col2{}, col3{}, col4{};
  stringstream headers(line);
  headers >> col1 >> col2 >> col3 >> col4;

  while (getline(file, line))
  {
    stringstream ss(line);
    string value{""};
    vector<string> row;
    while (getline(ss, value, ','))
    {
      row.push_back(value);
    }
    csvData.push_back(row);
  }
  close_file(file);
  return 1;
}

bool Data::close_file(ifstream &file)
{
  file.close();
  return 1;
}

void Data::print_data_test(vector<vector<string>> &csvData)
{
  for (const auto &row : csvData)
  {
    for (const auto &value : row)
    {
      cout << value << " ";
    }
    cout << endl;
  }
}

void Data::write_to_csv(Movies &movie_list)
{
  ofstream outFile("/home/wheeler/udemy/cpp_beginner/13-OOP/GitChallenge/MovieTracker/MoviePP_V2/src/data/data.csv", ios::trunc);


  if (outFile.is_open())
  {

    /************************************************************
      PSEUDOCODE:

      For Every Movie in the Movies List
      - Write it out to the file

      For Every Movie in the CSV File
      - if The UserID at(0) isnt equal to this->userID, then write it to the file
    *************************************************************/
    outFile << "userid,name,rating,watched" << endl;
    movie_list.write_movie_to_file(outFile, this->user_id);
    for (const auto &var : this->csvData)
    {
      if (var.at(0) != this->user_id)
      {
        outFile << var.at(0) << "," << var.at(1) << "," << var.at(2) << "," << var.at(3) << endl;
      }
    }

    outFile.close();
  }

  return;
}
