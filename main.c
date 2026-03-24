#include <stdio.h>
#include <stdlib.h>


void push_back(int **arr, size_t *capacity, int *length, int value);

int main(void) {
    size_t capacity = 10;
    int length = 0;
    int *arr = malloc(capacity * sizeof(int));
    for (int i = 0; i < 11; i++) {
        push_back(&arr, &capacity, &length, i);
    }
    for (int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }


    free(arr);
    return 0;
}


void push_back(int **arr, size_t *capacity, int *length, int value) {
    if (*length == (int)*capacity) {
        *capacity = *capacity * 2;
        int *new_arr = realloc(*arr, *capacity * sizeof(int));
        *arr = new_arr;
    }

    (*arr)[*length] = value;
    (*length)++;
}