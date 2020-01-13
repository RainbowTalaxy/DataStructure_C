//written by talaxy

#include<stdlib.h>
#define LINKSTACKNUL -1

typedef int type_lt;

typedef struct Node {
    type_lt data;
    struct Node * pre;
} LinkStack;

LinkStack * create_linkstack() {
    LinkStack * stack = (LinkStack *) malloc(sizeof(LinkStack));
    stack->data = LINKSTACKNUL;
    stack->pre = NULL;
    return stack;
}

int empty_linkstack(LinkStack * stack) {
    if (stack->pre) return 0;
    else return 1;
}

int top_linkstack(LinkStack * stack) {
    return stack->data;
}

void push_linkstack(LinkStack * stack, type_lt value) {
    LinkStack * p = (LinkStack *) malloc(sizeof(LinkStack));
    p->data = stack->data;
    stack->data = value;
    p->pre = stack->pre;
    stack->pre = p;
}

void pop_linkstack(LinkStack * stack) {
    if (!empty_linkstack(stack)) {
        LinkStack * p = stack->pre;
        stack->data = p->data;
        stack->pre = p->pre;
        free(p);
    }
}

void delete_linkstack(LinkStack * stack) {
    LinkStack * p;
    while (stack) {
        p = stack->pre;
        free(stack);
        stack = p;
    }
}