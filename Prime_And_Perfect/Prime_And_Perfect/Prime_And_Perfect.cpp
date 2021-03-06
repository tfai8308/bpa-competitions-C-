//ID: 01-0024-0005
/*
This program will list all the prime and perfect numbers up to a specified number, "num".
*/
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

bool isPrime(int);
bool isPerfect(int);
void printPrime(int);
void printPerfect(int);

using namespace std;

bool isPrime(int num)
{
	//special cases
	if (num <= 1) return false;
	if (num <= 3) return true;

	//due to the nature of primes, only everything under sqrt(num) needs testing
	for (int i = 2; i <= floor(sqrt(num)); i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}

bool isPerfect(int num)
{
	//a perfect number exists if the sum of the divisors, i, equals num
	int i = 1;
	int total = 0;
	while (i < num)
	{
		if (num % i == 0) total += i;
		i++;
	}
	return num == total;
}


void printPrime(int num)
{
	//forcibly test all prime numbers above the first prime number until num
	for (int i = 2; i <= num; i++)
	{
		//printing the comma before the number, allowing the final comma to be omitted
		//the first number will never have a comma before it through this check
		if (i == 2)
		{
			if (isPrime(i)) cout << i;
		}
		else
		{
			if (isPrime(i))	cout << ", " << i;
		}
	}
	cout << "\n";
}

void printPerfect(int num)
{
	//forcibly test all integers above the first perfect number until num

	for (int i = 6; i <= num; i++)
	{
		//printing the comma before the number, allowing the final comma to be omitted
		//the first number will never have a comma before it through this check
		if (i == 6)
		{
			if (isPerfect(i)) cout << i;
		}
		else
		{
			if (isPerfect(i)) cout << ", " << i;
		}
	}
	cout << "\n";
}

int main()
{
	//control the running state
	char state;
	do
	{
		cout << "Enter a number: ";
		int num;
		cin >> num;

		system("PAUSE");
		system("CLS");

		cout << "Here are the prime numbers up to " << num << ":\n" << endl;
		printPrime(num);

		system("PAUSE");
		system("CLS");

		cout << "Here are the perfect numbers up to " << num << ":\n" << endl;
		printPerfect(num);

		system("PAUSE");
		system("CLS");

		cout << "Would you like to run the program again? (y/n) ";
		cin >> state;

		system("PAUSE");
		system("CLS");
	} while (state == 'y');
    return 0;
}

