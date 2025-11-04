#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int prec(char c){ if(c=='^')return 3; if(c=='*'||c=='/')return 2; if(c=='+'||c=='-')return 1; return 0; }
int isop(char c){ return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }

void infixToPostfix(const char *in, char *out){
    char st[N]; int top=-1,i=0,j=0;
    while(in[i]){
        char c=in[i++]; if(isspace(c)) continue;
        if(isalnum(c)) out[j++]=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){ while(top>=0 && st[top]!='(') out[j++]=st[top--]; if(top>=0) top--; }
        else if(isop(c)){
            while(top>=0 && st[top]!='(' && (prec(st[top])>prec(c) || (prec(st[top])==prec(c) && c!='^'))) out[j++]=st[top--];
            st[++top]=c;
        }
    }
    while(top>=0) out[j++]=st[top--];
    out[j]=0;
}

int main(){
    char in[N], out[N];
    if(!fgets(in,N,stdin)) return 0;
    in[strcspn(in,"\n")]=0;
    infixToPostfix(in,out);
    printf("%s\n", out);
    return 0;
}
