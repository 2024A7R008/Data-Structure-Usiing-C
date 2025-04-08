#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *createNode(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}

void insertNodeBegninning(int ele)
{
    Node *newNode = createNode(ele);
    newNode->next = head;
    head = newNode;
    printf("Node Inserted\n");
}

void insertNodeEnd(int ele)
{
    Node *newNode = createNode(ele);
    if (head == NULL)
        head = newNode;
    else
    { 
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("newNode Inserted in the end\n");
    }
}

void insertNodeAtAnyPosition(int ele, int pos)
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else if (pos == 1)
        insertNodeBegninning(ele);
    else
    {
        Node *newNode = createNode(ele);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            printf("Invalid Position\n");
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted\n");
        }
    }
}

void display()
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}
void deleteNodeBeginning()
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Node Deleted\n");
    }
}

void deleteNodeEnd()
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else
    {
        Node *t;
        if (head->next == NULL)
        {
            deleteNodeBeginning();
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            t = temp->next;
            temp->next = NULL;
        }
        free(t);
        printf("Node Deleted\n");
    }
}

void deleteNodeAtAnyPosition(int pos)
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else if (pos == 1)
        deleteNodeBeginning();
    else
    {
        int i = 1;
        Node *temp = head;
        while (i < pos - 1 && temp->next != NULL)
        {
            i++;
            temp = temp->next;
        }
        if (temp->next != NULL && pos > 0)
        {
            Node *t = temp->next;
            temp->next = temp->next->next;
            free(t);
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
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                printf("Found\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not Found\n");
    }
}

void sort()
{
    if (head == NULL)
        printf("Empty");
    else
    {
        Node *last = NULL;
        for (Node *i = head; i->next != NULL; i = i->next)
        {
            Node *j;
            for (j = head; j->next != last; j = j->next)
            {
                if (j->data > j->next->data)
                {
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
            }
            last = j;
        }
    }
}

void display()
{
    if (head == NULL)
        printf("Linked List is empty\n");
    else
    {
        Node *temp = head;
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
        printf("------Slingley Linked List------\n");
        printf("1.Insert Node in Beginnig\n");
        printf("2.Insert Node at End\n");
        printf("3.Insert Node at any Position\n");
        printf("4.Delete Node from Beginnig\n");
        printf("5.Delete Node from End\n");
        printf("6.Delete Node from any Position\n");
        printf("7.Search Element\n");
        printf("8.Sort Element\n");
        printf("9.Display List\n");
        printf("10.Exit\n");

        int choice, value, pos;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &value);
            insertNodeBegninning(value);
            break;
        case 2:
            printf("Enter Value: ");
            scanf("%d", &value);
            insertNodeEnd(value);
            break;
        case 3:
            printf("Enter Value: ");
            scanf("%d", &value);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insertNodeAtAnyPosition(pos, value);
            break;
        case 4:
            deleteNodeBeginning();
            break;
        case 5:
            deleteNodeEnd();
            break;
        case 6:
            printf("Enter pos: ");
            scanf("%d", &pos);
            deleteNodeAtAnyPosition(pos);
            break;
        case 7:
            printf("Enter value: ");
            scanf("%d", &value);
            searchInNode(value);
            break;
        case 8:
            sort();
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
        system("pause");
    }
    return 0;
}
