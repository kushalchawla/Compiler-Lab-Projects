%{
	#include <stdio.h>
	#include <vector>
	#include <string>
	#include <queue>
	#include <map>
	#include <set>
	#include <iostream>
	#include <fstream>

	int yylex(void);
	extern int yylineno;
	void yyerror(char *);
	using namespace std;
	
	struct node
	{
		string name;
		int type;
		int val;
	};

	void yyerror(char *);

	extern char* yytext;
	
	struct symtab_entry
	{
		string name;
		int type;
		int val;
	};

	int scope = 0;
	
	vector<symtab_entry> default_push;
	ofstream fout;

	//
		set<string> prototyped_functions;
	//
	string f_name;
	map< int, vector<symtab_entry> > f_symtab;
	vector<symtab_entry> p_symtab;

	vector<symtab_entry> param_list;

	//
	#define YYSTYPE node

	

%}
%token VAR
%token PROTOTYPE
%token DEF
%token INT
%token BOOL
%token CHAR
%token BEG
%token END
%token RET
%token ASSIGN
%token CALL
%token SCAN
%token PRINT
%token ENDL
%token SPACE
%token WHILE
%token IF
%token THEN
%token ID
%token NUM
%%

Start: S {cout<<"S parsed\n";}
;

S: S1 S 
| 

;

S1: PROTOTYPE PF ';' 
{

}
| DEF DF
;


PF: INT FF 
| BOOL FF
| CHAR FF
;
FF: id '(' PARAM ')'
{
	if(prototyped_functions.find($1.name) != prototyped_functions.end())
	{
		cout<<"Function name "<<$1.name <<"already used\n";
		return 0;
	}

	else
	{
		prototyped_functions.insert($1.name);
		cout<<$1.name<<" function prototyped\n";
	}
}
;
PARAM: INT id PP

| BOOL id PP
| CHAR id PP
;
PP: ',' PARAM  

|
;

DF: INT id
{
	if($1.name != "main" && prototyped_functions.find($1.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $1.name<<"' not pototyped before use\n";
	}

	else
	{
		cout<<$1.name<<"definition begins .. \n";
		fout<<$1.name<<"_label:\n";
	}

	param_list.clear();
	p_symtab.clear();
	f_symtab.clear();
} DF1
| BOOL id
{
	
	if($1.name != "main" && prototyped_functions.find($1.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $1.name<<"' not pototyped before use\n";
	}

	else
	{
		cout<<$1.name<<"definition begins .. \n";
		fout<<$1.name<<"_label:\n";
	}

	param_list.clear();
	p_symtab.clear();
	f_symtab.clear();
	
}
DF1
| CHAR id 
{
	
	if($1.name != "main" && prototyped_functions.find($1.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $1.name<<"' not pototyped before use\n";
	}

	else
	{
		cout<<$1.name<<"definition begins .. \n";
		fout<<$1.name<<"_label:\n";
	}

	param_list.clear();
	p_symtab.clear();
	f_symtab.clear();
		
}DF1

;
DF1: '(' PARAM ')' BEG stmt_list RET V ';' END {cout<<"DF int parsed\n";}


stmt_list: stmt stmt_list 
|
;
stmt: ASSIGN id '=' E_or_C ';' 
| WHILE expr BEG stmt_list END 
| IF expr BEG stmt_list END
| VAR DV ';'
;
DV: INT id 
 
| BOOL id 
| CHAR id
;
E_or_C: expr 

| CALL id '(' PARAM1 ')'

;
PARAM1: V PP1

| 

; 
PP1: ',' PARAM1 

|

;

V: num 

|
 id

;

num: NUM 

;
id: ID 
{
	$$.name = yytext;
}

;

expr: O E1

;
E1: '|' O E1 

|

;

O: A O1

;
O1: '&' A O1
 
|

;

A: M A1

;
A1: '%' M A1 

|

;

M: G M1

;
M1: '>' G M1

|

;

G: L G1

;
G1: '<' L G1 

|
;

L: AS L1
;
L1: '+' AS L1 

| '-' AS L1 

|
;

AS: MD AS1
;
AS1: '*' MD AS1 
| '/' MD AS1 
|
;

MD: num 
| id 
| '(' expr ')'

; 


%%
void yyerror(char *s) {

	extern int yylineno;
	fprintf(stderr, "At line %d %s\n", yylineno , s);
 
 fprintf(stderr, "%s\n", s);

}

int main(void) 
{
	fout.open("mips_code.asm");

	fout<<".text\n.globl main\n\n";
	yyparse();
	cout<<"DONE"<<endl; 
	fout.close();
	return 0;
}