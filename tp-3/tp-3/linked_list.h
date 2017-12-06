/*
This module has the definitions for LINKED_LIST
*/

#ifndef T_LINKED_LIST 
#define T_LINKED_LIST 

typedef struct
{
	int num_el;
	t_node * first;
	t_node * last;
}t_list;


// initializes the linked list
void init_list(t_list *);

// check if the list is empty 
int list_empty(const t_list *);


// eventually i could do the same function for all push's and pop's and use a type : 
//	0 for start
//	-1 for end
//	other values for nth

// push element in the start
void push_list_start(t_list *, t_element);

// push element in the end
void push_list_end(t_list *, t_element);

// push element in the n_th place
void push_list_nth(t_list *, t_element, int);

// pop element in the start
t_element pop_list_start(t_list *);

// pop element in the end
t_element pop_list_end(t_list *);

// pop element in the n_th place
t_element pop_list_nth(t_list *, int);


#endif // !T_LINKED_LIST
