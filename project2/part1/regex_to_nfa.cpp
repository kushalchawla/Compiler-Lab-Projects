//kushal - step 1
//each nfa is a pair of vector< vector< set<int> >  > and int start state, int(final state)
//deallocate old nfa's after combining.
/*
RE is parsed using the following grammar- 
precendence order is(highest to lowest) (),*,.,+
R->PR'
R'->+PR'|e
P->DP'
P'->.DP'|e
D->VD'
D'->*D'|e
V->id|(R)

*/

#include "regex_to_nfa.h"
#include "shared_data.h"

using namespace std;
int cur_index=0;

//create nfa for a variable
pair< vector< vector< set<int> > >, pair<int,int> > do_id(char ch)
{
	int input=(int)ch-97+1;
	pair< vector< vector< set<int> > >, pair<int,int> > final;
	vector< vector< set<int> > > matrix;
	vector< set<int> > row(27);
	matrix.push_back(row);
	matrix.push_back(row);
	matrix[0][input].insert(1);
	final.first=matrix;
	final.second.first=0;
	final.second.second=1;
	return final;	
}

//combine 2 NFAs according to + operator
pair< vector< vector< set<int> > >, pair<int,int> > do_plus( pair< vector< vector< set<int> > >, pair<int,int> > A, pair< vector< vector< set<int> > >, pair<int,int> > B)
{

	pair< vector< vector< set<int> > >, pair<int,int> > final1;
	
	vector< vector< set<int> > > final;
	
	int l1=A.first.size();
	for(int i=0;i<l1;i++)
	{
		final.push_back(A.first[i]);
	}
	int l2=B.first.size();
	for(int i=0;i<l2;i++)
	{
		final.push_back(B.first[i]);
	}

	for(int i=l1;i<(l1+l2);i++)
	{
		for(int j=0;j<27;j++)
		{
			if(final[i][j].size()>0)
			{
				set<int>::iterator it;
				set<int> temp;
				for(it=final[i][j].begin();it!=final[i][j].end();it++)
				{
					temp.insert((*it)+l1);
				}
				final[i][j]=temp;
			}
		}
	}
	
	vector< set<int> > row(27);
	final.push_back(row);
	final.push_back(row);
	final1.second.first=l1+l2;
	final1.second.second=l1+l2+1;
	final[l1+l2][0].insert(A.second.first);
	final[l1+l2][0].insert(B.second.first+l1);
	final[A.second.second][0].insert(l1+l2+1);
	final[B.second.second+l1][0].insert(l1+l2+1);
	final1.first=final;
	
	return final1;
}

//combine 2 NFAs according to . operator
pair< vector< vector< set<int> > >, pair<int,int> > do_dot( pair< vector< vector< set<int> > >, pair<int,int> > A, pair< vector< vector< set<int> > >, pair<int,int> > B)
{
	pair< vector< vector< set<int> > >, pair<int,int> > final1;
	vector< vector< set<int> > > final;
	int l1=A.first.size();
	for(int i=0;i<l1;i++)
	{
		final.push_back(A.first[i]);
	}
	int l2=B.first.size();
	for(int i=0;i<l2;i++)
	{
		final.push_back(B.first[i]);
	}
	for(int i=l1;i<(l1+l2);i++)
	{
		for(int j=0;j<27;j++)
		{
			if(final[i][j].size()>0)
			{
				set<int>::iterator it;
				set<int> temp;
				for(it=final[i][j].begin();it!=final[i][j].end();it++)
				{
					temp.insert((*it)+l1);
				}
				final[i][j]=temp;
			}
		}
	}
	final[A.second.second][0].insert(B.second.first + l1);
	final1.second.first=A.second.first;
	final1.second.second=B.second.second+l1;
	final1.first=final;
	return final1;
}

//create NFA corresponding to * operation
pair< vector< vector< set<int> > >, pair<int,int> > do_star( pair< vector< vector< set<int> > >, pair<int,int> > A)
{
	pair< vector< vector< set<int> > >, pair<int,int> > final1;
	vector< vector< set<int> > > final;
	int l1=A.first.size();
	for(int i=0;i<l1;i++)
	{
		final.push_back(A.first[i]);
	}
	vector< set<int> > row(27);
	final.push_back(row);
	final.push_back(row);
	final[A.second.second][0].insert(A.second.first);
	final[l1][0].insert(A.second.first);
	final[l1][0].insert(l1+1);
	final[A.second.second][0].insert(l1+1);
	
	final1.first=final;
	final1.second.first=l1;
	final1.second.second=l1+1;
	return final1;
}

void re_to_nfa()
{
	cout<<"Enter the regular expression !"<<endl;
	cin>>RE;
	int in_len=RE.size();
	if(in_len==0)
	{
		cout<<"No expression was provided"<<endl;
		exit (EXIT_FAILURE);
	}
	pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
	nfa1=R();
	if(cur_index!=RE.size())
	{
		cout<<"Wrong input format at index"<<cur_index<<endl;
		exit(EXIT_FAILURE);
	}
	NFA=nfa1.first;
	nfa_start_state=nfa1.second.first;
	nfa_final_states.insert(nfa1.second.second);
	cout<<"RE converted to NFA successfully!"<<endl;
}

pair< vector< vector< set<int> > >, pair<int,int> > R()
{
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='(' || (RE[cur_index]>='a' && RE[cur_index]<='z'))
		{
			pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa2;
			nfa1=P();
			nfa2=R_prime(nfa1);
			return nfa2;
		}
		else
		{
			cout<<"Wrong format at index "<<cur_index<<endl;
			exit (EXIT_FAILURE);
		}
	}
	else
	{
		cout<<"Wrong format at index "<<cur_index<<endl;
		exit (EXIT_FAILURE);
	}
}

pair< vector< vector< set<int> > >, pair<int,int> > R_prime(pair< vector< vector< set<int> > >, pair<int,int> > A)
{
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='+')
		{
			cur_index++;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
			nfa1=P();
			pair< vector< vector< set<int> > >, pair<int,int> > nfa2;
			nfa2=do_plus(A,nfa1);
			pair< vector< vector< set<int> > >, pair<int,int> > nfa3;
			nfa3=R_prime(nfa2);
			return nfa3;
		}
		else
		{
			return A;
		}
	}
	else
	{
		return A;
	}
}

pair< vector< vector< set<int> > >, pair<int,int> > P()
{
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='(' || (RE[cur_index]>='a' && RE[cur_index]<='z'))
		{
			pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa2;
			nfa1=D();
			nfa2=P_prime(nfa1);
			return nfa2;
		}
		else
		{
			cout<<"Wrong format at index "<<cur_index<<endl;
			exit (EXIT_FAILURE);
		}
	}
	else
	{
		cout<<"Wrong format at index "<<cur_index<<endl;
		exit (EXIT_FAILURE);
	}	
}

pair< vector< vector< set<int> > >, pair<int,int> > P_prime(pair< vector< vector< set<int> > >, pair<int,int> > A)
{
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='.')
		{
			cur_index++;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
			nfa1=D();
			pair< vector< vector< set<int> > >, pair<int,int> > nfa2;
			nfa2=do_dot(A,nfa1);
			pair< vector< vector< set<int> > >, pair<int,int> > nfa3;
			nfa3=P_prime(nfa2);
			return nfa3;
		}
		else
		{
			return A;
		}
	}
	else
	{
		return A;
	}
}

pair< vector< vector< set<int> > >, pair<int,int> > D()
{
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='(' || (RE[cur_index]>='a' && RE[cur_index]<='z'))
		{
			pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa2;
			nfa1=V();
			nfa2=D_prime(nfa1);
			return nfa2;
		}
		else
		{
			cout<<"Wrong format at index "<<cur_index<<endl;
			exit (EXIT_FAILURE);		
		}
	}
	else
	{
		cout<<"Wrong format at index "<<cur_index<<endl;
		exit (EXIT_FAILURE);
	}	
}

pair< vector< vector< set<int> > >, pair<int,int> > D_prime(pair< vector< vector< set<int> > >, pair<int,int> > A)
{
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='*')
		{
			cur_index++;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
			nfa1=do_star(A);
			pair< vector< vector< set<int> > >, pair<int,int> > nfa2;
			nfa2=D_prime(nfa1);
			return nfa2;
		}
		else
		{
			return A;
		}
	}
	else
	{
		return A;
	}
}

pair< vector< vector< set<int> > >, pair<int,int> > V()
{
	if(cur_index<RE.size())
	{
		if(RE[cur_index]>='a' && RE[cur_index]<='z')
		{
			cur_index++;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa1;
			nfa1=do_id(RE[cur_index-1]);
			return nfa1;
		}
		else if(RE[cur_index]=='(')
		{
			cur_index++;
			pair< vector< vector< set<int> > >, pair<int,int> > nfa2;
			nfa2=R();
			if(RE[cur_index]==')')
			{
				cur_index++;
				return nfa2;
			}
			else
			{
				cout<<"Wrong paranthesis matching at index "<<cur_index<<endl;
				exit (EXIT_FAILURE);
			}
		}
		else
		{
			cout<<"Wrong format at index "<<cur_index<<endl;
			exit (EXIT_FAILURE);
		}
	}
	else
	{
		cout<<"Wrong format at index "<<cur_index<<endl;
		exit (EXIT_FAILURE);
	}
}


void pmat()
{
	cout<<"Printing NFA"<<endl;
	for(int i=0;i<NFA.size();i++)
	{
		cout<<" state- "<<i<<endl;
		for(int j=0;j<3;j++)
		{
			cout<<"input is- "<<(char)(j-1+97)<<endl;

			set<int>::iterator it;
			for(it=NFA[i][j].begin();it!=NFA[i][j].end();it++)
			{
				cout<<*it<<"\t";
			}
			cout<<endl;
		}
	}
	cout<<endl;

}