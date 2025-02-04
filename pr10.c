#include <stdio.h>

void printBinary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void printFloatParts(float num) {
    union {
        float f;
        unsigned int i;
    } floatUnion;
    
    floatUnion.f = num;

    unsigned int sign = (floatUnion.i >> 31) & 1;
    unsigned int exponent = (floatUnion.i >> 23) & 0xFF;
    unsigned int mantissa = floatUnion.i & 0x7FFFFF;

    printf("Sign: %u\n", sign);
    printf("Exponent: ");
    printBinary(exponent, 8);
    printf("\nMantissa: ");
    printBinary(mantissa, 23);
    printf("\n");
}

int main() {
    float num;
    printf("Enter a floating point number (single precision): ");
    scanf("%f", &num);
    printFloatParts(num);
    return 0;
}
