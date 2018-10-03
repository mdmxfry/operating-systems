#include <stdlib.h>
#include <stdio.h>

int main() {
    int N;
    printf("> N: ");
    scanf("%i", &N);

    // Init array
    int *array = malloc(N * sizeof(int));

    // Fill array
    for(int i=0; i<N; i++){
        array[i] = i;
    }

    // Print Array
    for(int i=0; i<N; i++){
        printf("%i\n", array[i]);
    }

    // Free memory
    free(array);

    return 0;
}