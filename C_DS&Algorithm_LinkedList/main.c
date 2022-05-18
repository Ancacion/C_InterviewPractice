//
//  main.c
//  C_DS&Algorithm_LinkedList
//
//  Created by Ancacion on 2022/5/4.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
}; //定義單一Node結構

typedef struct node ListNode; //定義node的資料型態為ListNode
typedef ListNode *ListNodePtr; //定義ListNode的指標

//定義Linked List需要使用的函數
void insert(ListNodePtr *sPtr, int value);
int delete(ListNodePtr *sPtr, int value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr current);
void instruction(void);

void instruction(void) {  //文字選單
    puts( "Enter your choice:\n"
         "  1 to insert an element into the list.\n"
         "  2 to delete an element from the list.\n"
         "  3 to end the program.\n");
}

int isEmpty(ListNodePtr sPtr) {
    return sPtr == NULL;
}

void printList(ListNodePtr current) {
    if(isEmpty(current)) {
        puts("List is empty.\n");
    }
    else{
        puts("The List is: ");
        
        while(current != NULL) {
            printf("%d -> ", current -> data);
            current = current -> next;
        }
        puts("NULL\n");
    }
}

void insert(ListNodePtr *sPtr, int value) {
    ListNodePtr newNode; //新增的Node
    ListNodePtr previous; //記錄上一個狀態的current所在的Linked List位置
    ListNodePtr current; //現在的Linked List位置
    
    newNode = malloc(sizeof(ListNode)); //新增記憶體空間給新的Node
    
    if(newNode != NULL) { //若有足夠的記憶體空間給新的Node
        newNode -> data = value; //給予新Node數值
        newNode -> next = NULL;
        
        previous = NULL;
        current = *sPtr;
        
        while(current != NULL && value > current -> data) { //當current還沒到最底且輸入值大於目前所在Node的數值時右移
            previous = current; //紀錄目前走到的位置
            current = current -> next; //current前進到下一個Node
        }
        
        if(previous == NULL) {
            newNode -> next = *sPtr;
            *sPtr = newNode;
        }
        else {
            previous -> next = newNode;
            newNode -> next = current;
        }
    }
    else {
        printf("%d not inserted. No memory available!\n", value);
    }
}

int delete(ListNodePtr *sPtr, int value) {
    ListNodePtr previous, current, temp;
    if(value == (*sPtr) -> data) {
        temp = *sPtr;
        *sPtr = (*sPtr) -> next;
        free(temp);
        return value;
    }
    else {
        previous = *sPtr;
        current = (*sPtr) -> next;
        
        while(current != NULL && current -> data != value) {
            previous = current;
            current = current -> next;
        }
        
        if(current != NULL) {
            temp = current;
            previous -> next = current -> next;
            free(temp);
            return value;
        }
    }
    return '\0';
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNodePtr startPtr = NULL;
    unsigned int choice;
    int input;
    
    instruction();
    printf("%s", "? ");
    scanf("%u", &choice);
    
    while(choice != 3) { //當輸入不等於結束指令時持續執行
        switch (choice) {
            case 1:
                printf("%s", "Enter a element: \n");
                scanf("%d", &input);
                insert(&startPtr, input);
                printList(startPtr);
                break;
            case 2:
                if(isEmpty(startPtr)) {
                    puts("List is empty!\n");
                }
                else {
                    printf("%s", "Enter the number to be deleted: \n");
                    scanf("%d", &input);
                    if(delete(&startPtr, input)) {
                        printf("%d deleted.\n", input);
                        printList(startPtr);
                    }
                    else{
                        printf("%d is not found. \n\n", input);
                    }
                }
                break;
                
            default:
                puts("Invalid choice.\n");
                instruction();
                break;
        }
        
        printf("%s", "? ");
        scanf("%u", &choice);
    }
    
    puts("End of run.\n");
    return 0;
}
