void shellsort(int arr[], int n){
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
            for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap){
                temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
            }
        }
    }
}

int main(void){
    int n[4];
    int i;

    n[0] = 3;
    n[1] = 1;
    n[2] = 8;
    n[3] = 0;

    shellsort(n, 4);
    for (i = 0; i < 4; i++){
        printf("%d%c", n[i], i == 4 ? '\n' : ' ');
    }
}
