// @Author : Geekers-donald237

//fichier contenant le code source  de mes fonctions 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//inlusion des prototypes de mes fonctions(.h) et librairies standart
#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*fonction pour la creation d'un nouveau contact et ajout ds le fichier
@return un pointeur sur contact dont les differents champs sont initialises
*/
void newContact(Contact* contacts,int* nombreDeContacts){
    
    
    //Creation d'une variable de type Contact a initialiser ses champs
    //puis l'ajouter au tableau de contacts
    Contact contactElm;
            
            printf("\t\tEntrer le nom :");
            //Chaque valeur est recuperee de facon securisee via la sortie standart
            fgets(contactElm.nom,TAILLE,stdin);
            fgets(contactElm.nom,TAILLE,stdin);
			printf("\n");
            //On vide le tampon juste apres
            fflush(stdin);
            printf("\t\tEntrer le prenom :");
            fgets(contactElm.prenoms,TAILLE,stdin);
            fflush(stdin);			
			printf("\n");

            /*NB: Un controle de champ sera effectue sur la valeur du 
            Un numero valide au cameroun est compose de 9 chiffres et commence 
            obligatoirement par 6*/
            printf("\t\tEntrer le numero de Tel :");
            fgets(contactElm.numeroTel,TAILLE,stdin);
            fflush(stdin);
            while( contactElm.numeroTel[0] != '6' || strlen(contactElm.numeroTel) != 10 ){
            	printf("\t\tUn numero valide au cameroun est compose de 9 chiffres et commence obligatoirement par 6 \n");
            	printf("\t\tEntrer le numero de Tel :");
           		fgets(contactElm.numeroTel,TAILLE,stdin);
           		fflush(stdin);
	 			printf("\n");

            } 
            printf("\t\tEntrer la ville :");
            fgets(contactElm.ville,TAILLE,stdin);
            fflush(stdin);
			printf("\n");
            printf("\t\tEntrer l'email :");
            fgets(contactElm.email,TAILLE,stdin);
            fflush(stdin);
			printf("\n");

			        
        
        contacts[*nombreDeContacts] = contactElm;
     //   fprintf(monFichier,"Contact numero %d\n",*nombreDeContacts+1);
        //On peut aussi envoyer les informations d'un contact par paquet
        // fwrite(contacts,sizeof(Contact),*nombreDeContacts,monFichier);
        printf("Contact ajoute avec succes\n\t\t");
        *nombreDeContacts = *nombreDeContacts + 1;
        // printf("%d\n",*nombreDeContacts);
        
}


//fonction pour l'affichage de la liste des contacts

void readContactList(Contact* contacts,int nombreDeContacts){
	int i;
	
	
		for( i= 0;i < nombreDeContacts ;i++){
				fprintf(stdout,"\n\n\t\tcontact numero %d :\n\n",i+1);
				fflush(stdout);
				printf("\t\t");
		        fputs((contacts+i)->nom,stdout);//stdout designe la sortie standart (terminal)
		        fflush(stdout);
				printf("\t\t");
		        fputs((contacts+i)->prenoms,stdout);
		        fflush(stdout);
				printf("\t\t");
		        fputs((contacts+i)->numeroTel,stdout);
		        fflush(stdout);
				printf("\t\t");
		        fputs((contacts+i)->ville,stdout);
		        fflush(stdout);
				printf("\t\t");
		        fputs((contacts+i)->email,stdout);
		        fflush(stdout);
				printf("\t\t\n");
		}
}


//fonction de modification d'un contact

void updateContact(Contact* contacts,int nombreDeContacts,char* nomContact){
	int i,ok= 0;
	Contact contactElm ;
	char* ptr = (char*)malloc(sizeof(char)*100);
	
		for(i=0;i<nombreDeContacts;i++){
			strcpy(ptr,contacts[i].nom);
			if(  strcmp(contacts[i].nom,nomContact) == 0 ){
				printf("\t\tEntrer le  nouveau nom :");
		        // fgets(contactElm.nom,TAILLE,stdin);
		        fgets(contactElm.nom,TAILLE,stdin);
		        fflush(stdin);
				printf("\n");
		        printf("\t\tEntrer le  nouveau prenom :");
		        fgets(contactElm.prenoms,TAILLE,stdin);
		        fflush(stdin);			
				printf("\n");
		        printf("\t\tEntrer le nouveau numero de Tel :");
		        fgets(contactElm.numeroTel,TAILLE,stdin);
		        fflush(stdin);
				printf("\n");
		        printf("\t\tEntrer la nouvelle  ville :");
		        fgets(contactElm.ville,TAILLE,stdin);
		        fflush(stdin);			
				printf("\n");
		        printf("\t\tEntrer le nouveau email :");
		        fgets(contactElm.email,TAILLE,stdin);
		        fflush(stdin);				
				printf("\n");
		        contacts[i] = contactElm ;  
		        ok = 1 ;  
			}
		}
		if( ok == 0 )
			printf("\t\tConctact inexistant merci de Re-essayer !!\n\n");
}


//fonction de suppression d'un contact


void deleteContact(Contact* contacts,int* nombreDeContacts,char* nomContact){
	int i,ok= 0;
	char* ptr  = (char*)malloc(sizeof(char)*100);
	Contact contactElm ;
	
		for(i=0;i<*nombreDeContacts;i++){
				strcpy(ptr,contacts[i].nom);
				if(  strcmp(ptr,nomContact) == 0 ){
					contactElm = contacts[i];
					contacts[i] = contacts[*nombreDeContacts-1];
					contacts[*nombreDeContacts-1] = contactElm;
					*nombreDeContacts -= 1;
				    ok = 1 ;  
				}
		}
		if( ok != 0 )
				printf("\t\t%s Supprimer Avec Succes\n");
		printf("\t\tConctact inexistant merci de Re-essayer !!\n\n");	
		
}


//fonction de recherche d'un contact

void searchContact(Contact* contacts,int nombreDeContacts,char* nomContact){
	int i,ok= 0;
	char *ptr = (char*)malloc(sizeof(char)*100);
	Contact contactElm ;
	
		for(i=0;i<nombreDeContacts;i++){
			strcpy(ptr,contacts[i].nom);
			if(  strcmp(ptr,nomContact) == 0 ){
				contactElm = contacts[i];
				fprintf(stdout," caracteristique du contatct de nom %s\n\t\t",nomContact);
				fputs(contactElm.nom,stdout);
				fputs(contactElm.prenoms,stdout);
				fputs(contactElm.numeroTel,stdout);
				fputs(contactElm.ville,stdout);
				fputs(contactElm.email,stdout);
				fprintf(stdout,"\n\t\t");
		        ok = 1 ;  
			}
		}
		if( ok == 0 )
				printf("\t\tConctact inexistant merci de Re-essayer !!\n\n");
}


//fonction d'affichage du menu

void menu (){

    int nombreDeContacts=0,i=0;
    Contact* contacts = (Contact*) malloc(sizeof(Contact)*TAILLE);
	int choixmenu,dernierverdicte = 1 ;
 // recuperation de tous les contacts enregistrer dans le fichier dans notre structure   
    FILE *monFichier = fopen("contact.txt","r"); 
    	if( monFichier != NULL ){
    		fgets(contacts[0].nom,100,monFichier);
    		do{
				fgets(contacts[i].prenoms,100,monFichier);
				fgets(contacts[i].numeroTel,100,monFichier);
				fgets(contacts[i].ville,100,monFichier);
				fgets(contacts[i].email,100,monFichier);
				i+=1;
    		}while( fgets(contacts[i].nom,100,monFichier) != NULL );
    		nombreDeContacts = i ;
    	}
    	// printf("%d\n", nombreDeContacts);
    
    
    
   	
   	while( dernierverdicte >= 0){
		printf("\n\t\tConctact ManagementApp :\tQue Voulez-Vous Faire ??\n\n\t\t 1--> enregistrer un contact  \n\t\t 2--> afficher la liste de contacts   \n\t\t 3--> modifier les informations d'un contact  \n\t\t 4--> suprimer un contact \n\t\t 5--> rechercher les informations d'un contact \n\t\t 6--> afficher toutes les historiques \n\t\t 7--> Sortir  \n\n Votre Choix: ");
		scanf("%d",&choixmenu);
		while( choixmenu < 1 && choixmenu > 6){
			printf(" ATTENTION !!!!!\n\t\tle choix que vous avez faits n'est pas reconnue \n"); 
			printf("\n\t\tConctact ManagementApp :\tQue Voulez-Vous Faire ??\n\n\t\t 1--> enregistrer un contact  \n\t\t 2--> afficher la liste de contacts   \n\t\t 3--> modifier les informations d'un contact  \n\t\t 4--> suprimer un contact \n\t\t 5--> rechercher les informations d'un contact \n\t\t 6--> afficher toutes les historiques \n\t\t 7--> Sortir  \n\n Votre Choix: ");
			scanf("%d",&choixmenu);
		}
		
		
	   	if( choixmenu == 1 ){
			newContact(contacts,&nombreDeContacts);
			char* nomAction = (char*)malloc(sizeof(char)*100);
			nomAction = "cree nouveau contact" ;
			historique(nomAction);
		}
		
			if( choixmenu == 2 ){
			
				readContactList(contacts,nombreDeContacts);
				char* nomAction = (char*)malloc(sizeof(char)*100);
				nomAction = "affiche liste contact" ;
				historique(nomAction);
			}
			
			
			if(	choixmenu == 3 ){
				char* nomModifie = (char*)malloc(sizeof(char)*TAILLE);
				printf("\t\tEntrer le nom du conctact a Modifier  ");
				fgets(nomModifie,100,stdin);
				fgets(nomModifie,100,stdin);
				printf("\n");
				updateContact(contacts,nombreDeContacts,nomModifie);
				char* nomAction = (char*)malloc(sizeof(char)*100);
				nomAction = "modifie" ;
				historique(nomAction);
			}
			
			
			if(	choixmenu == 4 ){
				char* nomsupprime = (char*)malloc(sizeof(char)*TAILLE);
				printf("\t\tEntrer Le Nom du Conctact a Supprimer  ");
				fgets(nomsupprime,100,stdin);
				fgets(nomsupprime,100,stdin);
				printf("\n");
				deleteContact(contacts,&nombreDeContacts,nomsupprime);
				char* nomAction = (char*)malloc(sizeof(char)*100);
				nomAction = "supprime" ;
				historique(nomAction);
			}
			
			
			if(	choixmenu == 5 ){
				char* nomcherche = (char*)malloc(sizeof(char)*TAILLE);
				printf("\t\tEntrer Le Nom du Conctact a Rechercher  ");
				fgets(nomcherche,100,stdin);
				fgets(nomcherche,100,stdin);
				printf("\n");
				searchContact(contacts,nombreDeContacts,nomcherche);
				char* nomAction = (char*)malloc(sizeof(char)*100);
				nomAction = "recherche" ;
				historique(nomAction);
			}
		
		
		
		if( choixmenu == 6){
			FILE *monFichier = fopen("time.txt","r");
			printf("\n");
			char* ptr = (char*)malloc(sizeof(char)*100) ;
			
			if( monFichier != NULL ){
				while ( fgets(ptr,100,monFichier) != NULL ){
					printf("\t\t%s\n",ptr);
				}
				fclose(monFichier);
				char* nomAction = (char*)malloc(sizeof(char)*100);
				nomAction = "affiche historique" ;
				historique(nomAction);
			}
			else 
				printf("\n\t\t aucune historique trouver dans la base de donne \n");
		}
		
		
		
		if(	choixmenu == 7 ){
			Contact contactElm ;
			//Sauvegarde de tous les  contacts dans le fichier;
			FILE *monFichier = fopen("contact.txt","w");
			for(i=0;i<nombreDeContacts;i++){
				contactElm = contacts[i] ;
				fputs(contactElm.nom,monFichier);
				fputs(contactElm.prenoms,monFichier);
				fputs(contactElm.numeroTel,monFichier);
				fputs(contactElm.ville,monFichier);
				fputs(contactElm.email,monFichier);
			}
			fclose(monFichier);
			exit(EXIT_FAILURE);
		}
	}
}



//gestion historique 


void historique(char* nomAction){
	
	//Ouverture du fichier en mode ajout
	FILE *monFichier = fopen("time.txt","a");
	int h,min,s,day,mois,an;
	time_t now ;
	
	// revoie l'heure actuelle 
		time(&now);
	// convertir au format heure locale 
	//	printf("aujord'hui est : %s ",ctime(&now));
	struct tm *local = localtime (&now);
	
	h = local->tm_hour ;
	min = local->tm_min ;
	s = local->tm_sec ;
	day = local->tm_mday ;
	mois = local->tm_mon + 1 ;
	an = local->tm_year + 1900 ;
	fprintf(monFichier,"%s %d:%d:%d %d/%d/%d \n",nomAction,h,min,s,day,mois,an);	
	
	fclose(monFichier);
}

