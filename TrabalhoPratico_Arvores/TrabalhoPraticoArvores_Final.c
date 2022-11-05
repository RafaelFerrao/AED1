#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Node;

Node *NewNode(int id) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->id = id;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void Insert(Node **root, Node *n) {
    if( *root == NULL )
        *root = n;
    else {
        if( n->id < (*root)->id )
            Insert( &(*root)->left, n );
        else if ( n->id > (*root)->id )
            Insert( &(*root)->right, n );
        else
            free(n);
    }
}

int Height(Node *root) {
    int left = 0, right = 0;

    if(root == NULL)
        return 0;

    left = Height(root->left);
    right = Height(root->right);

    if(left > right)
        return left + 1;
    else 
        return right + 1;    
}

int VerifyBF(Node *root) {
    return Height(root->left) - Height(root->right);
}

int IsAvlTree(Node *root) {

    int res = 1; // Comecamos supondo que eh arvore avl
    int bf;

    bf = VerifyBF(root);

    if(bf > 1 || bf < -1) {
        res = 0;
        return res;
    }

    if(res == 1 && root->left != NULL)
        res = IsAvlTree(root->left);
    
    if(res == 1 && root->right != NULL)
        res = IsAvlTree(root->right);
        

    if(res == 0)
        return 0;

    return 1;

}

int IsLeaf(Node *n) {
    return n->right == NULL && n->left == NULL;
}

//            30
//        20     40
//      10  25


void PreOrder(Node *root) {
    printf("\n%d", root->id);
    if(root->left != NULL)
        PreOrder(root->left);
    if(root->right != NULL)
        PreOrder(root->right);
}

void ClearTree(Node *root) {
    if(root->left != NULL)
        ClearTree(root->left);
    if(root->right != NULL)
        ClearTree(root->right);
    free(root);
}


int main(int argc, char const *argv[])
{

    Node *treeRoot = NULL;

    int id;

    do {
        printf("\nInsert a number or insert 0 to quit");
        printf("\nYour choice: ");
        scanf("%d", &id);

        if( id != 0)
            Insert(&treeRoot, NewNode(id));

    } while (id != 0);
    

    printf("PreOrder Tree Print: ");
    PreOrder(treeRoot);

    int result = IsAvlTree(treeRoot);
    if( result == 1 )
        printf("\nThis is an AVL tree");
    else
        printf("\nThis is not an AVL tree");

    ClearTree(treeRoot);

    return 0;
}
