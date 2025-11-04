#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data, height; struct Node *l, *r; } Node;

static int h(Node *n){ return n ? n->height : 0; }
static int max(int a,int b){ return a>b?a:b; }
static Node* nnode(int k){ Node *p = calloc(1,sizeof *p); p->data = k; p->height = 1; return p; }

static Node* rrot(Node *y){
    Node *x = y->l; y->l = x->r; x->r = y;
    y->height = 1 + max(h(y->l), h(y->r));
    x->height = 1 + max(h(x->l), h(x->r));
    return x;
}

static Node* lrot(Node *x){
    Node *y = x->r; x->r = y->l; y->l = x;
    x->height = 1 + max(h(x->l), h(x->r));
    y->height = 1 + max(h(y->l), h(y->r));
    return y;
}

static Node* insert(Node *node, int k){
    if(!node) return nnode(k);
    if(k < node->data) node->l = insert(node->l, k);
    else if(k > node->data) node->r = insert(node->r, k);
    else return node;
    node->height = 1 + max(h(node->l), h(node->r));
    int bal = h(node->l) - h(node->r);
    if(bal > 1 && k < node->l->data) return rrot(node);
    if(bal < -1 && k > node->r->data) return lrot(node);
    if(bal > 1 && k > node->l->data){ node->l = lrot(node->l); return rrot(node); }
    if(bal < -1 && k < node->r->data){ node->r = rrot(node->r); return lrot(node); }
    return node;
}

static void preorder(Node *r){ if(r){ printf("%d ", r->data); preorder(r->l); preorder(r->r); } }

int main(void){
    Node *root = NULL; int n;
    if(scanf("%d", &n)!=1) return 0;
    for(int i=0, v;i<n && scanf("%d",&v)==1;i++) root = insert(root, v);
    printf("Preorder: "); preorder(root); putchar('\n');
    return 0;
}
