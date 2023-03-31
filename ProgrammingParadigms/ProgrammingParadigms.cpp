/*
In this project I am demonstrating various programming paradigms.
*/


#include <iostream>
#include "monolithic.c"
#include "modular.c"
#include "structural.c"
#include "ObjectOriented.h"

int main()
{
    std::cout << "################# MONOLITHIC STYLE START #################\n\n";
    monolithic();
    std::cout << "\n################## MONOLITHIC STYLE END ##################\n\n\n";

    std::cout << "################## MODULAR STYLE START ##################\n\n";
    modular();
    std::cout << "\n################### MODULAR STYLE END ###################\n\n\n";

    std::cout << "################# STRUCTURAL STYLE START #################\n\n";
    stuctural();
    std::cout << "\n################# STRUCTURAL STYLE END #################\n\n\n";

    std::cout << "################# OBJECT ORIENTED STYLE START #################\n\n";
    oops();
    std::cout << "\n################# OBJECT ORIENTED STYLE END #################\n\n\n";

    return 0;
}