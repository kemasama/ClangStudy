#include <stdio.h>
#include <stdlib.h>

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

/*************************************************************************
    クイックソートを行う
*************************************************************************/
int
quick_sort(
int *array, // ソートする配列
int left,   // 左端
int right   // 右端（※配列の要素数ではない）
)
{
    int smaller_index;
    int larger_index;
    int pivot_index;
    int pivot;

    if ( left >= right ) {
        return -1;
    }

    smaller_index = left;
    larger_index = right;
    pivot_index = left;
    pivot = array[left];

    while ( smaller_index < larger_index ) {
        while ( array[smaller_index] < pivot )
        {
            smaller_index++;
        }

        while ( array[larger_index] > pivot )
        {
            larger_index--;
        }

        if ( array[smaller_index] > array[larger_index] ) {
            swap(&array[smaller_index], &array[larger_index]);
        } else if ( array[smaller_index] == array[larger_index] ) {
            smaller_index++;
        }
    }

    quick_sort(array, left, larger_index - 1);
    quick_sort(array, larger_index + 1, right);

    return 0;
}

/***********************************
メイン関数
***********************************/
int
main()
{
    /*
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
    */

    char dataFile[] = "data.txt";
    FILE *fp = fopen(dataFile, "r");

    if ( fp == NULL ) {
        printf("file can not open.\n");
        return -1;
    }

    fseek(fp, 0, SEEK_SET);
    int line_count = 0;
    int c;
    while ( (c = fgetc(fp)) != EOF )
    {
        if ( c == '\n')
        {
            line_count++;
        }
    }

    int array[line_count];

    fseek(fp, 0, SEEK_SET);

    int read_line_size = 512;
    char read_line[read_line_size];
    int j;

    for ( j = 0 ; j < line_count ; j++ )
    {
        fgets(read_line, read_line_size, fp);
        array[j] = atoi(read_line);
    }

    fclose(fp);

    int length = sizeof(array) / sizeof(int);

    printf("Length: %d\n", length);
    quick_sort(array, 0, length - 1);

    int i ;
    
    for ( i = 0 ; i < length ; i++ )
    {
        printf("%d", array[i]);
        printf("\n");
    }

    return 0;
}
