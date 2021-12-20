#include<math.h>
#include<ctype.h>

int htoi(char s[]){
    int i;
    int n = 0;
    int h = 0;
    if (s[0] != '0' && (s[1] != 'x' || s[1] != 'X')){
        printf("This is not hexadecimal number!\n");
        return -1;
    }
    else{
        for (i = 2; i < strlen(s); i++){
            switch (tolower(s[i])){
            case 'a':
                h = 10;
                break;
            case 'b':
                h = 11;
                break;
            case 'c':
                h = 12;
                break;
            case 'd':
                h = 13;
                break;
            case 'e':
                h = 14;
                break;
            case 'f':
                h = 15;
                break;
            default:
                if (s[i] >= '0' && s[i] <= '9'){
                    h = s[i] - '0';
                }
                else{
                    printf("There is an error in input number!\n");
                    return -2;
                }
            }
            n = 16 * n + h;
        }
    }
    return n;
}

int main(void){
    char H[] = "0X7dE";
    printf("\nHexadecimal %s is equal to %d decimal\n", H, htoi(H));
    return 0;
}
