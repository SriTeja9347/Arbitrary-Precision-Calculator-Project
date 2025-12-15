#include "header.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	if(*head1== NULL && *head2==NULL)   
	    	return FAILURE;
	
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	int carry = 0,result = 0;
	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 != NULL && temp2 == NULL){

			result=temp1->data + 0 + carry;

		}
		else if(temp1 == NULL && temp2 != NULL){

			result = temp2->data + 0 + carry;
		}
		else
		{
			result = temp1->data + temp2->data + carry;
		}

		carry = 0;
		if(result > 9)
		{
			carry = result / 10;
			result = result % 10;
		}
		insert_at_first(headR,tailR,result);

		if (temp1) 
			temp1 = temp1->prev;
		if (temp2)
		       	temp2 = temp2->prev;
	}
	if(carry)
		insert_at_first(headR,tailR,carry);

	return SUCCESS;
}

