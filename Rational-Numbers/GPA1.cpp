// GPA1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct rational {
	int numerator;
	int denominator;
};

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void reduce(rational *inputrational, rational *outputrational)
{
	int D = gcd(inputrational->numerator, inputrational->denominator);
	outputrational->numerator = inputrational->numerator / D;
	outputrational->denominator = inputrational->denominator / D;
}

bool isEqual(struct rational num1, struct rational num2) {
	//Write your solution code below this line
	rational A, B;
	reduce(&num1,&A);
	reduce(&num2,&B);
	return (A.numerator == B.numerator && A.denominator == B.denominator);

}

int main() {
	int result;
	rational num1, num2;
	cout << "Enter Details of Number 1 " << endl;
	cout << "Enter Numerator :" << endl;
	cin >> num1.numerator;
	cout << "Enter Denominator :" << endl;
	cin >> num1.denominator;
	cout << "Enter Details of Number 2 " << endl;
	cout << "Enter Numerator :" << endl;
	cin >> num2.numerator;
	cout << "Enter Denominator :" << endl;
	cin >> num2.denominator;
	result = isEqual(num1, num2);     //to check rational 'num1' is equal to rational 'num2' 
	if (result == true)
		cout << "Both rational numbers are equal" << endl;
	else
		cout << "Both rational numbers are not equal" << endl;
	return 0;
}