#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    float grade;
    char name[100];
    char matriculation[100];
} Student;

typedef struct Node {
    Student student;
    struct Node *left, *right;
} Node;

void initializeNode(Node **node);
void insertValue(Node **node, float grade, char name[], char matriculation[]);
void printOrder(Node *node, int desc);
void printPreOrder(Node *node);
void printPosOrder(Node *node);
int count(Node *node);
Node* highest(Node *node);
Node* lowest(Node *node);
int numbersOfMean(Node *node);