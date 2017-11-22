/*
* Ce module repr�sente une pile qui peut contenir des donn�es d'un seul et m�me type
*d�fini par t_element dont l'acc�s est dernier arriv�-premier servi (Last In First Out)
*
*Il suffit de changer le type de r�f�rence pour que la pile change de type
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

//Proc�dure pour initialiser une pile, la pile est vide
//� utiliser pour vider une pile(new)
void init_pile(t_pile *);

//Retourne si une pile est pleine ou non(is_full)
int  est_pleine(const t_pile*);

//Retourne si une pile est vide ou non(is_empty)
int  est_vide(const t_pile*);

//Ajoute l'�l�ment re�u sur le dessus de la pile(push)
void empile(t_pile*, t_element );

//Retourne l'�l�ment sur le dessus et le retire de la pile(pop)
t_element desempile(t_pile*);

#endif
