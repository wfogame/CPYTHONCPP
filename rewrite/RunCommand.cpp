#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include "neuron.h"
using namespace std;

// Neuron(double input, double weight, double bias, double target = 1):input(input),weight(weight),bias(bias),target(target){}
void RunNeuron(stringstream& shutupbuddy){
  double input;
  double weight;
  double bias;
  double target;
  double lr;
  cout << "Enter input: " << endl;
  cin >> input;
  cout << "Enter weight: " << endl;
  cin >> weight;
  cout << "Enter bias: " << endl;
  cin >> bias;
  cout << "Enter target: " << endl;
  cin >> target;
  cout << "Enter learning rate: " << endl;
  cin >> lr;
  Neuron neuron(input,weight,bias,target);
  neuron.infoGetter();
  neuron.Update(lr);
  neuron.infoGetter();
};
void Help(stringstream& BUDDYbuddy);
  
map<string,void(*)(stringstream&)>commandline{
    {"Neuron",&RunNeuron},
    {"help",&Help}
  };


void RunCommand(string command,stringstream& ss){
  commandline[command](ss); //Hmm I wonder, can I pass an arugment here? Will it bak?

  
}
void Help(stringstream& BUDDYbuddy){
 for(auto& cmd:commandline){
   
    cout << cmd.first << endl;
 }
}
