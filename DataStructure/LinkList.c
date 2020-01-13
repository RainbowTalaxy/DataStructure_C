//written by talaxy

#include<stdio.h>
#include<stdlib.h>

typedef int type_ll;

typedef struct Node {
    type_ll data;
    struct Node * next;
} LinkList;

LinkList * create_linklist() {
    LinkList * list = (LinkList *) malloc(sizeof(LinkList));
    list->next = NULL;
    return list;
}

int empty_linklist(LinkList * list) {
    if (list->next) return 0;
    else return 1;
}

int size_linklist(LinkList * list) {
    int size = 0;
    LinkList * p = list->next;
    while (p) {
        size++;
        p = p->next;
    }
    return size;
}

LinkList * get_linklist(LinkList * list, int pos) {
    if (pos < -1) return NULL;
    LinkList * p = list;
    for (int i = 0; p != NULL && i <= pos; i++) {
        p = p->next;
    }
    return p;
}

void add_linklist(LinkList * list, type_ll value) {
    LinkList * p = list;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = (LinkList *) malloc(sizeof(LinkList));
    p = p->next;
    p->data = value;
    p->next = NULL;
}

void insert_linklist(LinkList * list, int pos, type_ll value) {
    LinkList * p = get_linklist(list, pos);
    if (p && pos >= 0)  {
        LinkList * q = (LinkList *) malloc(sizeof(LinkList));
        q->data = p->data;
        q->next = p->next;
        p->data = value;
        p->next = q;
    }
}

void remove_linklist(LinkList * list, int pos) {
    LinkList * p = get_linklist(list, pos - 1);
    if (p && p->next) {
        LinkList * q = p->next;
        p->next = q->next;
        free(q);
    }
}

void assign_linklist(LinkList * list, int pos, type_ll value) {
    LinkList * p = get_linklist(list, pos);
    p->data = value;
}

void reverse_linklist(LinkList * list) {
    if (empty_linklist(list)) return;
    LinkList * p = list->next, * pre = list, * q;
    while (p) {
        q = p->next;
        p->next = pre;
        pre = p;
        p = q;
    }
    list->next->next = NULL;
    list->next = pre;
}

int find_linklist(LinkList * list, type_ll value) {
    LinkList * p = list->next;
    int pos = -1;
    for (int i = 0; p != NULL; i++) {
        if (p->data == value) {
            pos = i;
            break;
        }
        p = p->next;
    }
    return pos;
}

void delete_linklist(LinkList * list) {
    LinkList * p = list, * q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
}

void print_linklist(LinkList * list) {
    list = list->next;
    int flag = 1;
    printf("[");
    while (list != NULL) {
        if (flag) flag = 0;
        else printf(", ");
        printf("%d", list->data);
        list = list->next;
    }
    printf("]\n");
}