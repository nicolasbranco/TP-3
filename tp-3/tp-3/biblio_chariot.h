#pragma once
#ifndef __T_BIBLIO_CHARIOT__
#define __T_BIBLIO_CHARIOT__

#define CHARIOT_CHOIX_MIN 0
#define CHARIOT_CHOIX_MAX 3
#define NB_MAX_LIVRE_CHARIOT 100

#define POS_KIOSTE 0
#define POS_DEPLACEMENT 1

#define MAX_OPTION_MENU_CHARIOT 4
#define MIN_OPTION_MENU_CHARIOT	0


#include "modele.h"
#include "Bibliotheque.h"

struct bibliotheque;	// On vient dire au compilateur "fais-moi confiance, il y a une struct biblio... quelque part..."

						//typedef t_livre t_donnee;  // Optionnel pour être générique.
typedef struct noeud t_noeud;
typedef struct bibliotheque t_bibliotheque; // On vient créer un type t_biblio, pour ne pas traîner struct biblio partout.

typedef struct noeud t_noeud;
//Declarer un noeud pour avoir un chaine dynamique
struct noeud {

	t_livre* pLivre;
	struct {
		t_noeud * suivant;
		t_noeud * precedent;
	};

};


typedef struct {

	t_noeud*    tete;
	int nb_livre;
	int position;

	t_bibliotheque* pBiblio; // un pointeur ver la bibliotheque

}t_chariot;




//-----------------------------------//
//-------------FONCTION-----------------//

//en vue
int chariot_ajouter_livre(t_chariot * chariot, t_livre* pNouveau_livre);

t_livre* chariot_retirer_livre(t_chariot * chariot, int ISBN);

t_livre* chariot_emprunter_livre(t_chariot *);

t_livre* chariot_apporter_un_livre(t_chariot* pChariot, int isbn); // a finaliser et changer de nom ... 


void chariot_retouner_les_livres(t_chariot* pChariot);

int get_position(t_chariot* pChariot);


//cacher..
void chariot_init(t_chariot* chariot, t_bibliotheque * biblio);




int chariot_trouver_position_livre(t_chariot * chariot, t_livre* pLivre);





void chariot_afficher_menu();




int chariot_demander_choix_emprunt();





int chariot_faire_emprunt(t_chariot* pChariot, t_livre* pLivre);




void chariot_afficher_livre(t_chariot * pChariot);


void chariot_menu_option(t_chariot*pChariot);


void chariot_afficher_option_menu();

void chariot_apporter(t_chariot*pChariot); // avec lui .....``





















#endif