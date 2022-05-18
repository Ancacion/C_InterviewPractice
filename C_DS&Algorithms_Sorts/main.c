//
//  main.c
//  C_DS&Algorithms_Sorts
//
//  Created by Ancacion on 2022/5/18.
//

#include <stdio.h>

void swap(int *a, int *b);
//
void bubbleSort(int data[]);
//
void insertionSort(int data[]);
//
void quickSort(int data[], int head, int tail);
int partition(int data[], int head, int tail);
//
void mergeSort(int data[], int head, int tail);
void merge(int data[], int head, int tail, int mid);
//

void swap(int *a, int *b) { //雙數字交換
    int temp = *a;
    *a = *b;
    *b = temp;
}

//bubble sort實作程式
void bubbleSort(int data[]) {
    int i, j;
    //int sizeOfData = (int) (sizeof(data) / sizeof(int));
    int sizeOfData = (int) (sizeof(data)) - 1;
    //printf("%d.\n", sizeOfData);
    for(i = 0; i < sizeOfData; i++) {
        for(j = 0; j < sizeOfData - 1 - i; j++) {
            if(data[j] > data[j + 1]) {
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
    
    for(i = 0;  i < sizeOfData; i++) {
        if(i == sizeOfData - 1)
            printf("%d", data[i]);
        else
            printf("%d, ", data[i]);
    }
    printf("\n");
}

//insertion sort實作程式
void insertionSort(int data[]) {
    int i;
    //int sizeOfData = (int) (sizeof(data) / sizeof(int));
    int sizeOfData = (int) (sizeof(data)) - 1;
    //printf("%d.\n", sizeOfData);
    for(i = 1; i < sizeOfData; i++) {
        int position = i;
        const int value = data[i];
        while(position > 0 && data[position - 1] > value) {
            int temp = data[position - 1];
            data[position - 1] = data[position];
            data[position] = temp;
            position--;
        }
        data[position] = value;
    }
    
    for(i = 0;  i < sizeOfData; i++) {
        if(i == sizeOfData - 1)
            printf("%d", data[i]);
        else
            printf("%d, ", data[i]);
    }
    printf("\n");
}

//quick sort實作，使用遞迴，partition為quick sort進行數值交換的子程式
void quickSort(int data[], int head, int tail) {
    if(head >= tail) {
        return;
    }
    else {
        int q = 0;
        q = partition(data, head, tail);
        quickSort(data, head, q - 1);
        quickSort(data, q + 1, tail);
    }
}

int partition(int data[], int head, int tail) {
    int i = head - 1;
    int j;
    for(j = head; j < tail; j++) {
        if(data[j] <= data[tail]) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[tail]);
    return i + 1;
}
//----------quick sort部分結束----------

//merge sort實作，使用遞迴
void mergeSort(int data[], int head, int tail) {
    if(head >= tail) {
        return;
    }
    else {
        int mid = head + (tail - head) / 2;
        mergeSort(data, head, mid);
        mergeSort(data, mid + 1, tail);
        
        merge(data, head, tail, mid);
    }
}

void merge(int data[], int head, int tail, int mid) {
    int i, j, k;
    int n1 = mid - head + 1;
    int n2 = tail - mid;
    int L[n1], R[n2];
    
    for(i = 0; i < n1; i++) {
        L[i] = data[head + i];
    }
    for(j = 0; j < n2; j++) {
        R[j] = data[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = head;
    while(i < n1 && j < n2) {
        if(L[i] >= R[j]) {
            data[k] = R[j];
            j++;
        }
        else {
            data[k] = L[i];
            i++;
        }
        k++;
    }
    
    while(i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}
//----------merge sort部分結束----------

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int sort01[] = {1, 5, 2, 3, 9, -1, -10};
    bubbleSort(sort01);
    printf("%d\n", sort01[0]);
    
    int sort02[] = {-3, 1, -6, 15, 8, 27, 8, -2};
    insertionSort(sort02);
    printf("%d\n", sort02[0]);
    
    int sort03[] = {3, 1, 0, -9, 89, 4, 5, 7, 17};
    int head = 0, tail = (int) (sizeof(sort03) / sizeof(sort03[0]));
    quickSort(sort03, head, tail - 1);
    for(int i = 0; i < tail; i++) {
        if(i == tail - 1)
            printf("%d", sort03[i]);
        else
            printf("%d, ", sort03[i]);
    }
    printf("\n");
    
    int sort04[] = {13, 11, 7, 8, -2, 18};
    int sort04Size = (int) (sizeof(sort04) / sizeof(sort04[0]));
    mergeSort(sort04, 0, sort04Size - 1);
    for(int i = 0; i < sort04Size; i++) {
        if(i == sort04Size - 1)
            printf("%d", sort04[i]);
        else
            printf("%d, ", sort04[i]);
    }
    printf("\n");
    
    return 0;
}
