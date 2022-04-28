#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
array_copy(
    int *array1,
    int *array2,
    int array2_size
)
{
    int i;

    for ( i = 0 ; i < array2_size ; i++ ) {
        array1[i] = array2[i];
    }

    return 0;
}

int
quick_sort(
    int *array,
    int left,
    int right
)
{
    int *group_small;
    int *group_large;
    int small_index = 0;
    int small_size  = 0;
    int large_index = 0;
    int large_size  = 0;

    int i   = 0;
    int range   = right - left;
    int pivot;
    int pivot_index = 0;

    if ( left >= right ) {
        return -1;
    }

    group_small = (int *)malloc(sizeof(int) * range);
    if ( group_small == NULL ) {
        return -1;
    }

    group_large = (int *)malloc(sizeof(int) * range);
    if ( group_large == NULL ) {
        free(group_small);
        return -1;
    }

    pivot = array[left];

    for ( i = left + 1 ; i <= right ; i++ ) {
        if ( array[i] < pivot ) {
            group_small[small_index] = array[i];
            small_index++;
            small_size++;
        } else {
            group_large[large_index] = array[i];
            large_index++;
            large_size++;
        }
    }

    pivot_index = left + small_size;

    array_copy(array + left, group_small, small_size);
    array[pivot_index] = pivot;
    array_copy(array + pivot_index + 1, group_large, large_size);

    free(group_small);
    free(group_large);

    quick_sort(array, left, pivot_index - 1);
    quick_sort(array, pivot_index + 1, right);

    return 0;
}

int
main(
    int argc,
    char *argv[]
)
{
    int i;

    int length = 200;
    int rand_limit = 100;

    if ( argc > 1 ) {
        length = atoi(argv[1]);
    }

    int array[length];

    srand((int)time(NULL));

    for ( i = 0 ; i < length ; i++ ) {
        array[i] = rand() % rand_limit + 1;
    }

    time_t start_at = time(NULL);
    quick_sort(array, 0, length - 1);
    time_t end_at = time(NULL);

    for ( i = 0 ; i < length ; i++ ) {
        printf("%d\n", array[i]);
    }

    printf("elapsed: %lds\n", end_at - start_at);

    return 0;
}
