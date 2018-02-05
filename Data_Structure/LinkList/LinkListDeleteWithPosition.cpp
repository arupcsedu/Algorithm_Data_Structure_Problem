/*
    Date: 05-02-2018
    Author: Arup Kumar Sarker
    url: https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
*/

#include<stdio.h>
#include<malloc.h>


typedef struct LinkNode Node_t;

struct LinkNode
{
    int data;
    Node_t *next;
};

/* Create a Link List by inserting node into head*/
void pushToLinkList( Node_t **head, int data)
{
    Node_t *tmp = (Node_t*) malloc(sizeof(Node_t));

    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void deleteNodeWithPosition( Node_t **head, int pos)
{
    Node_t *tmp = (*head);

    /* 1. Check if the position of Node is 0*/
    if(pos == 0)
    {
        if(tmp == NULL)
        {
            printf("List is empty\n");
            return;
        }
        else{
            (*head) = tmp->next;
            free(tmp);
            return;
        }
    }
    /* 2. Iterate until the given position */
    for(int i = 0; i<pos-1; i++)
        tmp = tmp->next;

    /*3. tmp->next is the node to be delete. Check whether it is NULL of not*/
    if(tmp == NULL || tmp->next == NULL)
    {
        printf("Node is not found in the list\n");
        return;
    }

    /* 4. save the next node pointer of tmp->next*/
    Node_t *node = tmp->next->next;

    /* 5. Free the node */
    free(tmp->next);

    /* 6. Assign Save Node to tmp->next*/

    tmp->next = node;

}

void printLinkList(Node_t *head)
{
    while(head)
    {
        printf(" %d ",head->data);
        head = head->next;
    }
}
int main()
{
    Node_t *head = NULL;
    pushToLinkList(&head, 7);
    pushToLinkList(&head, 1);
    pushToLinkList(&head, 3);
    pushToLinkList(&head, 2);
    pushToLinkList(&head, 8);

    printf("Create Link List\n");
    printLinkList(head);
    deleteNodeWithPosition(&head, 4);
    printf("\n Link List After delete\n");
    printLinkList(head);

    return 0;
}
