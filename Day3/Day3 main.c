#include <assert.h>
#include <stdio.h>
#include "Day3.h"

void test_convert_binary_to_decimal();
void test_convert_decimal_to_binary();
void test_sequence_generator();
void test_pattern_generator();
void test_magic_seven_numbers();
void test_power_of_number_using_recursion();
void test_factorial_of_number_using_recursion();
void test_series_generator();
void test_macro_square();
void test_math_function();

int main() {

	//test_convert_binary_to_decimal();             //Testing binary number to decimal function call
	//test_convert_decimal_to_binary();             //Testing decimal number to binary function call
	//test_sequence_generator();                   //Testing sequence generator function call
	//test_pattern_generator();                    //Testing pattern generator function call
	//test_magic_seven_numbers();                 // Testing magic seven number sequence generator function call
	//test_power_of_number_using_recursion();     // Testing power of number using recursion function call
	//test_factorial_of_number_using_recursion(); // Testing factorial of number using recursion function call
	//test_series_generator();                   // Testing series generator
	//concatenate_two_integer();
	//test_macro_square();                         //Testing function to find square of a number using macros
	// test_math_function();                      //Testing math_function


}

void test_convert_binary_to_decimal() { //Testing binary number to decimal function 

	assert(convert_binary_to_decimal(101) == 5);
	assert(convert_binary_to_decimal(111) == 7);
	assert(convert_binary_to_decimal(001) == 1);
	assert(convert_binary_to_decimal(1101) == 13);
	assert(convert_binary_to_decimal(000) == 0);
}

void test_convert_decimal_to_binary() {  //Testing decimal number to binary function call

	assert(convert_decimal_to_binary(5) == 101);
	assert(convert_decimal_to_binary(7) == 111);
	assert(convert_decimal_to_binary(1) == 001);
	assert(convert_decimal_to_binary(16) == 10000);
	assert(convert_decimal_to_binary(74) == 1001010);
	assert(convert_decimal_to_binary(35) == 100011);
}

void test_sequence_generator() {   //Testing sequence generator function
	// sequence_generator(int N), N is no. of elements
	// function returns no. of elements in sequence

	assert(sequence_generator(5) == 5);
	assert(sequence_generator(1) == 1);
	assert(sequence_generator(2) == 2);
	assert(sequence_generator(3) == 3);
	assert(sequence_generator(0) == -1);
}

void test_pattern_generator() { //Testing pattern generator function

	assert(pattern_generator(5) == 0);
	assert(pattern_generator(-5) == -1);
}

void test_magic_seven_numbers() { // Testing magic seven number sequence generator function

	assert(magic_seven_numbers() == 0);
}

void test_power_of_number_using_recursion() { // Testing power of number using recursion function

	assert(power_of_number_using_recursion(5, 3) == 125);
	assert(power_of_number_using_recursion(2, 10) == 1024);
	assert(power_of_number_using_recursion(3, 5) == 243);
	assert(power_of_number_using_recursion(5, 0) == 1);
	assert(power_of_number_using_recursion(5, -3) == -1);
	assert(power_of_number_using_recursion(-5, 3) == -1);
}

void test_factorial_of_number_using_recursion() { // Testing factorial of number using recursion function

	assert(factorial_of_number_using_recursion(4) == 24);
	assert(factorial_of_number_using_recursion(5) == 120);
	assert(factorial_of_number_using_recursion(0) == 1);
	assert(factorial_of_number_using_recursion(-4) == -1);
}

void test_series_generator() {
	int x, n;
	double ans1,ans2;

	 //assert(series_generator(1,3)== 1.541667);
	 //assert(series_generator_two(1,3)== 1.175000);
	
	// Series 1 F(x) = x + (x*3 / 3!)+ (x*5 / 5!)+ (x*7 / 7!)+ …
	 
	// Series 2 F(x) = x + (x^3 / 3!)+ (x^5 / 5!)+ (x^7 / 7!)+ …
	// series_generator(int x, int n)
	// "n" is no. of series elements

	printf("Enter the value of x\n");
	scanf_s("%d", &x);
	printf("Enter the value of n\n");
	scanf_s("%d", &n);

	ans1 = series_generator(x, n);
	ans2 = series_generator_two(x, n);

	printf("The sum of the series1 is %0.6lf\nThe sum of the series2 is %0.6lf\n", ans1, ans2);
}

void test_macro_square() {

	assert(macro_square(5) == 25);
	assert(macro_square(-5) == 25);
	assert(macro_square(0) == 0);

}

void test_math_function() {

	assert(math_function() == 0);
}