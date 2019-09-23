#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vld(char *s){
    //checking if any valid identifier or number;
    if(isdigit(s[0])){
        int i,ln=strlen(s);
        for(i=0;i<ln;i++)if(!isdigit(s[i]))return 0;//something like 0121abcd
        return 1;//number
    }
    else return 1;//variable name
}
int ln=0;
char ex[1000];

int mtc(int p,char *s){
    for(int i=0;i<3;i++){
        if(ex[p+i]!=s[i]) return 0;
    }
    return 1;
}

int repl(int pos){
    int p;
//in this function we will find if there is any (E) or EAE at pos position.
//if we find any we will replace it with /
    if(mtc(pos,"(E)")||mtc(pos,"EAE")){
        p=pos;
        do{
            ex[p]=ex[p+2];//left shifting 2 char;
        }while(ex[p]);//while last char is not null
        ex[pos]='E';
        return 1;
    }
    else return 0;//not found
}
int main()
{
    int i,j,a,b,ts,f=1,cn=0;
    char s[100];
    freopen("test.txt","r",stdin);
    // sample input: 0509 * ( 2 + val ) * num1 + 32235
    // input must be space saparated
    // we will use bottom up apporoch here
    while(scanf("%s",s)==1){
        if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'){
            ex[ln++]='A';//sign
        }
        else if(s[0]=='('||s[0]==')') ex[ln++]=s[0];
        else if(vld(s)){// if valid identifier or number
            ex[ln++]='E';
        }
        else{
            puts("Invalid Expression");
            return 0;
        }
    }

    puts("Valid Expression");

    return 0;
}

