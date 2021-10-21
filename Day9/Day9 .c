#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Day9.h"

int create_file() {

	FILE* fp;

	fp = fopen("ReadMe.txt", "w");

	fprintf(fp, "%s", "a simple program to display the contents of a file.");
	fclose(fp);

	return 0;
}

int display_file()
{ 
	// Function to display the contents of a file.
	FILE* fp1;

	fp1 = fopen("ReadMe.txt", "r");
	char ch = "";


	if (fp1 == NULL) {

		printf("Unable to open the file");
		return 0;
	}

	while (ch != EOF) {
		//printf("v\n");
		ch = fgetc(fp1);
		printf("%c", ch);
	}

	fclose(fp1);

	return 0;
}

int copy_file()
{// Function to copy the contents of one file to another

	FILE* fp2, *fp3;
	char ch ="";

	fp2 = fopen("CopyMe.txt", "w");
	fp3 = fopen("ReadMe.txt", "r");

	while (ch != EOF) {
		//printf("v\n");
		ch = fgetc(fp3);
		fputc(ch,fp2);
		printf("%c", ch);
	}
	fclose(fp2);
	fclose(fp3);

	return 0;
}

int counter()
{// Function to count number of characters, spaces tabs and lines in a file.
	FILE* fp4;
	char ch="";
	int no_space = 0, no_tabs=0, no_line = 1, no_char = 0;

	fp4 = fopen("ReadMe.txt", "r");

	if (fp4 == NULL) {

		printf("Unable to the file");
		return 0;
	}

	while (1) {
		ch = getc(fp4);

		if (ch == EOF)
			break;

		if (ch == '\n')
			no_line++;
		
		if (ch == '\t')
			no_tabs++;

		if (ch == ' ')
			no_space++;
		
		no_char++;
	}

	printf("No. of Character = %d\nNo. of lines = %d\nNo. of tabs = %d\nNo. of space = %d\n",no_char,no_line,no_tabs,no_space);

	fclose(fp4);

	return 0;
}

int odd_or_even()
{                  //Read a file which contains one number per line.
                   //Check the number is odd or even and write to corresponding odd.txt or even.txt accordingly.
                   //Note: Numbers may not be single digit numbers.
	FILE* fp5, * fp6, * fp7;

	int ch=0;

	fp5 = fopen("Numbers.txt","r");
	
	if (fp5 == NULL) {

		printf("Unable to the file");
		return 0;
	}

	while (!feof(fp5)) {
		fscanf(fp5, "%d", &ch);

		if (ch % 2 == 0) {
			//printf("%d", ch);
			fp6 = fopen("even.txt", "a");
			fprintf(fp6, "%d\n", ch);
			fclose(fp6);
		}

		else {
			//printf("o%d", ch);
			fp7 = fopen("odd.txt", "a");
			fprintf(fp7, "%d\n", ch);
			fclose(fp7);
		}
	}

	fclose(fp5);
	return 0;
}

int create_telephone_directory()
{
	//Function to create a directory

	FILE* fp8;

	fp8 = fopen("telephone_directory.txt", "w");   //Opening the directory in "write mode"

	if (fp8 == NULL) { //If "fopen" function  fails to open a file, -1 is returned.

		printf("Unable to create the directory");
		return -1;
	}

	fclose(fp8);

	return 0;
}

int add_contacts()
{
	//Function to add entries to the directory created using "create_telephone_directory()" function
	FILE *fp9;
	char address[100], name[30];
	int phone_number;
	 
	fp9 = fopen("telephone_dictionary.txt", "a");       //Opening the directory in "append mode"


	printf("Enter the phone number :\n");
	scanf("%d", &phone_number);                //Asking the user to enter the number
	fprintf(fp9, "%d\n", phone_number);        //printing the number the user has entered to the file (dictionary)

	printf("Enter the name :\n");              
	scanf("%s", &name);                        //Asking the user to enter the name
	fprintf(fp9,"%s\n",name);                  //printing the name the user has entered to the file (dictionary)

	printf("Enter the address :\n");          
	scanf("%s", &address);                    //Asking the user to enter the address
	fprintf(fp9, "%s\n", address);            //printing the address the user has entered to the file (dictionary)

	fprintf(fp9,"\n");                 //Moving the cursor to the next line so that there's gap of 1 line between the entries of 2 users

	fclose(fp9);

	return 0;
}

/* int number_finder() { 

	FILE* fp10;
	char num[100];
	char file_num[15]="";
	int count,line_num=0,flag=0;

	printf("Enter the number to be searched\n");
	scanf("%s", &file_num);

	fp10= fopen("telephone_dictionary.txt", "r");

	if (fp10 == NULL) {
		printf("Unable to open the directory");
		return -1;
	}

	while (!feof(fp10)) {    //we search till End Of File, feof returns non zero number when end of file is reached.
		
		fgets(num,11, fp10); //we read a line from the file. '11' because we enter 10 (because phone num contains 10 numbers) it reads 9 numbers
		                     //maybe one extra character for '\0' (null character )[don't know not sure :( ]so 11.    

		 /* printf("num %s l%d\n", num, line_num); 
		
		if (!(strcmp(num, file_num))) {

			flag = 1;    //If the 'number' read from the file matches the 'number to be searched, we maake flag=1 and proceed to print the details

			printf("\nNumber %s found in the directory\nDetails :\n", file_num);
			count = 3;  //counter to print next 2 lines i.e. the name and the address. 
			            //count = 3 because for the 1st iteration fgets reads blank line.[again don't know y :( ].
			            //hence we intialze count =3 (one number extra than required).

			while (count > 0) {
				fgets(num, 100, fp10); // '100' because address max size is set 100, and we are reading address also.

				if (count == 2)
					printf("Name : %s\n", num);
				
				if(count==1)
					printf("Address : %s\n", num);

				count--;
			}

			fclose(fp10);   //After displaying the details, we close the file and return the line number the "phone number" was found in the directory 
			return line_num;

		}
		else {           //If there's no match, we proceed to read the next line and increment the line counter(i.e line_num)
			line_num++;
		}
	}



	if (!flag) { //if flag is '0' it means that Number doesn't exist in the directory, hence we close the file and return 0

		printf("\nNumber %s doesn't exist in the directory\nDetails :", file_num);
		fclose(fp10);
		return 0;
	}

	

} */

/* int edit_telephone_directory()
{
	FILE* fp11, *fp12;

	char data[100];
	//char new_num[10];
	int line_num = 0;

	printf("Enter the number to be edited\n");
	//scanf("%s", &new_num);

	fp11 = fopen("telephone_dictionary.txt", "r");

	if (fp11 == NULL) {
		printf("Unable to open the directory");
		return -1;
	}

	fp12 = fopen("temperory_dictionary.txt", "a");


	while (line_num < 5) {

		fgets(data, 100, fp11);
		fprintf(fp12, "%s", data);

		fgets(data, 30, fp11);
		fprintf(fp12, "%s", data);

		fgets(data, 100, fp11);
		fprintf(fp12, "%s\n", data);
		
		printf("line : %d", line_num);
		line_num++;
	}

	fclose(fp11);
	fclose(fp12);

	return 0;
} */

int update_directory_entry(Line_Details details) {

	FILE* fp11;
	
	char data[] = "";
	//char new_num[10];

	printf("Enter the updated number \n");        
	scanf("%s", &data);                  //Asking the user to enter the new number to be replaced with the old number
	 
	fp11 = fopen("telephone_dictionary.txt", "r+"); //Opening the directory in "read & write mode"

	if (fp11 == NULL) { //If "fopen" function  fails to open a file, -1 is returned.
		printf("Unable to open the directory");
		return -1;
	}


	fseek(fp11, details.char_position, SEEK_SET);    //setting the cursor position to the line where the searched number was found

	//fputs("9111122332", fp11);  //overwriting old number with new one.           
	fputs(data, fp11);  //where 'data' is declared as char data="", and taken from the user;
	//fprintf(fp11, "%s", data);

	fclose(fp11);
	
	//printf("lb%d\nlp%d", l1.line_number, l1.char_position);
	return 0;

}


int delete_directory_entry(Line_Details details) {

	FILE* fp12;
	int count = 0;

	fp12 = fopen("temperory_dictionary.txt", "r+"); //Opening the directory in "read & write mode"

	if (fp12 == NULL) { //If "fopen" function  fails to open a file, -1 is returned.
		printf("Unable to open the directory\n");
		return -1;
	}

	fseek(fp12, details.char_position, SEEK_SET);    //setting the cursor position to the line where the searched number was found

	while (count < 3) { //Itirating 3 times so that data in consecutive 3 lines(Phone number,name,address) gets overwriiten with white space.
		fputs("            ", fp12); //Overwriting the existing data gets overwritten with 12 white spaces
		count++;
	}

	printf("The above entry is successfully deleted from the directory\n");
	fclose(fp12);

	return 0;

}

Line_Details directory_search()
{
	FILE* fp13;
	char num[100];
	char file_num[15] = "";
	Line_Details l1;     //declaring a structure to store line number and character position.
	int count, flag = 0;

	printf("Enter the number to be searched\n");  //User enters the number to be searched
	scanf("%s", &file_num);

	fp13 = fopen("telephone_dictionary.txt", "r"); //Opening the directory in "read mode"

	l1.line_number = -1;
	l1.char_position = -1;

	if (fp13 == NULL) {   //If "fopen" function  fails to open a file,Structure 'l1' with  line_number & char_position=-1 is returned
		printf("Unable to open the directory\n");
		return l1;
	}

	while (!feof(fp13)) {    //searches till End Of File, feof returns non zero number when end of file is reached.

		l1.char_position = ftell(fp13); //ftell returns position of file pointer in the file with respect to starting of the file    

		fgets(num, 11, fp13); //reads a line from the file. '11' because we enter 10 (because phone num contains 10 numbers) it reads 9 numbers
							 //maybe one extra character for '\0' (null character )[don't know not sure :( ]so 11.    



		 /* printf("num %s l%d\n", num, line_num); */

		if (!(strcmp(num, file_num))) {

			flag = 1;    //If the 'number' read from the file matches the 'number to be searched, flag is made 1 (i.e. flag=1) and proceed to print the details

			printf("\nNumber %s found in the directory\nDetails :\n", file_num);
			count = 3;  //counter to print next 2 lines i.e. the name and the address. 
						//count = 3 because for the 1st iteration fgets reads blank line.[again don't know y :( ].
						//hence intialze count =3 (one number extra than required).

			while (count > 0) {
				fgets(num, 100, fp13); // Since address also been read by the same "fgets", offset value is made '100' (because address max size is declared as 100).

				if (count == 2)
					printf("Name : %s\n", num);

				if (count == 1)
					printf("Address : %s\n", num);

				count--;
			}

			/*printf("lwe%d", l1.char_position); */

			fclose(fp13); //After displaying the details, we close the file and  
			return l1;  //return the structure l1 which contains line number & char_position of the "phone number" found in the directory

		}
		else {      //If there's no match, proceed to read the next line and increment the line counter(i.e line_number)
			l1.line_number++;
		}
	}


	if (!flag) { //if flag is '0' it means that Number doesn't exist in the directory, hence close the file and
				 //return the structure l1 with line number & char_position equal to "0"

		printf("\nNumber %s doesn't exist in the directory\n", file_num);
		l1.char_position = 0;
		l1.line_number = 0;
		fclose(fp13);
		return l1;
	}
}



int create_telephone_directory_binary()
{

	//Function to create a directory

	FILE* fp14;

	fp14 = fopen("telephone_directory_binary.txt", "wb");   //Opening the directory in "write mode"

	if (fp14 == NULL) { //If "fopen" function  fails to open a file, -1 is returned.

		printf("Unable to create the directory");
		return -1;
	}

	fclose(fp14);

	return 0;
}

int add_contacts_binary()
{
	//Function to add entries to the directory created using "create_telephone_directory_binary()" function
	FILE* fp15;
	char address[100], name[30];
	int phone_number;

	fp15 = fopen("telephone_directory_binary.txt", "ab");       //Opening the directory in "append mode"


	printf("Enter the phone number :\n");
	scanf("%d", &phone_number);                //Asking the user to enter the number
	fwrite(&phone_number, sizeof(phone_number), 1, fp15);   //printing the number the user has entered to the file (dictionary)

	printf("Enter the name :\n");
	scanf("%s", &name);                        //Asking the user to enter the name
	fwrite(&name, sizeof(name), 1, fp15);                  //printing the name the user has entered to the file (dictionary)

	printf("Enter the address :\n");
	scanf("%s", &address);                    //Asking the user to enter the address
	fwrite(&address, sizeof(address), 1, fp15);            //printing the address the user has entered to the file (dictionary)

	//fprintf(fp9, "\n");                 //Moving the cursor to the next line so that there's gap of 1 line between the entries of 2 users

	fclose(fp15);

	return 0;
}
