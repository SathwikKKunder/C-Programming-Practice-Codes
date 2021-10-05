#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Day8.h"

void student_register();
void xy_plane();

int main() {

	student_register();

	xy_plane();

	return 0;
}


void student_register() {
	int size;

	printf("Enter no. of students\n");
	scanf("%d", &size);

	Student_Register *student;

	student = (Student_Register*)malloc(size * sizeof(Student_Register));

	for (int i = 0; i < size; i++)
	{
		student[i] = update_register();
	}

	search_by_name(student, size);

	search_by_rollnum(student, size);

     details_by_starting_letter_of_name(student, size);

	 printf("\n\nStudent who have scored highest marks\n");
	 print_student_register(merit_list(student, size));

	 deallocate_memory(student);

}

void xy_plane() {

	int no_of_points, vertical_line_count, horizontal_line_count;

	printf("Enter no. of points\n");
	scanf("%d", &no_of_points);

	XY_Plane* xy;
	XY_Plane point;

	xy = (XY_Plane*)malloc(no_of_points * sizeof(XY_Plane));

	for (int i = 0; i < no_of_points; i++)
	{
		xy[i] = add_coordinate(i);
		xy[i].weight = weight_calculator(xy[i]);
	}

	printf("\nThe point with maximum weight :\n");
	point = maximum_weight(xy, no_of_points);
	print_point(point);

	vertical_line_count = vertical_line_counter(xy, no_of_points);
	printf("\nThe number vertical lines is : %d\n", vertical_line_count);

	horizontal_line_count = horizontal_line_counter(xy, no_of_points);
	printf("\nThe number horizontal lines is : %d\n", horizontal_line_count);

	deallocate_memory2(xy);
}