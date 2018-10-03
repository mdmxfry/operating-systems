#include <stdlib.h>
#include <stdio.h>

int * c_realloc(int *arr, int old_size, int new_size){
    int *new_arr = malloc(new_size * sizeof(int));

    for(int i=0; i<old_size; i++){
        new_arr[i] = arr[i];
    }
    free(arr);
    return new_arr;
}

int main() {
    int N1;
    printf("> N1: ");
    scanf("%i", &N1);

    // Init array
    int *array = malloc(N1 * sizeof(int));

    int N2;
    printf("> N2: ");
    scanf("%i", &N2);

    for (int i = 0; i < N1; i++) {
        //Print each element out (to make sure things look right)
        printf("1: %d\n", array[i]);
    }

    array = c_realloc(array, N1, N2);

    for (int i = 0; i < N2; i++) {
        //Print each element out (to make sure things look right)
        printf("2: %d\n", array[i]);
    }

    return 0;
}