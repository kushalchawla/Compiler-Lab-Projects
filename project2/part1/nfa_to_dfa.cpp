// nfa to dfa
#include "nfa_to_dfa.h"
#include "shared_data.h"
#include <bits/stdc++.h>
#define alpha_size 26

using namespace std;

// function to find the epsilon closure of a set of states
vector<int> epsilon_closure (vector<int> states)
{
	vector <int> epsilon_states;
	for(std::vector<int>::iterator it = states.begin(); it != states.end(); ++it)
	{
		epsilon_states.insert(epsilon_states.end(), NFA[*it][0].begin(), NFA[*it][0].end());
	}

	return epsilon_states;
}

// function to find the 'set of states' obtained on an 'input' from a 'set of states'
vector<int> move (vector<int> states , int input )
{
	vector <int> next_states;
	for(std::vector<int>::iterator it = states.begin(); it != states.end(); ++it)
	{
		next_states.insert(next_states.end(), NFA[*it][input].begin(), NFA[*it][input].end());
	}
	
	return next_states;
}

//function to convert the DFA to NFA
void nfa_to_dfa ()
{
	int start_index, flag_unmarked, val;	
	
	// flag_unmarked -> flag to tell whether there are states in DFA which are unmarked
	// val -> used whenever a new state is introduced (to name it)
	
	flag_unmarked = 1;
	val = 0;
	
	std::map<std::vector<int>,int > ND;	//map of set of states of NFA TO DFA states.
	std::map<int,std::vector<int> > unmarked_DN;	//map of unmarked DFA states TO set of states of NFA.
	std::vector<int> new_state(alpha_size+1);	//to allocate memory in the DFA matrix for a new state
	
	
	
	std::vector<int> cur_states;	// set of current states
	std::vector<int> next_states;	// set of next states
	std::vector<int> NFA_start_set;	// set of the start state of NFA
	std::vector<int> last;	// inserting the last state (non accepting)

	NFA_start_set.push_back(nfa_start_state);

	cur_states = epsilon_closure (NFA_start_set);	//epsilon closure of start state

	ND.insert( std::pair<vector<int>,int>( cur_states, val ) );
	unmarked_DN.insert( std::pair<int,vector<int> >( val++, cur_states ) );
	DFA.push_back(new_state);

	while(flag_unmarked)
	{
		for (std::map<int, std::vector<int> >::iterator it = unmarked_DN.begin(); it!=unmarked_DN.end();)
		{
			for(int input = 1; input <= alpha_size; ++input)
			{
				next_states = epsilon_closure( move ( it->second, input ) );	

				if(!next_states.empty())
				{
					if( ND.find(next_states) == ND.end()) 
					{
						// new state inserted
						DFA.push_back(new_state);
						ND.insert( std::pair<vector<int>,int>( next_states, val ) );
						unmarked_DN.insert( std::pair<int,vector<int> >( val++, next_states ) );
						DFA[ it->first ][input] = val - 1 ;
					}

					else
					{
						DFA[ it->first ][input]  = ND[next_states];
					}
				}

				else
				{
					DFA[ it->first ][input] = -1;
				}
			}

			DFA[ it->first ][0] = it->first ;
			unmarked_DN.erase(it++);	//this state is marked now
			
		}

		if(unmarked_DN.empty())
			flag_unmarked = 0;
	}

	for(int i=0;i<DFA.size();i++)
	{
		for(int j=0;j<=alpha_size;j++)
		{
			if( DFA[i][j] == -1 )	
				DFA[i][j] = val;
		}		
	}

	for(int j=0;j<=alpha_size;j++)
		last.push_back(val);

	DFA.push_back(last);
}

void print_dfa_matrix()
{
	cout<<"\n\tE\t";

	for(int i=1; i<=alpha_size; i++)
	{
		cout<<char((int)'a'+i-1)<<"\t";
	}

	cout<<endl;

	for(int i=0;i<DFA.size();i++)
	{
		//cout<<"ajinkya";
		cout<<"\n\t";
		for(int j=0;j<=alpha_size;j++)
		{
			cout<<"S"<<DFA[i][j]<<"\t";
		}		
	}

	cout<<endl;
}