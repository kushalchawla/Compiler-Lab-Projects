//kushal - step 1
//each nfa is a pair of vector< vector< vector<int> >  > and int start state, int(final state)
//deallocate old nfa's after combining.
#include "regex_to_nfa.h"
#include "shared_data.h"

using namespace std;
int cur_index=0;

//nfa for a variable
pair< vector< vector< vector<int> > >, pair<int,int> > do_id(char ch)
{
	int input=(int)ch-97+1;
	pair< vector< vector< vector<int> > >, pair<int,int> > final;
	vector< vector< vector<int> > > matrix;
	vector< vector<int> > row(27);
	matrix.push_back(row);
	matrix.push_back(row);
	matrix[0][input].push_back(1);
	final.first=matrix;
	final.second.first=0;
	final.second.second=1;
	cout<<"ch is"<<ch<<"sdfd"<<final.second.first<<" "<<final.second.second;
	return final;	
}
//plus operation
pair< vector< vector< vector<int> > >, pair<int,int> > do_plus( pair< vector< vector< vector<int> > >, pair<int,int> > A, pair< vector< vector< vector<int> > >, pair<int,int> > B)
{

	pair< vector< vector< vector<int> > >, pair<int,int> > final1;
	
	vector< vector< vector<int> > > final;
	
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
				int l3=final[i][j].size();
				for(int k=0;k<l3;k++)
				{
					final[i][j][k]+=l1;
				}
			}
		}
	}
	
	vector< vector<int> > row(27);
	final.push_back(row);
	final.push_back(row);
	final1.second.first=l1+l2;
	final1.second.second=l1+l2+1;
	final[l1+l2][0].push_back(A.second.first);
	final[l1+l2][0].push_back(B.second.first+l1);
	final[A.second.second][0].push_back(l1+l2+1);
	final[B.second.second+l1][0].push_back(l1+l2+1);
	final1.first=final;
	
	return final1;
}

//dot operation
pair< vector< vector< vector<int> > >, pair<int,int> > do_dot( pair< vector< vector< vector<int> > >, pair<int,int> > A, pair< vector< vector< vector<int> > >, pair<int,int> > B)
{
	pair< vector< vector< vector<int> > >, pair<int,int> > final1;
	vector< vector< vector<int> > > final;
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
				int l3=final[i][j].size();
				for(int k=0;k<l3;k++)
				{
					final[i][j][k]+=l1;
				}
			}
		}
	}
	final[A.second.second][0].push_back(B.second.first + l1);
	final1.second.first=A.second.first;
	final1.second.second=B.second.second+l1;
	final1.first=final;
	return final1;
}

//star operation
pair< vector< vector< vector<int> > >, pair<int,int> > do_star( pair< vector< vector< vector<int> > >, pair<int,int> > A)
{
	pair< vector< vector< vector<int> > >, pair<int,int> > final1;
	vector< vector< vector<int> > > final;
	int l1=A.first.size();
	for(int i=0;i<l1;i++)
	{
		final.push_back(A.first[i]);
	}
	vector< vector<int> > row(27);
	final.push_back(row);
	final.push_back(row);
	final[A.second.second][0].push_back(A.second.first);
	final[l1][0].push_back(A.second.first);
	final[l1][0].push_back(l1+1);
	final[A.second.second][0].push_back(l1+1);
	
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
	pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
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

pair< vector< vector< vector<int> > >, pair<int,int> > R()
{
	cout<<"R\n";
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='(' || (RE[cur_index]>='a' && RE[cur_index]<='z'))
		{
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa2;
			nfa1=P();
			nfa2=R_prime(nfa1);
			cout<<"ret"<<endl;
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

pair< vector< vector< vector<int> > >, pair<int,int> > R_prime(pair< vector< vector< vector<int> > >, pair<int,int> > A)
{
	cout<<"R_prime"<<cur_index<<endl;
	cout<<"sdfd"<<RE.size()<<endl;
	if(cur_index<RE.size())
	{
		cout<<"gsgs"<<endl;
		if(RE[cur_index]=='+')
		{
			cur_index++;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
			nfa1=P();
			cout<<"dfgdsssssssssss"<<nfa1.second.first<<" "<<nfa1.second.second<<endl;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa2;
			//nfa2=do_plus(A,nfa1);
			do_plus(A,nfa1);
			nfa2=nfa1;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa3;
			nfa3=R_prime(nfa2);
			cout<<"fet"<<endl;
			return nfa3;
		}
		else
		{
			cout<<"I am here"<<endl;
			return A;
		}
	}
	else
	{
		cout<<"I am here";
		return A;
	}
}

pair< vector< vector< vector<int> > >, pair<int,int> > P()
{
	cout<<"P"<<cur_index<<endl;
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='(' || (RE[cur_index]>='a' && RE[cur_index]<='z'))
		{
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa2;
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

pair< vector< vector< vector<int> > >, pair<int,int> > P_prime(pair< vector< vector< vector<int> > >, pair<int,int> > A)
{
	cout<<"P_prime"<<cur_index<<endl;
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='.')
		{
			cur_index++;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
			nfa1=D();
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa2;
			nfa2=do_dot(A,nfa1);
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa3;
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

pair< vector< vector< vector<int> > >, pair<int,int> > D()
{
	cout<<"D"<<cur_index<<endl;
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='(' || (RE[cur_index]>='a' && RE[cur_index]<='z'))
		{
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa2;
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

pair< vector< vector< vector<int> > >, pair<int,int> > D_prime(pair< vector< vector< vector<int> > >, pair<int,int> > A)
{
	cout<<"D_prime"<<cur_index<<endl;
	if(cur_index<RE.size())
	{
		if(RE[cur_index]=='*')
		{
			cur_index++;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
			nfa1=do_star(A);
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa2;
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

pair< vector< vector< vector<int> > >, pair<int,int> > V()
{
	cout<<"V"<<cur_index<<endl;
	if(cur_index<RE.size())
	{
		if(RE[cur_index]>='a' && RE[cur_index]<='z')
		{
			cur_index++;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa1;
			nfa1=do_id(RE[cur_index-1]);
			return nfa1;
		}
		else if(RE[cur_index]=='(')
		{
			cur_index++;
			pair< vector< vector< vector<int> > >, pair<int,int> > nfa2;
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
