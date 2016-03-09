	//dfa to min dfa

	#include "dfa_to_mindfa.h" 
	#include <vector>
	#include <iostream>
	#include "shared_data.h"
	using namespace std;
	bool distinct[5001][5001];
	bool comp(int i,int j)
	{
		int in;
		for(in=1;in<alpha_size+1;in++)
		{
			if(distinct[DFA[i][in]][DFA[j][in]])
				return 1;	
		}	

		return 0;
	}

	void dfa_to_mindfa()
	{
		int i,j,n=DFA.size();
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((dfa_final_states.find(i)==dfa_final_states.end())&&(dfa_final_states.find(j)!=dfa_final_states.end()))
				{
					distinct[i][j]=1;
					distinct[j][i]=1;
				}
				else if((dfa_final_states.find(j)==dfa_final_states.end())&&(dfa_final_states.find(i)!=dfa_final_states.end()))
				{
					distinct[i][j]=1;
					distinct[j][i]=1;
				}
				else
				{
					distinct[i][j]=0;
					distinct[j][i]=0;
				}	
			}	
		}

		bool flag=1;
		while(flag)
		{
			flag=0;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(!distinct[i][j])
					{
						if(comp(i,j))
						{		
							distinct[i][j]=1;
							flag=1;
						}
					}
				}	
			}
		}
		int parent[n+1];
		for(i=0;i<n;i++)
			parent[i]=i;
		for(i=0;i<n;i++)
		{
			if(i==parent[i])
			{
				for(j=i+1;j<n;j++)
				{
					if(distinct[i][j]==0)
						parent[j]=i;
				}
			}
		}
		
		vector<int> trans;
		vector <int> empt;
		for(i=0;i<alpha_size+1;i++)
			empt.push_back(-1);


		for(i=0;i<DFA.size();i++)
		{
			if(parent[i]==i)
			{
				trans.clear();
				if(dfa_final_states.find(i)!=dfa_final_states.end())
					mindfa_final_states.insert(i);
				trans.push_back(i);
				for(j=1;j<alpha_size+1;j++)
					trans.push_back(parent[DFA[i][j]]);
				min_DFA.push_back(trans);
				
			}	
			else
				min_DFA.push_back(empt);
		}
		
	}

void print_mindfa_matrix()
{
	cout<<"\nstates\t";

	for(int i=1; i<=alpha_size; i++)
	{
		cout<<char((int)'a'+i-1)<<"\t";
	}

	cout<<endl;

	for(int i=0;i<min_DFA.size();i++)
	{
		if(min_DFA[i][1]!=-1)
		{
			cout<<"\nS" << i << "\t";
			for(int j=1;j<=alpha_size;j++)
			{
				cout<<"S"<<min_DFA[i][j]<<"\t";
			}
		}		
	}

	cout<<"\nstart state of min dfa : "<<mindfa_start_state;
	cout<<"\nfinal states of min dfa : ";
	for(set<int>::iterator it = mindfa_final_states.begin(); it != mindfa_final_states.end(); it++)
	{
		cout<<*it<<",\t";
	}
	cout<<endl;
	
}
