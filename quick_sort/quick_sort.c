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

        if ( array[smaller_index] < array[larger_index] ) {
            break;
        }

        swap(&array[smaller_index], &array[larger_index]);

        if ( array[smaller_index] == array[larger_index] ) {
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
    int i;
    int j;
    int c;
    int length = 0;
    int read_line_size = 512;
    char read_line[read_line_size];
    FILE *fp;

    char dataFile[] = "data.txt";
    fp = fopen(dataFile, "r");

    if ( fp == NULL ) {
        printf("file can not open.\n");
        return -1;
    }

    fseek(fp, 0, SEEK_SET);
    while ( (c = fgetc(fp)) != EOF )
    {
        if ( c == '\n')
        {
            length++;
        }
    }

    int array[length];

    fseek(fp, 0, SEEK_SET);

    for ( j = 0 ; j < length ; j++ )
    {
        fgets(read_line, read_line_size, fp);
        array[j] = atoi(read_line);
    }

    fclose(fp);

    printf("Length: %d\n", length);
    quick_sort(array, 0, length - 1);
    
    for ( i = 0 ; i < length ; i++ )
    {
        printf("%d", array[i]);
        printf("\n");
    }

    return 0;
}
