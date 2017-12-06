/*
Cette module possibilite l’utilisation de pile dynamiques de livres.
*/

#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "stack.h"


// initialize stack
void init_stack(t_stack* stack) 
{
	stack->top = NULL;
	stack->num_el = STACK_EMPTY;
}

// if i have time
//void pile_pleine(const t_noeud*);

// check if the stack is empty
int stack_empty(const t_stack* stack) 
{
	return stack->num_el == STACK_EMPTY;
}

// add element
void push_stack(t_stack* stack, const t_element el)
{
	t_node * top;

	top = (t_node*)malloc(sizeof(t_node));

	top->el = el;
	top->next = stack->top;

	stack->top = top;
	stack->num_el++;
}


// retire element
t_element pop_stack(t_stack* stack)
{
	t_element el;
	t_node * aux;

	if (stack_empty(stack))
	{
		printf("\nError - Stack Empty.\n");
	}
	else
	{
		aux = stack->top;
		el = aux->el;

		stack->top = stack->top->next;
		stack->num_el--;

		free(aux);

		return el;
	}
}
