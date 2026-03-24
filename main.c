#include <stdio.h>
#include <stdlib.h>

void push_back(int **arr, size_t *capacity, int *length, int value);
void pop_back(int *length);
int get(int *arr, int index);
int size(int *length);

int main(void)
{
    size_t capacity = 10;
    int length = 0;
    int *arr = malloc(capacity * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        push_back(&arr, &capacity, &length, i);
    }

    puts("After push_back");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    pop_back(&length);
    puts("After pop_back");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("element by 1 index %d, size of arr %d", get(arr, 1), size(length));
    free(arr);
    return 0;
}

void push_back(int **arr, size_t *capacity, int *length, int value)
{
    if (*length == (int)*capacity)
    {
        *capacity = *capacity * 2;

        int *new_arr = realloc(*arr, *capacity * sizeof(int));
        if (new_arr == NULL) return;

        *arr = new_arr;
    }

    (*arr)[*length] = value;
    (*length)++;
}

void pop_back(int *length)
{
    if (*length != 0)
        *length = *length - 1;
}

int get(int *arr, int index) {
    return arr[index];
}

int size(int *length) {
    return *length;
}