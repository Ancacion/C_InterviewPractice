//
//  main.c
//  C_Bitwise02
//
//  Created by Ancacion on 2022/5/18.
//

#include <stdio.h>

unsigned int get_highest_bit_position(unsigned int x) { //獲得8 bit最高位元位置
    x |= (x >> 1); //    00001000
                //    |  00010001
                //    =  00011001
    printf("x1 = %d.\n", x); // = 25
    x |= (x >> 2); //    00000110
                //    |  00011001
                //    =  00011111
    printf("x2 = %d.\n", x); // = 31
    x |= (x >> 4); //    00000001
                //    |  00011111
                //    =  00011111
    printf("x4 = %d.\n", x); // = 31
    x |= (x >> 8);  //   00000000
                //    |  00011111
                //    =  00011111
    printf("x8 = %d.\n", x); // = 31
    return x - (x >> 1); // 00011111
                //        - 00001111 = 16
    /*
    while((x & (x - 1)) != 0) {
        x &= (x - 1);
    }
    return x;
    */
}

unsigned int get_lower_bit_position(unsigned int x) { //獲得8 bit最低位元位置
    x = x & (-x);  // 01010010
                //  & 10101110 //負數為原正數01倒轉後+1
                //  = 00000010
    printf("x = %d.\n", x);
    return get_highest_bit_position(x); //與補數and運算完後呼叫求最高位元位置的子程式
}

int numbers_of_1_in_int(unsigned int x) {
    int ans = 0, i;
    for(i = 0; i < 8; i++) {
        if(((x >> i) & 1 )== 1) {
            ans++;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    unsigned int x0 = 0b00010001;
    unsigned int ans1 = get_highest_bit_position(x0);
    printf("ans1 = %d.\n\n", ans1);
    
    unsigned int x1 = 0b01010010;
    unsigned int ans2 = get_lower_bit_position(x1);
    printf("ans2 = %d.\n\n", ans2);
    
    unsigned int x3 = 0b11111110;
    int x3_1_count = numbers_of_1_in_int(x3);
    printf("x3_1_count = %d.\n\n", x3_1_count);
    
    return 0;
}
