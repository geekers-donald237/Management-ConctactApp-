//MAde By Geekers-Dd237
#include <stdio.h>
#include <stdlib.h>
#include "pile_avec_liste.h"
#include "verification_expression.h"

int main()
{ 
   int choix;
   do{
   char chaine[taille];
   printf("\nSaisir l'expression a verifier : ");
   scanf("%s",chaine);

   if(verif_expression(chaine)){
       printf("\nCette expression est bien formee\n");
   }else{
      printf("\nCette expression est mal formee\n");
   }
   printf("\nVoulez vous entrer une nouvelle expression ?(O/1): ");
   scanf("%d",&choix);
   }while(choix != 0);
    return 0;
}


