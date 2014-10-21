#include<stdio.h>

#define IN 1
#define OUT 0

main(){
    int c, nl, nw, nc, state;
    //double nc;

    printf("EOF is %d\n", EOF);

    //  I would say that for correct work of the program
    //  one should use end of line '\n' than EOF
    //  except you are really working with flows

    /*while ((c = getchar()) != EOF){
        putchar(c);
    }*/

    /*for (nc = 0; getchar() != '\n'; ++nc)
        ;
    printf("%.0f\n", nc);*/


    //  Exercise 1.10
    /*nl = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n')
            ++nl;
        if (c == '\t'){
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b'){
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\'){
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
    printf("%d\n", nl);*/

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
