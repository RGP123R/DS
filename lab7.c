#include <stdio.h>
#include <stdlib.h>
struct node
{
    int USN, SEM;
    char NAME[50], PRG[50];
    int PHNO;
    struct node *next;
};
struct node *head;
void IEND()
{
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter DETAILS USN NAME PRG SEM PHONENO\n"); 
    scanf("%d%s%s%d%d", &(newnode->USN), (newnode->NAME), (newnode->PRG), &(newnode->SEM), &(newnode->PHNO));
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
        printf("STUDENT DETAILS ENTERED\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        temp = newnode;
        printf("STUDENT DETAILS ENTERED\n");
    }
}
void IBEGIN()
{
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter DETAILS USN NAME PRG SEM PHONENO \n");
    scanf("%d%s%s%d%d", &(newnode->USN), (newnode->NAME), (newnode->PRG), &(newnode->SEM), &(newnode->PHNO));

    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
        printf("STUDENT DETAILS ENTERED\n");
    }
    else
    {
        temp = head;
        newnode->next = temp;
        head = newnode;
        printf("STUDENT DETAILS ENTERED\n");
    }
}

void DBIG()
{
    struct node *temp;
    if (head == NULL)
        printf("\nNO STUDENT ENTRY\n");
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        printf("\nDETAIL DELETED FROM START\n");
    }
}
void DEND()
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("\nNO STUDENT DETAILS\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("\nDETAILS DELETED FROM END\n");
    }
}
void DISPLAY()
{
    int count = 0;
    struct node *temp;
    temp = head;
    printf("\n USN\tNAME\tPRG\tSEM\t PHNO\n");
    while (temp->next != NULL)
    {
        printf("||%d||%s||%s||%d||%d||\n", (temp->USN), (temp->NAME), (temp->PRG), (temp->SEM), (temp->PHNO));
        printf("\n");
        temp = temp->next;
        count++;
    }
    printf("||%d||%s||%s||%d||%d||\n", (temp->USN), (temp->NAME), (temp->PRG), (temp->SEM), (temp->PHNO));
    printf("\ntotal records is %d\n", count + 1);
}
int main()
{
    printf("\nuse following operations to enter student details\n");
    printf("1. Insert(IBEGIN)\n2. Insert(end) \n3. Deletion(front)\n4. Deletion(end)\n5. Display\n6.Exit\n");
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
        case 6:
        exit(1);
        break;
        default:
            printf("\nInvalid choice\n");
        }
    } 
    return 0;
}
