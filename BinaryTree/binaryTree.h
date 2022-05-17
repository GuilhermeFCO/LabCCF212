#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long value;
    Node *left, *right;
} Node;

void initializeNode(Node **node);
void insertValue(Node **node, long value);
void printOrder(Node *node);
void printPreOrder(Node *node);
void printPosOrder(Node *node);