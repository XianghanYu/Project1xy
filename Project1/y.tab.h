enum yytokentype 
{
	Literal = 258,
	IndentifierName = 259,
	IF = 260, 
	ELSE = 261, 
	INT = 262, 
	BOOL = 263
}; 
union YYSTYPE 
{
	char* name;     
	int num; 
};

extern YYSTYPE yylval;

