%{
#include<stdio.h>
int id=0,op=0.,br=0;
%}

%%
[0-9]+ { id++; printf("\n the identifer \n");ECHO;}
[+|*] { op++; printf("\n the operator \n");ECHO;}
"(" {br++;}
")" { if(br==0) {br=1;return 0;} else br--;}
%%

int main()
{
printf("enter the expression \n");
yylex();

if((op+1)==id && br==0)
{
printf("\n valid expression");
printf("\n no of identifers :%d", id);
printf("\n no of operators: %d \n", op);
}
else{
printf("\n invalid expression\n");
}
}
