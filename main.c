#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


void loadString(Queue* q){
    empty(q);
    char newString[31];
    fgets(newString, 31, stdin);
    for(int i = 0; i < 30; i++){
        if(newString[i] == '\0' || newString[i] == '\n') break;
        push(q, newString[i]);
    }
}

void peekQueue(Queue* q){
    printf("\"");
    struct cNode *curNode = q->root;
    while(curNode != NULL){
        printf("%c", curNode->val);
        curNode = curNode->next;
    }
    printf("\"\n");
}

int main(int argc, char** argv){

    Queue q = {.root = NULL, .size = 0};

    int opt = 0;

    while(1){
        
        scanf("%d", &opt);

        switch(opt){
            case 1:
                getchar();
                loadString(&q);
                break;
            case 2:
                getchar();
                push(&q, getchar());
                break;
            case 3:
                pop(&q);
                break;
            case 4:
                peekQueue(&q);
                break;
            case 5:
                empty(&q);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("????? tá doido irmão??\n");
        }
    }
}