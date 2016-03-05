// main file
#include <iostream>
#include "regex_to_nfa.h"
#include "nfa_to_dfa.h"
using namespace std;

int main()
{
	re_to_nfa();
	nfa_to_dfa();
	//dfa_to_mindfa();
	//final answer is in min_DFA 2d matrix...
	cout<<"Conversion done successfully!"<<endl;
	return 0;
}