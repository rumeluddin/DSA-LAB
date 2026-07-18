#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if(front == NULL)
    {
        front = rear = newNode;
        newNode->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Inserted successfully.\n");
}

void dequeue()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    if(front == rear)
    {
        temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }

    printf("Deleted successfully.\n");
}

void display()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    temp = front;

    printf("Circular Queue elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != front);

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\nCIRCULAR QUEUE MENU\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program End.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
