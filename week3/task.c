#include <stdio.h>

void bubble_sort(int n, int *array) {
    int temp;
    for (int i=0; i < n; i++) {
        for (int j=0; j < n - i; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    for (int i=0; i < n; i++) {
        printf("%d\t", array[i]);
    }
}

int main() {
    int arr_size = 7;
    int array[] = {9, 3, 0, 7, 1, 0, 1};
    bubble_sort(arr_size, array);
}

