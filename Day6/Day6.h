#define _CRT_SECURE_NO_WARNINGS

struct _studentRegister_
{
	char name[20];
	int register_number;
	int age;
	float percentage;
};

typedef struct _studentRegister_ Student_Register;

struct _complexnumber_ {
	float real_number;
	float imaginary_number;
};

typedef struct _complexnumber_ ComplexNumber;

struct _grand_total_ {
	float item_price;
	int item_quantity;
};

typedef struct _grand_total_ GrandTotal;

ComplexNumber complex_addition(ComplexNumber number1, ComplexNumber number2);
ComplexNumber complex_subtraction(ComplexNumber number1, ComplexNumber number2);
ComplexNumber complex_multiplication(ComplexNumber number1, ComplexNumber number2);
int print_complex_number(ComplexNumber number1);


Student_Register student1_quickadd();
Student_Register student2_quickadd();
Student_Register student3_quickadd();
Student_Register student4_quickadd();
Student_Register student5_quickadd();
Student_Register student6_quickadd();
Student_Register student7_quickadd();
Student_Register student8_quickadd();
Student_Register student9_quickadd();
Student_Register student10_quickadd();

int print_student_register(Student_Register student);

int billing();

float discount_calculator(float total);

int print_bil(GrandTotal *items, float subtotal[], float grand_total, float total,int no_items);