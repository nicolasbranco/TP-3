/*
*STRAT�GIE : Nous avons d�cid� d'impl�menter la pile dans un tableau statique de MAX_PILE �l�ments d�fini dans pile.h
*
*             -� chaque ajout on incr�mente le sommet avant d'ins�rer dans le tableau d'�l�ments (voir t_pile)
*             - La pile est vide si le somme == PILE_VIDE
*             - La pile est pleine si le sommet == MAX_PILE - 1 (ou sommet + 1 == MAX_PILE)
*             - � chaque retrait, on d�cr�mente le sommet apr�s avoir retourn� l'�l�ment point� par celui-ci
*/

// Definitions
#define  MAX_PILE	50
#define  PILE_VIDE  -1

#define TAILLE_TITRE	80
#define TAILLE_NOM		30	
#define TAILLE_PRENOM	30

typedef enum { INVALID = -1, AUCUN = 0, FICTION = 1, HISTOIRE = 2, SCIENCE = 3, ENFANTS = 4, INFORMATIQUE = 5 } t_genre;

typedef struct t_livre {
	t_genre genre;
	int nb_pages;
	char auteur_prenom[TAILLE_PRENOM];
	char auteur_nom[TAILLE_NOM];
	char titre[TAILLE_TITRE];
	int isbn;
	int bEmprunte; // 1: Le livre a ete emprunte, 0: le livre est disponible.
} t_livre;

//changer cette d�claration pour obtenir des piles d'un autre type
typedef t_livre t_element;

typedef struct t_pile {

	//L'endroit de stockage des donn�es
	t_element  tab_elements[MAX_PILE];

	//L'endroit o� est la donn�e � d�sempiler
	int      sommet;
} t_pile;

#include "pile.h"


//Proc�dure pour initialiser une pile, la pile est vide
//� utiliser pour vider une pile.
void init_pile(t_pile *p)
{
	p->sommet = PILE_VIDE;
}

//Retourne si une pile est pleine ou non
int  est_pleine(const t_pile *p)
{

	//Les indices vont de 0 � MAX_PILE - 1
	return p->sommet == MAX_PILE - 1;
}

//Retourne si une pile est vide ou non
int  est_vide(const t_pile *p)
{
	return p->sommet == PILE_VIDE;
}

//Ajoute l'�l�ment re�u sur le dessus de la pile
void empile(t_pile *p, t_element e)
{
	//On utilise la pr� incr�mentation du C pour d�placer
	//le sommet avant d'ins�rer dans le tableau
	p->tab_elements[++p->sommet] = e;
}

//Retourne l'�l�ment sur le dessus et le retire de la pile
t_element desempile(t_pile* p)
{
	//On utilise la poist d�cr�mentation du C pour d�placer
	//le sommet apr�s avoir retourn� l'�l�ment.
	return p->tab_elements[p->sommet--];
}


