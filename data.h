#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Movie;
class Movies;

class Data {

  friend Movie;
  friend Movies;

private:
  // private members}
  const string filename;
  ifstream file;
  string line;
  vector<vector<string>> csvData;

  // Relatives to Movies
  string user_id;

public:
  // public members
  Data(string filename = "data.csv");
  string get_user_id();
  void set_user_id(string);
  vector<vector<string>> get_csv_data();

  bool check_file_open(const ifstream& file);
  bool add_data(const string &filename, ifstream &file, string &line, vector<vector<string>> &csvData);
  bool close_file(ifstream &file);

  void write_to_csv(Movies&); // outputs to csv file

  void print_data_test(vector<vector<string>> &csvData);

};

#endif 