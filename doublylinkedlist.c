#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *createNode(int ele)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = ele;
    temp->next = temp->prev = NULL;
    return temp;
}

void nodeAtBeginning(int ele)
{
    struct Node *newNode = createNode(ele);
    if (head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node is Inserted in the Beginning\n");
}

void nodeAtEnd(int ele)
{
    struct Node *newNode = createNode(ele);
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node is Inserted in the End\n");
}

void nodeAtAnyPosition(int ele, int pos)
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else if (pos == 1)
        nodeAtBeginning(ele);
    else
    {
        struct Node *newNode = createNode(ele);
        struct Node *temp = head;
        for (int i = 1; i <= pos; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            printf("Invalid Position\n");
        else
        {
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            newNode->next = temp;
            temp->prev = newNode;
            printf("Node Inserted in the given Position\n");
        }
    }
}

void deleteAtBeginning()
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else
    {
        struct Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Node is deleted from the beginning\n");
    }
}

void deleteAtEnd()
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else if (head->next == NULL)
        deleteAtBeginning();
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("Node is deleted from the end\n");
    }
}

void deleteAtAnyPosition(int pos)
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else if (pos == 1)
        deleteNodeBeginning();
    else
    {
        int i = 1;
        struct Node *temp = head;
        while (i != pos && temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            printf("Node Deleted\n");
        }
        else
            printf("Invalid Position\n");
    }
}

void searchInNode(int target)
{
    if (head == NULL)
        printf("List is Empty\n");
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                printf("Found\n");
                return;
            }
            temp = temp->next;
        }
    }
}

void display()
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        printf("-------Doubly Linked List-------\n");
        printf("1.Insert Node in the beginning\n");
        printf("2.Insert Node in the last\n");
        printf("3.Insert Node at any position\n");
        printf("4.Delete Node in the beginning\n");
        printf("5.Delete Node in the last\n");
        printf("6.Delete Node at any position\n");
        printf("7.Search Element\n");
        printf("8.Display Linked List\n");
        printf("9.Exit\n");

        int choice, value, pos;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value you want to Insert");
            scanf("%d", &value);
            nodeAtBeginning(value);
            break;
        case 2:
            printf("Enter Value: ");
            scanf("%d", &value);
            nodeAtEnd(value);
            break;
        case 3:
            printf("Enter Position: ");
            scanf("%d", &pos);
            printf("Enter the value you want to insert");
            scanf("%d", &value);
            nodeAtAnyPosition(pos, value);
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter Position: ");
            scanf("%d", &pos);
            deleteAtAnyPosition(pos);
            break;
        case 7:
            printf("Enter the value you want to search: ");
            scanf("%d", &value);
            searchInNode(value);
            break;
        case 8:
            display();
            printf("\n");
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid Choice!!!!!");
        }
        system("pause");
    }
    return 0;
}
