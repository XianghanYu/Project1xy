%{ 
#include <y.tab.h> 
#include <stdio.h> 
%} 
 
digit [0-9] 
letter [a-zA-Z] 
 
%% 
{letter}({letter}|{digit})*	{ yylval.name = _strdup(yytext); return IndentifierName; }
"=" 						{ return '='; }
[ \r\n\t]					/* skip whitespaces */
{digit}+					{ yylval.num = atoi(yytext); return Literal; }
";" 						{ return ';'; }

 
.                           {                                  
								fprintf(stderr, "invalid character '%c'\n", *yytext);                                 
								exit(0);                             
							} 
%% 
 
int yywrap() 
{     
	return 1; 
} 