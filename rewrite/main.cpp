#include <iostream>
#include <sstream>
#include <string>
#include <sstream>
#include "neuron.h"
#include "RunCommand.h"
int main(){

  using namespace std;
  string input;
  string command;
  while(true){

  
  cout << "➤▸ ";
  getline(cin,input);
  stringstream ss(input);
  ss >> command;

  RunCommand(command,ss);
  }
}
