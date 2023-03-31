#pragma once
#include <iostream>

/*****************************************************************************************************

This file contains the declaration of all the recursive functions that I have used in the project.
First I have tried to demonstrate types of recursive calls and letter are some example codes
which describes how recursion could be used to solve problems.

*****************************************************************************************************/

// Helper functions for indirect recursion...
void funcA(int n);
void funcB(int n);


int staticFun(int a)
{
	/**********************************************************************************
	
	This function demonstrates how static variable behaves with recursion.

	Static variables are created inside code section in the memory and their life
	span is as long as the run time of the program, they can be declared anywhere
	and can be utilized outside thir local scope also.
	
	***********************************************************************************/

	static int x = 0; //will be instantiated only once
	if (a > 0)
	{
		x++;          //will increment at every call
		std::cout << a << " ";
		return staticFun(a - 1) + x;  //x will be added at the end of every recursion
	}
	return 0;
}



void tailRecursion(int n)
{
	/**********************************************************************************

	If the recursive call is made at the end of the recursive function and there is no
	statements are written after the recursive call, we descrive it as tail recursion.

	**********************************************************************************/

	if (n > 0)
	{
		std::cout << n << '\n';
		tailRecursion(n - 1); //recursive call
	}
}


void headRecursion(int n)
{
	/************************************************************************************************************

	If the recursive call made at the very first statement of a recursive function, we call it a head recursion.
	In a head recursion, whatever statements are written after the recursive call will be executed
	once all the recursive calls are over.

	*************************************************************************************************************/


	if (n > 0) headRecursion(n - 1); //recursive call
	std::cout << n << '\n';
}


void treeRecursion(int n)
{
	/******************************************************************************************************************

	When we made more than one recursive call inside a recursive function, we call it a tree recursion.
	Time complexity of a tree recursion depends upon the number and the manner in which recursive calls are made.
	The following function has O(2^n) time complexity.
	Space complexity depends upon the height (or levels) of the tree, and following function has O(n) space complexity.

	*******************************************************************************************************************/

	if (n > 0)
	{
		std::cout << n << '\n';
		treeRecursion(n - 1);
		treeRecursion(n - 1);
	}
}


void funcB(int n)
{
	if (n > 0)
	{
		std::cout << n << '\n';
		funcA(n / 2);      //funcB calling funcA
	}
}

void funcA(int n)
{
	if (n > 0)
	{
		std::cout << n << '\n';
		funcB(n - 1);     //funcA calling funcB
	}
}

void indirectRecursion(int n)
{

	/**************************************************************************************************

	Let's consider two (or more than two) functions which are calling each other in a circular manner,

									 -> funcA()-
									/             \
								   |               |
								   |			   v
								 funcD()         funcB()
								   ^               |
								   |               |
									\		      /
									  -funcC()<-
	This is called indirect recursion, where we don't have a direct recursion, but we call the functions
	from another function in a circular fashion.

	Following is an example of the same with two functions.

	The initial call is made in the main body(types_of_recursion)

	******************************************************************************************************/

	funcA(n);           //First call
}


int nestedRecursion(int n)
{
	/*****************************************************************************************

	Nested recursion: When we pass the recursive function as parameter in the recursive call,
	we call it a nested recursion.

	******************************************************************************************/

	if (n > 100) return n - 10;
	else return (nestedRecursion(nestedRecursion(n + 11)));
}


/*
In the following files I have included the examples of recursion.These codes well explains how
recursion could be used to solve various kinds of problem
*/

int sumOfNaturalNumbers(int n);
int factorialOfN(int n);
int raisedToN(int m, int n);
double taylorsSeries(int x, int n);
int fibonacciSeries(int n);
int nCr(int n, int r);
void toh(int n, int A, int B, int C);
float sineSeries(float x, int n);
int countPartition(int n, int m);


int sumOfNaturalNumbers(int n)
{
	/******************************************************************************
	This is an example of recursion in action where we are taking the cumulative sum
	of n natural numbers using a recursion.

	Althought this sum can be calculated with O(1) complexity using the AP formula

					   Sum_of_n_natural_numbers = n/2 * (n + 1),

	But for the sake of understanding let's consider the recursive approach.
	here the time complexity is O(n) and same is the space complexity as well.

	*******************************************************************************/

	if (n == 0) return 0;
	else return sumOfNaturalNumbers(n - 1) + n;
}


int factorialOfN(int n) 
{
	/********************************************************************************
	We define factorial of n as follows:
	n! = 1 * 2 * 3 * 4 * ... * n

	we can calculate factorial using recursion as shown in the following code

	Following function is declared and called in the main body(examples_of_recursion)
	*********************************************************************************/

	if (n < 0) return 0;
	if ((n == 0) or (n == 1)) return 1;
	else return n * factorialOfN(n - 1);
}


int raisedToN(int m, int n)
{
	/******************************************************************************************
	In this function we are calculating an integer m raised to power of n using recursion.

	There are two approaches which we have used, and uncommented code below is the optimized
	approach, in which the number of function call are half of the calls made in commented code.

	*******************************************************************************************/


	//Following are the boundary conditions and shared among both the approaches
	if ((m == 1) or (n == 1)) return m;
	if (m == 0) return 0;
	if (n == 0) return 1;

	//Unoptimized Approach(Uncomment to test)
	//return m * raised_ro_power_of_n(m, n - 1);*/


	//Optimized approach
	if (n % 2 == 0) return raisedToN(m * m, n / 2);
	return m * raisedToN(m * m, (n - 1) / 2);
}

double taylorsSeries(int x, int n) {

	//Recursion (Unoptimized)
	/*static double p = 1, f = 1;
	double r;
	if (n == 0) return 1;
	r = taylorsSeries(x, n - 1);
	p *= x;
	f *= n;
	return(r + p / f);*/

	//Recursion(Optimized using Horner's Rule)
	static double S = 0;
	if (n == 0) return S;
	S = 1 + x * S / n;
	return taylorsSeries(x, n - 1);

	//Using iteration (loop)
	/*double S = 1;
	for (; n > 0; n--) {
	S = 1 + x * S / n;
	}
	return S;*/
}


// Fibonacci Series using memoization
int mfib(int n, int* F)
{
	if (n <= 1)
	{
		F[n] = n;
		return n;
	}

	else
	{
		if (F[n - 2] == -1) F[n - 2] = mfib(n - 2, F);
		if (F[n - 1] == -1) F[n - 1] = mfib(n - 1, F);
		F[n] = F[n - 2] + F[n - 1];
		return F[n];
	}
}

int fibonacciSeries(int n)
{
	/******************************************************************************************

	In this function I have included several ways in which we can get the nth term of a fibonacci
	series, the uncomented part is the optimal solution where memoization is used to avoid
	unnecessary calculations in the recursion, and broght down the time complexity to O(n) from
	O(2^n) in pure recursion. The iterative method also has O(n) time complexity.

	Feel free to uncomment other parts(and comment out part which is not in use).

	******************************************************************************************/

	//Part(1)Using iteration
	/*int t0 = 0, t1 = 1, s = 0, i;
	if (n <= 1) return n;
	for (i = 2; i <= n; i++) {
		s = t0 + t1;
		t0 = t1;
		t1 = s;
	}
	return s;*/

	//Part(2): Using  recursion (Unoptimized recursion)
	/*if (n <= 1) return n;
	return fibonacci_series(n - 2) + fibonacci_series(n - 1);*/

	//Part(3): Using memoization(Optimized recursion)
	int* F = new int[n] {0};  //Used for memoization
	// Initializing F[] to -1 to be used in mfib
	for (int i = 0; i < n; i++)
	{
		F[i] = -1;
	}
	return mfib(n, F);
}



int nCr(int n, int r)
{
	//Using Factorial
	/*int a, b, c;
	a = factorialOfN(n);
	b = factorialOfN(r);
	c = factorialOfN(n - r);
	return a / (b * c);*/

	//Using Recursion(Pascal's Triangle)
	if ((r == 0) || (n == r)) return 1;
	return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// Tower of Honoi
void toh(int n, int A, int B, int C)
{
	if (n > 0)
	{
		toh(n - 1, A, C, B);
		std::cout << "(From " << A << " To " << C << ")" << "\n";
		toh(n - 1, B, A, C);
	}
}


float sineSeries(float x, int n) {

	//static double r = x;
	x = x * 3.13 / 180;
	long r, dnmntr, nmrtr;
	if (n == 0) return x;
	r = sineSeries(x, n - 1);
	nmrtr = raisedToN(x, 2 * n + 1);
	dnmntr = factorialOfN(2 * n + 1);
	if (n % 2 == 0) return(r + nmrtr / dnmntr);
	return (r - nmrtr / dnmntr);

	/*
	// Iterative version...

	int i;
	long float t0, t1, R, sum;
	
	//Initialize First Term
	x = x * 3.13 / 180;
	t0 = x;
	
	//Make sum equal to the first term
	
	sum = t0;
	
	for (i = 1; i < n; i++)
	{
		// Find the ratio of the second term to the first term using already known relation
		R = -(x * x) / (2 * i + 1) / (2 * i);
		
		// Calculate the second term
		t1 = R * t0;
		
		// find the new sum
		sum = sum + t1;
		t0 = t1;
	}
	return sum;
	*/
}


int countPartition(int n, int m)
{
	/************************************************************************************
	This function is a recursive solution to the following problem:
			Write a program that counts the number of ways you can partition n object using
			parts upto m (assume m >= 0).
	*************************************************************************************/

	if (n == 0) return 1;
	else if ((m == 0) || (n < 0)) return 0;
	return (countPartition(n - m, m) + countPartition(n, m - 1));
}

