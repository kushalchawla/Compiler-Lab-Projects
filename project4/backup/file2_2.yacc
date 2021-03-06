%{
	#include <stdio.h>
	#include <vector>
	#include <string>
	#include <queue>
	#include <map>
	#include <set>
	#include <iostream>
	#include <fstream>
	#include <algorithm>

	int yylex(void);
	extern int yylineno;
	void yyerror(char *);
	using namespace std;
	
	struct node
	{
		string name;
		int type; //int 0; char 1, bool 2
		int val;
	};

	void yyerror(char *);

	extern char* yytext;

	struct symtab_entry
	{
		string name;
		int type; //int 0; char 1, bool 2
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
PARAM: INT id 
{
	$2.type=0;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	p_symtab.push_back(new_one);
}
PP 

| BOOL id 
{
	$2.type=2;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	p_symtab.push_back(new_one);
}
PP
| CHAR id 
{
	$2.type=1;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	p_symtab.push_back(new_one);
}
PP
|
;
PP: ',' PARAM  

|
;

DF: INT id
{
	scope++;

	if($2.name != "main" && prototyped_functions.find($2.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $2.name<<"' not pototyped before use\n";
	}

	else
	{
		f_name=$2.name;
		cout<<$2.name<<" definition begins .. \n";
		fout<<$2.name<<":\n";
		fout<<"move $fp $sp\n";	
		fout<<"sw $ra 0($sp)\n";
		fout<<"addiu $sp $sp -4\n\n";
	}
	p_symtab.clear();
	f_symtab.clear();
} DF1
| BOOL id
{
	scope++;
	if($2.name != "main" && prototyped_functions.find($2.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $2.name<<"' not pototyped before use\n";
	}

	else
	{
		f_name=$2.name;
		cout<<$2.name<<" definition begins .. \n";
		fout<<$2.name<<":\n";
		fout<<"move $fp $sp\n";	
		fout<<"sw $ra 0($sp)\n";
		fout<<"addiu $sp $sp -4\n\n";
	}
	p_symtab.clear();
	f_symtab.clear();
}
DF1
| CHAR id 
{
	scope++;
	if($2.name != "main" && prototyped_functions.find($2.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $2.name<<"' not pototyped before use\n";
	}

	else
	{
		f_name=$2.name;
		cout<<$2.name<<" definition begins .. \n";
		fout<<$2.name<<":\n";
		fout<<"move $fp $sp\n";	
		fout<<"sw $ra 0($sp)\n";
		fout<<"addiu $sp $sp -4\n\n";
	}
	p_symtab.clear();
	f_symtab.clear();

		
}DF1

;
DF1: '(' PARAM ')' { reverse(p_symtab.begin(), p_symtab.end()); } BEG stmt_list RET V ';' END 
{
	fout<<"\nlw $ra 4($sp)\n";
	fout<<"addiu $sp $sp "<<4*p_symtab.size() + 8<<"\n";
	fout<<"lw $fp 0($sp)\n";

	if(f_name=="main")
	{
		fout<<"li $v0 10\nsyscall\n\n\n";
	}
	else
	{
		fout<<"jr $ra\n\n\n";
	}
	cout<<"DF int parsed\n";
	p_symtab.clear();
	f_symtab.clear();
}


stmt_list: stmt stmt_list 
|
;
stmt: ASSIGN id '=' E_or_C ';' 
| WHILE expr BEG stmt_list END 
| IF expr BEG stmt_list END
| VAR DV ';'
;
DV: INT id 
{
	$2.type=0;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	f_symtab[scope].push_back(new_one);
	fout<<"li $t0,0\nsw $t0, 0($sp)\naddiu $sp $sp -4\n";
}
| BOOL id 
{
	$2.type=2;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	f_symtab[scope].push_back(new_one);
	fout<<"li $t0,0\nsw $t0, 0($sp)\naddiu $sp $sp -4\n";
}
| CHAR id
{
	$2.type=1;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	f_symtab[scope].push_back(new_one);
	fout<<"li $t0,0\nsw $t0, 0($sp)\naddiu $sp $sp -4\n";
}
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
	//cout<<"***"<<yytext<<"***"<<endl;
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