struct _studentRegister_
{
	char name[20];
	int register_number;
	int age;
	int marks;
};

typedef struct _studentRegister_ Student_Register;

Student_Register update_register();   // Declaration of function to enter the details of student

Student_Register search_by_name(Student_Register *student,int size); // Declaration of function to Search student by roll no.

Student_Register search_by_rollnum(Student_Register* student, int size);  // Declaration of function to Search student by name

Student_Register details_by_starting_letter_of_name(Student_Register* student, int size);  // Declaration of function to Display the details of the students whose name begins with ‘A’.

Student_Register merit_list(Student_Register* student, int size); // Declaration of function to Return student details who have scored highest marks.

Student_Register* deallocate_memory(Student_Register* student); // Declaration of function to deallocate the memory using free()

int print_student_register(Student_Register student); 



struct _xyplane_
{
	float x;
	float y;
	double weight;
};

typedef struct _xyplane_ XY_Plane;

XY_Plane add_coordinate(int i); // Declaration of function to enter the coordinates of the point.

double weight_calculator(XY_Plane xy); // Declaration of function to calculate weight of the points.

XY_Plane maximum_weight(XY_Plane* xy,int no_of_points); // Declaration of function to find the point with maximum weight.

int vertical_line_counter(XY_Plane* xy, int no_of_points); // Declaration of function to count the number of vertical lines.

int horizontal_line_counter(XY_Plane* xy, int no_of_points);  // Declaration of function to count the number of horizontal lines.

XY_Plane* deallocate_memory2(XY_Plane* xy); // Declaration of function to deallocate the memory using free()

int print_point(XY_Plane xy);

char* lower_case_to_upper_case(char low_string[]);
