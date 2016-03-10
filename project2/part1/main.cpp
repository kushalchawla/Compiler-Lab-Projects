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
	cout<<"\nRE TO NFA CONVERSION COMPLETE..\n";
	
	//pmat();
	nfa_to_dfa();
	cout<<"\nNFA TO DFA CONVERSION COMPLETE..\n";
	print_dfa_matrix();

	dfa_to_mindfa();
	cout<<"\nDFA TO MINIMIZED DFA CONVERSION COMPLETE..\n";
	print_mindfa_matrix();
	//final answer is in min_DFA 2d matrix...
	char r;
	int flag = 1;

	while(flag)
	{
		cout<<"\n\nENTER THE INPUT STRING (` for epsilon) :"<<endl;
		cin >> s;
		bool result = dfa_simulate(s);
		if(result)
			cout << "\n\tThe DFA output is YES..\n";
		else
			cout << "\n\tThe DFA output is NO..\n";
		
		r = 'z';
		cout <<"\n\t\tDO YOU WANT TO CONTINUE ? (y/n): ";

		while(1)
		{		
			cin >> r;
			if(r == 'n' || r == 'N')
			{
				flag = 0;
				break;
			}

			if(r == 'y' || r == 'Y')
			{
				break;
			}

			else
				cout<<"\nINCORRECT CHOICE...TRY AGAIN..\n";
		}

	}
	return 0;
}
