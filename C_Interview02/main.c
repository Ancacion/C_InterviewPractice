//
//  main.c
//  C_Interview_2
//
//  Created by Ancacion on 2022/5/18.
//

#include <stdio.h>
#include <stdlib.h>

int B = 2;

//傳入指標的指標來改動指標指向的數值
void func(int **p){ *p = &B; }

//分配記憶體
void getMemory(char** s)
{
    *s = (char*)malloc(sizeof(char));
    printf("s = %p\n", s);
    printf("*s = %p\n", *s);
}

//------交換字串------
void swap(char* a, char* b){
    if(a==b)return;
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
void reverseString(char* s, int sSize){
    int i=0,j=sSize-1;
    while(i<j){
        swap(s+i,s+j);
        i++;j--;
    }
    return;
}
//------------------

void pointer01() {
    int a0; // 一個整型數
    int *a1; // 一個指向整數的指標
    int **a2; // 一個指向指標的指標，它指向的指標是指向一個整型數
    int a3[10]; // 一個有10個整數型的陣列
    int *a4[10]; // 一個有10個指標的陣列，該指標是指向一個整數型的
    int (*a5)[10]; // 一個指向有10個整數型陣列的指標
    int (*a6)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
    int (*a7[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int A = 1, C = 3;
    int *ptrA = &A;
    func(&ptrA);
    printf("%d\n\n", *ptrA);
    
    char* ch = NULL;
    getMemory(&ch);
    printf("&ch = %p\n", &ch);
    printf("ch = %p\n\n", ch);
    
    char strAry[] = "This is string";
    char *aryPtr = strAry;
    int *intPtr = (int*)strAry;
    printf("[Line01] strAry=%s\n", strAry); //This is string
    printf("[Line02] aryPtr=%s\n", aryPtr); //This is string
    //printf(“\t[LineX] *aryPtr=%s\n”, *aryPtr); // Segment fault
    printf("[Line03] sizeof(aryPtr)=%d\n", sizeof(aryPtr)); //4
    printf("[Line04] sizeof(*aryPtr)=%d\n", sizeof(*aryPtr)); //1
    printf("[Line05] *aryPtr=’%c’\n", *aryPtr); //'T'
    printf("[Line06] *aryPtr+1=’%c’\n", *aryPtr+1); //'U'
    printf("[Line07] *(aryPtr+1)=’%c’\n", *(aryPtr+1)); //'h'
    printf("[Line08] sizeof(intPtr)=%d\n", sizeof(intPtr)); //4
    printf("[Line09] sizeof(*intPtr)=%d\n", sizeof(*intPtr)); //4
    printf("[Line10] intPtr=%s\n", intPtr); //This is string
    //printf(“\t[LineX] *intPtr=%s\n”, *intPtr); // Segment fault
    printf("[Line11] *intPtr=’%c’\n", *intPtr); //'T'
    printf("[Line12] *intPtr+1=’%c’\n", *intPtr+1); //'U'
    printf("[Line13] *(intPtr+1)=’%c’\n\n", *(intPtr+1)); //' '
    
    int a[] = {1,2,3,4,5,6,7,9,10};
    int *ptr = (int*) (&a+1);
    printf("%d\n", &a);
    printf("%d\n", &a+1);
    printf("%d\n", ptr);
    printf("%d\n", *(ptr));
    printf("%d\n", ptr-1);
    printf("%d\n", *(ptr-1));
    printf("%d\n", ptr-2);
    printf("%d\n", *(ptr-2));
    printf("%d\n", *a);
    printf("%d\n", *a+7);
    printf("%d\n\n", *(a+7));
    
    int arr[] = {10,20,30,40,50};
    int *ptr1 = arr;
    int *ptr2 = arr+5;
    printf("%d %d\n", *ptr1, *ptr2);
    printf("%d\n", (ptr2-ptr1));               //5
    printf("%d\n", (char*)ptr2 - (char*)ptr1); //20
    printf("%d %d\n\n", (char*)ptr2, (char*)ptr1);
    
    uint8_t *mall;
    mall = (uint8_t *)malloc(10 * sizeof(uint8_t));
    int sizeofWithout = (size_t)(&(mall) + 1) - (size_t)(&(mall));
    printf("sizeof mall = %d.\n", sizeofWithout);
    int ii = 0;
    for(ii = 0; ii < 10; ii++) {
        mall[ii] = ii;
    }
    printf("sizeof mall = %d. mall[5] = %d\n\n", sizeof(mall), mall[5]);
    free(mall);
    
    return 0;
}

/*
 void **(*d) (int &, char **(*)(char *, char **));
 --------------------------------------------------------------------
 + d is a pointer to a function that takes two parameters:
     + a reference to an int and
     + a pointer to a function that takes two parameters:
         + a pointer to a char and
         + a pointer to a pointer to a char
     + and returns a pointer to a pointer to a char
 + and returns a pointer to a pointer to void
 */
 
