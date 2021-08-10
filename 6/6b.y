%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int id=0,op=0,key=0;
%}

%token ID OP KEY

%%
prog: ID prog{++id;}
|OP prog{++op;}
|KEY prog{++key;}
|ID {++id;}
|OP{++op;}
|KEY{++key;}
;
%%

extern FILE*yyin;
int main()
{
    yyin = fopen("1.c","r");
    yyparse();
    printf("identifier: %d\n",id);
    printf("operator:%d\n",op);
    printf("keyword : %d\n",key);
    return 0;
}

int yyerror(){
    printf("some error occured\n");
    exit(0);
}
