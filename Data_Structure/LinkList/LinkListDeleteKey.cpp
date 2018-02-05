/*
    Date: 05-02-2018
    Description: Link List node delete with given Key
    url: https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
*/

#include<stdio.h>
#include<malloc.h>

typedef struct ListNode LNode;

struct ListNode
{
    int data;
    LNode *next;

};

void pushToList(LNode **head, int data)
{
    LNode *tmp = (LNode*) malloc(sizeof(LNode));
    tmp->data = data;

    tmp->next = (*head);
    (*head) = tmp;
}

void deleteFromList(LNode **head, int key)
{
    LNode *tmp = (*head), *prev;

    /* 1. Check if the node is in head*/

    if(tmp != NULL && tmp->data == key)
    {
        (*head) = tmp->next;
        free(tmp);
        return;
    }

    /* 2. Iterate until the desired node*/

    while(tmp != NULL && tmp->data != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    /* 3. Check whether it is NULL or not*/
    if(tmp == NULL)
    {
        printf("Node with %d key Not found int the list\n",key);
        return;
    }
    /* 4. Move the next node to previous node*/
    prev->next = tmp->next;
    free(tmp);
}

void printList(LNode *head)
{
    while(head)
    {
        printf(" %d ",head->data);
        head = head->next;
    }
}

int main()
{
    LNode *head = NULL;
    pushToList(&head, 7);
    pushToList(&head, 1);
    pushToList(&head,3);
    pushToList(&head,2);

    printf("Created List:\n");
    printList(head);

    deleteFromList(&head, 1);

    printf("\nList After Delete Node\n");
    printList(head);
    return 0;
}
