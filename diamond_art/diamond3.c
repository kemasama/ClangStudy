#include <stdio.h>
#include <stdlib.h>

int
output_whitespace(
    int length
)
{
    int i;
    
    for ( i = 0 ; i < length ; i++ ) {
        printf(" ");
    }

    return 0;
}

int
output_diamond_line(
    int diamond_size,
    int current_line
)
{
    int i;
    int j;
    int k;
    int l;

    // Left Side
    // Decoration
    for ( i = diamond_size - current_line ; i > 0 ; i-- ) {
        printf("%d", i);
    }

    // Padding
    output_whitespace(1);

    // Diamond
    for ( j = 1 ; j < current_line ; j++ ) {
        printf("%d", j);
    }

    // Right Side
    // Diamond
    for ( k = 0 ; k < current_line ; k++ ) {
        printf("%d", current_line - k);
    }

    // Padding
    if ( current_line != 0 ) {
        output_whitespace(1);
    }

    // Decoration
    for ( l = 1 ; l <= diamond_size - current_line ; l++ ) {
        printf("%d", l);
    }

    printf("\n");

    return 0;
}

int
output_diamond(
    int diamond_size
)
{
    int i;
    int j;

    for ( i = 0 ; i < diamond_size; i++ ) {
        output_diamond_line(diamond_size, i);
    }

    for ( j = diamond_size ; j >= 0 ; j-- ) {
        output_diamond_line(diamond_size, j);
    }

    return 0;
}

int
main(
    int argc,
    char *argv[]
)
{
    int diamond_size;

    if (argc < 2)
    {
        printf("Invalid command line arguments.\n");
        return -1;
    }

    diamond_size = atoi(argv[1]);

    if (diamond_size < 1 || diamond_size > 9)
    {
        printf("Can not create diamond (s: %d).\n", diamond_size);
        return -1;
    }

    output_diamond(diamond_size);

    return 0;
}
