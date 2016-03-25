/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int linkedListMedian(struct node *head) {
	struct node*temp, *temp1 = head, *temp2 = head, *temp3 = head, *temp4 = head, *temp5;
	int count = 0,i=1,mid;
	temp = head;
	if (temp == NULL)
		return -1;
	while (temp2 != NULL)
	{
		count++;
		temp2 = temp2->next;
	}
	if (count % 2 == 0)
	{
		while (i < count / 2)
		{
			temp3 = temp3->next;
			i++;
		}
		mid = ((temp3->num) + (temp3->next->num)) / 2;
		return mid;
	}
	else
	{
	while (temp1->next != NULL)
	{
		temp = temp->next; 
		temp1 = temp1->next->next;
	}
	mid = temp->num;
	return mid;
	}
}
