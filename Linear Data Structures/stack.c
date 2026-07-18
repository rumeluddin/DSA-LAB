#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Item inserted successfully.\n");
}

void pop()
{
    struct Node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("Deleted Item = %d\n", top->data);

    top = top->next;
    free(temp);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("Top Element = %d\n", top->data);
    }
}

void display()
{
    struct Node *temp;

    if(top == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }

    temp = top;

    printf("Stack Elements:\n");

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\nSTACK MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program End.\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
