/*
	This module has the definitions for STACK
	
*/

#ifndef T_STACK_H
#define T_STACK_H

#define STACK_EMPTY 0

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

typedef struct t_stack
{
	int num_el;
	t_node * top;	
}t_stack;


// initialise
void init_stack(t_stack*);

// if i have time
//void pile_pleine(const t_noeud*);

// check if its full
int stack_empty(const t_stack*);

// add element
void push_stack(t_stack*, const t_element);

// retire element
t_element pop_stack(t_stack*);
















#endif // !T_PILE_H



