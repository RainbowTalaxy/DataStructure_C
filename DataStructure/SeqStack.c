//written by talaxy

#include<stdlib.h>
#define SEQSTACKMAX 10
#define SEQSTACKNUL -1

typedef int type_st;

typedef struct {
    type_st data[SEQSTACKMAX];
    int top;
} SeqStack;

SeqStack * create_seqstack() {
    SeqStack * stack = (SeqStack *) malloc(sizeof(SeqStack));
    stack->top = -1;
    return stack;
}

int empty_seqstack(SeqStack * stack) {
    if (stack->top == -1) return 1;
    else return 0;
}

type_st top_seqstack(SeqStack * stack) {
    if (empty_seqstack(stack)) return SEQSTACKNUL;
    else return stack->data[stack->top];
}

int full_stack(SeqStack * stack) {
    if (stack->top == SEQSTACKMAX - 1) return 1;
    else return 0;
}

void push_seqstack(SeqStack * stack, type_st value) {
    if (!full_stack(stack)) {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

void pop_seqstack(SeqStack * stack) {
    if (!empty_seqstack(stack)) {
        stack->top--;
    }
}

void delete_seqstack(SeqStack * stack) {
    free(stack);
}