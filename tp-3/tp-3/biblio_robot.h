/*
This is the programm in corcern with biblio robot
*/

#ifndef T_BIBLIO_ROBOT
#define T_BIBLIO_ROBOT

#define ROBOT_EMPTY 0

// Start the node with data next element
typedef struct
{
	t_element book;
	t_node * next;
	t_node * previous;
} t_node;

typedef struct
{
	int num_el;
	t_node * top;
	t_chariot * pChariot;
}t_robot;

// initialize stack
void robot_init(t_robot*);

// check if the stack is empty
int robot_empty(const t_robot* robot);

// add a book in stack
void robot_add_book(t_robot * , t_book );

// gives all the books to the cart, if possible
void robot_put_books_chariot(t_robot*);

#endif // !T_BIBLIO_ROBOT