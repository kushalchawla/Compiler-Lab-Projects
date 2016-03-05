//kushal - step 1
//each nfa is a pair of vector< vector< vector<int> >  > and int start state, int(final state)

#include <iostream>
#include "regex_to_nfa.h"
#include "shared_data.h"

using namespace std;


void re_to_nfa()
{
	cout<<"Enter the regular expression !";
	cin>>RE;
	R();
}