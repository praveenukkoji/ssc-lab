#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int k=0,z=0,i=0,j=0,c=0;
char a[20],ac[20],stk[20],act[20];

void check() {
    strcpy(ac,"REDUCE TO E\n");
    for(z=0;z<c;z++)
    {
        if(stk[z]=='i'&& stk[z+1]=='d') {
            stk[z]='E';
            stk[z+1]='\0';
            printf("\n$%s\t%s$\t%s",stk,a,ac);
            j++;
        }
        if(stk[z]=='E'&& stk[z+1]=='+'&&stk[z+2]=='E') {
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("\n$%s\t%s$\t%s",stk,a,ac);
            i=i-2;
        }
        if(stk[z]=='E'&& stk[z+1]=='*' && stk[z+2]=='E') {
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("\n$%s\t%s$\t%s",stk,a,ac);
            i=i-2;
        }
        if(stk[z]=='('&& stk[z+1]=='E' && stk[z+2]==')') {
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("\n$%s\t%s$\t%s",stk,a,ac);
            i=i-2;
        }
    }
}

int main() {
    puts("GRAMMAR is E->E+E\n E->E*E\n E->(E)\nE->id");
    puts("enter the string");
    gets(a);
    c=strlen(a);
    strcpy(act,"SHIFT->");
    puts("stack\t input\t action");
    for(k=0,i=0;j<c;k++,i++,j++)
    {
        if(a[j]=='i'&& a[j+1]=='d') {
            stk[i]=a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j]=' ';
            a[j+1]=' ';
            printf("\n$%s\t%s\t%sid",stk,a,act);
            check();
        } else {
            stk[i]=a[j];
            stk[i+1]='\0';
            a[j]=' ';
            printf("\n$%s\t%s$\t%ssymbol",stk,a,act);
            check();
        }
    }
    return 0;
}
