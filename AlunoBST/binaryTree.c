#include "./binaryTree.h"
#include <string.h>

void initializeNode(Node **node) {
    *node = NULL;
}

void insertValue(Node **node, float grade, char name[], char matriculation[]) {
    if (*node != NULL) {
        if (grade <= (*node)->student.grade) insertValue(&((*node)->left), grade, name, matriculation);
        if (grade > (*node)->student.grade) insertValue(&((*node)->right), grade, name, matriculation);
    } else {
        (*node) = (Node *)malloc(sizeof(Node));
        (*node)->student.grade = grade;
        strcpy((*node)->student.name, name);
        strcpy((*node)->student.matriculation, matriculation);
        initializeNode(&((*node)->left));
        initializeNode(&((*node)->right));
    }

}

void printOrder(Node *node) {
    if (node == NULL) return;

    printOrder(node->left);
    printf("%s - %s - %f\n", node->student.name, node->student.matriculation, node->student.grade);
    printOrder(node->right);
}

void printPreOrder(Node *node) {
    if (node == NULL) return;

    printf("%s - %s - %f\n", node->student.name, node->student.matriculation, node->student.grade);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPosOrder(Node *node) {
    if (node == NULL) return;

    printPosOrder(node->left);
    printPosOrder(node->right);
    printf("%s - %s - %f\n", node->student.name, node->student.matriculation, node->student.grade);
}