//
//  main.c
//  C_DS&Algorithm_Stack
//
//  Created by Ancacion on 2022/6/13.
//

#include <stdio.h>
#include <stdlib.h>
/*
struct node {
    int data;
    struct node *next;
};
typedef struct node ListNode;
typedef ListNode *ListNodePtr;

typedef struct stack{
    ListNodePtr pop;
} stackPractice;
*/
struct stackNode {
    int data;
    struct stackNode *next;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *sPtr, int input) {
    StackNodePtr newStack;
    newStack = (StackNode *)malloc(sizeof(StackNode));
    
    if(newStack != NULL) {
        newStack -> data = input;
        newStack -> next = *sPtr;
        *sPtr = newStack;
    }
    else {
        printf("No memory available.\n");
    }
}

void pop(StackNodePtr *sPtr) {
    StackNodePtr tempPtr;
    int popValue = 0;
    
    tempPtr = *sPtr;
    popValue = tempPtr -> data;
    *sPtr = (*sPtr) -> next;
    free(tempPtr);
    printf("%d is popped out the stack.\n", popValue);
}

void printStack(StackNodePtr sPtr) {
    if(sPtr == NULL) {
        printf("The stack is empty.\n");
    }
    else {
        printf("The stack is : ");
        while(sPtr != NULL) {
            printf("%d -> ",sPtr -> data);
            sPtr = sPtr -> next;
        }
        printf("NULL\n");
    }
}
/*
void push(stackPractice *pMyStack, int input) {
    ListNodePtr newNode;
    ListNodePtr prev;
    ListNodePtr current;
    
    newNode = (ListNode *)malloc(sizeof(ListNode));
    
    if(newNode != NULL) {
        newNode -> data = input;
        newNode -> next = NULL;
        prev = NULL;
        current = pMyStack -> pop;
        
        while(current != NULL) {
            prev = current;
            current = current -> next;
        }
        
        if(prev == NULL) {
            newNode -> next = pMyStack -> pop;
            pMyStack -> pop = newNode;
        }
        else {
            prev -> next = newNode;
            newNode -> next = current;
        }
    }
    else {
        printf("No Memory availabile!\n");
    }
}

void pop(stackPractice *pMyStack) {
    ListNodePtr prev;
    ListNodePtr current, temp;
    
    if(sizeof(pMyStack -> pop) == 1) {
        puts("The Stack is empty!\n");
    }
    else if(sizeof(pMyStack -> pop) == 1) {
        temp = pMyStack -> pop;
        pMyStack -> pop = pMyStack -> pop -> next;
        free(temp);
    }
    else {
        prev = pMyStack -> pop;
        current = pMyStack -> pop -> next;
        
        while(current -> next != NULL) {
            prev = current;
            current = current -> next;
        }
        
        temp = current;
        prev -> next = current -> next;
        free(temp);
    }
}

void printStack(stackPractice *pMyStack) {
    ListNodePtr current;
    if(pMyStack == NULL) {
        printf("The stack is empty!");
    }
    else {
        current = pMyStack -> pop;
        
        printf("The element of stack is: ");
        while(current != NULL) {
            printf("%d -> ", current -> data);
            current = current -> next;
        }
        printf("NULL\n");
    }
}
*/
int main(int argc, const char * argv[]) {
    /*
    stackPractice pMyStack;
    int firstData[10] = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 10; i++) {
        push(&pMyStack, firstData[i]);
    }
    printStack(&pMyStack);
    pop(&pMyStack);
    pop(&pMyStack);
    push(&pMyStack, 16);
    printStack(&pMyStack);
    */
    StackNodePtr sPtr = NULL;
    int inputData[5] = {1, 4, 2, 8, 9};
    for(int i = 0; i < 5; i++) {
        push(&sPtr, inputData[i]);
    }
    printStack(sPtr);
    pop(&sPtr);
    pop(&sPtr);
    printStack(sPtr);
    
    return 0;
}
