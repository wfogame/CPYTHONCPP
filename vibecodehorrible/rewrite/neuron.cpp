#include <iostream>
#include <string>
#include <sstream>
class Neuron{
  // MISSING SIGMOID cuz one neuron on;y system EHH too bad to sad;
  private:
    double input = 1;
    double weight = 1;
    double bias = 1;
    double target = 1;
    double output;  
    double loss;
    // Basically, when output goes up by 1, how much does does loss change?
    double dLossdOutput;
    double DoutputDweight;
    // When weight is added by 1, obviously, output changs by input, because output = input * weight + bias ( SO slope = input ), or rate of change
    double DoutputDbias = 1; // Obviously, add bias by 1, output adds by 1. Pretty obvious.
  public:

    Neuron(double input, double weight, double bias, double target = 1):input(input),weight(weight),bias(bias),target(target){}
   void Update(double learningrate = 0.05){
     //WE need to find rate of change when loss change, how much does weight change, as we want to migate loss, by changing weight, as we can only change that.
     // If output is above target, then weight goes down, if it is the other way around, obviously since loss will be negative, negative * negative = postive so weight goes up, and eventually...
      output = input * weight + bias;
      loss = (output - target) * (output-target);
      dLossdOutput = 2 * (output - target);
      DoutputDweight = input;
      weight = weight - learningrate * dLossdOutput * DoutputDweight; // So, when output increases by 1, loss increases by 2 *(output-target), how much output changes is input_value * weigt, and so therefore if weight increases by 1, output increases by 1, and loss increases by 2 * ( output -target);
      bias = bias - learningrate * dLossdOutput * DoutputDbias; // Same logic. Although idk about updating both at same time but eh works enough;
    
    // SO this minimizes loss, because 
   }
    

};
