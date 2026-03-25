#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t capacity;
    size_t length;
    int *arr;

} VECTOR;

void init_vector(VECTOR *v, size_t initial_capacity);
void free_vector(VECTOR *v);
void push_back(VECTOR *v, int value);
void pop_back(VECTOR *v);
int get(VECTOR *v, size_t index);
size_t length(VECTOR *v);

int main(void)
{
    VECTOR v;
    init_vector(&v, 10);

    for (int i = 0; i < 10; i++)
    {
        push_back(&v, i);
    }

    puts("After push_back");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", v.arr[i]);
    }

    printf("\n");

    pop_back(&v);

    puts("After pop_back");
    for (int i = 0; i < v.length; i++)
    {
        printf("%d ", v.arr[i]);
    }

    printf("\n");

    printf("element by 1 index %d, size of arr %d", get(&v, 1), size(&v));

    free_vector(&v);
    return 0;
}

void init_vector(VECTOR *v, size_t initial_capacity)
{
    v->capacity = initial_capacity;
    v->length = 0;
    v->arr = malloc(v->capacity * sizeof(int));

    if (v->arr == NULL)
        exit(1);
}

void free_vector(VECTOR *v)
{
    free(v->arr);

    v->arr = NULL;
    v->capacity = 0;
    v->length = 0;
}

void push_back(VECTOR *v, int value)
{
    if (v->length == v->capacity)
    {
        v->capacity = v->capacity * 2;

        int *new_arr = realloc(v->arr, v->capacity * sizeof(int));
        if (new_arr == NULL)
            return;

        v->arr = new_arr;
    }

    (v->arr)[v->length] = value;
    (v->length)++;
}

void pop_back(VECTOR *v)
{
    if (v->length != 0)
        v->length -= 1;
}

int get(VECTOR *v, size_t index)
{
    if (index > v->length)
        return;
    return v->arr[index];
}

size_t length(VECTOR *v)
{
    return v->length;
}