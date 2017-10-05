#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "matrix.h"

int main()
{
    matrix* mat = new_matrix(3, 4);

    //Test matrix : 3x4
    /*
     *  3 5 8 2
     *  1 10 16 0
     *  8 0 0 9
     * */
    set(mat, 1, 1, 3); set(mat, 1, 2, 5); set(mat, 1, 3, 8); set(mat, 1, 4, 2);
    set(mat, 2, 1, 1); set(mat, 2, 2, 10); set(mat, 2, 3, 16); set(mat, 2, 4, 0);
    set(mat, 3, 1, 8); set(mat, 3, 2, 0); set(mat, 3, 3, 0); set(mat, 3, 4, 9);

    print_matrix(mat);

    printf("\nOperating... \n");

    add_row_combination(mat, 2, 1, -1.0/3);
    add_row_combination(mat, 3, 1, -8.0/3);
    multiply_row(mat, 1, 1.0/3);
    multiply_row(mat, 2, 1.0/get(mat, 2, 2));
    add_row_combination(mat, 1, 2, -get(mat, 1, 2));
    add_row_combination(mat, 3, 2, -get(mat, 3, 2));


    print_matrix(mat);

    delete_matrix(mat);

    return 0;
}
