/*
Cette module possibilite l’utilisation de pile dynamiques de livres.
*/

#include <stdio.h>
#include "model.h"
#include "queue.h"

#define QUEUE_EMPTY 0

#define TRUE	1
#define FALSE	0

// max length - 10 000


//initialize queue
void init_queue(t_queue * queue)
{
	queue->num_el = QUEUE_EMPTY;
	queue->first = NULL;
	queue->last = NULL;
}

//check if it's empty
int queue_empty(t_queue* queue)
{
	return queue->num_el == QUEUE_EMPTY;
}

//retire element
t_element pop_queue(t_queue * queue)
{
	t_element el;
	t_node * aux;

	// How to do this
	if (queue_empty(queue))
		printf("\nError - Queue Empty.\n");
	else
	{
		aux = queue->first;
		el = aux->el;
		
		queue->first = queue->first->next;
		if (queue->num_el != 1)
			queue->first->previous = NULL;
		queue->num_el--;

		if (queue_empty(queue)) // avoids trash
			queue->last = NULL;

		free(aux);

		return el;
	}
}

//add element
void push_queue(t_queue * queue, t_element el)
{
	t_node * new_el;

	new_el = (t_node*)malloc(sizeof(t_node));

	if (new_el == NULL)
		printf("\nError in creating new node.\n");
		
	else
	{
		new_el->el = el;
		
		if (queue_empty(queue)) // avoids reading violation
		{
			new_el->next = NULL;
			new_el->previous = NULL;

			queue->first = new_el;
			queue->last = new_el;
		}
		else
		{
			new_el->previous = queue->last;
			new_el->next = queue->last->next;

			new_el->previous->next = new_el;
			queue->last = new_el;
		}
		queue->num_el++;
	}
}


