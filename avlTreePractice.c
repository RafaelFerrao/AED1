#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

typedef struct Data {
    int value;
} Data;

typedef struct Node {
    Data *data;
    struct Node *left;
    struct Node *right;

} Node;

Node *CreateNewElement(int value) {
    Node *n = (Node *)malloc(sizeof(Node));
    Data *d = (Data *)malloc(sizeof(Data));
    n->data = d;
    n->data->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}



void PrintNode(Node *n) {
    printf("\n%d - %d", n, n->data->value);
}

bool IsLeaf(Node *n) {
    return (n->left == NULL && n->right == NULL);
}

void PreOrder(Node *root) {
    PrintNode(root);
    if(root->left != NULL)
        PreOrder(root->left);
    if(root->right != NULL)
        PreOrder(root->right);
}

void Central(Node *root) {

    if(IsLeaf(root))
        PrintNode(root);
    else {
        if(root->left != NULL)
            Central(root->left);
        PrintNode(root);
        if(root->right != NULL)
            Central(root->right);
    }
}

void PostOrder(Node *root) {
    if(root->left != NULL)
        PostOrder(root->left);
    if(root->right != NULL)
        PostOrder(root->right);
    PrintNode(root);

}

void ClearTree(Node *root) {
    if(root->left != NULL)
        ClearTree(root->left);
    if(root->right != NULL)
        ClearTree(root->right);
    free(root->data);
    free(root);
}

void SRR(Node **root) {
    Node *aux;
    aux = (*root)->left;
    (*root)->left = aux->right;
    aux->right = (*root);
    (*root) = aux;
}

void SLR(Node **root) {
    Node *aux;
    aux = (*root)->right;
    (*root)->right = aux->left;
    aux->left = (*root);
    (*root) = aux;
}

int Heigth(Node *root) {
    int left = 0, right = 0;
    if(root == NULL)
        return 0;
    left = Heigth(root->left);
    right = Heigth(root->left);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

int VerifyBF(Node *root) {
    return Heigth(root->left) - Heigth(root->right);
}

void BalanceLeft(Node **root) {
    int lbf = VerifyBF ( (*root)->left );
    if (lbf > 0) {
        SRR(root);
        return;
    }
    else if (lbf < 0) {
        SLR( &((*root)->left) );
        SRR( &(*root) );
        return;
    }
}

void BalanceRight(Node **root) {

    int rbf = VerifyBF ( (*root)->right );
    if (rbf > 0) {
        SLR(root);
        return;
    }
    else if (rbf < 0) {
        SRR( &((*root)->right) );
        SLR( &(*root) );
        return;
    }
}

void Balance(Node **root) {
    int bf = VerifyBF(*root);

    if(bf > 1)
        BalanceLeft(root);
    else if (bf < -1)
        BalanceRight(root);

}

void Insert(Node **root, Node *n) {

    if(*root == NULL)
        *root = n;
    else
        if(n->data->value < (*root)->data->value && (*root)->left != NULL)
            Insert(&(*root)->left, n);
        else if(n->data->value < (*root)->data->value && (*root)->left == NULL)
            (*root)->left = n;
        
        else if ((n->data->value > (*root)->data->value && (*root)->right != NULL))
            Insert(&(*root)->right, n);
        else if ((n->data->value > (*root)->data->value && (*root)->right == NULL)) 
            (*root)->right = n;

        Balance(root);
        
        
}

int main(int argc, char const *argv[])
{
    Node *treeRoot = NULL;

    Insert(&treeRoot, CreateNewElement(30));
    Insert(&treeRoot, CreateNewElement(20));
    Insert(&treeRoot, CreateNewElement(10));


    PreOrder(treeRoot);
    printf("\n");

    PrintNode(treeRoot);




    // SLR(&treeRoot);

    // printf("\n%d", VerifyBF(treeRoot));


    // PreOrder(treeRoot);

    
    // PostOrder(treeRoot);
    // ClearTree(treeRoot);
    // printf("\nTeste");
    // PostOrder(treeRoot);


    return 0;
}
