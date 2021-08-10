%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"y.tab.h"
%}

%%
[0-9a-zA-Z] { printf("identifiers is:%s\n",yytext);return ID;}
[+|-|/|*|<|>|{|}|(|)|%|=] {printf("operators is %s\n",yytext);return OP;}
if|else|void|main|int|float|double|char|for|return {printf("keywords is %s\n",yytext);return KEY;}
 .
%%
