/*
                            Priority Queue
    elements are stored according to their priority. based on the priority of elements we'll set our quere accordingly i.e in adcending order or in descending order.
*/

#include <stdio.h>
#include <stdlib.h>
#define size 100

typedef struct priorityQueue
{
    int element;
    int priority;

} pQueue;

pQueue pq[size];

int front = -1, count = -1;

int isEmpty(){
    return (front == -1) ? 1 : 0;
}

int isFull(){
    return (count == size - 1) ? 1 : 0;
}

void enQueue(int data, int priority){

    if(isEmpty()){

        count += 1;
        pq[count].element = data;
        pq[count].priority = priority;
        front = count; 

    }

    else {

    int i;

    for(i = front; i <=count; i++){

        if(pq[i].priority < priority){
            for(int j = count; j >=i; j--){
                pq[j + 1] = pq[j];
            }
            pq[i].element = data;
            pq[i].priority = priority;
            break;
        }
    }

    if(i == count + 1){
        pq[i].element = data;
        pq[i].priority = priority;
    }
    count++;
}
    printf("Element Added\n");
}

int deQueue(){
    int data = pq[front].element;

    if(front == count) front = count = -1;

    else front++;

    return data;
}

int peek(){
    return pq[front].element;
}

void display(){
    for(int i = front; i <= count; i++){
        printf("Element : %d Priority : %d\n", pq[i].element, pq[i].priority);
    }
}

int main(){
    
    while(1){
    printf("--------Priority Queue--------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue \n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    int choise, data,p;

    scanf("%d", &choise);

    switch (choise)
    {
    case 1:

        if(isFull()) printf("Queue Overflow!!!\n");

        else{
            scanf("%d %d", &data, &p);
            enQueue(data, p);
        }
        break;
    
    case 2:
        if(isEmpty()) printf("Queue Underflow!!!\n");

        else printf("%d is dequeue\n", deQueue());

        break;

    case 3:
        if(isEmpty()) printf("Queue is empty\n");
        
        else printf("%d\n", peek());

        break;

    case 4:
        
        if(isEmpty()) printf("Queue is Empty");

        else display();

        break;

    case 5:
        exit(0);
    
    default:
        break;
    }
}

    return 0;
}
