#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ----------- Function Declarations (Prototypes) -------------
struct Node* createTree();
void inorder(struct Node* root);
void preorder(struct Node* root);
void postorder(struct Node* root);

// ----------- Function Definitions ----------------------------
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// ----------- Main Function (Menu) ----------------------------
int main() {
    struct Node* root = NULL;
    int choice;

    do {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Create Binary Tree\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                root = createTree();
                printf("Binary tree created successfully!\n");
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else {
                    printf("In-order Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else {
                    printf("Pre-order Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else {
                    printf("Post-order Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}
