#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert()
{
    struct Node *newNode, *temp;
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
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Inserted successfully.\n");
}

void delete_begin()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Deleted from beginning.\n");
}

void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Linked List elements: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\nLINKED LIST MENU\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_begin();
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
