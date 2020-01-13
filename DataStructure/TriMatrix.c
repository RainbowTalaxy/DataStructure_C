//written by talaxy

#include<stdio.h>
#include<stdlib.h>
#define TRISIZE 10

typedef int type_tmx;

typedef struct {
    type_tmx data[TRISIZE * (TRISIZE + 1) / 2 + 1];
    int isUp;
} TriMatrix;

int size_trimatrix() {
    return TRISIZE * (TRISIZE + 1) / 2 + 1;
}

TriMatrix * create_trimatrix(int nil, int c, int isUp) {
    TriMatrix * matrix = (TriMatrix *) malloc(sizeof(TriMatrix));
    for (int i = 0; i < size_trimatrix() - 1; i++) {
        matrix->data[i] = nil;
    }
    matrix->data[size_trimatrix() - 1] = c;
    matrix->isUp = isUp;
    return matrix;
}

int valid_trimatrix(TriMatrix * matrix, int i, int j) {
    if ((matrix->isUp && i <= j) || (!matrix->isUp && i >= j)) {
        return 1;
    }
    else return 0;
}

int index_trimatrix(TriMatrix * matrix, int i, int j) {
    if (matrix->isUp) {
        if (i > j) return size_trimatrix() - 1;
        else return i * (2 * TRISIZE - i + 1) / 2 + j - i;
    }
    else {
        if (i < j) return size_trimatrix() - 1;
        else return i * (i + 1) / 2 + j;
    }
}

void assign_trimatrix(TriMatrix * matrix, int i, int j, type_tmx value) {
    if (valid_trimatrix(matrix, i, j)) {
        matrix->data[index_trimatrix(matrix, i, j)] = value;
    }
}

type_tmx get_trimatrix(TriMatrix * matrix, int i, int j) {
    return matrix->data[index_trimatrix(matrix, i, j)];
}

void print_trimatrix(TriMatrix * matrix) {
    for (int i = 0; i < TRISIZE; i++) {
        if (i) printf("\n");
        printf("[ ");
        for (int j = 0; j < TRISIZE; j++) {
            printf("%d ", get_trimatrix(matrix, i, j));
        }
        printf("]");
    }
}