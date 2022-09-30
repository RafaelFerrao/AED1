// Implementar uma agenda (nome, idade, telefone) que armazena os dados numa 
// árvore binária de busca (usuário escolhe qual dado é o fator de precedência). 
// A agenda deve permitir incluir, buscar, remover e imprimir toda a árvore usando pré-ordem, central e pós-ordem.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    n->person.name = (char *)malloc(sizeof(name));
    strcpy(n->person.name, name);
    n->person.age = age;
    n->person.tel = tel;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void InsertNode(Node *root, Node *n) {
    if(strcmp(n->person.name, root->person.name) < 1)
        if(root->left == NULL)
            root->left = n;
        else
            InsertNode(root->left, n);
    else
        if(root->right == NULL)
            root->right = n;
        else
            InsertNode(root->right, n);
}

void Push(Tree *tree, Node *n) {
    if(tree->root == NULL)
        tree->root = n;
    else
        InsertNode(tree->root, n);
}

void Search(Node *root, char *name) {
    if(strcmp(name, root->person.name) == 0){
        printf("\nName: %s | Age: %d | Telephone: %d", root->person.name, root->person.age, root->person.tel);
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

int main(int argc, char const *argv[]) {

    Tree *tree = Reset();
    Push(tree, CreateNode("Rafael", 20, 36710015));
    printf("\n%s", tree->root->person.name);
    Push(tree, CreateNode("Bernardo", 21, 36710222));
    Search(tree->root, "Bernardo");

    return 0;
}