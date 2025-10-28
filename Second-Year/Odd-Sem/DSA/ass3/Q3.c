#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
}Node;

struct Node* createNode(int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Node * insertTree(struct Node * root, int val){
    if(root == NULL){
        struct Node * temp = createNode(val);
        return temp;
    }

    if(root->data > val){
        root->left = insertTree(root->left , val);
    }

    if(root->data < val){
        root->right = insertTree(root->right, val);
    }

    return root;
}


int search(struct Node * root , int key){
    //base case
    if(root == NULL){
        return 0;
    }

    if(root->data == key){
        return 1;
    }

    else if(root->data > key){
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

//this search is for finding that node of successor and predessor


struct Node * search2(struct Node * root , int key){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    else if(root->data > key){
        return search2(root->left, key);
    }
    else {
        return search2(root->right, key);
    }
}


int predecessor(struct Node * root){

    if(root->left == NULL){
        return -1;
    }
    else {
        struct Node *curr = root->left;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        return curr->data;
    }
}

int successor(struct Node * root){//because successor is the left most node of the right subtree of that node
    struct Node * rightN = root->right;
    if(rightN == NULL){
        return -1;
    }
    else {
        while(rightN->left != NULL){
            rightN = rightN->left;
        }
        return rightN->data;
    }
}

void inorder(struct Node * root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int arr[] = {5, 3, 2, 4, 8, 10};
    struct Node * root = NULL;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i< size ; i++){
        root = insertTree(root, arr[i]);
    }

    inorder(root);

    printf("\n");
    int found = search(root, 7);
    if(found == 1){
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    struct Node * root1 = search2(root, 5);
    printf("%d \n",predecessor(root1));
    printf("%d \n",successor(root1));

    return 0;
}

