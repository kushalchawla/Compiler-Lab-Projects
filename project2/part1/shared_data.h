#include <bits/stdc++.h>
using namespace std;
//INPUT
static string RE;

//after step 1 
static std::vector< vector< set<int> > > NFA;
static int nfa_start_state;
static std::set<int> nfa_final_states;

//after step 2
static std::vector< vector<int> > DFA;
static int dfa_start_state;	
static std::set<int> dfa_final_states;

//Final Output
static std::vector< vector<int> > min_DFA;
static int mindfa_start_state;
static std::set<int> mindfa_final_states;