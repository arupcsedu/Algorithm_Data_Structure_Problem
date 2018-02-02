/*
File Name: LinkList.cpp
Author : Arup Kumar Sarker
Description: Link list create and insert(begining of the node, insert after a node and apopend at the end of link list)
url: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
*/

#include<stdio.h>
#include<malloc.h>

typedef struct Node Node_l;
struct Node
{
    int data;
    Node_l *next;
};

/*Push the Node at the begining of the Link List; */

void pushATBegin(Node_l **head, int data)
{
    /* 1. Allocate a node*/
    Node_l *tmp = (Node_l*) malloc(sizeof(Node_l));

    /* 2. Assign the Data*/
    tmp->data = data;
    /* 3. Assign/copy head address to the new node text*/
    tmp->next = (*head);
    /* 4. Now assign New Node to replace head*/
    (*head) = tmp;
}

/* Insert a node after a given node*/

void insertAfter(Node_l *prevNode, int data)
{
    /* 1. Check the node whether it is NULL or not*/
    if(prevNode == NULL)
    {
        printf("Node  is NULL and cannot be inserted\n");
        return;
    }

    /* 2. Allocate a Node*/
    Node_l *tmp = (Node_l*) malloc(sizeof(Node_l));

    /* 3. Assign the Data*/
    tmp->data = data;

    /* 4. Assign Previous Node next pointer to new node*/
    tmp->next = prevNode->next;

    /* 5. Move previous node to new node*/
    prevNode->next = tmp;
}

/* Append a node at the last of link list*/

void appendATLast(Node_l **head, int data)
{
    /* 1. Create a new Node with allocation*/
    Node_l *tmp = (Node_l*) malloc(sizeof(Node_l));

    /* 2. Assign the Data*/
    tmp->data = data;

    /* 3. Assign new Node next pointer to NULL*/
    tmp->next = NULL;

    /* 4. Check if head is NULL or not. That means it is first Node*/
    if((*head) == NULL)
    {
        (*head) = tmp;
        return;
    }

    /* 5. Declare a new node for iteration*/
    Node_l *last = (*head);

    /* 6. Iterate the new Node*/
    while(last->next)
        last = last->next;

    /* 7. Assign the new node to the last Node*/
    last->next = tmp;
    return;
}

/*Print Link List*/
void printLinkList(Node_l *node)
{
    while(node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    Node_l *head = NULL;

    appendATLast(&head, 6);
    appendATLast(&head, 7);
    appendATLast(&head, 1);
    appendATLast(&head, 4);
    appendATLast(&head, 8);
    appendATLast(&head, 9);
    appendATLast(&head, 3);
    appendATLast(&head, 10);
    printf("This link list is:\n");
    printLinkList(head);
    return 0;
}
