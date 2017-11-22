/*
	Ici sont les definitions de le programme.
*/


#ifndef MODEL_H
#define MODEL_H

#define TAILLE_TITRE	80
#define TAILLE_NOM		30
#define TAILLE_PRENOM	30

#define AVAIABLE 0
#define BORROWED 1	


typedef enum t_genre {
	INVALID = -1, AUCUN = 0, FICTION = 1, HISTOIRE = 2,
	SCIENCE = 3, ENFANTS = 4, INFORMATIQUE = 5
} t_genre;

typedef struct
{
	t_genre genre;
	int nb_pages;
	char auteur_prenom[TAILLE_PRENOM];
	char auteur_nom[TAILLE_NOM];
	char titre[TAILLE_TITRE];
	int isbn;
	int bEmprunte; // 1: Le livre a ete emprunte, 0: le livre est disponible.
} t_book;


#endif // !MODELE_H






