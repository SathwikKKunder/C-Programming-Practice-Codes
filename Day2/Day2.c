#include <math.h>
#include <stdio.h>
#include "Day2.h"

int sum_of_digits(int number) {      //Sum of digits function definition 
	int count=0,sum=0,remainder;

	if (number < 0)
		return -1;

	while (number != 0) {
		remainder = number % 10;
		sum += remainder;
		count++;
		number /= 10;
	}

	return sum;
}

int reverse_number(int number) {      //Reverse number function definition 
	int count = 0, num, remainder;

	num = number;
	while (num != 0)
	{
		num /= 10;
		count++;
	}

	if (count <= 1 || number < 0)
		return -1;

	while (number != 0)
	{
		remainder = number % 10;
		count--;
		num += remainder * pow(10, count);
		number /= 10;
	}

	return num;
}

int count_occurrences_of_digit(int digit, int number) { //Count the occurrences of digit function definition 


	int count = 0, remainder;

	while (number != 0) {

		remainder = number % 10;
		if (remainder == digit)
			count++;
		number /= 10;
	}
	
	if (count > 0)
		return count;
	else
		return -1;
}

int check_palindrome(int number) { //Check palindrome of a number function definition

	int rev_num;

	if (number < 0)
		return -1;

	rev_num = reverse_number(number);

	if (rev_num == number)
		return 1;
	else
		return 0;
}

int generate_n_prime_numbers(int n) { //Generate first 'N' prime numbers function definition


	int count = 0,flag,input=2;

	while (count < n) {
		flag = 0;
		for (int i = 2; i <= input / 2; i++) {
			
			if (input != i && input % i == 0) {
					
					flag = 1;
					break;
			}
		}
		
		if (flag == 0) {
			printf("%d\n", input);
			count++;
		}

		input++;
	}
	return count;
}

int sum_of_series(int n) {
	int sum=0,i=1;

	while(i<=n){ //function definition To display and find the sum of the series 1+11+111+....111 up to n.
		sum = sum * 10 + i;
		i++;
	}
	printf("Sum is %d\n", sum);
	return sum;
}

int armstrong_number(int number) { //function that asks the user to enter a numberand returns if it is Armstrong or not.

	int remainder, sum=0,og_num=number;

	if (number < 0)
		return -1;

	while (number != 0)
	{
		remainder = number % 10;
		sum += remainder * remainder * remainder;
		number /= 10;
	}

	if (og_num == sum)
		return 1;
	else
		return 0;
}

int amicable_numbers(int num1, int num2) {      //function to check that the input pair of numbers is amicable

/*/Amicable numbers are found in pairs.A given pair of numbers
is Amicable if the sum of the proper divisors(not including itself) of one number is equal to the other numberand vice – versa.*/

	int temp_num = 1,sum1=0,sum2=0;

	if (num1 < 0 || num2 < 0)
		return -1;

	while (temp_num <= num1 / 2) {

		if (num1 % temp_num == 0)
			sum1 += temp_num;
		
		temp_num++;
	}

	temp_num = 1;

	while (temp_num <= num2 / 2) {

		if (num2 % temp_num == 0)
			sum2 += temp_num;

		temp_num++;
	}

	if (sum1 == num2 && sum2 == num1)
		return 1;
	else
		return 0;
}

int calculator() {   // Function to read two integers& find their sum, difference& product

	int num1, num2, op;

	printf("Enter the two numbers :\n");
	scanf_s(" %d %d", &num1, &num2);
	printf("Enter the option :\n Sum : 1\n Difference : 2\n product : 3\n");
	scanf_s(" %d", &op);

	switch (op) {
	case 1:
		return num1 + num2;

	case 2:
		return num1 - num2;

	case 3:
		return num1 * num2;

	default:
		return -1;
	}
}

double cube_volume_generator() { //Cube volume function 

	double side,volume;

	printf("Enter the side length (in metre): \n");
	scanf_s(" %lf", &side);

	volume = side * side * side;
	printf("The volume of the cube is : %lf  metre cube\n", volume);
	return 0;
}

double cubiod_volume_generator() {   // Cubiod volume function 

	double length, height, breadth, volume;

	printf("Enter the length of the cubiod (in metre):\n");
	scanf_s(" %lf", &length);

	printf("Enter the height of the cubiod (in metre):\n");
	scanf_s(" %lf", &height);

	printf("Enter the breadth of the cubiod (in metre):\n");
	scanf_s(" %lf", &breadth);

	volume = length * height * breadth;
	printf("The volume of the cubiod is : %lf metre cube\n", volume);
	return 0;
}

double sphere_volume_generator() { // sphere volume function 

	double radius, volume;

	printf("Enter the radius of the sphere: (in metre)\n");
	scanf_s(" %lf", &radius);

	volume = 1.33333333333 * 3.14 * radius * radius * radius;
	printf("The volume of the sphere is : %lf metre cube\n", volume);
	return 0;
}

double cylinder_volume_generator() { // cylinder volume function

	double radius, height, volume;

	printf("Enter the radius of the cylinder: (in metre)\n");
	scanf_s(" %lf", &radius);

	printf("Enter the height of the cylinder (in metre):\n");
	scanf_s(" %lf", &height);

	volume = 3.14 * radius * radius * height;
	printf("The volume of the cylinder is : %lf metre cube\n", volume);
	return 0;
}

double cone_volume_generator() { // cone volume function

	double radius, height, volume;

	printf("Enter the radius of the cone: (in metre)\n");
	scanf_s(" %lf", &radius);

	printf("Enter the height of the cone (in metre):\n");
	scanf_s(" %lf", &height);

	volume = 3.14 * radius * radius * height/3;
	printf("The volume of the cone is : %lf metre cube\n", volume);
	return 0;
}

int electricity_bill_calculator(int units) { //Function to read no of unit conssumed and print out total charge amount

	int total = 0;

	if (units < 0)
		return -1;

	else if (units <= 200) {
		total = 1 * units;
		return total;
	}

	else if (units <= 300) {
		total = 1 * 200 + 1.5 *(units-200);
		return total;
	}

	else {
		total = 1 * 200 + 1.5 * 100+ 2 * (units -300);
		return total;
	}

}
