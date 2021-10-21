#pragma once
int create_file();  // Function to create a file.

int display_file(); // Function to display the contents of a file.

int copy_file();  // Function to copy the contents of one file to another

int counter();   // Function to count number of characters, spaces tabs and lines in a file.

int odd_or_even(); //Read a file which contains one number per line.
                   //Check the number is odd or even and write to corresponding odd.txt or even.txt accordingly.
                   //Note: Numbers may not be single digit numbers.


//--------------------------------FILE In TEXT MODE----------------------------------------------------

int create_telephone_directory();

int add_contacts();

int number_finder();

int edit_telephone_directory();

int update_directory_entry(Line_Details);

int delete_directory_entry(Line_Details);

struct _line_details_ {

    int line_number;
    int char_position;
};

typedef struct _line_details_ Line_Details;

Line_Details directory_search();


//--------------------------------FILE In BINARY MODE----------------------------------------------------

int create_telephone_directory_binary();

int add_contacts_binary();
