/*
This is the programm in corcern with biblio robot
*/

#include<stdio.h>
#include"model.h"
#include "biblio_robot.h"
#include "biblio_chariot.h"


// initialize stack
void robot_init(t_robot* robot, t_chariot * pChariot)
{
	robot->top = NULL;
	robot->pChariot = pChariot;
	robot->num_el = ROBOT_EMPTY;
}

// check if the stack is empty
int robot_empty(const t_robot* robot)
{
	return robot->num_el == ROBOT_EMPTY;
}

// add a book in stack
void robot_add_book(t_robot * robot, t_book book)
{
	if (chariot_get_position(robot->pChariot)== POS_KIOSTE)
		chariot_ajouter_livre(robot->pChariot, &book);
	else
	{
		t_node * new_el;

		new_el = (t_node*)malloc(sizeof(t_node));

		if (new_el != NULL)
		{
			new_el->book = book;

			new_el->next = robot->top;
			new_el->previous = NULL; // used just in queue and line

			robot->top = new_el;
			robot->num_el++;
		}
		else
			printf("Error in allocating memory.\n");
	}
}


// gives all the books to the cart, if possible
void robot_put_books_chariot(t_robot* robot)
{
	if (chariot_get_position(robot->pChariot) == POS_KIOSTE)
	{
		while (robot_empty(robot) != ROBOT_EMPTY)
		{
			t_book book;
			t_node * aux;

			aux = robot->top;
			book = aux->book;

			robot->top = robot->top->next;
			robot->num_el--;

			free(aux);

			chariot_ajouter_livre(robot->pChariot, &book);
		}
	}
	else
		printf("\nChariot non disponible\n.");
}


