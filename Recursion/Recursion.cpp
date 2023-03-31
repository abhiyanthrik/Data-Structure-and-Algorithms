/*****************************************************************************************************

This is the main body of the project which demonstrates the types of recursive functions.
In this project I have included 5 types of recursive function which are as follows:
1 TAIL RECURSION    2 HEAD RECURSION    3 TREE RECURSION    4 INDIRECT RECURSION    5 NESTED RECURSION

Then there are some example problem statements solved to demonstrate the how the concept of recursion
is applied to solve various kind of problems.

*****************************************************************************************************/

#include <iostream>
#include"recursion.h"


int main()
{
    // Followings are the types of recursion...
    std::cout << "This is the start of StaticFun\n";
    std::cout << staticFun(5) << '\n';
    std::cout << "Execution of StaticFun function is over\n\n";

    
    std::cout << "TailRecursion starts here\n";
    tailRecursion(5);
    std::cout << "TailRecursion ends here\n\n";

    std::cout << "HeadRecursion starts here\n";
    headRecursion(5);
    std::cout << "HeadRecursion ends here\n\n";

    std::cout << "TreeRecursion starts here\n";
    treeRecursion(3);
    std::cout << "TreeRecursion ends here\n\n";

    std::cout << "IndirectRecursion starts here\n";
    indirectRecursion(5);
    std::cout << "IndirectRecursion ends here\n\n";

    std::cout << "NestedRecursion ends here\n";
    std::cout << nestedRecursion(95) << '\n';
    std::cout << "NestedRecursion ends here\n\n";

    
    // Following are the examples demonstrating the use cases of recursion...
    std::cout << "sumOfNaturalNumbers starts here \n";
    std::cout << sumOfNaturalNumbers(9) << '\n';
    std::cout << "sumOfNaturalNumbers ends here \n\n";

    std::cout << "factorialOfN starts here \n";
    std::cout << factorialOfN(-2) << '\n';
    std::cout << "factorialOfN ends here \n\n";

    std::cout << "raisedToN starts here \n";
    std::cout << raisedToN(9, 3) << '\n';
    std::cout << "raisedToN ends here \n\n";

    std::cout << "taylorsSeries starts here \n";
    std::cout << taylorsSeries(2, 10) << '\n';
    std::cout << "taylorsSeries ends here \n\n";

    std::cout << "fibonacciSeries starts here \n";
    std::cout << fibonacciSeries(10) << '\n';
    std::cout << "fibonacciSeries ends here \n\n";

    std::cout << "nCr starts here \n";
    std::cout << nCr(5, 3) << '\n';
    std::cout << "nCr ends here \n\n";

    std::cout << "toh starts here \n";
    toh(3, 1, 2, 3);
    std::cout << "toh ends here \n\n";

    std::cout << "countPartition starts here \n";
    std::cout << countPartition(9, 8) << '\n';;
    std::cout << "countPartition ends here \n\n";

    std::cout << "sineSeries starts here \n";
    std::cout << sineSeries(45, 10) << '\n';
    std::cout << "sineSeries ends here \n\n";
    
    return 0;
}

