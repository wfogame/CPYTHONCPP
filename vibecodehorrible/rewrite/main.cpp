#include <iostream>
#include <sstream>
#include <string>
#include <sstream>
double main(){

  using namespace std;
  string input;
  string command;
  void RunCommand(string command);
  while(true){

  
  cout << "➤▸ ";
  getline(cin,input);
  stringstream ss(input);
  ss >> command;

  RunCommand(command,ss);
  }
}
