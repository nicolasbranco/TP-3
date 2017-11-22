/*
*STRATÉGIE : Nous avons décidé d'implémenter la pile dans un tableau statique de MAX_PILE éléments défini dans pile.h
*
*             -à chaque ajout on incrémente le sommet avant d'insérer dans le tableau d'éléments (voir t_pile)
*             - La pile est vide si le somme == PILE_VIDE
*             - La pile est pleine si le sommet == MAX_PILE - 1 (ou sommet + 1 == MAX_PILE)
*             - à chaque retrait, on décrémente le sommet après avoir retourné l'élément pointé par celui-ci
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

//changer cette déclaration pour obtenir des piles d'un autre type
typedef t_livre t_element;

typedef struct t_pile {

	//L'endroit de stockage des données
	t_element  tab_elements[MAX_PILE];

	//L'endroit où est la donnée à désempiler
	int      sommet;
} t_pile;

#include "pile.h"


//Procédure pour initialiser une pile, la pile est vide
//À utiliser pour vider une pile.
void init_pile(t_pile *p)
{
	p->sommet = PILE_VIDE;
}

//Retourne si une pile est pleine ou non
int  est_pleine(const t_pile *p)
{

	//Les indices vont de 0 à MAX_PILE - 1
	return p->sommet == MAX_PILE - 1;
}

//Retourne si une pile est vide ou non
int  est_vide(const t_pile *p)
{
	return p->sommet == PILE_VIDE;
}

//Ajoute l'élément reçu sur le dessus de la pile
void empile(t_pile *p, t_element e)
{
	//On utilise la pré incrémentation du C pour déplacer
	//le sommet avant d'insérer dans le tableau
	p->tab_elements[++p->sommet] = e;
}

//Retourne l'élément sur le dessus et le retire de la pile
t_element desempile(t_pile* p)
{
	//On utilise la poist décrémentation du C pour déplacer
	//le sommet après avoir retourné l'élément.
	return p->tab_elements[p->sommet--];
}


