#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Bibliotheque.h"







void chariot_init(t_chariot* chariot, t_bibliotheque * biblio)
{

	chariot->tete = NULL;
	chariot->nb_livre = 0;
	chariot->pBiblio = biblio;
	chariot->position = POS_KIOSTE;

}

int chariot_ajouter_livre(t_chariot* chariot, t_livre* pLivre)
{
	int verification = 0;
	int position = 0;
	int i = 1; // pour me mettre avant la place que je veut...
	t_noeud * pNew_noeud;
	t_noeud* tmp;


	if (chariot->nb_livre <= NB_MAX_LIVRE_CHARIOT) // etre sur que le chariot n'ets pas plein je pourrait le remplacer par un autre function 
	{
		if (pLivre->bEmprunte != EMPRUNT)// cer le livre n'est pas dans la biblio
		{
			if (pLivre->emplacement != DANS_CHARIOT)// car il est deja dans le chariot je peux pas le mettre deux fois
			{
				tmp = chariot->tete;
				//je dois mettre les livre dans l'ordre ISBN
				position = chariot_trouver_position_livre(chariot, pLivre);



				// ajouter de la place dans la list pour mettre le livre

				pNew_noeud = (t_noeud*)malloc(sizeof(t_noeud));//cree le noeud
				if (pNew_noeud)
				{
					pNew_noeud->pLivre = pLivre;
					verification++;

					///PT savoir si le chariot est plein a un jours serais important mais pour l<instant on a un chariot infini
					// mettre le livre dans la list
					if (tmp != NULL)
					{

						while (i < position) /// Trouver le noeud suivant de l'emplacement qu'on veut le mettre
						{
							tmp = tmp->suivant;
							i++;
						}

						if (tmp != NULL)
						{// si pas vide

							if (position == 0) /// si on met a postition 0
							{
								pNew_noeud->precedent = NULL;
								pNew_noeud->suivant = tmp;
								chariot->tete = pNew_noeud;
								tmp->precedent = pNew_noeud;

							}

							else if (tmp->suivant == NULL)
							{
								//juste si il est dans le derniere position
								tmp->suivant = pNew_noeud;
								pNew_noeud->precedent = tmp;
								pNew_noeud->suivant = NULL;
							}
							else // les autre condition 
							{
								pNew_noeud->precedent = tmp;
								pNew_noeud->suivant = tmp->suivant;
								tmp->suivant->precedent = pNew_noeud;
								tmp->suivant = pNew_noeud;


							}
						}
					}
					else
					{//Premier cree
						chariot->tete = pNew_noeud;
						pNew_noeud->precedent = NULL;
						pNew_noeud->suivant = NULL;
					}

					chariot->nb_livre++;
					pLivre->emplacement = DANS_CHARIOT;
				}
			}
			else
			{
				printf("Deja dans le chariot\n");
			}
		}
		else
		{
			printf("Le livre est emprunter ...");
		}

	}

	else
	{
		printf("ERRTEUR, Le cahriot est plein\n\n");
	}



	return verification;
}

int chariot_trouver_position_livre(t_chariot* chariot, t_livre* pLivre)
{
	int position = 0;
	int fin = 0; /// permet de savoir quand jai regarder tout les livre et si le livre va a la fin 
	t_noeud * tmp = NULL;

	tmp = chariot->tete;
	if (chariot->tete != NULL) // pas vide
	{
		while (pLivre->isbn > tmp->pLivre->isbn && fin == 0)
		{
			position++;
			if (tmp->suivant != NULL)
				tmp = tmp->suivant;
			else
				fin++;
		}
	}

	else // vide
	{
		position = 0;
	}

	return position;
}

t_livre* chariot_retirer_livre(t_chariot * chariot, int ISBN)
{
	t_noeud* tmp = NULL;
	t_livre* pLivre = NULL;
	int position = 0;




	if (chariot->tete != NULL)// si pas vide
	{

		tmp = chariot->tete;
		while (ISBN != tmp->pLivre->isbn && position != chariot->nb_livre)//permet de trouver un le livre avec le meme ISBN et dire il est ou 
		{
			tmp = tmp->suivant;
			position++;
		}

		if (chariot->nb_livre != position)// etre sur que le ISBN rechercher est valide 
		{
			pLivre = tmp->pLivre;
			chariot->nb_livre--; //diminuer le nb_livre dans le chariot

								 //refaire les lien
			if (position != 0)
			{
				if (tmp->suivant != NULL)
				{
					tmp->precedent->suivant = tmp->suivant;
					tmp->suivant->precedent = tmp->precedent;
				}
				else // si on enleve a la derniere position
				{
					tmp->precedent->suivant = NULL;
				}
			}
			else//si on enleve en position 0
			{
				if (tmp->suivant != 0)
				{
					chariot->tete = tmp->suivant;
					tmp->suivant->precedent = NULL;
				}
				else
				{

				}
			}
		}
		else
		{
			printf(" ERREUR!!!!!!! ISBN INVALIDE!!!\n");
		}
	}
	else
		printf("ERREUR !!!!, Le chariot est VIDE!!!");

	pLivre->emplacement = DANS_BIBLIOTHEQUE;
	free(tmp);
	return pLivre;
}

void chariot_afficher_menu()
{
	printf("===============================================\n");
	printf("             Menu d'Emprunt                    \n");
	printf("===============================================\n");
	printf("1 : Recherche par ISBN\n");
	printf("2 : Recherche par NOM et PRENOM\n");
	printf("3 : Recheche par TITRE\n");
	printf("0 : Sortir du menu emprunter\n");

	printf("===============================================\n");
	printf("OPTION :");
}

// pas encore totalement fini il manque la recherche des livre par chaine de caractere...
t_livre* chariot_emprunter_livre(t_chariot * pChariot)
{
	int isbn = -1;
	t_livre * pLivre = NULL;
	int choix_demprunt = -1;

	// Trouver un pointeur d'un livre avec le ISBN
	//pLivre = trouver_localisation(pBibli, isbn);

	int choix_menu;
	do
	{
		// Gestion du menu.
		chariot_afficher_menu();
		choix_menu = chariot_demander_choix_emprunt();
		system("cls");

		switch (choix_menu)
		{
		case 1: pLivre = chariot_apporter_un_livre(pChariot, isbn); break;
			//case 2: pLivre = recherche_nom_prenom(pChariot); break;
			//case 3: pLivre = recherche_par_titre(pBibli); break;
			//case 9: trier_livres(&bibli); break;
		case 0: break;
		}
		if (pLivre != NULL)// si on a un livre
		{
			if (pLivre->bEmprunte == EMPRUNT)//si emprunter
			{
				printf("\nLe livre est deja emprunte\n");
			}
			else//si pas emprunter
			{
				printf("\nVoulez-vous emprunter ce livre ?\n");
				afficher_livre(pLivre);


				do
				{

					printf("Si OUI appuyer sur 1\n\n SI NON appuyer sur 0\n CHOIX :");
					scanf("%d", &choix_demprunt);
					if (choix_demprunt == 1)
					{
						if (chariot_faire_emprunt(pChariot, pLivre))
						{
							chariot_retirer_livre(pChariot, pLivre->isbn);
							printf("\nLe livre a bien ete emprunter\n");


						}
						else
						{
							printf("\nUne erreur ces produite !!!!!!!!!! Desoler...\n");
						}
					}

					system("pause");
					system("cls");
				} while ((choix_demprunt != 1) && (choix_demprunt != 0));


			}

		}


	} while (choix_menu);

	printf("Vous avez quitter le menu d'emprunt");
	return pLivre;
}


int chariot_demander_choix_emprunt()
{
	int choix_menu = INVALID;

	while (choix_menu < CHARIOT_CHOIX_MIN || choix_menu > CHARIOT_CHOIX_MAX)
	{

		scanf("%d", &choix_menu);
	}

	return choix_menu;
}

// optiont recherche par isbn dans les choix de recherche du chariot
t_livre* chariot_apporter_un_livre(t_chariot* pChariot, int isbn)
{
	int i = 0;
	int j = 0;
	int position = 0; // si on met a 1 pourrait avoyer le chariot chercher le livre dans la biblio

	t_livre* ptr_livre_chercher = NULL;
	t_noeud* tmp = NULL;

	if (isbn = -1)// si le isbn n'est pas valide je demande a l'utilisateur en fait c pour mes autres partie du program que je me suis amuser...
		isbn = chariot_demander_isbn;

	//commencer par chercher dans le chariot si le livre est la 
	if (pChariot->tete != NULL)
	{
		tmp = pChariot->tete;
		while (tmp->pLivre->isbn == isbn && tmp->suivant != NULL)
		{
			tmp = tmp->suivant;

		}
		ptr_livre_chercher = tmp->pLivre;
		if (ptr_livre_chercher != NULL)
		{
			printf("Le livre est dans le chariot\n");
		}
	}
	else
	{
		//chariot vide 
	}

	//si pas trouver dans le chariot faire une recherche dans la bibliotheque 
	if (ptr_livre_chercher == NULL) // si toujours pas trouver le livre dans le chariot 
	{
		for (i = 0; i < NB_GENRES; i++)
		{
			for (j = 0; j < pChariot->pBiblio->nb_livres[i]; j++)
			{
				if (isbn == pChariot->pBiblio->biblio_dyna[i][j].isbn)
				{
					ptr_livre_chercher = &pChariot->pBiblio->biblio_dyna[i][j];
				}
			}
		}
		if (ptr_livre_chercher != NULL)
		{
			printf("Le livre est dans la bibliotheque\n");
			chariot_ajouter_livre(pChariot, ptr_livre_chercher);
		}
	}

	if (ptr_livre_chercher == NULL)
		//si rien trouver dire que le livre est inexitant ou pt deja emprunter 
	{

		printf("\nLe livre est inexistant !!!!!!!!!\n");
		system("pause");
		system("cls");
	}


	return ptr_livre_chercher;
}

// demande isbn a l' utilisateur du chariot
int chariot_demander_isbn()
{
	int isbn = 0;
	printf("Entree l'isbn du livre :");

	scanf("%d", &isbn);

	return isbn;
}

//permet de mettre un livre en emprunt
int chariot_faire_emprunt(t_chariot* pChariot, t_livre* pLivre)
{
	pLivre->bEmprunte = EMPRUNT;
	//peut etre avoir un /tudiant a qui mettre le livre deans ou le kiste vas le faire ... 
	return 1;
}

void chariot_retouner_les_livres(t_chariot* pChariot)
{
	int i = 0;
	t_livre* livre_retourner = NULL;
	t_noeud* tmp = NULL;
	int isbn;

	pChariot->position = POS_DEPLACEMENT;
	tmp = pChariot->tete;

	for (i = 0; i < pChariot->nb_livre; i++)
	{

		isbn = tmp->pLivre->isbn;

		if (tmp->suivant != NULL)
			tmp = tmp->suivant;

		livre_retourner = chariot_retirer_livre(pChariot, isbn);
		livre_retourner->emplacement = DANS_BIBLIOTHEQUE;


		//sleep(1000);
	}
	printf("Les livre ont tous ete retouner MERCII !!!\n");
	system("pause");
}

void chariot_afficher_livre(t_chariot * pChariot)
{
	int i = 0;
	t_livre* pLivre = NULL;
	t_noeud* tmp = NULL;

	tmp = pChariot->tete;

	for (i = 0; i < pChariot->nb_livre; i++)
	{
		pLivre = tmp->pLivre;
		afficher_livre(pLivre);
		if (tmp->suivant != NULL)
			tmp = tmp->suivant;
	}
	if (pChariot->nb_livre == 0)
	{
		printf("\n Le chariot est vide!!!!\n");

	}

	system("pause");
	system("cls");

}

int get_position(t_chariot* pChariot)
{
	return pChariot->position;
}

void chariot_menu_option(t_chariot*pChariot)
{
	int choix_menu;
	do
	{
		// Gestion du menu.
		chariot_afficher_option_menu();
		choix_menu = chariot_demander_choix_menu_option();
		system("cls");

		switch (choix_menu)
		{
		case 1:  chariot_emprunter_livre(pChariot); break;
		case 2: chariot_apporter_un_livre(pChariot); break;
		case 3: chariot_retouner_les_livres(pChariot); break;
		case 4:chariot_afficher_livre(pChariot); break;// pour pouvoir faire des test et les voir a l'ecran


		case 0: break;
		}
	} while (choix_menu);
}

int chariot_demander_choix_menu_option()
{
	int choix_menu = INVALID;

	while (choix_menu < MIN_OPTION_MENU_CHARIOT || choix_menu > MAX_OPTION_MENU_CHARIOT)
	{

		scanf("%d", &choix_menu);
	}

	return choix_menu;

}

void chariot_afficher_option_menu()
{
	printf("===============================================\n");
	printf("             Menu d'optiont CHARIOT            \n");
	printf("===============================================\n");
	printf("1 : menu d'emprunt\n");
	printf("2 : envoyer le chariot chercher un livre\n");
	printf("3 : retouner livre dans chariot\n");
	printf("4 : Afficher les livres di chariot\n");
	printf("0 : Sortir du menu option\n");

	printf("===============================================\n");
	printf("OPTION :");
}

void chariot_apporter(t_chariot* pChariot)
{
	int isbn;
	t_livre* ptr_livre = NULL;

	isbn = chariot_demander_isbn();

	ptr_livre = chariot_apporter_un_livre(pChariot, isbn);

	if (ptr_livre != NULL)
		chariot_ajouter_livre(pChariot, ptr_livre);

	else
		printf("IMPOSIBLE DE TROUVER VOTRE LIVRE... !!!\n");
}





