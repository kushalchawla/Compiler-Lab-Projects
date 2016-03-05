// main file
#include <iostream>
#include "regex_to_nfa.h"
#include "nfa_to_dfa.h"
#include "dfa_to_mindfa"
#include "dfa_simulation"
using namespace std;

int main()
{
	string s;
	re_to_nfa();
	nfa_to_dfa();
	dfa_to_mindfa();
	bool result = dfa_simulate(s);
	//final answer is in min_DFA 2d matrix...
	cout<<"Conversion done successfully!"<<endl;
	return 0;
}