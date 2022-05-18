//
//  main.c
//  C_Bitwise01
//
//  Created by Ancacion on 2022/5/18.
//

#include <stdio.h>

/* bit clear:
  a: int,
  pos: bit position to clear */
#define CLEARBIT(a, pos) (a &= ~(1 << pos))

void bitwiseConvertCase(char input) { //英文字母大小寫交換
    /* 'z': decimal value 122 (=01111010) */
    //char a = 'z';

    /* clearing the 5th bit */
    char aOut = CLEARBIT(input, 5);

    /* aOut = 'Z': decimal value 90 (=01011010) */
    printf("aOut = %c\n", aOut);
    
    char AOut = (input ^ ' ');
    printf("AOut = %c\n", AOut);
}

void xorSwap(int *x, int *y) { //不用額外消耗記憶體的數值交換做法
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

int isPowerOf2(int input) { //2次方檢查bitwise
    if(input > 0) {
        int checkNum = input & (input - 1);
        if(checkNum == 0) {
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

void bitwiseRight() {
    uint32_t num = 0b10100110; //0b = 二進制
    printf("%d\n", (num >> 2)); //0000101001
}

void bitwiseLeft() {
    uint32_t num = 0b10100110;
    printf("%d\n", (num << 2)); //1010011000, 8 + 16 + 128 + 512
}

int bitwiseGetBit(uint32_t num, int input) { //取出x在第n位的值
    return (num >> input) & 1; //1111 1010 1111 1100 右移8位變成 0000 0000 1111 1010, 取最右邊的數字與1做and運算
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    char input1 = 'a';
    bitwiseConvertCase(input1);
    printf("\n");
    
    int x0 = 2, y0 = 6;
    xorSwap(&x0, &y0);
    printf("x0 = %d, y0 = %d.\n\n", x0, y0);
    
    int x1 = 8, y1 = 10;
    int x1Check = isPowerOf2(x1), y1Check = isPowerOf2(y1);
    printf("x1Check = %d, y1Check = %d.\n\n", x1Check, y1Check);
    
    bitwiseRight();
    bitwiseLeft();
    printf("\n");
    
    uint32_t num01 = 0xfafc; //1111 1010 1111 1100
    int checkBit = 0;
    int num = 9;
    checkBit = bitwiseGetBit(num01, num - 1);
    printf("checkBit = %d\n", checkBit);
    
    return 0;
}
