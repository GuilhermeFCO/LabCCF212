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

void printOrder(Node *node, int desc) {
    if (node == NULL) return;

    if (desc == 0) {
        printOrder(node->left, desc);
        printf("%s - %s - %f\n", node->student.name, node->student.matriculation, node->student.grade);
        printOrder(node->right, desc);
    } else if (desc == 1) {
        printOrder(node->right, desc);
        printf("%s - %s - %f\n", node->student.name, node->student.matriculation, node->student.grade);
        printOrder(node->left, desc);
    }    
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

int count(Node *node) {
    if (node == NULL) return 0;

    return count(node->left) + count(node->right) + 1;
}

Node* highest(Node *node) {
    if (node->right == NULL) return node;
    return highest(node->right);
}

Node* lowest(Node *node) {
    if (node->left == NULL) return node;
    return lowest(node->left);
}

int numbersOfMean(Node *node) {
    if (node == NULL) return 0;
       
    if (node->student.grade >= 60.0) return numbersOfMean(node->left) + numbersOfMean(node->right) + 1;
    return numbersOfMean(node->right) + numbersOfMean(node->left);    
}