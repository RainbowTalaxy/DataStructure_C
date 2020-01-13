//written by talaxy

#include<stdio.h>
#include<stdlib.h>
#define SEQLISTMAX 100

typedef int type_sl;

typedef struct {
    type_sl data[SEQLISTMAX];
    int size;
} SeqList;

SeqList * create_seqlist() {
    SeqList * list = (SeqList *) malloc(sizeof(SeqList));
    list->size = 0;
    return list;
}

int empty_seqlist(SeqList * list) {
    if (list->size == 0) return 1;
    else return 0;
}

int full_seqlist(SeqList * list) {
    if (list->size >= SEQLISTMAX) return 1;
    else return 0;
}

void add_seqlist(SeqList * list, type_sl value) {
    if (!full_seqlist(list)) {
        list->data[list->size] = value;
        list->size++;
    }
}

void insert_seqlist(SeqList * list, int pos, type_sl value) {
    if (pos >= 0 && pos < list->size) {
        if (!full_seqlist(list)) {
            for (int i = list->size; i > pos; i--) {
                list->data[i] = list->data[i - 1];
            }
            list->data[pos] = value;
        }
        list->size++;
    }
}

void remove_seqlist(SeqList * list, int pos) {
    if (pos >= 0 && pos < list->size)  {
        list->size--;
        for (int i = pos; i < list->size; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
}

void assign_seqlist(SeqList * list, int pos, type_sl value) {
    if (pos >= 0 && pos < list->size) {
        list->data[pos] = value;
    }
}

int find_seqlist(SeqList * list, type_sl value) {
    int pos = -1;
    for (int i  = 0; i < list->size; i++) {
        if (list->data[i] == value) {
            pos = i;
            break;
        }
    }
    return pos;
}

void delete_seqlist(SeqList * list) {
    free(list);
}

void print_seqlist(SeqList * list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        if (i != 0) printf(", ");
        printf("%d", list->data[i]);
    }
    printf("]\n");
}