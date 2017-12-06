/*
This module has the definitions for QUEUE
*/

#ifndef T_QUEUE_H 
#define T_QUEUE_H 

typedef struct 
{
	int num_el;
	t_node * first;
	t_node * last;
}t_queue;

//initialize queue
void init_queue(t_queue *);

//check if it's empty
int queue_empty(t_queue*);

//retire element
t_element pop_queue(t_queue*);

//add element
void push_queue(t_queue *, t_element);


#endif // !T_QUEUE_H
