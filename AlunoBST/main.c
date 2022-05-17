#include "./binaryTree.h"
#include <string.h>

int main() {
    FILE *file;
    file = fopen("./students.txt", "r");
    char name[100], matriculation[100];
    float grade;
    Node *root;
    initializeNode(&root);


    while (fscanf(file, "%s - %s - %f", name, matriculation, &grade) != -1) {
        insertValue(&root, grade, name, matriculation);
    }
    fclose(file);

    printOrder(root);
    printf("\n\n");
    printPosOrder(root);
    printf("\n\n");
    printPreOrder(root);
    return 0;
}