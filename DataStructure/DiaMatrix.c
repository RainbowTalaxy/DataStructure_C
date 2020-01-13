//written by talaxy

#include<stdio.h>
#include<stdlib.h>
#define DIASIZE 10
//DIAWIDTH must be an odd
#define DIAWIDTH 5

typedef int type_dmx;

typedef struct {
    type_dmx data[(DIASIZE - 1) * DIAWIDTH + 2];
} DiaMatrix;

int size_diamatrix() {
    return (DIASIZE - 1) * DIAWIDTH + 2;
}

DiaMatrix * create_diamatrix(int nil, int c) {
    DiaMatrix * matrix = (DiaMatrix *) malloc(sizeof(DiaMatrix));
    for (int i = 0; i < size_diamatrix() - 1; i++) {
        matrix->data[i] = nil;
    }
    matrix->data[size_diamatrix() - 1] = c;
    return matrix;
}

int valid_diamatrix(int i, int j) {
    int det = j - i;
    if (det <= DIAWIDTH / 2 && det >= -DIAWIDTH / 2) return 1;
    else return 0;
}

int index_diamatrix(int i, int j) {
    if (valid_diamatrix(i, j)) return DIAWIDTH * i + (j - i);
    else return size_diamatrix() - 1;
}

void assign_diamatrix(DiaMatrix * matrix, int i, int j, type_dmx value) {
    if (valid_diamatrix(i, j)) matrix->data[index_diamatrix(i, j)] = value;
}

type_dmx get_diamatrix(DiaMatrix * matrix, int i, int j) {
    return matrix->data[index_diamatrix(i, j)];
}

void print_trimatrix(DiaMatrix * matrix) {
    for (int i = 0; i < DIASIZE; i++) {
        if (i) printf("\n");
        printf("[ ");
        for (int j = 0; j < DIASIZE; j++) {
            printf("%d ", get_diamatrix(matrix, i, j));
        }
        printf("]");
    }
}