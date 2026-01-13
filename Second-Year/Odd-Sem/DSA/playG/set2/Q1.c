#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->val = val;
    head->next = NULL;
    return head;
}

struct Node* insertNode(struct Node* head, int keyVal, int pos){
    struct Node*keyNode = createNode(keyVal);
    if(head == NULL){
        head = keyNode;
        return head;
    }
    if(pos == 1){
        keyNode->next = head;
        head = keyNode;
        return head;
    }

    struct Node *temp = head;
    for(int i = 0; i< pos - 1 && temp != NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("invalid pos\n");
        return head;
    }

    keyNode->next = temp->next;
    temp->next = keyNode;
    return head;
}

struct Node* reverse(struct Node * head){
    struct Node* curr = head;
    struct Node* prev= NULL;
    while(curr != NULL){
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void revPrint(struct Node* head){
    if(head == NULL) {
        printf("the list is null \n");
        return;
    }
    printList(reverse(head));
}

int count(struct Node * head){
    if(head == NULL) return 0;
    struct Node* temp = head;
    int c = 0;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }
    return c;
}


void printList(struct Node* head){
    if(head == NULL){
        printf("head is null \n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}