#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/*int strcmp(char *s, char *t){
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}*/

int main(){
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("Error: input to big to sort\n");
        return 1;
    }
}

#define MAXLEN 100

int getline(char *line, int max);
char *alloc(int n);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0){
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines){
    int i;

    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int getline(char *line, int max){
    int i, c;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n' && c != 'q'){
        line[i++] = c;
    }
    if (c == '\n'){
        line[i++] = c;
    }
    if (c == 'q'){
        return -3;
    }
    line[i] = '\0';

    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
    else{
        return -2;
    }
}

void qsort(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return ;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++){
        if (strcmp(*v[i], *v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
