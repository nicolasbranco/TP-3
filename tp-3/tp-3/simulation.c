/*
This part of the program is going to simuler les modules of the function
*/


#include<stdio.h>
#include"model.h"
#include"simulation.h"

// Choose in function of what is being tested

enum simulation_options {STACK, QUEUE};

#define SIMULATION STACK;

void main() 
{
	int choice = SIMULATION;

	switch (choice)
	{
	case STACK: test_stack(); break;
	//case QUEUE: test_queue(); break;
	default:	break;
	}
	
	printf("\n\n");
	system("pause");
}


////simule a book
//t_book simulate_book()
//{
//	t_book book1;
//	book1.genre = FICTION;
//	strcpy(book1.title, "Les Ninjas de l'Info 2");
//	strcpy(book1.authors_name, "Yannick");
//	strcpy(book1.authors_surname, "Roy");
//	book1.num_pg = 252;
//	book1.isbn = 369;
//	book1.bBorrowed = AVAIABLE;
//
//	return book1;
//}

t_book simulate_book()
{
	t_book book;

	book.genre = HISTORY;
	
	//book.title = "Title test\0";
	//book.title = "Author's name test\0";
	//book.title = "Author's surname test\0";
	strcpy(book.title, "Title test");
	strcpy(book.authors_name, "Author's name test");
	strcpy(book.authors_surname, "Author's surname test");
	book.num_pg = 150;
	book.isbn = 100;
	book.bBorrowed = AVAIABLE;
	
	return book;
}



//This part is for testing the queue
//void test_queue()
//{
//	t_queue queue;
//
//	t_element book;
//
//	book = simulate_book();
//	//book = simuler_book();
//
//	init_queue(&queue);
//
//	push_queue(&queue, book);
//
//	push_queue(&queue, book);
//
//	pop_queue(&queue);
//
//	pop_queue(&queue);
//
//}




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




