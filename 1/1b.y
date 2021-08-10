%{

#include<stdio.h>
#include<stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token num
%left '+' '-'
%left '*' '/'
%nonassoc UNMINUS

%%
exp:num{$$=$1;yylval=$$;}
|exp'+'exp{$$=$1+$3;yylval=$$;}
|exp'-'exp{$$=$1-$3;yylval=$$;}
|exp'*'exp{$$=$1*$3;yylval=$$;}
|exp'/'exp{if($3==0) {printf("divide by zero error\n");exit(0);}
else $$=$1/$3;yylval=$$;}
|'('exp')'{$$=$2;}
|'-'exp %prec UNMINUS{$$=$2;yylval=$$;}
;

%%

int main()
{
printf("enter an arithmetic expr to evaluate:\n");
yyparse();
printf("valid  expression\n");
printf("result=%d\n",yylval);
exit(0);
}

void yyerror()
{
printf("invalid  expression\n");
exit(0);
}
