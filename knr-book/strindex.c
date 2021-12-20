#include <stdio.h>
#define MAXLINE 100

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void){
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0){
        if (strindex(line, pattern) >= 0){
            printf("%s", line);
            found++;
        }
    }

    return found;
}

//  Read the string into s and return its length
int getline(char line[], int max){
    int i, c;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c;
    }
    if (c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
}

int strindex(char source[], char searchfor[]){
    int i, j, k;

    for (i = 0; source[i] != '\0'; i++){
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;
        if (k > 0 && searchfor[k] == '\0'){
            return i;
        }
    }

    return -1;
}
