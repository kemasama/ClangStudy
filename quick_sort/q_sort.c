#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************
XとYを入れ替える
***********************************/
int
swap(
int *x,
int *y
)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;

    return 0;
}

/***********************************
中央値（Pivot）を求め、入れ替える
***********************************/
int
get_pivot(
int array[],
int left,
int right
)
{
    int i;
    int j;
    int pivot;

    i = left;
    j = right + 1;
    pivot = left;

    do 
    {
        do
        {
            i++;
        } while ( array[i] < array[pivot] );

        do {
            j--;
        } while ( array[pivot] < array[j] );

        if ( i < j )
        {
            swap(&array[i], &array[j]);
        }
    } while (i < j);

    swap(&array[pivot], &array[j]);

    return j;
}


/***********************************
クイックソートを行う
***********************************/
int
q_sort(
int array[],
int left,
int right
)
{
    int pivot;

    if ( left < right )
    {
        pivot = get_pivot(array, left, right);
        q_sort(array, left, pivot - 1);
        q_sort(array, pivot + 1, right);
    }

    return 0;
}

/***********************************
 クイックソートを行う
***********************************/
int
quick_sort(
int *array,
int left,
int right
)
{
    int right_index, left_index, pivot;

    if ( left >= right )
    {
        return -1;
    }

    left_index = left;
    right_index = right;
    pivot = left;

    for ( ; left_index < right_index ; )
    {
        for ( ; array[left_index] < array[pivot] ; )
        {
            left_index++;
        }

        right_index--;
        
        for ( ; array[right_index] > array[pivot] ; )
        {
            right_index--;
        }

        if ( left_index < right_index )
        {
            swap(&array[right_index], &array[left_index]);
        }
    }

    swap(&array[pivot], &array[right_index]);

    quick_sort(array, left, right_index - 1);
    quick_sort(array, right_index + 1, right);

    return 0;
}

/***********************************
メイン関数
***********************************/
int
main()
{
    int array[] = {
        10, 20, 30, 50,
        50, 10, 45, 65,
        76, 54, 56, 15,
        34, 31, 14, 17,
        14, 15, 11, 16,
        90, 19, 98, 76,
        75, 15, 161, 165,
        166, 167, 87, 86
    };

    int length = sizeof(array) / sizeof(int);

    printf("Length: %d\n", length);
    quick_sort(array, 0, length);

    int i ;
    
    for ( i = 0 ; i < length ; i++ )
    {
        printf("%d", array[i]);
        printf("\n");
    }

    return 0;
}

