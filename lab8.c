#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int SSN, SAL;
    char NAME[50], DEPT[50], DESIG[50];
    int PHNO;
    struct node *next;
};
struct node *head;
void IEND()
{
    struct node *tail;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter DETAILS: SSN NAME DEPT DESIGNATION SAL PHONENO\n");
    scanf("%d%s%s%s%d%d", &(newnode->SSN), (newnode->NAME), (newnode->DEPT), (newnode->DESIG), &(newnode->SAL), &(newnode->PHNO));
    if (head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        printf("\nEMPLOYEE DETAILS ENTERED\n");
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        printf("\nEMPLOYEE DETAILS ENTERED\n");
    }
}
void IBEGIN()
{
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter DETAILS: SSN NAME DEPT DESIGNATION SAL PHONENO\n");
    scanf("%d%s%s%s%d%d", &(newnode->SSN), (newnode->NAME), (newnode->DEPT), (newnode->DESIG), &(newnode->SAL), &(newnode->PHNO));

    if (head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        printf("\nEMPLOYEE DETAILS ENTERED\n");
    }
    else
    {
        temp = head;
        newnode->next = temp;
        temp->prev = newnode;
        head = newnode;
        printf("\nEMPLOYEE DETAILS ENTERED\n");
    }
}

void DBIG()
{
    struct node *temp;
    if (head == NULL)
        printf("\nNO EMPLOYEE ENTRY\n");
    else
    {
        temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp);
        printf("\nDETAIL DELETED FROM START\n");
    }
}
void DEND()
{
    struct node *temp, *tail;
    if (head == NULL)
    {
        printf("\nNO EMPLOYEE DETAILS\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            tail = temp;
            temp = temp->next;
        }
        tail->next = NULL;
        free(temp);
        printf("\nDETAILS DELETED FROM END\n");
    }
}
void DISPLAY()
{
    int count = 0;
    struct node *temp;
    temp = head;
    printf("\n SSN\tNAME\tDEPT\t DESIG \t  SALARY\tPHNO\n");
    while (temp->next != NULL)
    {
        printf("||%d||%s||%s||%s||%d||%d||\n", (temp->SSN), (temp->NAME), (temp->DEPT),(temp->DESIG), (temp->SAL), (temp->PHNO));
        printf("\n");
        temp = temp->next;
        count++;
    }
    printf("||%d||%s||%s||%s||%d||%d||\n", (temp->SSN), (temp->NAME), (temp->DEPT),(temp->DESIG), (temp->SAL), (temp->PHNO));
    printf("\ntotal records is %d\n", count + 1);
}
int main()
{
    printf("\nuse following operations to enter EMPLOYEE details\n");
    printf("\n1. Insert(IBEGIN)\n2. Insert(end) \n3. Deletion(front)\n4. Deletion(end)\n5. Display\n6.Exit\n");
    printf("\nFor Stack Choose 2,4 and 5 options\n");
    int choice;
    while (1)
    {
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            IBEGIN();
            break;
        case 2:
            IEND();
            break;
        case 3:
            DBIG();
            break;
        case 4:
            DEND();
            break;
        case 5:
            DISPLAY();
            break;
        default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}
