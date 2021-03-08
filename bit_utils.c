// PID: 730401749
// I pledge the COMP211 honor code.
#include "bit_utils.h"
#include "string.h"

void negate_twos(char *bstring, int size) {
    // reverse all 0s and 1s
    for (int i=0; i < size; i++){
        if (bstring[i] == '0')
            bstring[i] = '1';
        else
            bstring[i] = '0';
    }

    // binary addition to add 1
    for (int i=size-1; i >= 0; i--){
        if (bstring[i] == '0'){
            bstring[i] = '1';
            return;
        } else {
            bstring[i] = '0';
        }
    }
}

char* itob(int num, int size) {

    char output[size];
    int i = 0;
    int isnegative = 0;

        if (num < 0) 
            isnegative = 1;

        // assign string terminator
        output[size] = '\0'; 

        // Convert integer to binary string output
        for (int i = size-1; i >= 0; i--) {
            if (num % 2) {
                output[i] = '1';
            } else {
                output[i] = '0';
            }
            num = num / 2;
        }

        if (isnegative) 
            negate_twos(output, size);
    char *str = (char*)malloc(sizeof(char)*(size));
    str[size] = '\n';
    for (int i=0; i<size; i++) {
        str[i] = output[i];
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
