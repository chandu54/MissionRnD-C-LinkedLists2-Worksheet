/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	struct node*temp, *newnode, *temp1;
	int j = 1;
	int count = 0, i = 1, c = 0;
	temp = head;
	temp1 = head;
	if (temp == NULL || K <= 0)
		return NULL;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (K > count)
		return head;
	while (temp1 != NULL)
	{
		if ((i == K*j + c))
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->num = K;
			newnode->next = temp1->next;
			temp1->next = newnode;
			c++;
			j++;
		}
		i++;
		temp1 = temp1->next;
	}
	return head;
}

