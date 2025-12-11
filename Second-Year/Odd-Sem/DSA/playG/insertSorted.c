#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node * next;
};

struct Node * createNode(int val){
    struct Node * temp ;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}



