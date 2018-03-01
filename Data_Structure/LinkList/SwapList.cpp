/*
    Date: 1/3/2018
    Description: Swap Node in the link list without swaping data
    Author: Arup Kumar Sarker
    url: https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
*/

#include<stdio.h>
#include<malloc.h>

typedef struct List_s Slist;

struct List_s
{
    int data;
    Slist *next;
};

//Functions to Swap the value of X and Y without changing data

void swapNode(Slist **head, int x, int y)
{
    //1. If x and y are same, no need to swap. Return
    if(x == y)
        return;

    //2. Set the pointer and traverse until the X node find
    Slist *prevX = NULL, *curX = *head;
    while(curX && curX->data != x)
    {
        prevX = curX;
        curX = curX->next;
    }

    //3. Set the pointer and traverse until y node find

    Slist *prevY = NULL, *curY = *head;
    while(curY && curY->data != y)
    {
        prevY = curY;
        curY = curY->next;
    }

    // 4. Check whether x is present in head or not
    if(prevX != NULL)
        prevX->next = curY;
    else
        (*head) = curY;

    //5. Check whether y is present in the head or not
    if(prevY != NULL)
        prevY->next = curX;
    else
        (*head) = curX;

    //6. SWAP the next Node
    Slist *tmp = curY->next;
    curY->next = curX->next;
    curX->next = tmp;
}

//Push To a Link List
void pushToList(Slist **head, int val)
{
    Slist *newNode = (Slist*) malloc(sizeof(Slist));
    newNode->data = val;

    newNode->next = (*head);
    (*head) = newNode;
}

// Print the List
void printList(Slist *head)
{
    while(head != NULL)
    {
        printf(" %d ",head->data);
        head = head->next;
    }
}

int main()
{
    Slist *head = NULL;
    pushToList(&head,7);
    pushToList(&head,6);
    pushToList(&head,5);
    pushToList(&head,4);
    pushToList(&head,3);
    pushToList(&head,2);
    pushToList(&head,1);
    pushToList(&head,0);

    //print the list
    printf("List:\n");
    printList(head);
    swapNode(&head, 2,5);
    printf("\nList:\n");
    printList(head);

    return 0;
}
