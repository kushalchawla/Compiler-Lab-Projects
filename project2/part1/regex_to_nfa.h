//kushal - step 1 header
#include <bits/stdc++.h>
using namespace std;
void re_to_nfa();
void pmat();

pair< vector< vector< set<int> > >, pair<int,int> > do_id(char ch);
pair< vector< vector< set<int> > >, pair<int,int> > do_plus( pair< vector< vector< set<int> > >, pair<int,int> > A, pair< vector< vector< set<int> > >, pair<int,int> > B);
pair< vector< vector< set<int> > >, pair<int,int> > do_dot( pair< vector< vector< set<int> > >, pair<int,int> > A, pair< vector< vector< set<int> > >, pair<int,int> > B);
pair< vector< vector< set<int> > >, pair<int,int> > do_star( pair< vector< vector< set<int> > >, pair<int,int> > A);

pair< vector< vector< set<int> > >, pair<int,int> > R();
pair< vector< vector< set<int> > >, pair<int,int> > R_prime(pair< vector< vector< set<int> > >, pair<int,int> > A);
pair< vector< vector< set<int> > >, pair<int,int> > P();
pair< vector< vector< set<int> > >, pair<int,int> > P_prime(pair< vector< vector< set<int> > >, pair<int,int> > A);
pair< vector< vector< set<int> > >, pair<int,int> > D();
pair< vector< vector< set<int> > >, pair<int,int> > D_prime(pair< vector< vector< set<int> > >, pair<int,int> > A);
pair< vector< vector< set<int> > >, pair<int,int> > V();