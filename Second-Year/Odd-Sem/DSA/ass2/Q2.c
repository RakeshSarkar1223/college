#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node* next;
} Node;

struct Node* createNode(int data){
    struct Node * node = (struct Node*)malloc(sizeof(struct Node));
    node->val = data;
    node->next = NULL;
    return node;
}

struct Node * insertBegin(struct Node* head, int val){
    struct Node* temp = createNode(val);
    temp->next = head;
    head = temp;
    return head;
}

struct Node* createCircularLL(int n){
    struct Node* head = NULL, *temp = NULL, *newNode;
    int i;
    for(i = 0 ; i <= n; i++){
        newNode = createNode(i);
        if(head == NULL){
            head = newNode;
            head->next = head;
            temp = head;
        }
        else {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }
    return head;
}

int josephus(int n, int k){
    struct Node *head = createCircularLL(n), *prev = NULL, *ptr = head;
    int i ;
    while(ptr->next != ptr){
        for(i = 0; i< k; i++){
            prev = ptr;
            ptr = ptr->next;
        }
        printf("Eliminated %d\n",ptr->val);

        prev->next = ptr->next;
        free(ptr);
        ptr = prev;
    }

    int survivor = ptr->val;
    free(ptr);
    return survivor;
}
int main(){
    // int n, k;
    // printf("Enter the value of n : ");
    // scanf("%d",&n);
    // printf("Enter the value of k : ");
    // scanf("%d",&k);
    // int ans = josephus(n, k);
    // printf("The winner is %d",ans);

    struct Node * head = createNode(3);
    head = insertBegin(head, 5);
    head = insertBegin(head, 2);
    head = insertBegin(head, 1);
    struct Node * temp = head;
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }

    return 0;
}