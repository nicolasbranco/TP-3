/*
This part of the program is going to simuler les modules of the function
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include"stack.h"
#include"queue.h"
#include "linked_list.h"

//simule a book
t_book simulate_book();

//This part is for testing the fifo
void test_queue();

//This part is for testing the stack
void test_stack();

// testing list
void test_list();

#endif // !SIMULATION_H