// nfa to dfa
#include "nfa_to_dfa.h"
#include "shared_data.h"

#include <map>
#include <iostream>
using namespace std;

// function to find the epsilon closure of a set of states
set<int> epsilon_closure (set<int> states)
{
	set <int> epsilon_states;
	epsilon_states = states;
	set <int> temp;

	int prev_size,new_size;

	if( states.size() > 0 )
	{
		for(std::set<int>::iterator it = states.begin(); it != states.end(); ++it)
		{
			//epsilon_states.insert(*it);

			if( NFA[*it][0].size() > 0 )
			{
				for( std::set<int>::iterator it2 = NFA[*it][0].begin() ; it2 != NFA[*it][0].end() ; ++it2 )
				{
					prev_size = epsilon_states.size();
					epsilon_states.insert( *it2 );
					new_size = epsilon_states.size();

					if( prev_size < new_size )
					{
						temp.empty();
						temp.insert(*it2);
						temp = epsilon_closure(temp);

						if(temp.size() > 0)
							epsilon_states.insert( temp.begin(), temp.end() );
					}
				}
			}
			//temp.insert( NFA[*it][0].begin(), NFA[*it][0].end() );
			//epsilon_states.insert( epsilon_states.end(), temp.begin(), temp.end() );

		}
	}
	return epsilon_states;
}

set<int> move (set<int> states , int input )
{
	set <int> next_states;

	if( states.size() > 0 )
	{
		for(std::set<int>::iterator it = states.begin(); it != states.end(); ++it)
		{
			if(NFA[*it][input].size() > 0 )
				next_states.insert( NFA[*it][input].begin(), NFA[*it][input].end() ) ;
		}
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
	
	std::map<std::set<int>,int > ND;	//map of set of states of NFA TO DFA states.
	std::map<int,std::set<int> > unmarked_DN;	//map of unmarked DFA states TO set of states of NFA.
	std::vector<int> new_state(alpha_size+1);	//to allocate memory in the DFA matrix for a new state
	
	
	
	std::set<int> cur_states;	// set of current states
	std::set<int> next_states;	// set of next states
	std::set<int> NFA_start_set;	// set of the start state of NFA
	std::vector<int> last;	// for inserting the last state (non accepting)

	NFA_start_set.insert(nfa_start_state);

	cur_states = epsilon_closure (NFA_start_set);	//epsilon closure of start state

	for (std::set<int>::iterator it2 = cur_states.begin() ; it2 != cur_states.end(); ++it2)
	{
		if( nfa_final_states.find(*it2) != nfa_final_states.end() )
		{
			dfa_final_states.insert(val);
			break;
		}
	}

	ND.insert( std::pair<set<int>,int>( cur_states, val ) );
	unmarked_DN.insert( std::pair<int,set<int> >( val++, cur_states ) );
	DFA.push_back(new_state);

	

	while(flag_unmarked)
	{
		for (std::map<int, std::set<int> >::iterator it = unmarked_DN.begin(); it!=unmarked_DN.end();)
		{
			for(int input = 1; input <= alpha_size; ++input)
			{
				next_states.clear();				
				next_states = epsilon_closure( move ( it->second, input ) );	
				//cout<<endl<<it->first<<" "<<input<<" "<<next_states.size()<<endl;
				
				//cout<<endl;

				if(!next_states.empty())
				{
					if( ND.find(next_states) == ND.end()) 
					{
						// new state inserted

						for (std::set<int>::iterator it2 = next_states.begin() ; it2 != next_states.end(); ++it2)
						{
							if( nfa_final_states.find(*it2) != nfa_final_states.end() )
							{
								dfa_final_states.insert(val);
								break;
							}
						}

						DFA.push_back(new_state);
						ND.insert( std::pair<set<int>,int>( next_states, val ) );
						unmarked_DN.insert( std::pair<int,set<int> >( val++, next_states ) );
						DFA[ it->first ][input] = val - 1 ;
					}

					else
					{
						DFA[ it->first ][input]  = ND[next_states];
					}
				}

				else
				{
					//cout<<endl<<it->first<<" "<<input<<" "<<endl;
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
	cout<<"\nstates \t";

	for(int i=1; i<=alpha_size; i++)
	{
		cout<<char((int)'a'+i-1)<<"\t";
	}

	cout<<endl;

	for(int i=0;i<DFA.size();i++)
	{
		//cout<<"ajinkya";
		cout<<"\nS"<<i<<"\t";
		for(int j=1;j<=alpha_size;j++)
		{
			cout<<"S"<<DFA[i][j]<<"\t";
		}		
	}

	cout<<endl;

	cout<<"\nstart state of dfa : "<<dfa_start_state<<endl;
	cout<<"\nfinal states of dfa : ";
	for(set<int>::iterator it = dfa_final_states.begin(); it != dfa_final_states.end(); it++)
	{
		cout<<*it<<",\t";
	}
	cout<<endl;	
}
