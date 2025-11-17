OKay I am going to implemnt it as soon as I understand how to, notice I AM? So, 

vector <Neuron> layer ( The problem is, there should be muitple inputs per neuron so we need to change our neuron header class to actually accept vector<double> AS parameters,  So yeah little bit harder, limiting it by doing input1 is kidna bad. WEIGHT and bias shall be in another vector and passed off as references so taht when weight change in that, weight will change in original variable so data will be saved FOR that session only, so we need a way to print out all our variables AND a way to like input our variables, MAYBE we have another file called weights+bias.txt
which gets a getline or a cin, that reads the data, and uses that as a weight. AH THIS IS GOING TO TAKE VERY LONG. 
