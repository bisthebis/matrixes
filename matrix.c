/*
MIT License

Copyright (c) 2017 Boris Martin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct matrix {
    unsigned m, n;
    double **data;
};

matrix* new_matrix(unsigned rows, unsigned columns) {
    assert(rows * columns != 0);
    matrix* result = malloc(sizeof(matrix));
    if (!result)
        exit(EXIT_FAILURE);

    result->m = rows;
    result->n = columns;

    result->data = malloc(rows * sizeof(double*));
    for (unsigned i = 0; i < rows; ++i) {
        result->data[i] = malloc(columns * sizeof(double));
        for (unsigned j = 0; j < columns; ++j)
            result->data[i][j] = i == j ? 1.0 : 0.0;
    }

    return result;
}

void delete_matrix(matrix *src) {
    unsigned m = src->m;

    for (unsigned i = 0; i < m; ++i) {
        free(src->data[i]);
    }

    free(src->data);
    free(src);
}

void print_matrix(matrix *src) {
    for (unsigned i = 0; i < src->m; ++i) {
        for (unsigned j = 0; j < src->n; ++j) {
            printf("%4.3f ", src->data[i][j]);
        }
        printf("\n");
    }
}

void swap_row(matrix *src, unsigned fst, unsigned snd) {
    assert (fst <= src->m && snd <= src->m);
    assert (fst-- && snd--); //Reduce by one and esnure it was NOT 0. (Index conversion)

    double* temporary = src->data[fst];
    src->data[fst] = src->data[snd];
    src->data[snd] = temporary;
}
static void swapd(double* a, double* b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_columns(matrix *src, unsigned fst, unsigned snd) {
    assert (fst <= src->n && snd <= src->n);
    assert (fst-- && snd--); //Reduce by one and esnure it was NOT 0. (Index conversion)

    for (unsigned i = 0; i < src->m; ++i) {
        swapd(&(src->data[i][fst]), &(src->data[i][snd]));
    }

}

void multiply_row(matrix *src, unsigned i, double factor) {
    assert(i <= src->m);
    assert(i-- > 0);

    for (unsigned j = 0; j < src->n; ++j) {
        src->data[i][j] *= factor;
    }
}

void multiply_column(matrix *src, unsigned j, double factor) {
    assert(j <= src->n);
    assert(j-- > 0);

    for (unsigned i = 0; i < src->m; ++i) {
        src->data[i][j] *= factor;
    }
}

void set(matrix *src, unsigned i, unsigned j, double value) {
    assert(i <= src->m && j <= src->n);
    assert(i-- > 0 && j-- > 0);

    src->data[i][j] = value;
}

double get(matrix *src, unsigned i, unsigned j) {
    assert(i <= src->m && j <= src->n);
    assert(i-- > 0 && j-- > 0);

    return src->data[i][j];
}

void add_row_combination(matrix *src, unsigned target, unsigned row_to_add, double factor) {
    assert(target <= src->m && row_to_add <= src->m);
    assert(target-- > 0 && row_to_add-- > 0);

    for (unsigned j = 0; j < src->n; ++j) {
        src->data[target][j] += factor * src->data[row_to_add][j];
    }
}

void add_column_combination(matrix *src, unsigned target, unsigned column_to_add, double factor) {
    assert(target <= src->n && column_to_add <= src->n);
    assert(target-- > 0 && column_to_add-- > 0);

    for (unsigned i = 0; i < src->m; ++i) {
        src->data[i][target] += factor * src->data[i][column_to_add];
    }
}

unsigned matrix_columns(matrix *mat) {
    return mat->n;
}

unsigned matrix_rows(matrix *mat) {
    return mat->m;
}
