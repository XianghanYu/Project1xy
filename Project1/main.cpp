#include <stdio.h> 
#include "y.tab.h"
extern int yylex();
extern FILE *yyin;
YYSTYPE yylval;
int main(int argc, char* argv[]) 
{
	fopen_s(&yyin, argv[1], "r");

	int token;  
	do 
	{ 
		token = yylex();   
		printf("next token: "); 
		switch (token) 
		{ 
			case Literal:                 
				printf("Literal (%d)\n", yylval.num);                 
				break;             
			case IndentifierName:
				printf("IndentifierName (%s)\n", yylval.name);                 
				break;             
			case IF:                 
				printf("IF\n");                 
				break;             
			case ELSE:                 
				printf("ELSE\n");                 
				break;             
			case INT:                 
				printf("INT\n");                 
				break;             
			case BOOL:                 
				printf("BOOL\n");                 
				break;             
			case 0:                 
				printf("EOF\n");                 
				break;             
			default:                 
				printf("'%c'\n", token);                 
				break; 
		}
	} 
	while (token != 0);

	return 0;
}