#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Day8.h"

Student_Register update_register()
{
	//function to enter the details of student
	char name[20]={0};
	int register_no, age, marks,name_size;

	Student_Register student;

	printf("\nEnter the name of student\n");
	scanf("%s", &name);
	name_size = strlen(name);
	strcpy(student.name, name);
	student.name[name_size] = '\0';


	printf("Enter Register number\n");
	scanf_s("%d", &register_no);
	student.register_number = register_no;

	printf("Enter age\n");
	scanf_s("%d", &age);
	student.age = age;

	printf("Enter Total marks out 600\n");
	scanf_s("%d", &marks);
	student.marks = marks;

	return student;
}

int print_student_register(Student_Register student)
{
	printf("\n\nStudent Details :-\nStudent Name : %s\nRegister Number : %d\nAge : %d\nMarks : %d", student.name,student.register_number,student.age,student.marks);
	return 0;
}

Student_Register search_by_name(Student_Register* student,int size)
{
	//function to Search student by name
	int flag=-1;
	char name[20];

	printf("\n\nSearch student by name...\nEnter the name of the student\n");
	scanf("%s", &name);
	
	for (int i = 0; i < size; i++)
	{
		//printf("\nstudent[i].name %s %s\n", _strlwr(student[i].name), _strlwr(name));

		if ( !(strcmp(_strlwr(student[i].name), _strlwr(name))) ){
			print_student_register(student[i]);
			flag = i;
		}
	}
	if (flag == -1) {
		printf("\nThere's no student with name %s in the register\n",name);
	}

	return student[flag];
}

Student_Register search_by_rollnum(Student_Register* student, int size)
{
	//function to Search student by roll no.
	int flag = -1, rno;

	printf("\n\nSearch student by register number...\nEnter the register number of the student\n");
	scanf("%d", &rno);

	for (int i = 0; i < size; i++)
	{
		if (student[i].register_number == rno) {
			print_student_register(student[i]);
			flag = i;
		}
	}
	if (flag == -1) {
		printf("\nThere's no student with register number %d in the register\n", rno);
	}

	return student[flag];

}

Student_Register details_by_starting_letter_of_name(Student_Register* student, int size)
{
	//function to Display the details of the students whose name begins with ‘A’.
	int flag = -1;
	char letter;
	char name[20];

	printf("\n\nDetails of student with starting letter of name...\nEnter the letter\n");
	scanf(" %c", &letter);

	for (int i = 0; i < size; i++)
	{
		strcpy(name, student[i].name);
		//printf("\nstudent[i].name %c %c\n", toupper(name[0]), toupper(letter));

		if (toupper(name[0]) == toupper(letter)) {
			print_student_register(student[i]);
			flag = i;
		}
	} 

	if (flag == -1) {
		printf("\nThere's no student with name with starting letter %c in the register\n", letter);
	}

	return student[flag];
}

Student_Register merit_list(Student_Register* student, int size)
{
	// Function to Return student details who have scored highest marks.
	int highest_marks=0,n=0;

	for (int i = 0; i < size; i++) {

		if (student[i].marks > highest_marks) {
			highest_marks = student[i].marks;
			n = i;
		}
	}
	return student[n];
}

Student_Register* deallocate_memory(Student_Register* student)
{ //function to deallocate the memory using free()

	free(student);
	student = NULL;
	
	return student;
}





double weight_calculator(XY_Plane xy)
{// Declaration of function to calculate weight of the points.
	double weight= xy.x * xy.y;

	return weight;
}

XY_Plane add_coordinate(int i)
{// Declaration of function to enter the coordinates of the point.
	float x, y;

	XY_Plane xy;
	
	printf("\nEnter X%d coordinate : \n",i+1);
	scanf("%f", &x);
	xy.x = x;

	printf("\nEnter Y%d coordinate : \n",i+1);
	scanf("%f", &y);
	xy.y = y;

	return xy;
}

XY_Plane maximum_weight(XY_Plane* xy, int no_of_points)
{// Declaration of function to find the point with maximum weight.
	double max_weight = 0;
	int n=0;

	for (int i = 0; i < no_of_points; i++) {

		if (xy[i].weight > max_weight) {
			max_weight = xy[i].weight;
			n = i;
		}
	}
	return xy[n];
}

int vertical_line_counter(XY_Plane* xy, int no_of_points)
{// Declaration of function to count the number of vertical lines.
	int count = 0;
	//float k, h;

	for (int i = 0; i < no_of_points; i++) {
		//k = ;
		for (int j = i+1; j < no_of_points; j++) {
			//h = xy[i].x;
			
			if (xy[i].x == xy[j].x)
				count++;
		}
	}

	return count;
}

int horizontal_line_counter(XY_Plane* xy, int no_of_points)
{// Declaration of function to count the number of horizontal lines.
	int count = 0;
	//float k, h;

	for (int i = 0; i < no_of_points; i++) {
		//k = ;
		for (int j = i + 1; j < no_of_points; j++) {
			//h = xy[i].x;

			if (xy[i].y == xy[j].y)
				count++;
		}
	}

	return count;
}

int print_point(XY_Plane xy)
{
	printf("\nPoint(%0.2f,%0.2f)\nX coordinate : %0.2f\nY coordinate : %0.2f\nWeight : %0.2f\n", xy.x,xy.y, xy.x,xy.y, xy.weight);
	return 0;
}

XY_Plane* deallocate_memory2(XY_Plane* xy)
{ // Declaration of function to deallocate the memory using free()
	free(xy);
	xy = NULL;

	return xy;
}

char* lower_case_to_upper_case(char low_string[]) {
	//Function to convert all lower - case characters into their upper - case equivalents.
	char c[50];
	int len = 0;
	//len = strlen(low_string);

	while (low_string[len] != '\0') {

		if (low_string[len] >= 'a' && low_string[len] <= 'z')
			c[len] = low_string[len] - 32;
		//printf("%c", c[len]);
		len++;
	}
	c[len] = '\0';
	//printf("%s\n", c);
	return c;
}