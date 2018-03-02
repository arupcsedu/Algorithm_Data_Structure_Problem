/*
    Date: 02/03/2018
    Description: Reverse a Link List
    Author: Arup KUmar Sarker
    URL: https://www.geeksforgeeks.org/reverse-a-linked-list/
*/

#include<stdio.h>
#include<malloc.h>


typedef struct List_link Llist;

struct List_link
{
    int data;
    Llist *next;
};

void reverseList(Llist **head)
{
    Llist *prev = NULL;
    Llist *cur = (*head);
    Llist *next = cur->next;

    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;

    }
    (*head) = prev;
}
void pushToList(Llist **headref, int val)
{
    Llist *newNode = (Llist *) malloc(sizeof(Llist));
    newNode->data = val;
    newNode->next = (*headref);
    (*headref) = newNode;
}

void printList(Llist *head)
{
    while(head != NULL)
    {
        printf(" %d ", head->data);
        head = head->next;
    }
}

int main()
{
    Llist *head = NULL;
    pushToList(&head, 1);
    pushToList(&head, 2);
    pushToList(&head, 3);
    pushToList(&head, 4);
    pushToList(&head, 5);
    pushToList(&head, 6);
    printf("Print the list:\n");
    printList(head);
    printf("\nPrint AFter reverse the list:\n");
    reverseList(&head);
    printList(head);
    return 0;
}
