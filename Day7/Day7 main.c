#include <stdio.h>
#include "Day7.h"

void dynamic_allocation();

int main() {

	dynamic_allocation();
}

void dynamic_allocation() {

	int size,sum;
	int* array;
	Array_Min_Max element1;
	Elements_Array element2;

	printf("Enter no. of integers\n");
	scanf_s("%d", &size);

	array = (int*)malloc(size * sizeof(int));

	//printf("%p\n", array);

	array  = construt_array(array,size);
	
	linear_search(array, size);

	element1 = find_max_min(array, size);
	printf("\nThe minimum and maximum elements in a given array,\n max = %d, min = %d\n", element1.max, element1.min);

	sum = sum_array(array,size);
	printf("\nThe sum of all the elements of array is %d\n", sum);

	element2 = sum_of_array_elements(array, size);
	printf("\nThe sum of even elements in a given array = %d\nThe sum of odd elements in a given array = %d\n", element2.sum_of_even_elements, element2.sum_of_odd_elements);

	array_palindrome(array, size);

	array = deallocate_memory(array);
	//printf("%p\n", array);
}