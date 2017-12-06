/*
	This module has the definitions for STACK
	
*/

#ifndef T_STACK_H
#define T_STACK_H

typedef struct 
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



