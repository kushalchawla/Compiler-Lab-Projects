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
begin	{ return BEG;}
endl	{ return ENDL;}
return	{ return RET;}
assign	{ return ASSIGN;}
call	{ return CALL;}
scan	{ return SCAN;}
print 	{ return PRINT;}
space	{ return SPACE;}
while	{ return WHILE;}
if	{ return IF;}
then	{ return THEN;}
[-](_|{letter})(_|{letter}|{digit})*	{return ID;}
(_|{letter})(_|{letter}|{digit})*		{return ID;}
[-]{digit}+/[^a-zA-Z]					{return NUM;}
{digit}+/[^a-zA-Z]						{return NUM;}
[|&%<>+\-*/;(),=\n] return *yytext;
[ \t] ; /* skip whitespace */
. yyerror("invalid character");
%%	
int yywrap(void) {
 return 1;
}