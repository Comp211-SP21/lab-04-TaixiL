// PID: 730401749
// I pledge the COMP211 honor code.
#include "bit_utils.h"

void setDefaultTo (char origin[], char tar, int size) {
    if (tar==48) {
        for (int i=0; i<size; i++)
            origin[i] = 48;
    } else {
        for (int i=0; i<size; i++)
            origin[i] = 49;
    }
}

int power2 (int power) {
    int power2 = 1;
    for (int j=power; j>0; j--)
        power2 = 2*power2;
    return power2;
}

char* itob (int num, int size){

    char binary[size];
    int startVal = 0;
    char zero = 48;
    char one = 49;
    char sign = (num < 0) ? 45 : 43;
    setDefaultTo(binary, zero, size);

    binary[0] = (sign == 45 && num!=0) ? 49 : 48;

    if (sign == 45 && num != 0) {
        setDefaultTo(binary, one, size);
        startVal = 1;
        zero = 49;
        one = 48;
    }

    if (num<0){
        num = num - 2*num;
    }
    num = num - startVal;
    for (int i=size-1; i>0; i--) {
        int power2Val = power2(i-1);
        binary[size-i] = (power2Val<=num) ? one : zero;
        num = (binary[size-i]==one) ? (num-power2Val) : num;
    }
    char *str = (char*)malloc(sizeof(char)*(size));
    str[size] = '\n';
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

