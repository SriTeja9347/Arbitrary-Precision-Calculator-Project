/*NAME:A.Sriteja
  DATE:10/12/2025
DESCRIPTION :Implementing arithmetic operations on numbers that exceed the standard fixed-precision limits
             of typical data types (like int, long, double).
             This project typically focuses on handling very large integers, often representing them using
             data structures like linked lists or arrays. */
#include "header.h"
int negative;
int sign1 = 1,sign2 = 1;

int main(int argc, char * argv[])
{
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL,*tailR=NULL;
	char option, operator;
	char ch;

	do
	{
		/* Code for reading the inputs */
		operator = argv[2][0];
		if (argc != 4)
		{
			printf("Usage: ./a.out <num1> <operator> <num2>\n");
			return 0;
		}

		if(read_and_validate(argc, argv) == FAILURE)
		{
			printf("Read and validation failed!!!\n");
			return 0;
		}

		// inserting elements in LINKED LIST.
		insert_element(&head1,&tail1,argv[1],&sign1);
		insert_element(&head2,&tail2,argv[3],&sign2);

		opretion_validation(&operator,&head1,&head2);
		/* Function for extracting the operator */
		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
				if((addition(&head1, &tail1, &head2,&tail2,&headR,&tailR))==FAILURE)
				{
					printf("Addition operation fail\n");
				}
				else
				{
					printf("Addition Successful.\n");
					Print_list_element(headR);
				}
				break;
			case '-':
				/* call the function to perform the subtraction operation */
				if((subtraction(&head1, &tail1, &head2,&tail2,&headR,&tailR))==FAILURE)
				{
					printf("subtraction operation fail\n");
				}
				else
				{
					printf("subtraction Successful.\n");
					Print_list_element(headR);
				}
				break;
			case 'x':
				/* call the function to perform the multiplication operation */

				if((multiplication(&head1, &tail1, &head2,&tail2,&headR,&tailR))==FAILURE)
				{
					printf("multiplication operation fail\n");
				}
				else
				{
					printf("multiplication Successful.\n");
					Print_list_element(headR);
				}
				break;
			case '/':
				// call the function to perform the division operation 
				if((division(&head1, &tail1, &head2,&tail2,&headR,&tailR))==FAILURE)
				{
					printf("Division operation fail\n");
				}
				else
				{
					printf("Division Successful.\n");
					Print_list_element(headR);
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
				break;
		}
		Delete_list(&head1,&tail1);
		Delete_list(&head2,&tail2);
		Delete_list(&headR,&tailR);
		printf("Want to continue? Press [yY | nN]: \n");
		scanf(" %c",&option);
		if(option == 'n' || option == 'N')
		{
			return 0;
		}
		printf("Witch Opretion you wont to execute. ( '+ ' '-' 'x' '/' )\n");
		scanf(" %c",&ch);
		argv[2][0]=ch;
	}while (option == 'y' || option == 'Y');

	return 0;
}
