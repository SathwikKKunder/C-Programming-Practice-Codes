#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Day9.h"

int main() {
	Line_Details details;

	//create_file();  // Function to create a file.

	//display_file(); // Function to display the contents of a file.

	//copy_file();    // Function to copy the contents of one file to another

	//counter();       // Function to count number of characters, spaces tabs and lines in a file.

	//odd_or_even();    //Read a file which contains one number per line.
                     //Check the number is odd or even and write to corresponding odd.txt or even.txt accordingly.




	//--------------------------------FILE In TEXT MODE----------------------------------------------------

	//create_telephone_directory();

	//add_contacts();

	//number_finder();

	//edit_telephone_directory();


	details = directory_search();

	if (details.line_number > 0)          //update_directory_entry() is only called the searched is entry is present in the directory 
		update_directory_entry(details); //(i.e.if entry is present details.line_number will have non zero value)

	//if (details.line_number > 0)          //delete_directory_entry() is only called the searched is entry is present in the directory 
		//delete_directory_entry(details); //(i.e.if entry is present details.line_number will have non zero value)




	//--------------------------------FILE In BINARY MODE----------------------------------------------------


	//create_telephone_directory_binary();

	//add_contacts_binary();

	return 0;
}