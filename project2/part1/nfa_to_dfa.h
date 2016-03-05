//nfa to dfa header

//function to calculate epsilon closure of a 'set of states'
vector<int> epsilon_closure ( vector<int>);


// function to find the set of states obtained from a 'set of 
// states' on an 'input' 
vector<int> move ( vector<int> );

//function to convert the DFA to NFA
void nfa_to_dfa ();

// to print the transitions corresponding to states
void print_dfa_matrix();