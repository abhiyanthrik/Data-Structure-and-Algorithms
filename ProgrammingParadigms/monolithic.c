/*
This is a monolithic style of programming. It has all the processing done inside the same function.
It is not a recommended style of programming as it makes the program very much bulky to maintain and
hard to debug.
*/

#include <stdio.h>

int monolithic()
{
    int l = 12, b = 8;
    int peri = 0, area = 0;

    printf("Initial length and width is %d m and %d m respectively.\n", l, b);

    peri = 2 * (l + b);
    area = l * b;

    printf("Perimeter of the rectangle is: %d meters.\n", peri);
    printf("Area of the rectangle is: %d sq-meters. \n", area);

    return 0;
}
