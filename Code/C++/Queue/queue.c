#include <stdio.h>

#define size 5
#define pf printf

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int value){
    if(rear == size-1){
        printf("Overflow.\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        rear++;
        queue[rear] = value;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Empty.\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        printf("Poped elemnt: %d\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Empty.\n");
        return;
    }
    else{
        int i = front;
        while(i<=rear){
            printf("%d ", queue[i]);
            i++;
        }
        printf("\n");
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Empty.\n");
        return;
    }
    else{
        pf("Peek = %d\n", queue[front]);
    }
}

void main(){
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
}