/*
* Ce module représente une pile qui peut contenir des données d'un seul et même type
*défini par t_element dont l'accès est dernier arrivé-premier servi (Last In First Out)
*
*Il suffit de changer le type de référence pour que la pile change de type
*ex: typedef int t_element
*    typedef char t_element
*    typedef t_ t_element
*
* ou t_ est un type quelconque utilisable par sizeof
*
*
*/
#ifndef PILE_
#define PILE_

//Procédure pour initialiser une pile, la pile est vide
//À utiliser pour vider une pile(new)
void init_pile(t_pile *);

//Retourne si une pile est pleine ou non(is_full)
int  est_pleine(const t_pile*);

//Retourne si une pile est vide ou non(is_empty)
int  est_vide(const t_pile*);

//Ajoute l'élément reçu sur le dessus de la pile(push)
void empile(t_pile*, t_element );

//Retourne l'élément sur le dessus et le retire de la pile(pop)
t_element desempile(t_pile*);

#endif
