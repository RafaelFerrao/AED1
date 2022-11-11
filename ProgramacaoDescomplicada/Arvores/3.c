//Escreva uma funcao que conta o numero de nos nao-folha uma arvore binaria.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    struct Node *left;
    struct Node *right;
} Node;

Node *NewNode(int id) {
    Node *n = malloc(sizeof(Node));
    n->id = id;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void Insert(Node **root, Node *n) {
    if((*root) == NULL)
        (*root) = n;
    else
        if( n->id < (*root)->id )
            Insert(&(*root)->left, n);
        else if ( n->id > (*root)->id )
            Insert(&(*root)->right, n);
}

int IsLeaf(Node *n) {
    return (n->left == NULL && n->right == NULL);
}

int CountNotLeafNodes(Node *root) {
    int i = 0;
    
    if(!IsLeaf(root))
        i++;

    if(root->left != NULL)
        i += CountNotLeafNodes(root->left);
    if(root->right != NULL)
        i += CountNotLeafNodes(root->right);

    return i;
}

int main(int argc, char const *argv[])
{
    Node *treeRoot = NULL;

    Insert(&treeRoot, NewNode(10));
    Insert(&treeRoot, NewNode(5));
    Insert(&treeRoot, NewNode(15));
    Insert(&treeRoot, NewNode(16));

    Insert(&treeRoot, NewNode(4));
    Insert(&treeRoot, NewNode(6));





    printf("\n%d", CountNotLeafNodes(treeRoot));

    return 0;
}

