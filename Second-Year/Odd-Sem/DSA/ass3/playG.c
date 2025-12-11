#include<stdio.h>
#include<stdlib.h>

// typedef struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// }Node;

// struct Node* createNode(int data){
//     struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// int search(Node *root, int val){
//     if(root == NULL) return -1;

//     if(root->data == val) return 0;

//     int leftS = search(root->left, val);
//     int rightS = search(root->right, val);

//     if(leftS == -1 && rightS == -1) return -1;
//     else if(leftS != -1) return leftS + 1;
//     else if(rightS != -1) return rightS + 1;
     
//     return -1;
// }


// struct Node*  createFromPreOrder(int arr[], int n){
//     static int idx = -1;
//     idx++;
//     if(idx >= n || arr[idx] == -1){
//         return NULL;
//     }
//     struct Node * root = createNode(arr[idx]);
//     root->left = createFromPreOrder(arr, n);
//     root->right = createFromPreOrder(arr, n);
//     return root;
// }

// struct Node* createNodefromInorder(int *arr, int i, int j){
//     if(i > j) return NULL;
//     int mid = (i + j) / 2;
//     struct Node *root = createNode(arr[mid]);
//     root->left = createNodefromInorder(arr, i, mid - 1);
//     root->right = createNodefromInorder(arr, mid + 1, j);
//     return root;
// }

// void preorder(struct Node * root){
//     if(root == NULL) return;
//     printf("%d ",root->data);
//     preorder(root->left);
//     preorder(root->right);
// }


// int search2(struct Node *root, int key){
//     if(root == NULL){
//         return -1;
//     }
//     if(root->data == key){
//         return 0;
//     }
//     int leftS = search2(root->left, key);
//     int rightS = search2(root->right, key);
//     if(leftS == -1 && rightS == -1){
//         return -1;
//     }
//     else if(leftS == -1){
//         return rightS + 1;
//     }
//     else if(rightS == -1){
//         return leftS + 1;
//     }
//     return -1;
// }

// //successor
// int successor(struct Node* root, int val){
//     struct Node *thatNode = search_for_Node(root, val);
//     int ans = -1;
//     if(thatNode->right != NULL){
//         struct Node *curr = thatNode->right;
//         while(curr->left != NULL){
//             curr = curr->left;
//         }
//         ans = curr->data;
//         return ans;
//     }
//     return ans;
// }

// int predeccor(struct Node *root, int val){
//     struct Node *thatNode = search_for_Node(root,val);
//     int ans = -1;
//     if(thatNode->left != NULL){
//         struct Node *curr = thatNode->left;
//         while(curr->right != NULL){
//             curr = curr->right;
//         }
//         ans = curr->data;
//         return ans;
//     }
//     return ans;
// }

// struct Node* search_for_Node(struct Node* root, int val){
//     if(root == NULL) return NULL;
//     if(root->data == val) return root;
//     struct Node *leftN =  search_for_Node(root->left, val);
//     if(leftN != NULL) return leftN;
//     return search_for_Node(root->right, val);
// }

// struct Node* insert(struct Node *root, int val){
//     if(root == NULL) {
//         return createNode(val);
//     }
//     else if(root->data < val){
//         root->right = insert(root->right, val);
//     }
//     else if(root->data > val){
//         root->left = insert(root->left, val);
//     }
//     return root;
// }


// struct Node* delete(struct Node *root, int val){
//     if(root == NULL){
//         return NULL;
//     }
//     else if(root->data > val){
//         root->left = delete(root->left, val);
//     }
//     else if(root->data < val){
//         root->right = delete(root->right, val);
//     }
//     else {
//         //case -1
//         if(root->left == NULL && root->right == NULL){
//             return NULL;
//         }
//         //case -2
//         if(root->left != NULL){
//             return root->left;
//         }
//         else if(root->right != NULL){
//             return root->right;
//         }
//         //case -3
//         else {
//             int succsr = successor(root, root->data);
//             root->data = succsr;
//             delete(root->right, succsr);
//         }
//     }
// }

//insertion sort
void insertion(int *arr, int n){
    for(int i = 1; i< n; i++){
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

//selection sort
void selection(int *arr, int n){
    for(int i = 0; i< n -1 ; i++){
        int curr = i;
        for(int j = i + 1; j < n;j++){
            if(arr[curr] > arr[j]){
                curr = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[curr];
        arr[curr] = temp;
    }
}

//bubble sort
void bubble(int *arr, int n){
    for(int i = 0; i< n  ; i++){
        for(int j = 0 ; j < n - i - 1; j++){
            if(arr[j + 1] > arr[j]){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//
int main(){
    // Node *root = createNode(5);
    // root->left = createNode(3);
    // root->left->left = createNode(2);
    // root->left->right = createNode(4);
    // root->right = createNode(7);
    // root->right->left = createNode(6);
    // root->right->right = createNode(8);

    // printf("%d",search(root, 4));

    // int arr[] = {1, 2, 4, -1, -1, -1, 3, -1, 5, -1, -1};
    // int size = (int) sizeof(arr)/sizeof(arr[0]);
    // struct Node *rootp = createFromPreOrder(arr,size);
    // // preorder(rootp);

    int *arr = (int *)malloc(5 * sizeof(int)); // single pointer allocation

    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    selection(arr, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}