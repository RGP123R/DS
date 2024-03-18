#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int x, y, z;
    struct Node* next;
};

void insertTerm(struct Node** poly, int coeff, int x, int y, int z) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    newNode->next = NULL;
    if (*poly == NULL)
        *poly = newNode;
    else {
        struct Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
    }
    else {
        struct Node* temp = poly;
        while (temp != NULL) {
            printf("%dx^%dy^%dz^%d ", temp->coeff, temp->x, temp->y, temp->z);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    while (temp1 != NULL || temp2 != NULL) {
        int coeff;
        int x, y, z;

        if (temp1 == NULL) {
            coeff = temp2->coeff;
            x = temp2->x;
            y = temp2->y;
            z = temp2->z;
            temp2 = temp2->next;
        }
        else if (temp2 == NULL) {
            coeff = temp1->coeff;
            x = temp1->x;
            y = temp1->y;
            z = temp1->z;
            temp1 = temp1->next;
        }
        else if (temp1->x > temp2->x) {
            coeff = temp1->coeff;
            x = temp1->x;
            y = temp1->y;
            z = temp1->z;
            temp1 = temp1->next;
        }
        else if (temp1->x < temp2->x) {
            coeff = temp2->coeff;
            x = temp2->x;
            y = temp2->y;
            z = temp2->z;
            temp2 = temp2->next;
        }
        else {
            coeff = temp1->coeff + temp2->coeff;
            x = temp1->x;
            y = temp1->y;
            z = temp1->z;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        insertTerm(&result, coeff, x, y, z);
    }

    return result;
}

int main() {
    struct Node* POLY1 = NULL;
    struct Node* POLY2 = NULL;
    int coeff, x, y, z, terms;

    printf("Enter the number of terms for POLY1: ");
    scanf("%d", &terms);
    printf("Enter the terms for POLY1 (coeff x y z):\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d %d %d %d", &coeff, &x, &y, &z);
        insertTerm(&POLY1, coeff, x, y, z);
    }

    printf("Enter the number of terms for POLY2: ");
    scanf("%d", &terms);
    printf("Enter the terms for POLY2 (coeff x y z):\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d %d %d %d", &coeff, &x, &y, &z);
        insertTerm(&POLY2, coeff, x, y, z);
    }

    printf("POLY1(x,y,z) = ");
    displayPolynomial(POLY1);
    printf("POLY2(x,y,z) = ");
    displayPolynomial(POLY2);

    struct Node* POLYSUM = addPolynomials(POLY1, POLY2);
    printf("POLYSUM(x,y,z) = ");
    displayPolynomial(POLYSUM);

    return 0;
}