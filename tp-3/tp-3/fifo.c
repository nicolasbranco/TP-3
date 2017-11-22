/*
Cette module possibilite l’utilisation de pile dynamiques de livres.
*/

#include <stdio.h>
#include "model.h"
#include "fifo.h"

//initialize fifo
void init_fifo(t_fifo * fifo)
{
	fifo->num_el = FIFO_EMPTY;
	fifo->first = NULL;
	fifo->last = NULL;
}

//check if it's empty
int fifo_empty(t_fifo* fifo)
{
	return fifo->num_el == FIFO_EMPTY;
}

//retire element
t_element pop_fifo(t_fifo* fifo)
{
	t_element el;
	t_node * aux;

	if (fifo_empty(fifo))
	{
		printf("\nError - Fifo Empty.\n");
	}
	else
	{
		aux = fifo->first;
		el = aux->el;

		fifo->first = fifo->first->next;
		fifo->num_el--;

		free(aux);

		return el;
	}


}

//add element
void push_fifo(t_fifo * fifo , t_element el)
{
	t_node * last;

	last = (t_node*)malloc(sizeof(t_node));

	last->el = el;
	last->next = fifo->last;

	fifo->last = last;
	if (fifo_empty(fifo))
		fifo->first = fifo->last;
	fifo->num_el++;
}