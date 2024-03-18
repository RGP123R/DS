#include<stdio.h>
#include<stdlib.h>
int top = -1;
#define max 10
int stack[max];
void push()
{
    int ele;
    if (top == max - 1) {
        printf("\nOVERFLOW\n");
    }
    else
    {
        top++;
        printf("\nENTER THE ELEMENT:");
        scanf("%d", &ele);
        stack[top] = ele;

    }
}
void pop() {
    if (top == -1) {
        printf("underflow condition");
    }
    else {
        printf("the popped element is %d", stack[top]);
        top--;
    }

}
void peek() {
    if (top == -1) {
        printf("no elements");
    }
    else {
        printf("the top element of stack is%d", stack[top]);
    }

}

void palindrome() {
    int a;
    for (int i = 0, j = top;(i <= top/2), (j >= top / 2);i++, j--) {
        if (stack[i]!= stack[j]) {
            a = 1;
        }
        

    }

    (a == 1) ? printf("it is not palindrome") : printf("is palindrome");
}
void display() {
    for (int i = 0;i <= top;i++) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    printf("\n ---------STACK-----------\n");
    printf("\n ENTER YOUR CHOICE \n 1.push\n 2.pop \n 3.peek\n 4.display\n5.palindrome\n6.exit\n");
    int choice;
    while (1)
    {
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;
        case 3:peek();
        break;
        case 4:display();
        break;
        case 5:
            palindrome();
            break;
        case 6:
            exit(1);
            break;

        default:
            printf("Invalid choice");
        }

    }
    return 0;
}