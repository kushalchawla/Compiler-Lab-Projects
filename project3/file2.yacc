%{								
 #include <stdio.h>
 int yylex(void);
 void yyerror(char *);
%}
%token VAR
%token PROTOTYPE
%token DEF
%token INT
%token BOOL
%token BEG
%token ENDL
%token RET
%token ASSIGN
%token CALL
%token SCAN
%token PRINT
%token SPACE
%token WHILE
%token IF
%token THEN
%token ID
%token NUM
%%
program:
 program expr '\n' { printf("valid\n"); }
 |
 ;
expr:
 VAR
| PROTOTYPE
| DEF
| INT
| BOOL
| BEG
| ENDL
| RET
| ASSIGN
| CALL
| SCAN
| PRINT
| SPACE
| WHILE
| IF
| THEN
| ID
| NUM
| '|'
| '&'
| '%'
| '<'
| '>'
| '+'
| '-'
| '*'
| '/'
| ';'
| '('
| ')'
| ','
| '='
;
%%
void yyerror(char *s) {
 fprintf(stderr, "%s\n", s);
}
int main(void) {
 yyparse();
 return 0;
}