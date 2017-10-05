#include "matrix.h"
#include <assert.h>

static int null_column(matrix* mat, const unsigned j) {
    double product = 1.0;
    for (unsigned i = 1; i <= matrix_rows(mat); ++i) {
        product *= get(mat, i, j);
    }

    return product == 0;
}

//PRE : non null column, otherwise does nothing
static void swap_lines_to_get_non_null(matrix* mat, unsigned i, unsigned j) {
    for (unsigned k = 1; k <= matrix_rows(mat); ++k) {
        if (get(mat, k, j)) {
            swap_row(mat, i, k);
            return;
        }
    }
}

void matrix_row_reduce(matrix *mat) {
    const unsigned m = matrix_rows(mat); //Shortcuts
    const unsigned n = matrix_columns(mat);

    //Outputs a reduced echelon matrix : all lines start with 0,0,0,...,1,
    //each column with a 1 has all other elements = 0, 1s go to the right

    unsigned current_i = 1;

    while(1) { //Break inside
        for (unsigned j = 1; j <= n; ++j) {
            if (null_column(mat, j))
                continue;

            if (!get(mat, current_i, j)) {
                swap_lines_to_get_non_null(mat, current_i, j);
                assert(get(mat, current_i, j));
            }

            multiply_row(mat, current_i, 1.0/get(mat, current_i, j));
            //Make all the lines null in this column
            for (unsigned i = 1; i <= m; ++i) {
                if (i == current_i)
                    continue;

                add_row_combination(mat, i, current_i, -get(mat, i, j));
            }
            ++current_i;

        }
        break;

    }
}
