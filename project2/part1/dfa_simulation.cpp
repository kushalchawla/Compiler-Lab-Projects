//simulating the minimized DFA on an input
#include "dfa_simulation.h"
#include "shared_data.h"
#include <iostream>
bool dfa_simulate(string s)
{
	int x,state=mindfa_start_state,i=0;
	while(i<s.length())
	{
		x = s[i++] -96;
		if((x<0)||(x > alpha_size))
		{
			cout << " error\n";
			return 0;
		}	
		state=min_DFA[state][x];
	}
	return (mindfa_final_states.find(state)!=mindfa_final_states.end());
}
