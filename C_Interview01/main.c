//
//  main.c
//  C_Interview
//
//  Created by Ancacion on 2022/5/4.
//
#include <stdio.h>

#define PI 3.1415926
#define SUM(x, y) (x + y) //這邊若寫成main內的其他參數會導致使用該main參數進行計算
#define MAX(x, y) ((x) >= (y) ? (x) : (y))
//typedef enum {false, true} bool; //在C語言內自定義boolean之一
typedef int bool; //在C語言內自定義boolean之二
#define false 0;
#define true 1;

void swap(int *a, int *b) { //雙數字交換
    int temp = *a;
    *a = *b;
    *b = temp;
}

void strCopy(char *dst, char *src) { //字串複製
    /*
    while((*dst = *src) != '\0') {
        dst++;
        src++;
    }
    */
    while(*dst != '\0' || *src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
}

int strLength(const char *str) { //字串長度
    int len = 0;
    while(*str != '\0') {
        len++;
        str++;
    }
    return len;
}

int isPowerOf2(int input) { //2次方檢查&bitwise
    if(input > 0) {
        int checkNum = input & (input - 1);
        //printf("%d\n", checkNum);
        if(checkNum == 0) {
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

//-----指標練習(交換)-----
void pointerPractice01() {
    int a = 8, b = 5;
    int *aPointer =& a, *bPointer =& b;
    //指標顯示其指向的數值，需使用＊，若沒使用＊會回傳其記憶體位置
    //printf("aPointer = %d, bPointer = %d. \n", aPointer, bPointer);
    printf("a's address = %p, b's address = %p\n", aPointer, bPointer);
    printf("aPointer = %d, bPointer = %d. \n", a, b);
    swap(aPointer, bPointer);
    printf("aPointer = %d, bPointer = %d. \n", a, b);
    swap(&a, &b);
    printf("aPointer = %d, bPointer = %d. \n", a, b);
}

//-----指標的指標練習-----
void pointerPractice02() {
    int origin = 10;
    int *originPointer =& origin;
    int **testPointer =& originPointer;
    printf("%d\n", **testPointer);
    printf("testPointer's memory direct to = %p.\noriginPointer's memory direct to  = %p.\n", testPointer, originPointer);
    printf("testPointer's memory address = %p.\noriginPointer's memory address = %p.\n", &testPointer, &originPointer);
    **testPointer = **testPointer + 1;
    printf("origin = %d\n", origin);
    //printf("testPointer's memory address = %p.\noriginPointer's memory address = %p.\n", &testPointer, &originPointer);
}

//-----使用define-----
void definePractice01() {
    int c = 10, d = 15;
    int sumInt = SUM(c, d);
    printf("sumInt = %d\n",sumInt);
}

//-----array寫法-----
void arrayPractice01() {
    int array[10];
    int i;
    for(i = 0; i < 10; i++) {
        array[i] = i + 1;
    }
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i] + 1);
    }
    printf("\n");
}

//-----字串練習(複製與字串長度)-----
void stringPractice01() {
    char firstWord[10] = "ABCDEFGHIJ", secondWord[15] = "";
    strCopy(secondWord, firstWord);
    printf("%s\n", secondWord);
    int length = strLength(secondWord);
    printf("length = %d\n", length);
}

//-----bitwise練習(2次方檢查)-----
void bitwisePractice01() {
    int testPowerOf2_1 = 8, testPowerOf2_2 = 17;
    int result1 = isPowerOf2(testPowerOf2_1), result2 = isPowerOf2(testPowerOf2_2);
    printf("result1 = %d, result2 = %d\n", result1, result2);
}

//-----郭老習題範例-----
void jykuo01(int a, int *b, int *c) {
    int d;
    a = 2; *b = 3; c =& a; d = 5;
}

void jykuo02() {
    double i01 = 4, j01 = 5, *p01 =& j01, *q01 =& i01, *r;
    printf("%f, %f\n", *p01, *q01); //ans = 5.00 4.00
    r = p01; p01 = q01; q01 = r;  //swap記憶體位置 pi qj兩邊交換所以其分別代表的值也跟著交換
    printf("%f, %f\n", *p01, *q01); //ans = 4.00 5.00
}

void jykuo03() {
    int i02 = 1, sum = 0, a02[10] = {10,9,8,7,6,5,4,3,2,1}, *p02 =& i02, *q02 = a02+5;
    printf("%d %d\n", *a02, q02[1]); //ans = 10 4 (a02沒有做更動代表在陣列最前端, q02預設已經在陣列內移動5格目前位置在5, [1]表示再向右一個 -> 4)
    printf("%d %d\n", (*p02)++, *(++q02)); //ans = 1 4 (*p02取值後加一所以先印出原本的1後加一，目前為2; q02為在陣列內右移後取值，從5移動到4)
    printf("%d %d\n", *p02, *q02); //ans = 2 4
    for(sum = 0, p02 = a02 + 6; p02 > a02; p02--) {
        sum += *(p02 + 1); // +1 != ++, 所以是固定取p02右邊的值來做累加(3+4+5+6+7+8)
        //printf("sum = %d\n", sum);
    }
    printf("%d %d\n", sum, *p02); //ans = 33 10
    p02 = q02 = a02;  //p02跟q02的記憶體位置相等, q02與a02的記憶體位置相等, 所以三者皆指向a02
    printf("*p02 = %d, *q02 = %d, *a02 = %d\n", *p02, *q02, *a02); //印出的值皆為a02[0] = 10
    i02 = *(p02++); //i02 = 10, p02取值後右移
    printf("i02 = %d, *p02 = %d\n", i02, *p02); //ans = 10 9(p02已經右移至9)
    i02 += (*q02)++; //i02 = 10 + 10, q02取值後+1, 因q02與a02的位置相等 所以a02[0]也跟著+1變成11
    //printf("%d\n", i02);
    printf("%d %d\n", a02[0], --i02); //ans = 11 19(--在前先執行-1所以從20變19)
    printf("*p02 = %d, *q02 = %d, *a02 = %d\n", *p02, *q02, *a02); //印出的值為9 11 11
}

void jykuo04() {
    int i = 4, *p =& i, *q =& i;
    printf("%d %d\n", *p, *&i); //ans = 4 4
    i += (*q)*(*p); //i = 4 + 4 x 4 = 20
    printf("%d %d\n", i, q); //ans = 20 unknown(記憶體位置需使用%p)
    
    int a[] = {1,3,5,7,9}, *p2 = a, *q2 = p2 + 1;
    printf("%d %d\n", *a+3, *(a+3)); //ans = 4 7
    printf("%d %d\n", *p2, q2[3]); //ans = 1 9
    printf("%d %d\n", a[*p2], a[q2 - p2]); //ans = 3 3?
    
    char s[] = "abcdefg", *p3 = s + 2;
    printf("%d %d\n", s, s + 1); //ans = unknown unknown, 應改成%s
    printf("%d %d\n", *p3, p3); //ans = 99 unknown, 想用%d印出字元值會顯示其ascii的數字, 此處"c"為99。 若要印出記憶體位置需使用%p
    s[3] = 'h';
    printf("%d %d\n", s, p3[1]); //ans = unknown 104,h的ascii數
}
/*
void jykuo05() {
    int a[5] = {1,2,3,4,5};
    jykuo06(a, a[1], &a[2], a+3, &a[4]);
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void jykuo06(int a[], int p1, int *p2, int *p3, int *p4){
    a[0] = 8;
    p1 = 7;
    *p2 = 6;
    p3 = a+1;
    *p4 = 5 + (*p3);
}
*/
int main(int argc, const char * argv[]) {
    // insert code here...
    ///*
    pointerPractice01();
    printf("\n");
    
    definePractice01();
    printf("\n");
    
    arrayPractice01();
    printf("\n");
    
    stringPractice01();
    printf("\n");
    
    pointerPractice02();
    printf("\n");
    
    bitwisePractice01();
    printf("\n");
    
    int a = 1, b = 2, c = 3, d = 4;
    jykuo01(a, &b, &c);
    printf("%i, %i, %i, %i\n", a, b, c, d); //ans = 1, 3, 3, 4
    
    jykuo02();
    printf("\n");
    //*/
    jykuo03();
    printf("\n");
    
    //jykuo04();
    //printf("\n");
    
    //jykuo05();
    //printf("\n");
    
    return 0;
}
