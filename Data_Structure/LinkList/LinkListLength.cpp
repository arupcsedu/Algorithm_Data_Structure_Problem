/*
Description: Find the length of link list in recursive way
Author: Arup KUmar Sarker
url:https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
*/

#include<stdio.h>
#include<malloc.h>

typedef struct LinkNode LNode;
struct LinkNode
{
    int data;
    LNode *next;

};

void pushToList(LNode **root, int data)
{
    LNode *newNode = (LNode*) malloc(sizeof(LNode));
    newNode->data = data;


    newNode->next = (*root);
    (*root) = newNode;
}

void printList(LNode *root)
{
    while(root != NULL)
    {
        printf(" %d ",root->data);
        root = root->next;
    }
}

int getCount(LNode *root)
{
    if(root == NULL)
        return 0;
    return 1 + getCount(root->next);
}
int main()
{
    LNode *head = NULL;
    pushToList(&head, 2);
    pushToList(&head,3);
    pushToList(&head,4);

    printList(head);
    printf("\nLength of the List: %d\n",getCount(head));

    return 0;
}
