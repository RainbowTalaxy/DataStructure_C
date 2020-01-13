//written by talaxy

#include<stdio.h>
#include<stdlib.h>
#define SYMSIZE 5

typedef int type_smx;

typedef struct {
    type_smx data[SYMSIZE * (SYMSIZE + 1) / 2];
} SymMatrix;

int size_symmatrix() {
    return SYMSIZE * (SYMSIZE + 1) / 2;
}

SymMatrix * create_symmatrix(type_smx nil) {
    SymMatrix * matrix = (SymMatrix *) malloc(sizeof(SymMatrix));
    for (int i = 0; i < size_symmatrix(); i++) {
        matrix->data[i] = nil;
    }
    return matrix;
}

int index_symmatrix(int i, int j) {
    int k;
    if (i < j) k = j * (j + 1) / 2 + i;
    else k = i * (i + 1) / 2 + j;
    return k;
}

void assign_symmatrix(SymMatrix * matrix, int i, int j, type_smx value) {
    matrix->data[index_symmatrix(i, j)] = value;
}

type_smx get_symmatrix(SymMatrix * matrix, int i, int j) {
    return matrix->data[index_symmatrix(i, j)];
}

void print_symmatrix(SymMatrix * matrix) {
    for (int i = 0; i < SYMSIZE; i++) {
        if (i) printf("\n");
        printf("[ ");
        for (int j = 0; j < SYMSIZE; j++) {
            printf("%d ", get_symmatrix(matrix, i, j));
        }
        printf("]");
    }
}