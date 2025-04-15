#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

Node *createNode(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}

void push(int ele)
{
    Node *newNode = createNode(ele);
    if (newNode == NULL)
        printf("Stack Overflow!!!\n");
    else
    {
        newNode->next = top;
        top = newNode;
        printf("Node Inserted\n");
    }   
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow!!!!\n");
        return -1;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        int val = temp->data;
        free (temp);
        return val;
    }
}

void peek()
{
    if(top == NULL)
        printf("Stack Underflow!!!!");
    else
    {
        printf("Top of the stack is %d\n",top->data);
    }
}

void display()
{
    if(top==NULL)
        printf("Stack is Empty!!!!\n");
    else
    {
        Node *temp = top;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        printf("------Stack Implementation Using Linked List------\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        int choice, data, res;
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            res = pop();
            if(res != -1)
                printf("%d pop from the stack\n",res);
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
        printf("--------------------------------------------------\n");
        printf("Press any key to continue...\n");
    }
}
