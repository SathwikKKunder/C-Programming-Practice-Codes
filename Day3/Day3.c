#include <math.h>
#include <stdio.h>
#include "Day3.h"

int convert_binary_to_decimal(int number) { // Function to convert a binary number to decimal.

	int remainder, dec_num=0,i=0;

	while (number != 0) {

		remainder = number % 10;
		dec_num += remainder * pow(2, i);
		number /= 10;
		i++;
	}
	return dec_num;
}

int convert_decimal_to_binary(int number) { // Function to convert a  decimal number to binary.

	int remainder, bin_num = 0, i = 0;

	while (number != 0) {

		remainder = number % 2;
		bin_num += remainder * pow(10, i);
		number /= 2;
		i++;
	}

	return bin_num;
}

int sequence_generator(int n) { 
/*Function generating a sequence of numberssuch that every number in the 
sequence is thesum of the previous three numbers.The first three numbers are 0, 0, 1. */ 
	// function returns no. of elements in sequence

	int sum, i=0, first_num=0, second_num=0, third_num=1;

	if (n <= 0)
		return -1;


	if (n == 3) {
		printf("\n%d,%d,%d", first_num, second_num, third_num);
		return n;
	}
	
	else if (n == 2) {
		printf("\n%d,%d", first_num, second_num);
		return n;
	}
	
	else if (n==1) {
	    printf("\n%d", first_num);
		return n;
	}
	
	else {
		printf("\n%d,%d,%d", first_num, second_num, third_num);
		while ((i + 3) < n)
		{
			sum = first_num + second_num + third_num;
			first_num = second_num;
			second_num = third_num;
			third_num = sum;
			printf(",%d", sum);
			i++;
		}
		return i + 3;
	}
}

int pattern_generator(int row_no){
	/*Function to print the following sketch by taking in N as number of rows
		* * * *
		  * * *
		    * *
		      *     */

	int row=row_no, column,i=0;

	if (row <= 0)
		return -1;

	while (row > 0) {
		column = row;
		i = 0;
		while (column > 0) {

			printf("*\t");
			column--;
		}

		printf("\n");
		
		while (i + row <= row_no) {
			printf("\t");
			i++;
		}

		row--;
	}
	return row;
}

int magic_seven_numbers() {
//Function which will print two digit numbers whose sum of both digit is multiple of seven.e.g. 16, 25, 34......

	int i=1, j,sum;

	while (i < 9)
	{
		j = 1;
		while (j < 9)
		{
			sum = i + j;
			
			if (sum % 7 == 0) {
				sum = i * 10 + j;
				printf("%d ", sum);
			}
			j++;
		}
		i++;
	}
	return 0;
}

int power_of_number_using_recursion(int base, int exponent) { //recursive function for calculating power of a number

	if (base < 0 || exponent < 0)
		return -1;

	if (exponent == 0)
		return 1;
	else
		return base * power_of_number_using_recursion(base, exponent - 1);
}

float factorial_of_number_using_recursion(int number) {  // recursive function for calculating factorial of a number

	if (number < 0)
		return -1;

	else if (number == 0)
		return 1;

	else
		return number * factorial_of_number_using_recursion(number - 1);
}

double series_generator(int x, int n) {
	// recursive calls to evaluate F(x) = x + (x*3 / 3!)+ (x*5 / 5!)+ (x*7 / 7!)+ …
	// "n" is no. of series elements
	static int odd_num=-1;

	if (n <= 0)
		return 0;

	else {
		odd_num += 2;
		return (x * odd_num) / factorial_of_number_using_recursion(odd_num) + series_generator(x, n-1);
	}

}

double series_generator_two(int x, int n) {
	// recursive calls to evaluate F(x) = x + (x^3 / 3!)+ (x^5 / 5!)+ (x^7 / 7!)+ …
	// "n" is no. of series elements
	static int odd_num = -1;

	if (n <= 0)
		return 0;

	else {
		odd_num += 2;
		return (pow(x, odd_num) / factorial_of_number_using_recursion(odd_num)) + series_generator_two(x, n-1);
	}
}

int concatenate_two_integer() {
	//#define concatenate(x,y) x##y
	// The ##preprocessor transforms printf(“ % d”, concatenate(x, y)); into printf(“ % d”, xy);

/* Allows tokens used as actual arguments to be concatenated to form other tokens.
It is often useful to merge two tokens into one while expanding macros.
This is called token pasting or token concatenation.The ‘##’ pre - processing operator performs token pasting.
When a macro is expanded, the two tokens on either side of each ‘##’ operator are combined into a single token,
which then replaces the ‘##’and the two original tokens in the macro expansion. */

	printf("%d",concatenate(7,4));
}

int macro_square(int number) { 
	//function to find square of a number using macros
	return Macro_Square(number);
}

int math_function() {
	//Function to display the mathematical functions like square root, natural log, log10x, power(x,n), Cos(x).
	int option;
	double x;

	printf("Select the mathematical function:\n Square root : 1\n Natural log : 2\n log10(x) : 3\n Power(x,n) : 4\n Cos(x) 'x in radians' : 5\n");
	scanf_s(" %d", &option);

	printf("Enter the value of x\n");
	scanf_s("%lf", &x);

	if (x < 0 || option < 0)
		return - 1;

	switch (option) {
	case 1:
		square_root(x);
		break;

	case 2:
		natural_log(x);
		break;

	case 3:
		log_to_base10(x);
		break;

	case 4:
		power(x);
		break;

	case 5:
		cos_function(x);
		break;

	default:
		return -2;
	}
}

int square_root(double x) {
	if (x == 0)
		return -1;
	printf("Square root of %0.1lf is %lf\n", x, sqrt(x));
	return 0;
}

int natural_log(double x) {
	if (x == 0)
		return -1;

	printf(" Natural log of %0.1lf is %lf\n", x, log(x));
	return 0;
}

int log_to_base10(double x) {
	if (x == 0)
		return -1;

	printf(" log10(%0.1lf) is %lf\n", x, log10(x));
	return 0;
}

int power(double x) {

	int n;

	if (x == 0)
		return -1;

	printf("Enter exponent value n : \n");
	scanf_s("%d", &n);
	printf(" %0.1lf to the power %d is %lf\n", x, n, pow(x, n));
	return 0;
}

int cos_function(double x) {

	printf("Value of Cos(%0.1lf) is %lf\n", x, cos(x));
	return 0;
}