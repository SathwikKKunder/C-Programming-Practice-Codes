#include "Day1_Header.h"
#include <stdio.h>
#include <math.h>

int upper_case_to_lower_converter(char letter) { // pper case to lower converter function defination

    if (letter < 64) // checking if character is in letter or not, Ascii number les than 64 is of symbols
        return -1;

    else if (letter > 97) // checking if character is in lower case or not, Ascii number of lower case letter starts from 97, with 97 being 'a'
        return -2;

    else
        return letter + 32;
}

float circle_area_generator(int radius) { // Area of Circle function defination
    float area;
    area = 3.14 * radius * radius;
    return area;
}

float simple_interest_calculator(int princi_amt, int time_period, int rate) { // Simple interest function defination

    return (princi_amt * time_period * rate) / 100;
}

double compound_interest_calculator(double princi_amt, double time_period, double rate) { // Compound interest function defination
    double rate_calc,int_calc;

    rate_calc = (1 + rate * 0.01);
    int_calc = PRINCI_AMT * (pow(rate_calc, TIME_PERIOD) - 1);
    return int_calc;
}

int check_even_number(int number) { //Check even number function defination
    if (number % 2 == 0)
        return 1;
    else
        return 0;
}

float temperature_scale_converter(int scale, float temperature) { //Temperature Scale Converter function defination
    float converted_temp;

    /*scale = 0 for Celcius to Farenheit
    scale = 1 for Farenheit to Celcius*/

    if (scale == 0) {
       // (X°C × 9 / 5) + 32 = Y°F

        converted_temp = (temperature * 1.8) + 32;
        return converted_temp;
    }

    else if (scale == 1) {
        //(Y°F − 32) × 5 / 9 = X°C

        converted_temp = (temperature - 32) * 5 / 9;
        return converted_temp;
    }
    
    else
        return -1;
}

int check_leap_year(int year) { //Check leap year function defination
    if (year < 0)
        return -1;

    else if (year % 100 == 0) {
        if (year % 400 == 0)
            return 1;
        else
            return 0;
    }

    else if (year % 4 == 0)
        return 1;

    else
        return 0;
}

int power_of_two_using_left_shit_operator(int exponent) { // Power of 2 using left shit operator function defination

    if (exponent < 0)
        return -1;
    
    else
        return (2 << exponent-1);
}