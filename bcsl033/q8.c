#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node *createNode(int d) {
    struct Node *n = malloc(sizeof *n);
    n->data = d; n->left = n->right = NULL; return n;
}

struct Node *insert(struct Node *r, int d) {
    if (!r) return createNode(d);
    if (d < r->data) r->left = insert(r->left, d);
    else if (d > r->data) r->right = insert(r->right, d);
    else printf("Duplicate %d\n", d);
    return r;
}

struct Node *findMin(struct Node *r) { while (r && r->left) r = r->left; return r; }

struct Node *deleteNode(struct Node *r, int d) {
    if (!r) { printf("%d not found\n", d); return NULL; }
    if (d < r->data) r->left = deleteNode(r->left, d);
    else if (d > r->data) r->right = deleteNode(r->right, d);
    else {
        if (!r->left) { struct Node *t = r->right; free(r); return t; }
        if (!r->right) { struct Node *t = r->left; free(r); return t; }
        struct Node *s = findMin(r->right); r->data = s->data; r->right = deleteNode(r->right, s->data);
    }
    return r;
}

struct Node *search(struct Node *r, int d) { return (!r || r->data == d) ? r : (d < r->data ? search(r->left, d) : search(r->right, d)); }

void inorder(struct Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(struct Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

void printTree(struct Node *r, int s) {
    if (!r) return;
    s += 4;
    printTree(r->right, s);
    printf("\n");
    for (int i = 4; i < s; ++i) putchar(' ');
    printf("%d\n", r->data);
    printTree(r->left, s);
}

int countNodes(struct Node *r) { return r ? 1 + countNodes(r->left) + countNodes(r->right) : 0; }
int height(struct Node *r) { if (!r) return 0; int lh = height(r->left), rh = height(r->right); return (lh > rh ? lh : rh) + 1; }
void freeTree(struct Node *r) { if (r) { freeTree(r->left); freeTree(r->right); free(r); } }

int main(void) {
    struct Node *root = NULL; int n, ch, val;
    printf("Enter number of initial elements: ");
    if (scanf("%d", &n) == 1 && n > 0) for (int i = 0; i < n; ++i) { scanf("%d", &val); root = insert(root, val); }

    do {
        printf("\n1:Insert 2:Delete 3:Search 4:Inorder 5:Preorder 6:Postorder\n");
        printf("7:Display 8:Min 9:Max 10:Count 11:Height 12:Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &val); root = insert(root, val); break;
            case 2: printf("Value: "); scanf("%d", &val); root = deleteNode(root, val); break;
            case 3: printf("Value: "); scanf("%d", &val); printf(search(root, val) ? "Found\n" : "Not found\n"); break;
            case 4: inorder(root); printf("\n"); break;
            case 5: preorder(root); printf("\n"); break;
            case 6: postorder(root); printf("\n"); break;
            case 7: if (!root) printf("Empty\n"); else { printTree(root, 0); } break;
            case 8: { struct Node *m = findMin(root); if (m) printf("Min: %d\n", m->data); else printf("Tree empty\n"); } break;
            case 9: { struct Node *t = root; while (t && t->right) t = t->right; if (t) printf("Max: %d\n", t->data); else printf("Tree empty\n"); } break;
            case 10: printf("Count: %d\n", countNodes(root)); break;
            case 11: printf("Height: %d\n", height(root)); break;
            case 12: freeTree(root); break;
            default: printf("Invalid\n");
        }
    } while (ch != 12);
    return 0;
}
