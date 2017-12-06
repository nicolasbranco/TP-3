/*
Cette module possibilite l’utilisation de pile dynamiques de livres.
*/

#include <stdio.h>
#include "model.h"
#include "linked_list.h"

#define LIST_EMPTY 0

// initializes the linked list
void init_list(t_list * list)
{
	list->first = NULL;
	list->last = NULL;
	list->num_el = LIST_EMPTY;
}

// check if the list is empty 
int list_empty(const t_list * list)
{
	return list->num_el == LIST_EMPTY;
}

// push element in the start
void push_list_start(t_list * list, t_element el)
{
	t_node * new_el;

	new_el = (t_node*)malloc(sizeof(t_node));

	if (new_el == NULL)
		printf("\nError in creating new node.\n");

	else
	{
		new_el->el = el;

		if (list_empty(list)) // avoids reading violation
		{
			new_el->next = NULL;
			new_el->previous = NULL;

			list->first = new_el;
			list->last = new_el;
		}
		else
		{
			new_el->next = list->first;
			new_el->previous = list->first->previous;

			new_el->next->previous = new_el;
			list->first = new_el;
		}
		list->num_el++;
	}
}

// push element in the end
void push_list_end(t_list * list, t_element el)
{
	t_node * new_el;

	new_el = (t_node*)malloc(sizeof(t_node));

	if (new_el == NULL)
		printf("\nError in creating new node.\n");

	else
	{
		new_el->el = el;

		if (list_empty(list)) // avoids reading violation
		{
			new_el->next = NULL;
			new_el->previous = NULL;

			list->first = new_el;
			list->last = new_el;
		}
		else
		{
			new_el->previous = list->last;
			new_el->next = list->last->next;

			new_el->previous->next = new_el;
			list->last = new_el;
		}
		list->num_el++;
	}
}

// push element in the n_th place
void push_list_nth(t_list * list, t_element el, int node_num)
{
	t_node * new_el;
	t_node * aux;

	new_el = (t_node*)malloc(sizeof(t_node));

	if (new_el == NULL)
		printf("\nError in creating new node.\n");
	else
	{
		new_el->el = el;

		if (node_num <= list->num_el)
		{
			if (node_num * 2 <= list->num_el) // if it is closed to go by first
			{
				aux = list->first;

				// goes up to n_th place
				for (int i = 1; i < node_num; i++)
					aux = aux->next;
			}
			else
			{
				aux = list->last;

				// goes up to n_th place
				for (int i = list->num_el; i > node_num; i--)
					aux = aux->previous;
			}

			new_el->next = aux;
			new_el->previous = aux->previous;

			new_el->previous->next = new_el;
			aux->previous = new_el;

			list->num_el++;
		}
		else
			printf("\nError in node placement\n");
		}
	}

	// pop element in the start
	t_element pop_list_start(t_list * list)
	{
		t_element el;
		t_node * aux;

		// How to do this
		if (list_empty(list))
			printf("\nError - List Empty.\n");
		else
		{
			aux = list->first;
			el = aux->el;

			list->first = list->first->next;
			if (list->num_el != 1) // otherwise it will have error reading previous el
				list->first->previous = NULL;
			list->num_el--;

			if (list_empty(list)) // avoids trash
				list->last = NULL;

			free(aux);

			return el;
		}
	}

	// pop element in the end
	t_element pop_list_end(t_list * list)
	{
		t_element el;
		t_node * aux;

		// How to do this
		if (list_empty(list))
			printf("\nError - List Empty.\n");
		else
		{
			aux = list->last;
			el = aux->el;

			list->last = list->last->previous;
			if (list->num_el != 1) // otherwise it will have error reading previous el
				list->last->next = NULL;
			list->num_el--;

			if (list_empty(list)) // avoids trash
				list->first = NULL;

			free(aux);

			return el;
		}
	}

// pop element in the n_th place
t_element pop_list_nth(t_list *, int);







