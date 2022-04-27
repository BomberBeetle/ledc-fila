#include "queue.h"
#include <stdlib.h>

int push(Queue *q, char c){
    if (q->size >= 30){
        return -1;
    }
    else{
        struct cNode *prevRoot = q->root;

        q->root = malloc(sizeof(struct cNode));

        q->root->val = c;
        q->root->next = prevRoot;
        q->root->prev = NULL;
        
        if(prevRoot != NULL) prevRoot->prev = q->root;

        q->size++;

        return 1;
    }
}

char pop(Queue* q){
    if (q->size == 0) {
        return '\0';
    }
    else{
        struct cNode *curNode = q->root;

        while(curNode->next != NULL){
            curNode = curNode->next;
        }

        curNode->prev->next = NULL;
        q->size--;
        char c = curNode->val;
        free(curNode);
        return c;
    }
}

void empty(Queue* q){
    q->size = 0;
    struct cNode *curNode = q->root;
    struct cNode *prevNode;

    q->root = NULL;

    while(curNode != NULL){
        prevNode = curNode;
        curNode = prevNode->next;
        free(prevNode);
    }
}