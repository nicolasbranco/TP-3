/*
	Ici sont les definitions de le programme.
*/


#ifndef MODEL_H
#define MODEL_H

#include <stdlib.h>

#define SIZE_TITLE		80
#define SIZE_SURNAME	30
#define SIZE_NAME		30

#define AVAIABLE 0
#define BORROWED 1	

#define STUDENT_ID_MAX		1 
#define STUDENT_ID_MIN		1000000
#define STUDENT_YEAR_MIN	2000
#define STUDENT_YEAR_MAX	2017
#define STUDENT_MAX_BOOKS	5


typedef enum {
	INVALID = -1, NONE = 0, FICTION = 1, HISTORY = 2,
	SCIENCE = 3, KIDS = 4, INFORMATICS = 5
} t_genre;

typedef struct 
{
	t_genre genre;
	int num_pg;
	char authors_name[SIZE_NAME];
	char authors_surname[SIZE_SURNAME];
	char title[SIZE_TITLE];
	int isbn;
	int bBorrowed; // 1: Le livre a ete emprunte, 0: le livre est disponible.
} t_book;

typedef struct
{
	int id;
	int subscription_year; //check name
	t_book book[STUDENT_MAX_BOOKS];
} t_student;

// Define t_element as t_book
typedef t_book t_element;

// Start the node with data next element
typedef struct
{
	t_element el;
	t_node * next;
	t_node * previous;
} t_node;


#endif // !MODELE_H






