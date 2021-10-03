//int array_size(int arr[]);
int print_array(int* arr, int size);

int* sort_array(int *arr, int size, int op, int print); // Array sorting function declaration

int swap_numbers(int* a, int* b);  // Numbers swaping function declaration

int find_max_min(int array[], int size, int* max, int* min); // Declaration of function to find Max and Min element in an array

int remove_duplicate_entries_array(int arr[], int size, int print); // Declaration of function to remove the duplicate entries in the array

int linear_search(int arr[], int size, int element);  // Declaration of function to search for a given integer in an array using the linear search technique

// Declaration of function to search for a given integer in an array using the binary search technique
int binary_search(int arr[], int size, int element);                                   
int binary_search_agorithm(int* sort_arr, int element, int start_position, int end_position);

int sum_of_product(); // Declaration of function to read list of 'n' integer and print sum of product of consecutive number

int length_of_string(); //Declaration of function to read a string from the user and return the length of string.

int worded_format_date(); /* Declaration of function to Input date, monthand year from the user, and using switch case,
                          display in worded format.e.g.input: d = 16, m = 7, y = 1992,Output: 16th July, 1992 */

int lower_case_to_upper_case(char low_string[]); //Declaration of function to convert all lower-case characters into their upper-case equivalents.

int reverse_string();  //Declaration of function to read a string from the userand reverse the string

int matrix_5_cross_5(); //Declaration of function to construct 5 * 5 matrix and display the contents

int** construct_2Dmatrix(int row_size, int column_size); //Declaration of function to construct 2Dmatrix and display the contents

int print_2Dmatrix(int** arr, int row_size, int column_size); //Declaration of function to display the contents of the 2Dmatrix

int add_two_matrix();   //Declaration of function to add 2 matrixes

int check_whether_two_matrixes_are_same(); //Declaration of function to check whether 2 matrixes are same.

int sparse_matrix(); //Declaration of Function to check if given matrix is a sparse matrix

int set_union(int arr1[],int size1, int arr2[], int size2); //Declaration of Function to input and prints results of A union B

int set_intersection(int arr1[], int size1, int arr2[], int size2); //Declaration of Function to input and prints results of A intersection B

int set_difference(int arr1[], int size1, int arr2[], int size2); //Declaration of Function to input and prints results of A-B and B-A
