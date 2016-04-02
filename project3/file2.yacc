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
S1: VAR DV ';' 
{
$$=new node; 
$$->content="S1"; 
$$->children.push_back($1); 
$$->children.push_back($2);
$3 =new node;
$3->content="Semicolon";
$$->children.push_back($3);
} 
| PROTOTYPE PF ';' 
{
$$=new node; 
$$->content="S1"; 
$$->children.push_back($1); 
$$->children.push_back($2);
$3 =new node;
$3->content="Semicolon";
$$->children.push_back($3);


} 
| DEF DF 
{
$$=new node; 
$$->content="S1"; 
$$->children.push_back($1); 
$$->children.push_back($2);

} 
;
DV: INT id 
{
$$=new node; 
$$->content="DV";
$1=new node;
$1->content="INT";
$$->children.push_back($1); 
$$->children.push_back($2);
} 
| BOOL id 
{
$$=new node; 
$$->content="DV"; 
$$->children.push_back($1); 
$$->children.push_back($2);


} 
;
PF: INT FF 
{
$$=new node; 
$$->content="PF"; 
$$->children.push_back($1); 
$$->children.push_back($2);


} 

| BOOL FF
{
$$=new node; 
$$->content="PF"; 
$$->children.push_back($1); 
$$->children.push_back($2);


} 

;
FF: id '(' PARAM ')'
{

	$$=new node; 
$$->content="FF"; 
$$->children.push_back($1);
$2 = new node;
$2->content="(";
$$->children.push_back($2);

$4 = new node;
$4->content=")";
$$->children.push_back($4);
} 

;
PARAM: INT id PP {
$$=new node; 
	$1= new node;
	$1->content = "INT";
	$$->content = "PARAM";
	$$->children.push_back($1);

$$->children.push_back($2);
$$->children.push_back($3);


}| BOOL id PP
{
$$=new node; 
	$1= new node;
	$1->content = "BOOL";
	$$->content = "PARAM";
	$$->children.push_back($1);

$$->children.push_back($2);
$$->children.push_back($3);


}

;
PP: ',' PARAM  {
	$$=new node; 
	$1= new node;
	$1->content = "Comma";
	$$->content = "PP";
	$$->children.push_back($1);

$$->children.push_back($2);



}
|
{
	$$=new node; 
	$1= new node;
	$1->content = "Epsilon";
	$$->content = "PP";
	$$->children.push_back($1);




}
;

DF: id '(' PARAM ')' BEG stmt_list RET V ';' END
{
$$=new node; 
	$$->children.push_back($1);

	$2= new node;
	$2->content = "(";
	$$->content = "DF";
	$$->children.push_back($2);
	$$->children.push_back($3);
	
$4= new node;
	
	$4->content = ")";
	$$->children.push_back($4);
$5= new node;
	
	$5->content = "BEG";
	$$->children.push_back($5);
$$->children.push_back($5);
$6= new node;
	
	$6->content = "RET";
	$$->children.push_back($6);

$$->children.push_back($7);
$8= new node;
	
	$8->content = ";";
	$$->children.push_back($8);

$9= new node;
	
	$9->content = "END";
	$$->children.push_back($9);



}
;

stmt_list: stmt stmt_list 
{
$$=new node; 
	$$->content="Stmt list";
	$$->children.push_back($1);
$$->children.push_back($2);




}

|
{
	$$=new node; 
	$1= new node;
	$1->content = "Epsilon";
	$$->content = "Stmt List";
	$$->children.push_back($1);




}

;
stmt: ASSIGN id '=' E_or_C ';' 

{
$$=new node; 
	$$->content="Stmt";
$1= new node;
$1->content= "ASSIGN";
	$$->children.push_back($1);
$$->children.push_back($2);
$3= new node;
$3->content= "Equals";
	$$->children.push_back($3);
$$->children.push_back($4);
	$5= new node;
$5->content= "Semicolon";
	$$->children.push_back($5);




}

| SCAN id ';' 
{
$$=new node; 
	$$->content="Stmt";
$1= new node;
$1->content= "SCAN";
	$$->children.push_back($1);
$$->children.push_back($2);
$3= new node;
$3->content= "Semicolon";
	$$->children.push_back($3);


}

| PRINT V1 ';' {
$$=new node; 
	$$->content="Stmt";
$1= new node;
$1->content= "PRINT";
	$$->children.push_back($1);
$$->children.push_back($2);
$3= new node;
$3->content= "Semicolon";
	$$->children.push_back($3);


}| WHILE expr BEG stmt_list END 
{
$$=new node; 
	$$->content="Stmt";
$1= new node;
$1->content= "WHILE";
	$$->children.push_back($1);
$$->children.push_back($2);
$3= new node;
$3->content= "BEG";
	$$->children.push_back($3);
$$->children.push_back($4);
$5= new node;
$5->content= "END";
	$$->children.push_back($5);
}
| IF expr BEG stmt_list END
{
$$=new node; 
	$$->content="Stmt";
$1= new node;
$1->content= "IF";
	$$->children.push_back($1);
$$->children.push_back($2);
$3= new node;
$3->content= "BEG";
	$$->children.push_back($3);
$$->children.push_back($4);
$5= new node;
$5->content= "END";
	$$->children.push_back($5);
}
;
E_or_C: expr 
{

	$$=new node;
	$$->content="E_or_C";
	$$->children.push_back($1);
}
| CALL id '(' PARAM1 ')' ';'
{
$$=new node; 
	$$->content="E_or_C";
$1= new node;
$1->content= "CALL";
	$$->children.push_back($1);
$$->children.push_back($2);
$3= new node;
$3->content= "(";
	$$->children.push_back($3);
$$->children.push_back($4);
$5= new node;
$5->content= ")";
	$$->children.push_back($5);
$6= new node;
$6->content= ";";
	$$->children.push_back($6);

}
;
PARAM1: V PP1
{
$$= new node;
$$->content= "PARAM1";
	$$->children.push_back($5);
}
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
id: ID 
{
	$$=new node;
	$$->content="id";
	$1=new node;
	$1->content="ID";
	$$->children.push_back($1);
}

| '~' ID	
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