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

    output_whitespace(diamond_size - current_line);

    for ( i = 1 ; i < current_line ; i++ ) {
        printf("#");
    }

    for ( i = 0 ; i < current_line ; i++ ) {
        printf("#");
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

    for ( j = diamond_size ; j > 0 ; j-- ) {
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

    if (diamond_size < 1)
    {
        printf("Can not create diamond (s: %d).\n", diamond_size);
        return -1;
    }

    output_diamond(diamond_size);

    return 0;
}
