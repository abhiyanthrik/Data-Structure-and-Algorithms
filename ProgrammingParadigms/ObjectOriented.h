/*
In this example I used Object-Oriented style of programming.

This is an extension of structural programming as we use a class for grouping related data members
along with their member functions under same name. This way we we complete the implimentation of
our data structure.

Although OOP is a big concept, we are just looking at it in it's very basic form. 

I have converted the class into a generic template.
*/
#pragma once

#include <iostream>

template <class T>
class Rectangle
{

private:
    T length, width;

public:
    Rectangle() {} // Default constructor

    Rectangle(T l, T b); // Parameterised constructor

    T perimeter(); // Calculating the perimeter of rectangle

    T area(); // Calculating the area

    void set_length(T new_length); // Updating lenth

    void set_width(T new_width); // Updating Width

    //As private data-members are inaccessible outside the class,
    //So, we need to write functions to access them.
    T get_length();
    T get_width();
};

template <class T>
Rectangle<T> ::Rectangle(T l, T b)
{
    length = l;
    width = b;
}

template <class T>
T Rectangle<T> ::perimeter()
{
    return 2 * (length + width);
}

template <class T>
T Rectangle<T> ::area()
{
    return length * width;
}

template <class T>
void Rectangle<T> ::set_length(T new_length)
{
    length = new_length;
}

template <class T>
void Rectangle<T> ::set_width(T new_width)
{
    width = new_width;
}

template <class T>
T Rectangle<T> ::get_length()
{
    return length;
}

template <class T>
T Rectangle<T> ::get_width()
{
    return width;
}

void oops()
{
    float peri = 0.0, ar = 0.0, l = 0.0, b = 0.0;

    l = 12.56, b = 8.7;

    Rectangle<float> rect{ l, b };

    std::cout << "Initial length and width is " << rect.get_length() << " and " << rect.get_width() << " respectively.\n";

    peri = rect.perimeter();
    ar = rect.area();

    std::cout << "Perimeter of the rectangle is: " << peri << " meters.\n";
    std::cout << "Area of the rectangle is: " << ar << " sq-meters. \n";

    std::cout << "Let's update length and width of the rectanle.\n";
    std::cout << "The old lenth and width are " << rect.get_length() << " and " << rect.get_width() << " respectively.\n";

    rect.set_length(20.056);
    rect.set_width(12.098);

    std::cout << "New lenth and width are " << rect.get_length() << " and " << rect.get_width() << " respectively.\n";

}