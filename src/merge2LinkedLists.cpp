/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node* temp1,*temp2,*result,*temp3,*temp4;
	struct node *root = NULL, *cur = NULL;
	int count1 = 0, count2 = 0;
	temp1 =temp3= head1;
	temp2 = temp4=head2;
	if (temp1 == NULL&&temp2 == NULL)
		return NULL;
	if(temp1 == NULL&&temp2 != NULL) 
		return head2;
	if (temp2 == NULL&&temp1 != NULL)
		return head1;
	while (temp3 != NULL&&temp4 != NULL)
	{
		result = (struct node*)malloc(sizeof(struct node));
		if (temp3->num < temp4->num)
		{
			result->num = temp3->num;
			temp3 = temp3->next;
			result->next = NULL;
		}
		else
		{
			result->num = temp4->num;
			temp4 = temp4->next;
			result->next = NULL;
		}
		if (root == NULL)
		{
			root = result;
			cur = root;
		}
		else
		{
			cur->next = result;
			cur = result;
		}
	}
	while (temp3 != NULL)
	{
		result = (struct node*)malloc(sizeof(struct node));
		result->num = temp3->num;
		 result->next=NULL;
		 cur->next = result;
		 cur = result;
		 temp3 = temp3->next;
	}
	while (temp4 != NULL)
	{
		result = (struct node*)malloc(sizeof(struct node));
		result->num = temp4->num;
		 result->next=NULL;
		 cur->next = result;
		 cur = result;
		 temp4 = temp4->next;
	}
	return root;
}
