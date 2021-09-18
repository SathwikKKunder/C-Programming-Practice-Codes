#include <assert.h>
#include <stdio.h>
#include "Day1_Header.h"

void test_upper_case_to_lower_converter();
void test_area();
void test_simple_interest();
void test_compound_interest();
void test_check_even_number();
void test_temperature_scale_converter();
void test_check_leap_year();
void test_power_of_two_using_left_shit_operator();


int main() {
    //test_upper_case_to_lower_converter();             //Testing Upper case to lower converter function call
    //test_area();                                     // Testing Area of Circle test function call
    //test_compound_interest();                        // Testing Compound interest function call
    //test_simple_interest();                         // Testing Simple interest function call
    //test_check_even_number();                       //Testing heck even number function call
    //test_temperature_scale_converter();            //Testing Temperature Scale Converter function call
    //test_check_leap_year();                        //Testing Check leap year function call
    //test_power_of_two_using_left_shit_operator();  // Testing Power of 2 using left shit operator function call

    return 0;
}

void test_upper_case_to_lower_converter() { // Testing Upper case to lower converter function

    assert(upper_case_to_lower_converter('C') == 'c');
    assert(upper_case_to_lower_converter(' ') == -1);
    assert(upper_case_to_lower_converter('c') == -2);

}

void test_area() { // Testing Area of Circle test function 

    //assert(circle_area_generator(3)==28.260000);
    printf("area is %f\n", circle_area_generator(3));
}

void test_simple_interest() {    //Testing Simple interest function

    //assert(simple_interest_calculator(PRINCI_AMT, TIME_PERIOD, RATE) == 2100);
    printf("Simple Interest %f\n", simple_interest_calculator(PRINCI_AMT, TIME_PERIOD, RATE));
}

void test_compound_interest() {      //Testing Compound interest function

    printf("Compound Interest is %lf\n", compound_interest_calculator(PRINCI_AMT, TIME_PERIOD, RATE));
}

void test_check_even_number() {      //Testing Check even number function 
    assert(check_even_number(4) == 1);
    assert(check_even_number(8) == 1);
    assert(check_even_number(7) == 0);
    assert(check_even_number(5) == 0);
}

void test_temperature_scale_converter() { //Testing Temperature Scale Converter function

    /*scale = 0 for Celcius to Farenheit
    scale = 1 for Farenheit to Celcius*/

    //temperature_scale_converter(0, 10);
    assert(temperature_scale_converter(0, 10) == 50.000000);

    assert(temperature_scale_converter(5, 10) == -1);
    //temperature_scale_converter(1, 10);
    assert(temperature_scale_converter(1, 10) == -12.222222);

}

void test_check_leap_year() { //Testing Check leap year function defination

    assert(check_leap_year(1992) == 1);
    assert(check_leap_year(2020) == 1);
    assert(check_leap_year(1700) == 0);
    assert(check_leap_year(2300) == 0);
    assert(check_leap_year(-2020) == -1);
}

void test_power_of_two_using_left_shit_operator() { // Testing Power of 2 using left shit operator function

    assert(power_of_two_using_left_shit_operator(2) == 4);
    assert(power_of_two_using_left_shit_operator(4) == 16);
    assert(power_of_two_using_left_shit_operator(-2) == -1);
}