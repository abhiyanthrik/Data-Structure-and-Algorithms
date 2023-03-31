/*

This is a modular style of programming.

It has separate modules/functions to perform individual computations,
and user interaction is done inside the main(modular in this case) function.

Modularity makes the program much easier to maintain and upgrade in future.
It also makes it easy to debug as we know which module might be buggy.

Modular style is generally used with stuctural and Object Oriented styles of progamming.

*/


#include <stdio.h>


int perimeter(int lenth, int width)
{
    return 2 * (lenth + width);
}

int area(int length, int width)
{
    return length * width;
}

void modular()
{
    int l = 12, b = 8;
    int peri = 0, ar = 0;

    printf("Initial length and width is %d m and %d m respectively.\n", l, b);

    peri = perimeter(l, b);
    ar = area(l, b);

    printf("Perimeter of the rectangle is: %d meters.", peri);
    printf("\nArea of the rectangle is: %d sq-meters. \n", ar);
}
