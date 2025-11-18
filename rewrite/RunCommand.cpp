#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include "neuron.h"
#include <fstream>
#include <vector>
using namespace std;
vector<double> weight;
double cweight;
// Neuron(double input, double weight, double bias, double target = 1):input(input),weight(weight),bias(bias),target(target){}
//TODO Need to rewrite RunNeuron entirely.
//Do not judge this code cuz to do. 
void RunNeuron(stringstream& shutupbuddy){
  vector<double> input;
  vector<double> weight;
  double bias;
  double target;
  double lr;
  cout << "Enter target: " << endl;
  cin >> target;
  cout << "Enter learning rate: " << endl;
  cin >> lr;
  Neuron neuron(input,weight,bias,target);
};
void Help(stringstream& BUDDYbuddy);
void setup(stringstream& BUDDYBUDDY){
ifstream file("Weights.txt");
  if(!file){
  }else{
    while(file >> cweight){
      weight.push_back(cweight);
    }
  }
} 
map<string,void(*)(stringstream&)>commandline{
    {"Neuron",&RunNeuron},
    {"help",&Help},
    {"setup",&Setup}
  };


void RunCommand(string command,stringstream& ss){
  if (commandline.find(command) != commandline.end()){
    commandline[command](ss); //Hmm I wonder, can I pass an arugment here? Will it bak?
  }
  else{
    cout << "Command not found: " << command;
  }

  
}
void Help(stringstream& BUDDYbuddy){
 for(auto& cmd:commandline){
   
    cout << cmd.first << endl;
 }
}
