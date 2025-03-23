// Program to convert temperatures between Celcius 
#include <stdio.h>

//Conversion functions
float cel_to_far(float celsius) {return (9.0/5.0) * celsius + 32; }
float far_to_cel(float fahrenheit) {return (5.0/9.0) * (fahrenheit - 32); }
float cel_to_kel(float celsius) {return celsius + 273.15; }
float kel_to_cel(float kelvin) {return kelvin - 273.15; }

//Function to categorize temperature and provide an advisory
void categorize_temperature(float_celsius) {
    if (celsius < 0) printf("Category: Freezing - Wear warm clothes!\n");
    else if (celsius < 10) printf("Category: Cold - Wear a jacket.\n");
    else if (celsius < 25) printf("Category: Comfortable - You should feel comfortable.\n");
    else if (celsius < 35) printf("Category: Hot - Stay hydrated.\n");
    else printf("Category: Extreme Heat - Stay indoors!\n");
}

//Main function to handle user input, perform conversion and categorize temperature
int main() {
    float temp;
    int from, to;
    printf("Enter temperature: ");
    scanf("%f", &temp);
    printf("Choose the current scale (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &from);
    printf("Convert to (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
    scanf("%d", &to);
    
    float converted_temp = temp;
    if (from == 1 && to ==2) converted_temp = cel_to_far(temp);
    else if (from == 1 && to == 3) converted_temp = cel_to_kel(temp);
    else if (from == 2 && to == 1) converted_temp = far_to_cel(temp);
    else if (from == 2 && to == 3) converted_temp = cel_to_kel(far_to_cel(temp));
    else if (from == 3 && to == 1) converted_temp = kel_to_cel(temp);
    else if (from == 3 && to == 2) converted_temp = cel_to_far(kel_to_cel(temp));
    else {
        printf("invalid conversion choice.\n");
        return 1;
    }
    
    printf("Converted temperature: %.2f\n", converted_temp);
    if (to == 1) categorize_temperature(converted_temp);
    return 0;
    
}