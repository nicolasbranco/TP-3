/*
This module has the definitions for FIFO
*/

#ifndef T_FIFO_H
#define T_FIFO_H

#define FIFO_EMPTY 0

#define TRUE	1
#define FALSE	0

// max length - 10 000

// Define as a pile of t_livres
typedef t_book t_element;

// Start the node with data next element
typedef struct t_node
{
	t_element el;
	struct t_node * next;
}t_node;

typedef struct t_fifo
{
	int num_el;
	t_node * first;
	t_node * last;
}t_fifo;


//initialize fifo
void init_fifo(t_fifo *);

//check if it's empty
int fifo_empty(t_fifo*);

//retire element
t_element pop_fifo(t_fifo*);

//add element
void push_fifo(t_fifo *, t_element);




#endif // !T_PILE_H
