#include <stdio.h>
#include "Day6.h"

void test_studentRegister();
void test_complex_arthimatic();


int main() {

	//test_studentRegister();    // Function to store nd print the roll no., name, ageand marks of 10 students using structures.
	//test_complex_arthimatic(); //Function to add, subtract and multiply two complex numbers using structures
	billing();

	return 0;
}

void test_studentRegister() {
	// Function to store nd print the roll no., name, ageand marks of 10 students using structures.

	Student_Register student1 = student1_quickadd();
	print_student_register(student1);

	Student_Register student2 = student2_quickadd();
	print_student_register(student2);

	Student_Register student3 = student3_quickadd();
	print_student_register(student3);

	Student_Register student4 = student4_quickadd();
	print_student_register(student4);

	Student_Register student5 = student5_quickadd();
	print_student_register(student5);

	Student_Register student6 = student6_quickadd();
	print_student_register(student6);

	Student_Register student7 = student7_quickadd();
	print_student_register(student7);

	Student_Register student8 = student8_quickadd();
	print_student_register(student8);

	Student_Register student9 = student9_quickadd();
	print_student_register(student9);

	Student_Register student10 = student10_quickadd();
	print_student_register(student10);

}

void test_complex_arthimatic() {

	ComplexNumber num1, num2,add,sub,mul;
	num1.real_number = 5;
	num1.imaginary_number = 10;

	num2.real_number = 2;
	num2.imaginary_number = 3;

	printf("Complex number 1 \n");
	print_complex_number(num1);

	printf("Complex number 2 \n");
	print_complex_number(num2);

	add = complex_addition(num1,num2);
	printf("\nComplex number addition : \n");
	print_complex_number(add);

	sub = complex_subtraction(num1, num2);
	printf("\nComplex number subtraction : \n");
	print_complex_number(sub);

	mul = complex_multiplication(num1, num2);
	printf("\nComplex number multiplication : \n");
	print_complex_number(mul);


}