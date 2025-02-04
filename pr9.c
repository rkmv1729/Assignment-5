#include <stdio.h>

int BCDToDecimal(unsigned char bcd);

int main(void)
{
    unsigned char bcdNumber;

    printf("Enter an 8-bit BCD encoded number: ");
    scanf("%hhu", &bcdNumber);

    int decimalNumber = BCDToDecimal(bcdNumber);

    printf("The decimal number is: %d\n", decimalNumber);

    return 0;
}

int BCDToDecimal(unsigned char bcd)
{
    int tens = (bcd >> 4) & 0x0F; // Extract the tens digit (upper nibble)
    int ones = bcd & 0x0F;        // Extract the ones digit (lower nibble)

    return (tens * 10) + ones;
}
