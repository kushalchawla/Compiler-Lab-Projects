%option noyywrap

digit	[0-9]
letter	[a-zA-Z]	

%%

var 									printf("< var , - >\n");
prototype								printf("< prototype , - >\n");
def										printf("< def , - >\n");
int										printf("< int , - >\n");
bool									printf("< bool , - >\n");
begin									printf("< begin , - >\n");
end										printf("< end , - >\n");
return									printf("< return , - >\n");
assign									printf("< assign , - >\n");
call									printf("< call , - >\n");
scan									printf("< scan , - >\n");
print 									printf("< print , - >\n");
endl									printf("< endl , - >\n");
space									printf("< space , - >\n");
while									printf("< while , - >\n");
if										printf("< if , - >\n");
then									printf("< then , - >\n");
"|"										printf("< | , - >\n");
"&"										printf("< & , - >\n");
"%"										printf("< % , - >\n");
">"										printf("< > , - >\n");	
"<"										printf("< < , - >\n");
"+"										printf("< + , - >\n");
"-"										printf("< - , - >\n");
"*"										printf("< * , - >\n");
"/"										printf("< / , - >\n");
";"										printf("< ; , - >\n");
"("										printf("< ( , - >\n");
")"										printf("< ) , - >\n");
","										printf("< , , - >\n");
"="										printf("< = , - >\n");
[-](_|{letter})(_|{letter}|{digit})*	printf("< id , %s >\n",yytext); 
(_|{letter})(_|{letter}|{digit})*		printf("<id, %s >\n",yytext);
[-]{digit}+/[^a-zA-Z]					printf("< num , %s >\n",yytext);
{digit}+/[^a-zA-Z]						printf("< num , %s >\n",yytext);
" " 									printf(" ");
.										{printf("Error in '%s' in line %d\n",yytext,yylineno); return;}
%%

main()
{
  yylex();
}
