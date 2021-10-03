#include <stdio.h>
#include <string.h>
#include "Day4.h"


 /* int array_size(int arr[]) {
	int i = 0;
	//int arr[] = a;
	//i = (*(&arr + 1) - arr);

 	while (1)
	{
		if (arr[i] == NULL) {
			printf("j %d  k %d\n", i, arr[i]);
			break;
		}
		printf("i %d  k %d\n", i, arr[i]);
		i += 1;
	}
	return i; 
}  */

    int* sort_array(int* arr, int size, int op, int print){             //Function to sort an array 
		int temp;
		//print_array(arr, size);

		if (op == 1) {                             //sorting array in ascending order
			for (int i = 0; i < size; i++) {
				//printf("i %d\n", i);
				for (int j = i + 1; j < size; j++) {

					if (arr[i] > arr[j]) {
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
				
			}
		}

		else {                                   //sorting array in descending order
			for (int i = 0; i < size; i++) {
				
				for (int j = i + 1; j < size; j++) {

					if (arr[i] < arr[j]) {
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}

			}
		}
		
		if (print == 1) {
			printf("\nRevised array after sorting are :\n");
			print_array(arr, size);
		}

	return arr;                       //returning the array is necessary for binary search function 
}

	int print_array(int* arr, int size) {
		int i = 0;
		if (size <= 0)
		{
			printf(" Error!! Invalid  Size %d ", size);
		}
		while (i<size)
		{
			printf("  %d\n", arr[i]);
			i++;
		}

		return 0;
	}

	int swap_numbers(int* a, int* b) {        //Swaping two numbers using call by reference
		int temp;
		printf(" The numbers before swaping a = %d, b = %d\n", *a, *b);
		temp = *a;
		*a = *b;
		*b = temp;
		printf(" The numbers after swaping a = %d, b = %d\n", *a, *b);
		return 0;
	}

	int find_max_min(int array[], int size, int* max, int* min) {
		
		*max = *min = array[0];

			for (int j = 1; j < size; j++) {

				if (*max < array[j])        //To find maximum elements in a given array
					*max = array[j];

				if (*min > array[j])       //To find minimum elements in a given array
					*min = array[j];
				
			}

		printf(" The minimum and maximum elements in a given array,\n max = %d, min = %d\n", *max, *min);
		return 0;
	}

	int remove_duplicate_entries_array(int arr[], int size, int print) {

		int new_size = size;

		if (size <= 0)
		{
			printf(" Error!! Invalid  Size %d ", size);
		}
		else {
			for (int i = 0; i < new_size; i++) {

				for (int j = i + 1; j < new_size; j++) { //for traversing each entries in the array

					if (arr[i] == arr[j]) { // Checking for duplicate entries in the array

						//printf("\ni%d j%d arr[i]%d arr[j]%d new_size%d\n", i, j,  arr[i], arr[j], new_size);

						for (int k = j; k < new_size; k++) { //
							arr[k] = arr[k + 1];
							//printf(" k%d  arr[k]%d arr[k + 1]%d\n", k, arr[k], arr[k + 1]);
						}

						j = i;     //when there's two or consecutive repeated elements eg : {1,1,1......}, j=i assures that the repeated elements at 2+ position are also eliminated
						new_size--;       //Revising the size of array after removing an element
					}

				}

			}
		}
		//printf("\nnew_size%d\n", new_size);
		
		if (print == 1) {
			printf("\nRevised entires of the array without duplicate entries are :\n");
			print_array(arr, new_size);
		}

		return new_size;   //returning the size of the new array is necessary for binary search function
	}

	int linear_search(int arr[], int size, int element) {

		if (size <= 0)
		{
			printf(" Error!! Invalid  Size %d\n", size);
			return -1;
		}

		for (int j = 1; j < size; j++) {
			
			if (element == arr[j])        //To find element in a given array
				return 1;
		}

		return 0;
	}

	int binary_search_agorithm(int *sort_arr, int element, int start_position, int end_position) { //Function to search for a given integer in an array using the binary search technique
		
		int mid_value = start_position + (end_position - start_position) / 2;

		if (end_position < 0 || start_position > end_position) {
			//printf("\nQ mid_value%d end_position%d start_position%d \n", mid_value, end_position, start_position);
			return 0;
		}
		
		else if (element == sort_arr[mid_value]) {
			//printf("\nA mid_value%d end_position%d start_position%d \n", mid_value, end_position, start_position);
			return 1;
		}

		else if (element > sort_arr[mid_value]) {
			start_position = mid_value + 1; // eliminating the values that are in position before the mid value position i.e "element < sort_arr[mid_value]"
			//printf("\nG mid_value%d end_position%d start_position%d \n", mid_value, end_position, start_position);
			binary_search_agorithm(sort_arr, element, start_position, end_position);
		}

		else {
			end_position = mid_value - 1;  // eliminating the values that are in position after the mid value position i.e "element < sort_arr[mid_value]"
			//printf("\nL mid_value%d end_position%d start_position%d \n", mid_value, end_position, start_position);
			binary_search_agorithm(sort_arr, element, start_position, end_position);
		}

		return 0;

	}

	int binary_search(int arr[], int size, int element) {

		if (size <= 0)
		{
			printf(" Error!! Invalid  Size %d\n", size);
			return -1;
		}

		int* sort_arr = sort_array(arr, size,1,0);     // '1' to sort in ascending order
		int new_size = remove_duplicate_entries_array(sort_arr, size,0);
		int start_position=0,end_position = new_size - 1;
		
		return binary_search_agorithm(sort_arr, element, start_position, end_position);

	}

	int sum_of_product() {
		/* function to read list of 'n' integer and print sum of product of consecutive numbers.
		   Ex: if n=7 and numbers are 4,5,2,5,6,4,7 then output is 4*5+5*2+2*5+5*6+6*4+4*7 = 122 */

		int size=0, sum=0,n,no;
		int* arr;
		printf("Enter the Number of integers to be entered\n");
		scanf_s("%d", &n);

		arr = (int*)malloc(n * sizeof(int));
		
		printf("Enter %d integers\n",n);
		while (size<n)
		{
			scanf_s("%d", &no);
			arr[size] = no;
			size++;
		}

		n -= 1;

		while (n > 0) {
			printf("(%d * %d)", arr[n - 1], arr[n]);
			sum += arr[n-1] * arr[n];
			n--;
			if (n> 0)
				printf(" + ");
		}

		printf(" = %d",sum);
		free(arr);
		return 0;
	}

	int length_of_string() {
		//function to read a string from the userand return the length of string.
		int len = 0;
		char c[50];

		printf("Enter the string\n");
		gets(c);

		while (c[len] != '\0')
		{
			//printf("L %c\n", c[len]);
			len++;
		}
		printf("Length of the string is %d\n", len);
		return 0;
	}

	int worded_format_date() {
		/* Function to Input date, monthand year from the user, and using switch case,
		display in worded format.e.g.input: d = 16, m = 7, y = 1992,Output: 16th July, 1992 */
		int year, date, month;
		char mon[12][15] = {"January","Febuary","March","April","May","June","July","August","September","Octomber","November","December"};

		printf("Enter the year\n");
		scanf_s("%d", &year);

		printf("Enter the date\n");
		scanf_s("%d", &date);

		printf("Enter the month\n");
		scanf_s("%d", &month);

		if (year <= 0) {
			printf(" Error!! Invalid  year no. %d ", year);
			return 0;
		}

		if (date <= 0 || date > 31) {
			printf(" Error!! Invalid  date  %d ", date);
			return 0;
		}

		switch (month)
		{
		case 1:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n",date,mon[0],year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[0], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[0], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[0], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[0], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[0], year);
				break;

			default:
				printf("%dth %s, %d\n", date, mon[0], year);
				break;
			}

			break;


		case 2:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[1], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[1], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[1], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[1], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[1], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[1], year);
				break;

			default:
				if (date > 29) {
					printf(" Error!! Invalid date, %d doesnt exist in %s", date,mon[1]);
					return 0;
				}
				printf("%dth %s, %d\n", date, mon[1], year);
				break;
			}

			break;

		case 3:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[2], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[2], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[2], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[2], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[2], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[2], year);
				break;

			default:
				printf("%dth %s, %d\n", date, mon[2], year);
				break;
			}

			break;

		case 4:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[3], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[3], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[3], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[3], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[3], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[3], year);
				break;

			default:
				if (date > 30) {
					printf(" Error!! Invalid date, %d doesnt exist in %s", date, mon[3]);
					return 0;
				}
				printf("%dth %s, %d\n", date, mon[3], year);
				break;
			}

			break;

		case 5:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[4], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[4], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[4], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[4], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[4], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[4], year);
				break;

			default:
				printf("%dth %s, %d\n", date, mon[4], year);
				break;
			}

			break;

		case 6:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[5], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[5], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[5], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[5], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[5], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[5], year);
				break;

			default:
				if (date > 30) {
					printf(" Error!! Invalid date, %d doesnt exist in %s", date, mon[5]);
					return 0;
				}
				printf("%dth %s, %d\n", date, mon[5], year);
				break;
			}

			break;

		case 7:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[6], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[6], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[6], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[6], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[6], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[6], year);
				break;

			default:
				printf("%dth %s, %d\n", date, mon[6], year);
				break;
			}

			break;

		case 8:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[7], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[7], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[7], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[7], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[7], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[7], year);
				break;

			default:
				printf("%dth %s, %d\n", date, mon[7], year);
				break;
			}

			break;

		case 9:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[8], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[8], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[8], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[8], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[8], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[8], year);
				break;

			default:
				if (date > 30) {
					printf(" Error!! Invalid date, %d doesnt exist in %s", date, mon[8]);
					return 0;
				}
				printf("%dth %s, %d\n", date, mon[8], year);
				break;
			}

			break;

		case 10:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[9], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[9], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[9], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[9], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[9], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[9], year);
				break;

			default:
				printf("%dth %s, %d\n", date, mon[9], year);
				break;
			}

			break;

		case 11:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[10], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[10], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[10], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[10], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[10], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[10], year);
				break;

			default:
				if (date > 30) {
					printf(" Error!! Invalid date, %d doesnt exist in %s", date, mon[10]);
					return 0;
				}
				printf("%dth %s, %d\n", date, mon[10], year);
				break;
			}

			break;

		case 12:
			switch (date)
			{
			case 1:
				printf("%dst %s, %d\n", date, mon[11], year);
				break;

			case 21:
				printf("%dst %s, %d\n", date, mon[11], year);
				break;

			case 2:
				printf("%dnd %s, %d\n", date, mon[11], year);
				break;

			case 22:
				printf("%dnd %s, %d\n", date, mon[11], year);
				break;

			case 3:
				printf("%drd %s, %d\n", date, mon[11], year);
				break;

			case 23:
				printf("%drd %s, %d\n", date, mon[11], year);
				break;

			default:
				printf("%dth %s, %d\n", date, mon[11], year);
				break;
			}

			break;

		default:
			printf(" Error!! Invalid  month no. %d ", month);
			break;
		}

		return 0;
	}

	/* int lower_case_to_upper_case() {

		int len = 0;
		char character[50];

		printf("Enter the string\n");
		gets(character);

		while (character[len] != '\0')
		{
			len++;
		}
		//printf("len%d", len);
	    
		for(int i=0; character[i] = '\0'; i++)
		{
			printf("\nReversed  :\n");
			//printf("%s :\n", character[i]);
			if(character[i]>= 'a' && character[i] <= 'z')
			character[i] -= 32;
		}
		character[len] = '\0';
		printf("\nReversed String :\n");
		printf("%s", character);
		//return character;
	} */

	int lower_case_to_upper_case(char low_string[]) {
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
		printf("%s\n", c);
		return 0;
	}

	int reverse_string() {
		//function to read a string from the userand reverse the strin
		int i = 0,len=0;
		char reverse[50],straight[50];

		printf("Enter the string\n");
		gets(straight);
		
		while (straight[len] != '\0')
		{
			len++;
		}

		while (len >0 ) {
			reverse[i] = straight[len-1];
			//printf("f%d %c2 %c1 \n", len, reverse[i], straight[len-1]);
			i++;
			len--;
		}
		reverse[i] = '\0';
		
		printf("\nReversed String :\n");
		printf("%s", reverse);
		return 0;
	}

	int matrix_5_cross_5()
	{
		//int **matrix;
		int row_size = 3, column_size = 3;

		int** matrix = construct_2Dmatrix(row_size, column_size);

		print_2Dmatrix(matrix, row_size, column_size);
		return 0;
	}

	int** construct_2Dmatrix(int row_size, int column_size)
	{
		int** arr;
		int n;
		arr = (int**)malloc(row_size * sizeof(int*));

		for (int i = 0; i < row_size; i++)
		{
			arr[i] = (int*)malloc(column_size * sizeof(int));
		}

		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < column_size; j++)
			{
				printf("matrix[%d][%d] = ",i,j);
				scanf_s("%d", &n);
				arr[i][j] = n;
				printf("\n");
			}

		}
		return arr;
	}

	int print_2Dmatrix(int** arr, int row_size, int column_size)
	{
		printf("matrix[%d][%d] = \n", row_size, column_size);

		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < column_size; j++)
			{
				printf("%d  ",arr[i][j]);
			}
			printf("\n");
		}
		return 0;
	}

	int add_two_matrix()
	{  //Declaration of function to add 2 matrixes

		int** sum;
		int row_size1=2,column_size1=2, row_size2,column_size2;
		
		row_size2 = row_size1;
		column_size2 = column_size1;
		int arr1[2][2] = { {9,4},{2,5} };
		int arr2[2][2] = { {1,1},{1,1} };
		if (row_size1 != row_size2 || column_size1 != column_size2) {

			printf("Error!!! For Matrix addition, matrices must have the same dimensions\n");
			return -1;
		}
		
		

		sum = (int**)malloc(row_size1 * sizeof(int*));

		for (int i = 0; i < row_size1; i++)
		{
			sum[i] = (int*)malloc(column_size1 * sizeof(int));
		}

		for (int i = 0; i < row_size1; i++)
		{
			for (int j = 0; j < column_size1; j++)
			{
				sum[i][j] = arr1[i][j] + arr2[i][j];
			}
		}

		printf("The sum of the above 2 matrices :\n");
		print_2Dmatrix(sum, row_size1, column_size1);
		return 0;
	}

	/*
	int check_whether_two_matrixes_are_same(int** arr1, int row_size1, int column_size1, int** arr2, int row_size2, int column_size2)
	{
		//int** array1;
		//int** array2;

		if (row_size1 != row_size2 || column_size1 != column_size2) {

			return 0;
		}

		for (int i = 0; i < row_size1; i++)
		{
			for (int j = 0; j < column_size1; j++)
			{
				if (arr1[i][j] != arr2[i][j])
					return 0;
			}

		}
		return 1;
	}*/
	int check_whether_two_matrixes_are_same()
	{
		//function to check whether 2 matrixes are same.
		//int** array1;
		//int** array2;
		int row_size1 = 2, column_size1 = 3, row_size2, column_size2;

		row_size2 = row_size1;
		column_size2 = column_size1;

		int arr1[2][3] = { 0, 1 ,2 ,3 ,4 , 5 };
		int arr2[2][3] = { 1,1,1,1,1,1 };
		if (row_size1 != row_size2 || column_size1 != column_size2) {

			return 0;
		}

		for (int i = 0; i < row_size1; i++)
		{
			for (int j = 0; j < column_size1; j++)
			{
				if (arr1[i][j] != arr2[i][j])
					return 0;
			}

		}
		return 1;
	}

	int sparse_matrix()
	{
	/* function to check if given matrix is a sparse matrix.If the number of zeros in a matrix exceeds(n * m) / 2,
		where n, m is the dimension of the matrix, matrix is sparse matrix.
		Sparse matrix has more zero elements than nonzero elements.*/

		int row_size1, column_size1,count=0, sparse_num;
		int** array;

		printf("Enter row size\n");
		scanf_s("%d", &row_size1);

		printf("Enter column size\n");
		scanf_s("%d", &column_size1);

		array = construct_2Dmatrix(row_size1, column_size1);

		print_2Dmatrix(array, row_size1, column_size1);

		for (int i = 0; i < row_size1; i++)
		{
			for (int j = 0; j < column_size1; j++)
			{
				if (array[i][j] == 0)
					count++;
			}

		}

		sparse_num = (row_size1 * column_size1) / 2;

		if(count > sparse_num)
			printf("It's sparse matrix\n");
		else
			printf("It's not sparse matrix\n");

		return 0;
	}

	int set_union(int arr1[], int size1, int arr2[], int size2)
	{
		//Function to input and prints results of A union B 

		int* union_set;
		int union_size,flag=0,count=0;

		union_size = size1 + size2;
		
		union_set = (int*)malloc(union_size * sizeof(int));

		for (int i = 0; i < size1; i++)
		{
			union_set[i] = arr1[i];
		}

		for (int i = 0; i < size2; i++)
		{
			for (int j = 0; j < size2; j++) {
				if (arr2[i] == union_set[j]) {
					flag = 1;
					break;
				}		
			}	
			if (flag == 0) {
				union_set[size1 + count] = arr2[i];
				count++;
			}
			flag = 0;
		}

		printf(" Union set :\n");
		print_array(union_set, size1+count);
		free(union_set);
		*union_set = NULL;
		return 0;
	}

	int set_intersection(int arr1[], int size1, int arr2[], int size2)
	{
		int* intersection_set;
		int intersection_size, flag = 0, count = 0;

		if (size1 > size2)
			intersection_size = size2;
		else
			intersection_size = size1;

		intersection_set = (int*)malloc(intersection_size * sizeof(int));

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++) {

				if (arr1[i] == arr2[j]) {
					//printf("arr1[i]%d arr2[j]%d\n", arr1[i], arr2[j]);
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				intersection_set[count] = arr1[i];
				count++;
				flag = 0;
			}

		}

		printf(" Intersection set :\n");
		print_array(intersection_set, count);
		free(intersection_set);
		*intersection_set = NULL;
		return 0;
	}

	int set_difference(int arr1[], int size1, int arr2[], int size2)
	{

		int* difference_set1, *difference_set2;
		int difference_size, flag = 0, count = 0;

		//Function to input and prints results of A-B and B-A
		difference_size = size1;

		difference_set1 = (int*)malloc(difference_size * sizeof(int));

		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++) {

				if (arr1[i] == arr2[j]) {
					//printf("arr1[i]%d arr2[j]%d\n", arr1[i], arr2[j]);
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				difference_set1[count] = arr1[i];
				count++;
			}
			flag = 0;
		}

		printf(" Difference set Set1-Set2 :\n");
		print_array(difference_set1, count);
		free(difference_set1);
		*difference_set1 = NULL;

		//Function to input and prints results of B-A
		flag = 0;
		count = 0;
		difference_size = size2;

		difference_set2 = (int*)malloc(difference_size * sizeof(int));

		for (int i = 0; i < size2; i++)
		{
			for (int j = 0; j < size1; j++) {

				if (arr2[i] == arr1[j]) {
					//printf("arr1[i]%d arr2[j]%d\n", arr1[i], arr2[j]);
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				difference_set2[count] = arr2[i];
				count++;
			}
			flag = 0;
		}

		printf(" Difference set Set2-Set1 :\n");
		print_array(difference_set2, count);
		free(difference_set2);
		*difference_set2 = NULL;

		return 0;
	}