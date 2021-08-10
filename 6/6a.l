%{
#include<stdio.h>
#include<stdlib.h>
int com=0;
%}

%%
"/*"[^\n]+"*/" {com++;}
"//"[^\n]+"//" {com++;}
%%

int main()
{

yyin = fopen("1.c","r");
yyout = fopen("res.c","w");
yylex();
fclose(yyin);
fclose(yyout);
printf("No of comments : %d\n",com);
}
