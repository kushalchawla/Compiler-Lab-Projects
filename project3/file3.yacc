%{								
#include <stdio.h>
 #include <vector>
 #include <string>
 #include<iostream>
 int yylex(void);
 void yyerror(char *);
using namespace std;
 
 struct node
 {
 	string content;
 	vector<node *> children;
 };

#define YYSTYPE node*
 node *root;
%}
%token VAR
%token PROTOTYPE
%token DEF
%token INT
%token BOOL
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
Start: S 
{ printf("valid\n"); 
$$=new node; 
root=$$;
$$->content="Start";
$$->children.push_back($1);
}
;
S: S1 S
{
$$=new node; 
$$->content="S"; 
$$->children.push_back($1); 
$$->children.push_back($2);
} 
| 
{
	$$=new node; 
	$$->content="epsilon"; 
}
;
S1: VAR DV ';' | PROTOTYPE PF ';' | DEF DF 
;
DV: INT id | BOOL id 
;
PF: INT FF | BOOL FF
;
FF: id '(' PARAM ')'
;
PARAM: INT id PP | BOOL id PP
;
PP: ',' PARAM 
|
;

DF: id '(' PARAM ')' BEG stmt_list RET V ';' END
;

stmt_list: stmt stmt_list 
|
;
stmt: ASSIGN id '=' E_or_C ';' | SCAN id ';' | PRINT V1 ';' | WHILE expr BEG stmt_list END | IF expr BEG stmt_list END
;
E_or_C: expr | CALL id '(' PARAM1 ')' ';'
;
PARAM1: V PP1
; 
PP1: ',' PARAM1 
|
;

V: num | id
;
V1: id | num | SPACE | ENDL
;
num: NUM | '~' NUM
;
id: ID | '~' ID	
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
L1: '+' AS L1 | '-' AS L1 
|
;

AS: MD AS1
;
AS1: '*' MD AS1 | '/' MD AS1 
|
;

MD: num | id | '(' expr ')'
; 


%%
void yyerror(char *s) {
 fprintf(stderr, "%s\n", s);
}
int main(void) {
 yyparse();
 cout<<"DONE"<<endl;
 cout<<root->content<<endl;
 return 0;
}