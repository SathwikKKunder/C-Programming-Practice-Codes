
struct _find_min_max_ {
	int min;
	int max;
};

typedef struct _find_min_max_ Array_Min_Max;

struct _elements_array_ {
	int sum_of_even_elements;
	int sum_of_odd_elements;
};

typedef struct _elements_array_ Elements_Array;

int* construt_array(int array[], int size); //Declaration of function to create an  array

int print_array(int* arr, int size);

int linear_search(int arr[], int size);  // Declaration of function to search for a given integer in an array using the linear search technique

Array_Min_Max find_max_min(int array[], int size); // Declaration of function to find Max and Min element in an array

int sum_array(int array[], int size); // Declaration of function to find sum of all the elements of array

Elements_Array sum_of_array_elements(int array[], int size); // Declaration of function to find the sum of evenand odd elements of array

int array_palindrome(int array[], int size); // Declaration of function to Check whether the array in palindrome

int* deallocate_memory(int* array);// Declaration of function to deallocate the memory using free()