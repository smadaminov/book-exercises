/*
Converter from Fahrenheit to Celsius and backwards
The program outputs table
*/

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
}
