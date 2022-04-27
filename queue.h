#pragma once

struct cNode{
    char val;
    struct cNode *next, *prev;
};

typedef struct{
    int size;
    struct cNode *root;
}Queue;

int push(Queue *, char);
char pop(Queue *);
void empty(Queue *);