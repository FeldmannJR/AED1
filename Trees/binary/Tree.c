#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* insert(Node* root, Node* no)
{
	if (root == NULL) {
		root = no;
	} else {
		if (root->value->valor > no->value->valor) {
			root->left = insert(root->left, no);
			if (debug)
				printf("Botando %d a esquerda de %d \n", no->value->valor,
				    root->value->valor);
		} else if(root->value->valor < no->value->valor) {
			root->right = insert(root->right, no);
			if (debug)
				printf("Botando %d a direita de %d \n", no->value->valor,
				    root->value->valor);
		}else{
			printf("Node already in the tree!");
		}
	}
	return root;
}

Node** findNodeAtRight(Node** root)
{
	if ((*root)->right == NULL) {
		return root;
	}
	return findNodeAtRight(&((*root)->right));
}

void removeNode(Node** root, int valor)
{
	/*
  Se não tiver nenhum descendente só tira ele
  Se o no que for tirar tiver 1 descendente
  Se o no conter 2 descendentes
      Pega o no mais a direita da arvore da esquerda
  */
	if ((*root)->value->valor < valor) {
		removeNode(&(*root)->right, valor);
		return;
	}
	if ((*root)->value->valor > valor) {
		removeNode(&(*root)->left, valor);
		return;
	}
	//Se não tiver na direita,e le pega o valor da esquerda e puxa pra cima, mesmo se o da esquerda for nulo
	if ((*root)->right == NULL) {
		Node* tmp = *root;
		*root = (*root)->left;
		free(tmp);
		return;
	}
	//Se não tiver na esquerda puxa o da direita pra cima
	if ((*root)->left == NULL) {
		Node* tmp = *root;
		*root = (*root)->right;
		free(tmp);
		return;
	}
	//Agora se tiver nos dois ele pega o valor mais a direita da arvore da esquerda e subistitui
	Node** min = findNodeAtRight(&(*root)->left); //Elemento mais da direita da arvore da esquerda
	//Copia o valor do mais da direita pro atual
	(*root)->value = (*min)->value;
	//Agora se o minimo tiver um valor para a esquerda ele puxa pra cima
	Node* aux = *min;
	*min = (*min)->left;
	free(aux);
}

Node* createNode(int val)
{
	Entry* v = malloc(sizeof(Entry));
	v->valor = val;
	Node* n = malloc(sizeof(n));
	n->value = v;
	n->right = NULL;
	n->left = NULL;
	return n;
}

void printTree(Node* no)
{
	if (no != NULL) {
		printf(" [%d", no->value->valor);
		printTree(no->left);
		printTree(no->right);

		printf("]");
	} else {
		printf("[X]");
	}
}
