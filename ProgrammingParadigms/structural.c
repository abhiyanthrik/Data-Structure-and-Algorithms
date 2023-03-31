/*
This is a structural style of programming.

We use structure for grouping related data members under one name and creat
our own data-type, we write helper-functions to manipulate the data inside the structure.

This style is used when we have our own data structure to impliment.

Combination of this style and right choice of data structure & algorithm makes the program
very efficient in terms of space and time complexities.

*/


#include <stdio.h>

// Custom data structure Rect
struct Rect
{
    int length, width;
};

void initialize(struct Rect* rectangle,int l, int b) // To initialize the structure
{
    rectangle->length = l;
    rectangle->width = b;
}

int rectPerimeter(struct Rect rectangle) // Calculating the perimeter of rectangle
{
    return 2 * (rectangle.length + rectangle.width);
}

int rectArea(struct Rect rectangle) // Calculating the area
{
    return rectangle.length * rectangle.width;
}

void updateLength(struct Rect*rectangle, int new_length) // Updating an existing structure
{
    rectangle->length = new_length;
}

void updateWidth(struct Rect*rectangle, int new_width) // Updating Width
{
    rectangle->width = new_width;
}

void stuctural()
{
    struct Rect rect = {0, 0};

    int peri = 0, ar = 0, l = 0, b = 0;
    
    l = 12, b = 8;
    
    initialize( &rect, l, b);

    printf("Initial length and width is %d m and %d m respectively.\n", rect.length, rect.width);
    
    peri = rectPerimeter(rect);
    ar = rectArea(rect);
    
    printf("Perimeter of the rectangle is: %d meters.\n", peri);
    printf("Area of the rectangle is: %d sq-meters. \n", ar);
    
    printf("Let's update length and width of the rectanle.\n");
    printf("The old lenth and width are %d and %d respectively.\n", rect.length, rect.width);

    updateLength(&rect, 20);
    updateWidth(&rect, 12);

    printf("New lenth and width are %d and %d respectively.\n", rect.length, rect.width);
}
