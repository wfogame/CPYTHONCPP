#ifndef RUNCOMMAND_H
#define RUNCOMMAND_H

#include <string>
#include <sstream>
#include <map>

// Declare the functions
void RunCommand(std::string command, std::stringstream& ss);
void RunNeuron(std::stringstream& shutupbuddy);
void Help(std::stringstream& BUDDYbuddy);

// Declare the global map
extern std::map<std::string, void(*)(std::stringstream&)> commandline;

#endif
