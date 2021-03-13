// PID: 730401749
// I pledge the COMP211 honor code.
#include "bit_utils.h"
#include <string.h>

int power2 (int power) {
    int power2 = 1;
    for (int j=power; j>0; j--)
        power2 = 2*power2;
    return power2;
}

char* itob (int num, int size){

    char binary[size];
    binary[size] = 0;
    char zero = 48;
    char one = 49;
    
    if (num>=0){
        for (int i=0; i<size; i++)
            binary[i] = 48; 
    } else {
        for (int i=0; i<size; i++)
            binary[i] = 49;
        zero = 49;
        one = 48;
        num = num - 2*num - 1;
    }
    
    for (int i=size-1; i>0; i--) {
        int power2Val = power2(i-1);
        binary[size-i] = (power2Val<=num) ? one : zero;
        num = (binary[size-i]==one) ? (num-power2Val) : num;
    }

    char *str = (char*)malloc(sizeof(char)*(size));
    str[size] = 0;
    for (int i=0; i<size; i++) {
        str[i] = binary[i];
    }

    return str;
}


int mask_bits(int num, int bit){
    int result = num & bit;
    return result;
}

int set_bits(int num, int bit){
    int result = num | bit;
    return result;
}

int inverse_bits(int num, int bit){
    int result = num ^ bit;
    return result;
}

int bit_select(int num, int mostSignificant, int leastSignificant){
    int number = mostSignificant - leastSignificant + 1;
    int result = (num >> (mostSignificant+1-number)) & ~(~0 << number);
    return result;
}
