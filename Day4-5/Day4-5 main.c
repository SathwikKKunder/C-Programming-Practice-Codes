#include <assert.h>
#include <stdio.h>
#include "Day4.h"

void test_sort_array();
void test_swap_numbers();
void test_find_max_min();
void test_remove_duplicate_entries_array();
void test_linear_search();
void test_binary_search();
void test_lower_case_to_upper_case();
void test_check_whether_two_matrixes_are_same();
void test_set_operations();

int main() {
	
	//test_sort_array();                  // Testing Array sorting function
	//test_swap_numbers();               // Testing Numbers swaping function
	//test_find_max_min();                 // Testing function to find minimum and maximum elements in a given array
	//test_remove_duplicate_entries_array();  // Testing function to remove the duplicate entries in the array
	//test_linear_search();      // Testing function to search for a given integer in an array using the linear search technique
	//test_binary_search();       // Testing function to search for a given integer in an array using the binary search technique
	//sum_of_product();            // Function to read list of 'n' integer and print sum of product of consecutive numbers
	//length_of_string();           //Function to read a string from the userand return the length of string.
	//worded_format_date();  /* Function to Input date, monthand year from the user, and using switch case,
		                    //display in worded format.e.g.input: d = 16, m = 7, y = 1992,Output: 16th July, 1992 */
	
	//test_lower_case_to_upper_case();//Testing Function to convert all lower - case characters into their upper - case equivalents.
	//reverse_string();       //Function to read a string from the userand reverse the string
	//matrix_5_cross_5();  //Function to construct 5 * 5 matrix and display the contents. Use functions for construction and display of matrix
	//add_two_matrix();    //Function to add 2 matrixes
	//test_check_whether_two_matrixes_are_same();  //Testing function to check whether 2 matrixes are same.
	//sparse_matrix();      //Function to check if given matrix is a sparse matrix
	//test_set_operations();  //Function to input and prints results of following set operations A union B, A intersection B, A-B and B-A
	
	return 0;
}

void test_sort_array() {
	int op, size;
	int arr[] = { 9,4,2,5,8 };
	size = (*(&arr + 1) - arr);

	while (1)
	{
		printf("Enter '1' to sort in ascending, and '2' to sort in descending\n");
		scanf_s("%d", &op);
		if (op == 1 || op == 2)
			break;
		printf(" Error!! Invalid  option %d\n", op);
	}
	
	//int* sort_array(int* arr, int size, int op, int print)
	// To print the sorted array 'print==1'
	sort_array(arr,size,op,1);
}

void test_swap_numbers() {
	int a = 3, b = 4;

	swap_numbers(&a, &b);
}

void test_find_max_min() {
	int size,min,max;
	int arr[] = { 9,4,2,5,-8 };
	size = (*(&arr + 1) - arr);

	find_max_min(arr, size, &min, &max);
}

void test_remove_duplicate_entries_array() {

	int size;
	int arr[] = { 1,2,3,4,5,1,6,7,2,8 };
	size = (*(&arr + 1) - arr);

	//int remove_duplicate_entries_array(int arr[], int size, int print)
	// To print the sorted array 'print==1'

	assert(remove_duplicate_entries_array(arr, size,1)==8);

	int arr1[] = { 1,1,3,5,8,6,7,3,8 };
	size = (*(&arr1 + 1) - arr1);

	assert(remove_duplicate_entries_array(arr1, size,1) == 6);

	int arr2[] = { 1,1,1,5,8,2,3,4,7,3,8,4 };
	size = (*(&arr2 + 1) - arr2);

	assert(remove_duplicate_entries_array(arr2, size,1) == 7);

	int arr3[] = { 1,1,1,5,8,2,3,4,7,3,3,3,8,4 };
	size = (*(&arr3 + 1) - arr3);

	assert(remove_duplicate_entries_array(arr3, size,1) == 7);


	int arr4[] = { 1,1,1,1,1};
	size = (*(&arr4 + 1) - arr4);

	assert(remove_duplicate_entries_array(arr4, size, 1) == 1);

	int arr5[] = { 1,1,1,1,1,2,2,2,3,3 };
	size = (*(&arr5 + 1) - arr5);

	assert(remove_duplicate_entries_array(arr5, size, 1) == 3);

}

void test_linear_search() {

	int size;
	int arr[] = { 1,2,3,4,5,1,6,7,2,8 };
	size = (*(&arr + 1) - arr);

	assert(linear_search(arr, size, 3) == 1);
	assert(linear_search(arr, size, 1) == 1);
	assert(linear_search(arr, size, 9) == 0);
	assert(linear_search(arr, size, 10) == 0);
	assert(linear_search(arr, 0, 3) == -1);
	assert(linear_search(arr, -1, 3) == -1);
}

void test_binary_search() {

	int size;
	int arr[] = { -1,1,2,3,2,77,6,9,8,0,74,139,-88};
	size = (*(&arr + 1) - arr);

	assert(binary_search(arr, size, -1) == 1);
	assert(binary_search(arr, size, 1) == 1);
	assert(binary_search(arr, size, 2) == 1);
	assert(binary_search(arr, size, 3) == 1);
	assert(binary_search(arr, size, 77) == 1);
	assert(binary_search(arr, size, 6) == 1);
	assert(binary_search(arr, size, 9) == 1);
	assert(binary_search(arr, size, 8) == 1);
	assert(binary_search(arr, size, 0) == 1);
	assert(binary_search(arr, size, 74) == 1);
	assert(binary_search(arr, size, 139) == 1);
	assert(binary_search(arr, size, -88) == 1); 
	
	assert(binary_search(arr, size, 88) == 0);
	assert(binary_search(arr, -1, 88) == -1);
}

void test_lower_case_to_upper_case() {

	assert(lower_case_to_upper_case("dcam")==0);
	assert(lower_case_to_upper_case("sath") == 0);
}

void test_check_whether_two_matrixes_are_same() {

	//int x[2][3] = { 0, 1 ,2 ,3 ,4 , 5 };
	//int y[2][3] = { 1,1,1,1,1,1 };

	//check_whether_two_matrixes_are_same(&x, 2, 3, &y, 2, 3);

	assert(check_whether_two_matrixes_are_same() == 0);
}

void test_set_operations() {
	int size1, size2;

	int arr1[] = { 9,4,2,5,8 };
	int arr2[] = { 1,25,6,5};
	size1 = (*(&arr1 + 1) - arr1);
	size2 = (*(&arr2 + 1) - arr2);

	printf(" set 1:\n");
	print_array(arr1, size1);

	printf(" set 2:\n");
	print_array(arr2, size2);

	set_union(arr1, size1, arr2, size2);
	set_intersection(arr1, size1, arr2, size2);
	set_difference(arr1, size1, arr2, size2);
}