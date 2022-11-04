//Escreva uma funcao que conta o numero de nos de uma arvore binaria.

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

int CountNodes(Node *root) {
    int i = 0;
    i++;
    if(root->left != NULL)
        i += CountNodes(root->left);
    if(root->right != NULL)
        i += CountNodes(root->right);

    return i;
}

int main(int argc, char const *argv[])
{
    Node *treeRoot = NULL;

    Insert(&treeRoot, NewNode(10));
    Insert(&treeRoot, NewNode(11));
    Insert(&treeRoot, NewNode(12));
    Insert(&treeRoot, NewNode(9));
    Insert(&treeRoot, NewNode(19));
    Insert(&treeRoot, NewNode(20));
    Insert(&treeRoot, NewNode(-100));


    printf("\n%d", CountNodes(treeRoot));

    return 0;
}

