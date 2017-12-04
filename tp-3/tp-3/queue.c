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
		queue->num_el--;

		free(aux);

		return el;
	}
}

//add element
//void push_queue(t_queue * queue, t_element el)
//{
//	t_node * new_el;
//
//	new_el = (t_node*)malloc(sizeof(t_node));
//
//	if (new_el != NULL)
//	{
//		new_el->el = el;
//
//		new_el->previous = queue->last;
//		new_el->next = queue->last->next;
//
//		new_el->previous->next = new_el;
//		queue->last = new_el;
//
//		if (queue_empty(queue))
//			queue->first = queue->last;
//		queue->num_el++;
//	}
//	else
//		printf("\nError in creating new node.\n");
//
//}


