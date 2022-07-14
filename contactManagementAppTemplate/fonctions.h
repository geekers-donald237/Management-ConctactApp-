// @Author : Geekers-Donald237

//fichier contenant mes headers ie signatures de mes fonctions 
//et la definition de ma structure contact.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Utilisation d'une constante de preprocesseur pour definir la taille 
#define TAILLE 100
//structure contact
struct contact
{
    char nom[TAILLE];
    char prenoms[TAILLE];
    char numeroTel[TAILLE];
    char ville[TAILLE];
    char email[TAILLE];
};
typedef struct contact Contact;

//Prototypes
//////////////////////////////////////////////////////////////////////////

/*fonction pour la creation d'un nouveau contact et ajout ds le fichier
initialise les differents champs d'un contact
*/
void newContact(Contact* contacts,int* nombreDeContacts);

/*fonction pour l'affichage de la liste des contacts
*/
void readContactList(Contact* contacts,int nombreDeContacts);

/*fonction pour la modification des informations d'un contact dont on connait le nom
*/
void updateContact(Contact* contacts,int nombreDeContacts,char* nomContact);

/*fonction pour la suppression d'un contact a partir de son nom
*/
void deleteContact(Contact* contacts,int* nombreDeContacts,char* nomContact);

/*fonction pour la recherche d'un contact a partir de son nom
*/
void searchContact(Contact* contacts,int nombreDeContacts,char* nomContact);

//fonction pour le menu 
void menu();

/*fonction pour la generation de l'historique des operations ds la base de donnees.
heure+min+sec ,date de chaque operation
*/
void historique(char *monActionclear);
