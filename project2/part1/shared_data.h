#include <vector>
#include <string>

//INPUT
static string RE;

//after step 1 
static std::vector< vector< vector<int> > > NFA;
static std::set<int> nfa_final_states;

//after step 2
static std::vector< vector<int> > DFA;	
static std::set<int> dfa_final_states;

//Final Output
static std::vector< vector<int> > min_DFA;
static std::set<int> mindfa_final_states;