#include <ctype.h>
#include <stdio.h>

//#define MAXLINE 100

double pow(double power, int n){
    int i;
    double result;

    result = 1.0;
    for (i = 0; i < n; i++)
        result *= power;

    return result;
}

double atof(char s[]){
    double val, power;
    int i, sign, esign;

    for(i = 0; i < isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i++] == 'e' || s[i++] == 'E'){
        esign = (s[i++] == '-') ? -1 : 1;
        for (i; isdigit(s[i]); i++)
            if (esign == -1)
                power *= pow(10, s[i] - '0');
            if (esign == 1)
                power *= pow(0.1, s[i] - '0');
    }

    return sign * val / power;
}

int main(void){
    double sum, atof(char []);
    char *line;

    line = "123.45e-6";

    printf("The line is %s and the number is %g\n", line, atof(line));

    return 0;
}
