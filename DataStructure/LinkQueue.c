//written by talaxy

#include<stdlib.h>
#define LINKQUEUENUL -1

typedef int type_lq;

typedef struct Node {
    type_lq data;
    struct Node * next;
} Node;

typedef struct {
    Node * head, * rear;
} LinkQueue;

Node * node_linkqueue() {
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = LINKQUEUENUL;
    node->next = NULL;
    return node;
}

LinkQueue * create_linkqueue() {
    Node * node = node_linkqueue();
    LinkQueue * queue = (LinkQueue *) malloc(sizeof(LinkQueue));
    queue->head = queue->rear = node;
    return queue;
}

int empty_linkqueue(LinkQueue * queue) {
    if (queue->head == queue->rear) return 1;
    else return 0;
}

type_lq front_linkqueue(LinkQueue * queue) {
    if (empty_linkqueue(queue)) return LINKQUEUENUL;
    else return queue->head->data;
}

void push_linkqueue(LinkQueue * queue, type_lq value) {
    Node * node = node_linkqueue();
    queue->rear->data = value;
    queue->rear->next = node;
    queue->rear = node;
}

void pop_linkqueue(LinkQueue * queue) {
    if (!empty_linkqueue(queue)){
        Node * p = queue->head;
        queue->head = queue->head->next;
        free(p);
    }
}

void delete_linkqueue(LinkQueue * queue) {
    LinkQueue * p;
    while(queue->head) {
        p = queue->head->next;
        free(queue->head);
        queue->head = p;
    }
    free(queue);
}