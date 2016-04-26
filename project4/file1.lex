%{
#include <stdlib.h>
void yyerror(char *);
#include "y.tab.h"
%}
digit	[0-9]
letter	[a-zA-Z]
%%
var { return VAR;}
prototype	{ return PROTOTYPE;}
def	{ return DEF;}
int	{ return INT;}
bool	{ return BOOL;}
char {return CHAR;}
begin	{ return BEG;}
end 	{ return END;}
return	{ return RET;}
assign	{ return ASSIGN;}
call	{ return CALL;}
scan	{ return SCAN;}
print 	{ return PRINT;}
endl	{ return ENDL;}
space	{ return SPACE;}
while	{ return WHILE;}
if	{ return IF;}
then	{ return THEN;}
[-](_|{letter})(_|{letter}|{digit})*	{return ID;}
(_|{letter})(_|{letter}|{digit})*		{return ID;}
[-]{digit}+/[^a-zA-Z]					{return NUM;}
{digit}+/[^a-zA-Z]						{return NUM;}
[']{letter}[']							{return CH;}	
[|&%<>+\-*/;(),=~] return *yytext;
[ \t\n] ; /* skip whitespace */
. yyerror("invalid character");
%%	
int yywrap(void) {
 return 1;
}