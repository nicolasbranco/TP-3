/*
This part of the program is going to simuler les modules of the function
*/


#include<stdio.h>
#include"model.h"
#include"simulation.h"

// Choose in function of what is being tested
#include"stack.h"

void main() 
{
	test_pile();




	system("pause");
}


//This part is for testing the stack
void test_pile()
{
	t_stack stack;

	t_book book1;
	t_book book2;
	book1.genre = INFORMATIQUE;
	strcpy(book1.titre, "Les Ninjas de l'Info 2");
	strcpy(book1.auteur_prenom, "Yannick");
	strcpy(book1.auteur_nom, "Roy");
	book1.nb_pages = 252;
	book1.isbn = 369;
	book1.bEmprunte = AVAIABLE;


	init_stack(&stack);

	push_stack(&stack, book1);

	push_stack(&stack, book1);

	stack_empty(&stack);

	book2 = pop_stack(&stack);
}


