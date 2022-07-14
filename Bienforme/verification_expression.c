//Made By Geekers-Dd237
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile_avec_liste.h"
#include "verification_expression.h"


char changer_carac(char c){
    char ouvrant[] = {'(','{','['};
    char fermant[]= {')','}',']'};
    for (int i = 0; i < 3; i++)
    {
       if(c == fermant[i]){
           return ouvrant[i];
    }
}
    
    
}
int verif_expression(char chaine[]){
    Pile*P;
    P = initialiser(P);
    int taille_chaine = strlen(chaine);
    for (int i = 0; i < taille_chaine; i++)
    {
             if(chaine[i] == '(' || chaine[i]== '[' || chaine[i] == '{'){  
                 empiler(P,chaine[i]);
             }
             else if(chaine[i] == ')' || chaine[i] == ']' || chaine[i] == '}'){
                 if(pile_vide(*P)){
                     return 0; 
                 }else{
                    char c = changer_carac(chaine[i]);
                    if(c == P->premier->carac){
                        depiler(P);
                    }else{
                        return 0;
                    }
                }   
             }
    }
    if(pile_vide(*P)){
       return 1;
    }else{
       return 0;
    }
    
}