#include "./binaryTree.h"
#include <string.h>

int main() {
    FILE *file;
    file = fopen("./students.txt", "r");
    char name[100], matriculation[100];
    float grade;
    Node *root, *bigger, *smaller;
    initializeNode(&root);


    while (fscanf(file, "%s - %s - %f", name, matriculation, &grade) != -1) {
        insertValue(&root, grade, name, matriculation);
    }
    fclose(file);

    printOrder(root, 1);
    printf("\n\n");
    printf("Number of students: %d", count(root));
    printf("\n\n");
    bigger = highest(root);
    printf("Highest grade: %s - %s - %f", bigger->student.name, bigger->student.matriculation, bigger->student.grade);
    printf("\n\n");
    smaller = lowest(root);
    printf("Lowest grade: %s - %s - %f", smaller->student.name, smaller->student.matriculation, smaller->student.grade);
    printf("\n\n");
    printf("Numbers of Mean: %d", numbersOfMean(root));
    printf("\n\n");
    return 0;
}