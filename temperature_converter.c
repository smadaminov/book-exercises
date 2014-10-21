/*
Converter from Fahrenheit to Celsius and backwards
The program outputs table
*/

#include<stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit to Celsius table\n");
    printf("Fahrenheit:\tCelsius:\n");
    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
        fahr += step;
    }

    printf("Celsius to Fahrenheit table\n");
    printf("Celsius:\tFahrenheit:\n");
    celsius = lower;
    while(celsius <= upper){
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t\t%6.1f\n", celsius, fahr);
        celsius += step;
    }

    printf("Fahrenheit to Celsius table using FOR loop\n");
    printf("Fahrenheit:\tCelsius:\n");
    for(fahr = UPPER; fahr >= LOWER; fahr -= STEP){
        printf("%3.0f\t\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
