/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node* temp,*temp1;
	struct node* end = NULL;
	temp = head;
	if (temp == NULL)
		return NULL;
	if (temp->next == NULL)
		return head;
	end = NULL;
	while (temp != NULL)
	{
		temp1 = end;
		end = temp;
		temp = temp->next;
		end->next = temp1;
	}
	head = end;
	return head;
}
