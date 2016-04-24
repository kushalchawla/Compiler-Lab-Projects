%{
	#include <stdio.h>
	#include <vector>
	#include <string>
	#include <queue>
	#include<iostream>
	int yylex(void);
	extern int yylineno;
	void yyerror(char *);
	using namespace std;
	int deb=0;
	
	struct node
	{
		string name;
		int type;
		int val;
	};

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
| DEF DF
;


PF: INT FF 
| BOOL FF
| CHAR FF
;
FF: id '(' PARAM ')'
;
PARAM: INT id PP

| BOOL id PP
| CHAR id PP
;
PP: ',' PARAM  

|
;

DF: INT id '(' PARAM ')' BEG stmt_list RET V ';' END {cout<<"DF int parsed\n";}
| BOOL id '(' PARAM ')' BEG stmt_list RET V ';' END {cout<<"DF bool parsed\n";}
| CHAR id '(' PARAM ')' BEG stmt_list RET V ';' END {cout<<"DF CHAR parsed\n";}
;

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

int main(void) {
 yyparse();
 cout<<"DONE"<<endl; 
 return 0;
}