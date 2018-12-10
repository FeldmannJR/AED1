#ifndef ARVORE_BASE 
#define ARVORE_BASE

#define debug 0

typedef struct Entry{
    int valor;
}Entry;

typedef struct Node{
    struct Entry *value;
    struct Node *right;
    struct Node *left;
}Node;

void removeNode(Node** raiz, int valor);
void printTree(Node *no);
Node* createNode(int val);
Node* insert(Node *raiz,Node *no);
void printTree ( Node *root );
int height(Node *raiz);

#endif