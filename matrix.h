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
#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix matrix;
matrix* new_matrix(unsigned rows, unsigned columns);
void delete_matrix(matrix* src);
void print_matrix(matrix* src);
//swapping row is in constant time, swapping column is linear to rows number
void swap_row(matrix* src, unsigned fst, unsigned snd);
void swap_columns(matrix* src, unsigned fst, unsigned snd);
void multiply_row(matrix* src, unsigned i, double factor);
void multiply_column(matrix* src, unsigned j, double factor);
void set(matrix* src, unsigned i, unsigned j, double value);
double get(matrix* src, unsigned i, unsigned j);

#endif // MATRIX_H
