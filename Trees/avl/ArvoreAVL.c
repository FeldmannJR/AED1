#include <stdio.h>
#include "../binary/Tree.h"

int height(Node* root)
{
	if (root == NULL) {
		return 0;
	}
	int altEsq = height(root->left);
	int altDir = height(root->right);
	if (altEsq > altDir) {
		return altEsq + 1;
	} else {
		return altDir + 1;
	}
}

int FB(Node* root) { return height(root->left) - height(root->right); }

int main(){
    printf("%d",debug);
    int teste[] = {15,27,49,10,67,59,9,13,20,19};
    int si = sizeof(teste)/sizeof(int);
    Node *raiz = NULL;
    for(int x =0;x<si;x++){
        raiz = insert(raiz,createNode(teste[x]));
    }
}
