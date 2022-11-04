//Escreva uma funcao que conta o numero de folhas uma arvore binaria.

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

int Height(Node *root) {
    int left = 0, right = 0;
    
    if(root == NULL)
        return 0;
    else {
        left = Height(root->left);
        right = Height(root->right);

        if(left > right)
            return left + 1;
        else
            return right + 1;
    }
}

void Remove(Node **root, int id) {
    if( (*root)->id == id )
        if( (*root)->left == NULL )
}

int main(int argc, char const *argv[])
{
    Node *treeRoot = NULL;

    Insert(&treeRoot, NewNode(10));
    Insert(&treeRoot, NewNode(9));
    Insert(&treeRoot, NewNode(8));
    Insert(&treeRoot, NewNode(7));
    Insert(&treeRoot, NewNode(11));


    printf("\n%d", Height(treeRoot));

    return 0;
}

