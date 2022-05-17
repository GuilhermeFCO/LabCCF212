#include "./binaryTree.h"

void initializeNode(Node **node) {
    *node = NULL;
}

void insertValue(Node **node, long value) {
    if (*node != NULL) {
        if (value <= (*node)->value) insertValue(&((*node)->left), value);
        if (value > (*node)->value) insertValue(&((*node)->right), value);
    } else {
        (*node) = (Node *)malloc(sizeof(Node));
        (*node)->value = value;
        initializeNode(&((*node)->left));
        initializeNode(&((*node)->right));
    }

}

void printOrder(Node *node) {
    if (node == NULL) return;

    printOrder(node->left);
    printf("%d", node->value);
    printOrder(node->right);
}

void printPreOrder(Node *node) {
    printf("%d", node->value);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPosOrder(Node *node) {
    printPosOrder(node->left);
    printPosOrder(node->right);
    printf("%d", node->value);
}