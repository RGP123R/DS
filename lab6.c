#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max];
int front=-1;
int rear=-1;
int count = 0;

void insert() {
    int ele;
    if ((front==-1)&&(rear==-1))
    {
        front++;
        rear++;
        printf("\nENTER THE ELEMENT:");
        scanf("%d", &ele);
        queue[rear] = ele;
        printf("\nELEMENT INSERTED\n");
        
    }
    else if((rear + 1) % max == front)
    {
        printf("\nOVERFLOW CONDITION\n");

    }
    else {
        rear = (rear + 1) % max;
        printf("\nENTER THE ELEMENT:");
        scanf("%d", &ele);
        queue[rear] = ele;
        printf("\nELEMENT INSERTED\n");
    }

}

void deleteElement() {
    if ((front == -1) && (rear == -1)) {
        printf("\nUNDERFLOW CONDITION\n");

    }
    else if(front == rear){
        front = rear = -1;
        printf("\nUNDERFLOW CONDITION\n");
    }
    else {
        printf("\nTHE DELETED ELEMENT IS:%d\n", queue[front]);
        front = (front + 1) % max;
    }


}

void display() {
    if ((front == -1) && (rear == -1)) {
        printf("\nNO ELEMENT TO DISPLAY\n");

    }
    else {
        printf("\nTHE ELEMENTS IN QUEUE ARE:\n");
        for (int i = front; i <= rear; i = (i + 1) % max) {
            printf("%d\n", queue[i]);

        }
    }
}

int main() {
    int choice;
    printf("ENTER OPERATION\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
    while (1) {
        printf("\nenter the choice:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nINVALID CHOICE\n");
        }
    }

    return 0;
}