/*
 * Author: Arup Kumar Sarker
 * Date: 01-12-2017
 * url: http://www.geeksforgeeks.org/quicksort-for-linked-list/
 * Description: Can we use same algorithm for Linked List?
	Following is C++ implementation for doubly linked list. The idea is simple, we first find out pointer to last node.
	Once we have pointer to last node, we can recursively sort the linked list using pointers to first and last nodes of linked list,
	similar to the above recursive function where we pass indexes of first and last array elements.
	The partition function for linked list is also similar to partition for arrays.
	Instead of returning index of the pivot element, it returns pointer to the pivot element.
	In the following implementation, quickSort() is just a wrapper function, the main recursive function is _quickSort() which is similar to quickSort() for array implementation.
 *
 */

#include<stdio.h>
#include<malloc.h>
#include<iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};
//Insert to doubly link list

void push_to_list(struct Node **head, int data)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->prev = NULL;

	temp->next = (*head);
	if(*head != NULL)
		(*head)->prev = temp;
	(*head) = temp;
}

// Print the list

void print_the_list(struct Node *head)
{
	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

//Find the last elements of an linklist
struct Node* find_last_elements(struct Node *head)
{
	while(head && head->next)
	{
		head = head->next;
	}
	return head;
}
// Swaping two value

void quick_swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
// Partition in doubly link list
struct Node* quick_partition(struct Node *l, struct Node *h)
{
	int x = h->data;
	struct Node *i = l->prev;
	for(Node *j = l; j != h; j = j->next)
	{
		if(j->data <= x)
		{
			i = (i == NULL) ? l : i->next; // It is like i++
			quick_swap(&(i->data), &(j->data));
		}
	}
	i = (i == NULL) ? l : i->next;
	quick_swap(&(i->data), &(h->data));
	return i;
}
// Quick sort recursion
void _quick_sort(struct Node *l, struct Node *h)
{
	if(h != NULL && l != h && l != h->next)
	{
		struct Node *pivot = quick_partition(l,h);
		_quick_sort(l, pivot->prev);
		_quick_sort(pivot->next,h);
	}
}

void _dlquick_sort(struct Node *head)
{
	struct Node *h = find_last_elements(head);
	_quick_sort(head,h);

}
int main()
{
	struct Node *a, *b = NULL;
	a = NULL;

	push_to_list(&a, 3);
	push_to_list(&a, 9);
	push_to_list(&a, 10);
	push_to_list(&a, 20);

	push_to_list(&a, 16);
	push_to_list(&a, 3);
	push_to_list(&a, 2);
	push_to_list(&a, 4);
	push_to_list(&a, 1);
	push_to_list(&a, 15);
	push_to_list(&a, 13);

	b = a;

	cout << "Print the list before sorting \n";
	print_the_list(b);

	_dlquick_sort(b);

	cout << "Print After the sorting\n";
	print_the_list(a);

	return 0;
}
