#include <assert.h>
#include <stdio.h>
#include "Day2.h"

void test_sum_of_digits();
void test_reverse_number();
void test_count_occurrences_of_digit();
void test_check_palindrome();
void test_generate_n_prime_numbers();
void test_sum_of_series();
void test_armstrong_number();
void test_amicable_numbers();
void test_calculator();
void volume_generator();
void test_electricity_bill_calculator();


int main() {

	//test_sum_of_digits();                       //Testing Sum of digits function call
	//test_reverse_number();                     //Testing Reverse number function call 
	//test_count_occurrences_of_digit();        //Testing Count the occurrences of digit function call
	//test_check_palindrome();                   //Testing Check palindrome of a number function call
	//test_generate_n_prime_numbers();             //Testing Generate first 'N' prime numbers function call
	//test_sum_of_series();              //Testing function call To display and find the sum of the series 1+11+111+....111 up to n.
	//test_armstrong_number();          // Testing Armstrong number function call
	//test_amicable_numbers();           // Testing Amicable numbers function call
	//test_calculator();                 // Testing Caculator function call
	//volume_generator();                 // volume generator function call
	//test_electricity_bill_calculator();    // Testing Electricity bill calculator function call


	return 0;
}

void test_sum_of_digits() {   //Testing Sum of digits function 

	assert(sum_of_digits(12345) == 15);
	assert(sum_of_digits(-15) == -1);
}

void test_reverse_number() {   //Testing Reverse number function

	assert(reverse_number(12345) == 54321);
	assert(reverse_number(987654321) == 123456789);
	assert(reverse_number(1) == -1);
	assert(reverse_number(0) == -1);
	assert(reverse_number(-12345) == -1);
}

void test_count_occurrences_of_digit() { //Testing Count the occurrences of digit function 
	 
	//count_occurrences_of_digit(int digit, int number)

	assert(count_occurrences_of_digit(3, 12334) == 2);
	assert(count_occurrences_of_digit(1, 12334) == 1);
	assert(count_occurrences_of_digit(5, 12334) == - 1);
}

void test_check_palindrome() {   //Testing Check palindrome of a number

	assert(check_palindrome(12321) == 1);
	assert(check_palindrome(56788765) == 1);
	assert(check_palindrome(-12321) == -1);
	assert(check_palindrome(12345) == 0);
}

void test_generate_n_prime_numbers() {//Testing Generate first 'N' prime numbers function

	//returns number of prime numbers generated

	assert(generate_n_prime_numbers(5) == 5);
	assert(generate_n_prime_numbers(11) == 11);

}

void test_sum_of_series() { //Testing function To display and find the sum of the series 1+11+111+....111 up to n.

	int n,sum=0;
	scanf_s("%d", &n);
	sum = sum_of_series(n);	
}

void test_armstrong_number() {  // Testing Armstrong number function
	int n,ans;
	scanf_s("%d", &n);
	ans = armstrong_number(n);

	if (ans == 1)
		printf("%d is an Armstrong number", n);
	else
		printf("%d is not an Armstrong number", n);

	assert(armstrong_number(153) == 1);
	assert(armstrong_number(100) == 0);
	assert(armstrong_number(147) == 0);
	assert(armstrong_number(-153) == -1);
}

void test_amicable_numbers() {  // Testing Amicable numbers function

	assert(amicable_numbers(220, 284) == 1);
	assert(amicable_numbers(1184, 1210) == 1);
	assert(amicable_numbers(96, 74) == 0);
	assert(amicable_numbers(-1184, 1210) == -1);

}

void test_calculator() {     // Testing Caculator function

	assert(calculator() == 12); //num1=5 num2=7 option:1
	assert(calculator() == -2); //num1=5 num2=7 option:2
	assert(calculator() == 35); //num1=5 num2=7 option:3
	assert(calculator() == -1); //num1=5 num2=7 option:77
}

void volume_generator() { // Function to calculate the volume of the following shapes : Cube, Cuboid, Sphere, Cylinderand Cone
	int option;

	printf("Select the Shape for which the volume to be found:\n Cube : 1\n Cuboid : 2\n Sphere : 3\n Cylinder : 4\n Cone : 5\n");
	scanf_s(" %d", &option);

	switch (option) {
	case 1:
		cube_volume_generator();
		break;

	case 2:
		cubiod_volume_generator();
		break;

	case 3:
		sphere_volume_generator();
		break;

	case 4:
		cylinder_volume_generator();
		break;

	case 5:
		cone_volume_generator();
		break;

	default:
		return -1;
	}

}

void test_electricity_bill_calculator() { // Testing Electricity bill calculator function

	assert(electricity_bill_calculator(100) == 100);
	assert(electricity_bill_calculator(200) == 200);
	assert(electricity_bill_calculator(300) == 350);
	assert(electricity_bill_calculator(500) == 750);
	assert(electricity_bill_calculator(-100) == -1);
}

