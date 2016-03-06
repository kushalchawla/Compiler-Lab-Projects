
//#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <utility>
#include <string>
using namespace std;
//INPUT
extern string RE;

//after step 1 
extern std::vector< vector< set<int> > > NFA;
extern int nfa_start_state;
extern std::set<int> nfa_final_states;

//after step 2
extern std::vector< vector<int> > DFA;
extern int dfa_start_state;	
extern std::set<int> dfa_final_states;

//Final Output
extern std::vector< vector<int> > min_DFA;
extern int mindfa_start_state;
extern std::set<int> mindfa_final_states;