/*
This part of the program is going to simuler les modules of the function
*/


#include<stdio.h>
#include"model.h"
#include"simulation.h"

// Choose in function of what is being tested

enum simulation_options {STACK, QUEUE, LINE};

#define SIMULATION LINE;

void main() 
{
	int choice = SIMULATION;

	switch (choice)
	{
	case STACK: test_stack(); break;
	case QUEUE: test_queue(); break;
	case LINE: test_list(); break;
	default:	break;
	}

	/*test_c();*/
	
	printf("\n\n");
	system("pause");
}


t_book simulate_book()
{
	t_book book;

	book.genre = HISTORY;
	strcpy(book.title, "Title test");
	strcpy(book.authors_name, "Author's name test");
	strcpy(book.authors_surname, "Author's surname test");
	book.num_pg = 150;
	book.isbn = 100;
	book.bBorrowed = AVAIABLE;
	
	return book;
}


//This part is for testing the queue
void test_queue()
{
	t_queue queue;

	t_element book;

	book = simulate_book();
	//book = simuler_book();

	init_queue(&queue);

	push_queue(&queue, book);

	push_queue(&queue, book);

	pop_queue(&queue);

	pop_queue(&queue);

}


//This part is for testing the stack
void test_stack()
{
	t_stack stack;
	t_element book;

	book = simulate_book();

	init_stack(&stack);

	push_stack(&stack, book);

	push_stack(&stack, book);

	stack_empty(&stack);

	pop_stack(&stack);

	pop_stack(&stack);
}


// testing list
void test_list()
{
	t_list list;
	t_book book;

	book = simulate_book();

	init_list(&list);

	push_list_start(&list, book);

	push_list_start(&list, book);

	push_list_end(&list, book);

	pop_list_start(&list);

	pop_list_end(&list);

	pop_list_start(&list);

}




