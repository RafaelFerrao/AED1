// Implementar uma agenda (nome, idade, telefone) que armazena os dados numa 
// árvore binária de busca (usuário escolhe qual dado é o fator de precedência). 
// A agenda deve permitir incluir, buscar, remover e imprimir toda a árvore usando pré-ordem, central e pós-ordem.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int balancementFactorChoice = 0;

typedef struct _person {
    char *name;
    int age;
    int tel;
} Person;

typedef struct _node {
    Person person;
    struct _node *left;
    struct _node *right;
} Node;

typedef struct _tree {
    Node *root;
} Tree;

Tree *Reset() {
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree; 
}

Node *CreateNode(char *name, int age, int tel) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->person.name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(n->person.name, name);
    n->person.age = age;
    n->person.tel = tel;
    n->left = NULL;
    n->right = NULL;

    return n;
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

int VerifyBF(Node *root) {
    int heightLeft = 0;
    int heightRight = 0;

    if(root->left != NULL) 
        heightLeft = Height(root->left);

    if(root->right != NULL) 
        heightRight = Height(root->left);
    
    return heightLeft - heightRight;

}

void SRL(Node** root)
{
    Node *nodeTemp;
    nodeTemp = (*root)->right;
    (*root)->right = nodeTemp->left;
    nodeTemp->left = (*root);
    (*root) = nodeTemp;
}

void SRR(Node** root)
{
    Node *nodeTemp;
    nodeTemp = (*root)->left;
    (*root)->left = nodeTemp->right;
    nodeTemp->right = (*root);
    (*root) = nodeTemp;
}

int BalanceLeft(Node **root) {
    int bf = VerifyBF( (*root)->left );
    if(bf > 0) {
        SRR(root);
        return 1;
    }
    else if ( bf < 0) {
        SRL( &((*root)->left));
        SRR( root );
        return 1;
    }
    return 0;
}

int BalanceRight(Node **root) {
    int bf = VerifyBF( (*root)->right );
    if(bf < 0) {
        SRL(root);
        return 1;
    }
    else if ( bf > 0) {
        SRR( &((*root)->right));
        SRL( root );
        return 1;
    }
    return 0;
}

int Balance(Node **root) {
    int bf = VerifyBF(*root);

    if (bf > 1)
        return BalanceLeft(&(*root));
    else if (bf < -1)
        return BalanceRight(&(*root));
    else
        return 0;
}

int IsLeaf(Node *root) {
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return 0;
}

void PrintPerson(Node *n) {
        printf("\nName: %s | Age: %d | Telephone: %d", n->person.name, n->person.age, n->person.tel);
}

void Search(Node *root, char *name) {
    if(strcmp(name, root->person.name) == 0){
        PrintPerson(root);
        return;
    } else {
        if(strcmp(name, root->person.name) < 1) {
            if(root->left != NULL)
                Search(root->left, name);
        } else {
            if(root->right != NULL)
                Search(root->right, name);
        }
    }
}

void InsertNode(Node **root, Node *n) {
    int result = 0;
    if(balancementFactorChoice == 0)
        result = strcmp(n->person.name, (*root)->person.name) < 1;
    else 
        if (balancementFactorChoice == 1)
            result = n->person.age < (*root)->person.age;
        else 
            if (balancementFactorChoice == 2)
                result = n->person.tel < (*root)->person.tel;

    if(result == 1)
        if((*root)->left == NULL)
            (*root)->left = n;
        else
            InsertNode(&(*root)->left, n);
    else
        if((*root)->right == NULL)
            (*root)->right = n;
        else
            InsertNode(&(*root)->right, n);

    Balance(&(*root));
}

void Push(Tree *tree, Node *n) {
    if(tree->root == NULL)
        tree->root = n;
    else
        InsertNode(&(tree->root), n);
}

void PreOrder(Node *root){
    PrintPerson(root);
    if(root->left != NULL)
        PreOrder(root->left);
    if(root->right != NULL)
        PreOrder(root->right);
}

void Central(Node *root){
    if(IsLeaf(root) == 1)
        PrintPerson(root);
    else {
        if(root->left != NULL)
            Central(root->left);
        PrintPerson(root);
        if(root->right != NULL) 
            Central(root->right);          
    }
}

void PostOrder(Node *root) {
    if(root->left != NULL)
        PostOrder(root->left);
    if(root->right != NULL)
        PostOrder(root->right);
    PrintPerson(root);
}

void PrintTreeIdentationStyle(Node *n) {
    int height = Height(n);
    if(IsLeaf(n) == 1){
        for(int i = 0; i < height; i++)
            printf(" ");
        printf("Name: %s | Age: %d | Telephone: %d | alt: %d \n", n->person.name, n->person.age, n->person.tel, Height(n));
    }
    else {
        if(n->left != NULL)
            PrintTreeIdentationStyle(n->left);
        for(int i = 0; i < height; i++)
            printf(" ");
        printf("Name: %s | Age: %d | Telephone: %d | alt: %d\n", n->person.name, n->person.age, n->person.tel, Height(n));
        if(n->right != NULL)
            PrintTreeIdentationStyle(n->right);    
    }
}

char *ReadName() {
    char *str = NULL;
    int i = 0, j = 2, c;
    str = (char*)malloc(sizeof(char));
    //error checking
    if (str == NULL) {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    while((c = getc(stdin)) && c != '\n')
    {
        str[i] = c;
        str = realloc(str,j*sizeof(char));
        //error checking
        if (str == NULL) {
            printf("Error allocating memory\n");
            free(str);
            exit(EXIT_FAILURE);
        }

        i++;
        j++;
    }
    str[i] = '\0';
    printf("\n%s", str);
    return str;
}

int main(int argc, char const *argv[]) {
    
    do
    {
        printf("\nWich Balancement Factor you want to use to insert, remove and search elements in the tree?");
        printf("\n 0 - Name");
        printf("\n 1 - Age");
        printf("\n 2 - Telephone");
        printf("\nYour choice: ");
        scanf("%d", &balancementFactorChoice);

    } while (balancementFactorChoice < 0 || balancementFactorChoice > 2);
    
    printf("\nBalance Factor set!\n");


    Tree *tree = Reset();

    int userSelect = 1, age, tel, printOrder = 0;
    char *name;

    do
    {
        
        printf("\n1 - Insert person");
        printf("\n2 - Remove person");
        printf("\n3 - Search person");
        printf("\n4 - Print tree");

        printf("\n0 - Exit");
        printf("\nYour choice:");
        setbuf( stdin, NULL );
        scanf("%d", &userSelect);

        switch (userSelect)
        {
        case 1:
            printf("\nInsert the person's name: ");
            setbuf( stdin, NULL );
            name = ReadName();
            printf("\nInsert the person's age: ");
            setbuf( stdin, NULL );
            scanf("%d", &age);
            printf("\nInsert the person's telephone: ");
            setbuf( stdin, NULL );
            scanf("%d", &tel);

            Push(tree, CreateNode(name, age, tel));

            break;

        case 4:

            do {
                printf("\nInsert the print order you wish:");
                printf("\n1 - PreOrder");
                printf("\n2 - Central");
                printf("\n3 - PostOrder");
                printf("\n4 - Central with identation style");


                printf("\nYour choice: ");

                scanf("%d", &printOrder);
                if (printOrder == 1)
                    PreOrder(tree->root);
                else if (printOrder == 2)
                    Central(tree->root);
                else if (printOrder == 3)
                    PostOrder(tree->root);
                else if (printOrder == 4)
                    PrintTreeIdentationStyle(tree->root);
                else
                    printOrder = 0;
            } while (printOrder < 1 || printOrder > 4);
        
        default:
            break;
        }

    } while (userSelect != 0);

    // Central(tree->root);

    printf("\n%d", tree->root->person.age);
    printf("\n%d", tree->root->left->person.age);
    printf("\n%d", tree->root->right->person.age);





    return 0;
}