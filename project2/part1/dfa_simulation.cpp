
bool dfa_simulate(string s)
{
	int state=mindfa_start_state,i=0;
	while(i<s.length())
	{
		state=min_DFA[state][s[i++]];
	}
	if (mindfa_final_states.find(state)!=mindfa_final_states.end())
		return 1;
	return 0;
}