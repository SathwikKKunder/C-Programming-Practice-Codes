#include <stdio.h>
#include "Day7.h"

int* construt_array(int array[], int size)
{
	int x;
	//int* array1 =array;

	printf("\nEnter the integers\n");
	
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &x);
		*(array + i) = x;
	}

	//printf("Integers in the Array are:\n");
	//print_array(array1, size);

	return array;
}

int print_array(int* arr, int size) {
	int i = 0;
	if (size <= 0)
	{
		printf(" Error!! Invalid  Size %d ", size);
	}
	while (i < size)
	{
		printf("  %d\n", arr[i]);
		i++;
	}

	return 0;
}

int linear_search(int arr[], int size) {
	//function to search for a given integer in an array using the linear search technique
	int element,flag=0;

	printf("\nEnter the element to be searched\n");
	scanf_s("%d", &element);

	if (size <= 0)
	{
		printf(" Error!! Invalid  Size %d\n", size);
		return -1;
	}

	for (int j = 0; j < size; j++) {

		if (element == arr[j]) {
			printf("The Element %d is present in the array\n", element);   //To find element in a given array
			flag=1;
			break;
		}      
			
	}
	
	if(flag==0)
		printf("The Element %d is not present in the array\n", element);

	return 0;
}

Array_Min_Max find_max_min(int array[], int size) {
	//Function to find Max and Min element in an array

	
	Array_Min_Max element1;
	element1.max = element1.min = array[0];
	
	for (int j = 1; j < size; j++) {

		if (element1.max < array[j])        //To find maximum elements in a given array
			element1.max = array[j];

		if (element1.min  > array[j])       //To find minimum elements in a given array
			element1.min = array[j];

	}

	//printf(" The minimum and maximum elements in a given array,\n max = %d, min = %d\n", *max, *min);
	return element1;
}

int sum_array(int array[], int size)
{
	//function to find sum of all the elements of array
	int sum=0;

	for (int i = 0; i < size; i++)
	{
		sum += array[i];

	}
	return sum;
}

Elements_Array sum_of_array_elements(int array[], int size)
{ //function to find the sum of even and odd elements of array
	int even_sum=0, odd_sum=0;
	Elements_Array arr1;

	for (int i = 0; i < size; i++)
	{
		if (array[i] % 2 == 0)
			even_sum += array[i];
		else
			odd_sum += array[i];
	}
	arr1.sum_of_even_elements = even_sum;
	arr1.sum_of_odd_elements = odd_sum;

	return arr1;
}

int array_palindrome(int array[], int size)
{ //function to Check whether the array in palindrome
	int flag = 1;

	for (int i = 0; i < size/2; i++)
	{
		if (array[i] != array[size-1-i]) {
			flag = 0;
			break;
		}
	}

	if (flag)
		printf("\nArray is a palindrome\n");
	else
		printf("\nArray is not a palindrome\n");

	return flag;
}

int* deallocate_memory(int* array)
{
	//function to deallocate the memory using free()

	free(array);
	*array = NULL;
	return array;
}