#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

// find kth from last...
struct Node *findKthNode(struct Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct Node *kth = head;
    for (int i = 0; i < k; i++)
    {
        if (kth == NULL)
            return NULL;
        kth = kth->next;
    }
    struct Node *ans = head;
    while (kth != NULL)
    {
        kth = kth->next;
        ans = ans->next;
    }
    return ans;
}

// 2.Write a program to move the last node of a singly linked list to the 1st position.

struct Node *moveLasttoFirst(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        prev = curr;
    }
    if (prev == NULL)
        return NULL;
    prev->next = NULL;
    curr->next = head;
    head = curr;
    return head;
}

// 3.	Write a program to find the address of the middle node in a singly linked list.

struct Node *findMid(struct Node *head)
{
    if (head == NULL)
        return NULL;
    struct Node *slow = head;
    struct Node *fast = head;
    fast = fast->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// 4.	Write a program to detect a cycle in a singly linked list.
int detectCycle(struct Node *head)
{
    if (head == NULL)
        return 0;
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

// 5.	Write a program to find the address of the 1st intersecting node in a singly linked list with which another singly linked list is attached.
int isAttached(struct Node *head1, struct Node *head2)
{
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return 1;
        if (temp1 == NULL)
            temp1 = head2;
        if (temp2 == NULL)
            temp2 = head1;
    }
    return 0;
}

// 6.	Write a program to merge two sorted singly linked lists.

struct Node *mergeSortedList(struct Node *head1, struct Node *head2)
{
    struct Node *ans = createNode(-1);
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    struct Node *temp3 = ans;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val <= temp2->val)
        {
            ans->next = temp1;
            ans = temp1;
            temp1 = temp1->next;
        }
        else if (temp1->val > temp2->val)
        {
            ans->next = temp2;
            ans = temp2;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        ans->next = temp1;
        ans = temp1;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        ans->next = temp2;
        ans = temp2;
        temp2 = temp2->next;
    }
    return ans->next;
}

// 7.	Write a program for binary search in a singly linked list.

struct Node *getBinaryMid(struct Node *start, struct Node *end)
{
    if (start == NULL)
        return NULL;
    struct Node *slow = start;
    struct Node *fast = start;
    fast = fast->next;
    while (fast != end)
    {
        fast = fast->next;
        if (fast != end)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

struct Node *binarySearch(struct Node *head, int val)
{
    struct Node *start = head;
    struct Node *end = NULL;

    while (start != end)
    {
        struct Node *mid = getBinaryMid(start, end);

        if (mid->val == val)
        {
            return mid;
        }
        else if (mid->val > val)
        {
            end = mid;
        }
        else
        {
            start = mid->next;
        }
    }
    return NULL;
}

// 8.	Write a program to add a node with data x at the end of a circular doubly linked list.

struct DNode{
    int val;
    struct DNode* next;
    struct DNode* prev;
};

struct DNode* createDLLNode(int val){
    struct DNode* head = (struct DNode*) malloc(sizeof(struct DNode));
    head->val = val;
    head->next = head;
    head->prev = head;
    return head;
}

struct DLL{
    struct DNode* head;
    struct DNode* tail;
};

struct DLL* insertEnd(struct DLL * head, int x){
    struct DNode* temp = createDLLNode(x);
    if(head== NULL){
        head = (struct DLL*)malloc(sizeof(struct DLL));
        head->head = temp;
        head->tail = temp;
        return head;
    }
    temp->prev = head->tail;
    temp->next = head->head;

    head->tail->next = temp;
    head->head->prev = temp;
    head->tail = temp;
    return head;
}