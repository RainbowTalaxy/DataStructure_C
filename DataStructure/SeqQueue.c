//written by talaxy

#include<stdlib.h>
#define SEQQUEUEMAX 100
#define SEQQUEUENUL -1

typedef int type_sq;

typedef struct SeqQueue {
    type_sq data[SEQQUEUEMAX];
    int head, rear, size;
} SeqQueue;

SeqQueue * create_seqqueue() {
    SeqQueue * queue = (SeqQueue *) malloc(sizeof(SeqQueue));
    queue->head = queue->rear = queue->size = 0;
    return queue;
}

int empty_seqqueue(SeqQueue * queue) {
    if (queue->size) return 0;
    else return 1;
}

int full_seqqueue(SeqQueue * queue) {
    if (queue->size == SEQQUEUEMAX) return 1;
    else return 0;
}

type_sq front_seqqueue(SeqQueue * queue) {
    if (empty_seqqueue(queue)) return SEQQUEUENUL;
    else return queue->data[queue->head];
}

void push_seqqueue(SeqQueue * queue, type_sq value) {
    if (!full_seqqueue(queue)) {
        queue->data[queue->rear] = value;
        queue->rear = (queue->rear + 1) % SEQQUEUEMAX;
        queue->size++;
    }
}

void pop_seqqueue(SeqQueue * queue) {
    if (!empty_seqqueue(queue)) {
        queue->head = (queue->head + 1) % SEQQUEUEMAX;
        queue->size--;
    }
}

void delete_seqqueue(SeqQueue * queue) {
    free(queue);
}