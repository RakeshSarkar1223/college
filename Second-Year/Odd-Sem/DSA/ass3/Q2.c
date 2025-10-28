#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

static int i = -1;
struct Node* preOrder(int *arr){
    i++;
    if(arr[i] == -1){
        return NULL;
    }
    struct Node* root = createNode(arr[i]);
    root->left = preOrder(arr);
    root->right = preOrder(arr);
    return root;
}


int main(){
    int arr[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    struct Node* root = preOrder(arr);
    printf("%d",root->data);
    return 0;
}