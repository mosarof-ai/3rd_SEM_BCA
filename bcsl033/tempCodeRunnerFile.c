#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int c, e; struct Node *n; } Node;

Node* mk(int c,int e){ Node* p=malloc(sizeof *p); p->c=c; p->e=e; p->n=NULL; return p; }

void ins(Node **h,int c,int e){
    if(c==0) return;
    Node **pp=h;
    while(*pp && (*pp)->e>e) pp=&(*pp)->n;
    if(*pp && (*pp)->e==e){ (*pp)->c+=c; if((*pp)->c==0){ Node *t=*pp; *pp=(*pp)->n; free(t); } return; }
    Node *x=mk(c,e); x->n=*pp; *pp=x;
}

Node* input(int id){
    int n,c,e; Node *h=NULL;
    printf("\nPoly %d terms: ", id);
    if(scanf("%d",&n)!=1) return NULL;
    for(int i=0;i<n;i++){ scanf("%d%d",&c,&e); ins(&h,c,e); }
    return h;
}

Node* combine(Node *a, Node *b, int sign){ Node *r=NULL; for(;a;a=a->n) ins(&r,a->c,a->e); for(;b;b=b->n) ins(&r,sign*b->c,b->e); return r; }

void show(Node *h){
    if(!h){ printf("0\n"); return; }
    int first=1;
    for(;h;h=h->n){
        if(h->c==0) continue;
        if(!first){ printf(h->c>0?" + ":" - "); } else if(h->c<0){ printf("-"); }
        int v = first ? abs(h->c) : abs(h->c);
        if(first && h->c<0) v = -h->c; // already printed '-' so keep magnitude positive
        printf("%d", v);
        if(h->e!=0) printf("x%s%d", h->e==1?"":"^", h->e);
        first=0;
    }
    printf("\n");
}

void freeP(Node *h){ while(h){ Node*t=h; h=h->n; free(t);} }

int main(){
    Node *p1=input(1), *p2=input(2);
    printf("\nPoly1: "); show(p1);
    printf("Poly2: "); show(p2);
    Node *sum=combine(p1,p2,1), *diff=combine(p1,p2,-1);
    printf("\nSum: "); show(sum);
    printf("Diff: "); show(diff);
    freeP(p1); freeP(p2); freeP(sum); freeP(diff);
    return 0;
}
