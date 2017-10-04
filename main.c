#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "matrix.h"

int main()
{
    matrix* mat = new_matrix(4, 4);


    print_matrix(mat);
    printf("Swapping \n");
    set(mat, 1, 2, 2.5);
    print_matrix(mat);

    delete_matrix(mat);

    return 0;
}
