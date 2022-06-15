//
//  main.c
//  C_DS&Algorithm_Queue
//
//  Created by Ancacion on 2022/6/15.
//

#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    int data;
    struct queueNode *next;
};
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr *sPtr, QueueNodePtr *lPtr, int input) {
    QueueNodePtr newQueue;
    newQueue = (QueueNode *)malloc(sizeof(QueueNode));
    
    if(newQueue != NULL) {
        newQueue -> data = input;
        newQueue -> next = NULL;
        
        if(*sPtr == NULL) {
            *sPtr = newQueue;
        }
        else {
            (*lPtr) -> next = newQueue;
        }
        
        *lPtr = newQueue;
    }
    else {
        printf("No memory available.\n");
    }
}

void dequeue(QueueNodePtr *sPtr, QueueNodePtr *lPtr) {
    int value;
    QueueNodePtr temp;
    
    value = (*sPtr) -> data;
    temp = *sPtr;
    *sPtr = (*sPtr) -> next;
    
    if(*sPtr == NULL) {
        *lPtr = NULL;
    }
    
    free(temp);
    printf("%d is dequeued. \n", value);
}

void printQueue(QueueNodePtr sPtr) {
    if(sPtr == NULL) {
        printf("The Queue is empty.\n");
    }
    else {
        printf("The Queue is : ");
        while(sPtr != NULL) {
            printf("%d -> ", sPtr -> data);
            sPtr = sPtr -> next;
        }
        printf("NULL\n");
    }
}

int main(int argc, const char * argv[]) {
    QueueNodePtr sPtr = NULL;
    QueueNodePtr lPtr = NULL;
    int inputData[10] = {0, 4, 2, 7, 9, 1, 3, 8, 5, 6};
    
    for(int i = 0; i < 10; i++)
        enqueue(&sPtr, &lPtr, inputData[i]);
    
    printQueue(sPtr);
    dequeue(&sPtr, &lPtr);
    dequeue(&sPtr, &lPtr);
    printQueue(sPtr);
    enqueue(&sPtr, &lPtr, 99);
    printQueue(sPtr);
    printf("lPtr's data = %d\n", lPtr -> data);
    return 0;
}
