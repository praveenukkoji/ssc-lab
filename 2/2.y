%{
#include<stdio.h>
#include<stdlib.h>
int valid;
%}

%token A B

%%
str: A expr B | B
expr: A expr|;

%%

int main()
{
printf("enter the string:\n");
yyparse();
printf("valid grammer\n");
exit(0);
}
yyerror()
{
printf("invalid gramer\n");
exit(0);
}
