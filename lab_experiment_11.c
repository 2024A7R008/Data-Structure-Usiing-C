#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

Node *createNode(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}
void enqueue(int ele)
{
    Node *newNode = createNode(ele);
    if (newNode == NULL)
        printf("Queue Overflow\n");
    else
    {
        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        printf("Element Inserted\n");
    }
}
void dequeue()
{
    if (front == NULL)
        printf("Queue Underflow\n");
    else
    {
        Node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
        printf("Element Deleted\n");
    }
}
void peek()
{
    if (front == NULL)
        printf("Queue Underflow\n");
    else
        printf("Front of the queue is %d\n", front->data);
}
void display()
{
    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        printf("-------Queue Using Linked List-------\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        int choice, value;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
        printf("Press any key to continue....\n");
    }
}
