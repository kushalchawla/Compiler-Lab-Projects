// main file
#include <iostream>
#include "regex_to_nfa.h"
#include "nfa_to_dfa.h"
#include "dfa_to_mindfa.h"
#include "dfa_simulation.h"

using namespace std;

string RE;

//after step 1 
std::vector< vector< set<int> > > NFA;
int nfa_start_state;
std::set<int> nfa_final_states;

//after step 2
std::vector< vector<int> > DFA;
int dfa_start_state;	
std::set<int> dfa_final_states;

//Final Output
std::vector< vector<int> > min_DFA;
int mindfa_start_state;
std::set<int> mindfa_final_states;

int main()
{
	string s;
	re_to_nfa();
	cout<<"re to nfa done\n";
	
	pmat();
	nfa_to_dfa();
	cout<<"nfa to dfa done\n";
	print_dfa_matrix();

	dfa_to_mindfa();
	cout<<"dfa to mindfa done.\n";
	print_mindfa_matrix();
	//final answer is in min_DFA 2d matrix...
	string r;
		
	while(1)
	{
		cout<<"\nEnter input string."<<endl;
		cin >> s;
		bool result = dfa_simulate(s);
		if(result)
			cout << "present";
		else
			cout << "not present";
		cout <<"\n Continue(y/n)?";
		cin >> r;
		if(r[0]=='n')
			break;
	}
	return 0;
}
