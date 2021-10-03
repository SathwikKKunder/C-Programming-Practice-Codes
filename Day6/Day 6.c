#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "Day6.h"


Student_Register student1_quickadd() {

	Student_Register student = { "Virat",1,20,97.7 };
	return student;
}

Student_Register student2_quickadd() {

	Student_Register student = { "Rohit",2,20,96.5 };
	return student;
}

Student_Register student3_quickadd() {

	Student_Register student = { "Rahul",3,18,95 };
	return student;
}

Student_Register student4_quickadd() {

	Student_Register student = { "Mayank",4,18,91.8 };
	return student;
}

Student_Register student5_quickadd() {

	Student_Register student = { "Smriti",5,17,93.6};
	return student;
}

Student_Register student6_quickadd() {

	Student_Register student = { "Shreyas",6,17,92.4};
	return student;
}

Student_Register student7_quickadd() {

	Student_Register student = { "Milthli",7,22,94.3};
	return student;
}

Student_Register student8_quickadd() {

	Student_Register student = { "Risbah",8,17,94.9};
	return student;
}

Student_Register student9_quickadd() {

	Student_Register student = { "Jasprit",9,18,96.96 };
	return student;
}

Student_Register student10_quickadd() {

	Student_Register student = { "Jullan",10,21,94.7};
	return student;
}

int print_student_register(Student_Register student)
{
	Student_Register std;
	
	strcpy(std.name, student.name);
	std.register_number = student.register_number;
	std.age = 10;
	std.percentage = student.percentage;
	printf("Student Name : %s\nRollNo. : %d\nAge : %d\nPercentge : %0.2f %\n\n",std.name,std.register_number,std.age,std.percentage);
	
	return 0;
}

ComplexNumber complex_addition(ComplexNumber number1, ComplexNumber number2)
{
	ComplexNumber answer;

	answer.real_number = number1.real_number + number2.real_number;
	answer.imaginary_number = number1.imaginary_number + number2.imaginary_number;

	return answer;
}

ComplexNumber complex_subtraction(ComplexNumber number1, ComplexNumber number2)
{
	ComplexNumber answer;

	answer.real_number = number1.real_number - number2.real_number;
	answer.imaginary_number = number1.imaginary_number - number2.imaginary_number;
	
	return answer;
}

ComplexNumber complex_multiplication(ComplexNumber number1, ComplexNumber number2)
{
	ComplexNumber answer;

	answer.real_number = number1.real_number * number2.real_number;
	answer.imaginary_number = number1.imaginary_number * number2.imaginary_number;

	return answer;
}

int print_complex_number(ComplexNumber number1)
{
	printf("%0.1f + %0.1fj\n", number1.real_number, number1.imaginary_number);
	return 0;
}

int billing()
{
	int ex=1,no_items,quantity;
	float price,total=0,grand_total;
	float *subtotal;
	GrandTotal *bill;
	printf("Enter no. of items\n");
	scanf("%d",&no_items);

	bill = (GrandTotal*)malloc(no_items * sizeof(GrandTotal));
	subtotal = (float*)malloc(no_items * sizeof(float));

	for (int i = 0; i < no_items; i++) {
		printf("\nEnter Item%d Price :",i+1);
		scanf_s("%f", &price);
		bill[i].item_price = price;

		printf("Enter Item%d Quantity :",i+1);
		scanf_s("%d", &quantity);
		bill[i].item_quantity = quantity;
	}

	for (int i = 0; i < no_items; i++) {
		//printf("total%d %0.2f, bill[i].item_price%f,bill[i].item_quantity%d\n",i, total, bill[i].item_price, bill[i].item_quantity);
		subtotal[i] = bill[i].item_price * bill[i].item_quantity;
	}

	for (int i = 0; i < no_items; i++) {
		//printf("total%d %0.2f, bill[i].item_price%f,bill[i].item_quantity%d\n",i, total, bill[i].item_price, bill[i].item_quantity);
		total += subtotal[i];
	}
	grand_total = discount_calculator(total);

	//printf("grand total %0.2f\n", total);

	print_bil(bill,subtotal,grand_total,total,no_items);
	return 0;
}

float discount_calculator(float total)
{
	//int grand_total;

	if (total < 1000) {
		total -= total * 0.05;
		return total;
	}
	else if(total<5000) {
		total -= total * 0.1;
		return total;
	}
	else{
		total -= total * 0.15;
		return total;
	}
	
}

int print_bil(GrandTotal *items, float subtotal[], float grand_total, float total, int no_items)
{
	float discount;

	printf("\nItems\t\tPrice\t\tQuantity\t\tSubtotal\n");

	for (int i = 0; i < no_items; i++) {

		printf("Items %d\t\t%0.2f\t\t   %d\t\t\t %0.2f\n",i+1, items[i].item_price, items[i].item_quantity,subtotal[i]);
	}

	printf("\n---------------------------------------------------------------------\n");
	printf("\nTOTAL %0.2f\n", total);

	if (total < 1000) {
		discount = total * 0.05;
		printf("Discount 5'%' - %0.2f\n", discount);
	}
	else if (total < 5000) {
		discount = total * 0.10;
		printf("Discount 10'%' - %0.2f\n", discount);
	}
	else {
		discount = total * 0.15;
		printf("Discount 15'%' - %0.2f\n", discount);
	}

	printf("\n---------------------------------------------------------------------\n");
	printf("GRAND TOTAL %0.2f\n", grand_total);
	return 0;
}