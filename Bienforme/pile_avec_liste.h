//Made By Geekers-Dd237
#ifndef __PILE_AVEC_LISTE_H
#define __PILE_AVEC_LISTE_H
#define taille 50


typedef struct Liste Liste;
struct Liste
{
    char carac;
    Liste *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Liste *premier;
};

Pile*initialiser();
int pile_vide(Pile P);
char depiler(Pile*P);
void empiler(Pile*P,char e);
void Vider_pile(Pile*P);

#endif
