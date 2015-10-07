#include<stdio.h>
#include<ctype.h>

int main(int argc, char *argv[]){
    int i = 0;
    if (argc < 2) {
        printf("Error: argument is expected!\n");
        return -1;
    }
    else if (argc > 3) {
        printf("Error: just one argument is expected!\n");
        return -2;
    }
    if (strstr(argv[0], "exercise_7-1") != NULL){
        printf("Output: ");
        while (argv[1][i]){
            putchar(tolower(argv[1][i]));
            i++;
        }
    }
    else if (strstr(argv[0], "EXERCISE_7-1") != NULL){
        printf("Output: ");
        while (argv[1][i]){
            putchar(toupper(argv[1][i]));
            i++;
        }
    }
    else{
        printf("Error: incorrect program usage! Please write program name either in uppercase letters or lowercase letters.\n");
    }
    // Uncomment following line if the program exit immediately (e.g. if you use Windows)
    getchar();
    return 0;
}
