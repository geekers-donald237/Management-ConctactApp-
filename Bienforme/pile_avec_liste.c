//Made By Geekers-Dd237
#include <stdio.h>
#include <stdlib.h>
#include "pile_avec_liste.h"
#include "verification_expression.h"


Pile*initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
}


int pile_vide(Pile P){
    int val;
    if(P.premier == NULL){
        return 1;
    }else{
        return 0;
    }
}

void empiler(Pile *pile, char e)
{
    Liste *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->carac = e;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}


char depiler(Pile *pile)
{
    if (pile_vide(*pile))
    {
        printf("La pile est vide");
    }

    char caracDepile;
    Liste *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        caracDepile = elementDepile->carac;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return caracDepile;
}


void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
       printf("Pile vide");
    }
    Liste *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->carac);
        actuel = actuel->suivant;
    }

    printf("\n");
}