#include <stdio.h>
#include <stdlib.h>

char T[100], D[300], S[20];
int t;


//cette fonction pour afficher le menu
void afficher_Menu()
{
    system("color 0A");
    printf("******      Menu      ******\n");
    printf("============================\n\n");
    printf("1- Ajouter une nouvelle tache\n\n");
    printf("2- Ajouter plusieurs nouvelles taches\n\n");
    printf("3- Afficher la liste de toutes les taches\n\n");
    printf("4- Modifier une tache\n\n");
    printf("5- Supprimer une tache par identifiant\n\n");
    printf("6- Rechercher les taches\n\n");
    printf("7- Statistiques\n");
    printf("8- Quitter\n\n");
}

//cette fonction pour afficher les choix  de trier des tâches
void trier()
{
    printf("3-1 Trier les taches par ordre alphabetique\n");
    printf("3-2 Trier les taches par deadline\n");
}

//cette fonction pour afficher les choix de modification d'une tâche(decription, statut, deadline)
void modification()
{
    printf("4-1 Modifier la description d'une tache\n");
    printf("4-2 Modifier le statut d’une tache\n");
    printf("4-3 Modifier le deadline d’une tache\n");
}

//cette fonction pour afficher les choix de recherche
void recherche()
{
    printf("6-1 Rechercher une tache par son Identifiant\n");
    printf("6-2 Rechercher une tache par son Titre\n");
}

//cette fonction pour afficher les choix de statistiques
void statistique()
{
    printf("7-1 Afficher le nombre total des taches\n");
    printf("7-2 Afficher le nombre de taches complètes et incompletes\n");
    printf("7-3 Afficher le nombre de jours restants jusqu'au delai de chaque tache\n");
}

//ajouter nouvelle tâche
void nouvelle_tache()
{
    int id,jour,n=1;

    printf("Veuiller entrer une nouvelle tache:\n");

    printf("identifiant:");
    scanf("%d",&id);

    printf("Title:");
    scanf(" %[^\n]s",T);

    printf("Description:");
    scanf(" %[^\n]s",D);

    printf("Deadline(en jour(s)):");
    scanf("%d",&jour);

    printf("Statut:");
    scanf(" %[^\n]s\n\n\n",S);


    printf("=========Tache:%d=========\n",n);
    printf("identifiat: %d\n",id);
    printf("Title: %s\n",T);
    printf("Description: %s\n",D);
    printf("Deadline: %d jour(s)\n",jour);
    printf("Statut: %s\n",S);
    n++;

}

//Ajouter plusieurs nouvelles tâches
void Ajouter_plutache()
{
    int id,jour, i, n=1;
    printf("Veuillez Entrer Votre nombre des taches:");
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        printf("Veuiller entrer les tache:\n");
        printf("Tache:%d\n",n);

        printf("identifiant:");
        scanf("%d",&id);

        printf("Title:");
        scanf(" %[^\n]s",T);

        printf("Description:");
        scanf(" %[^\n]s",D);

        printf("Deadline(en jour(s)):");
        scanf("%d",&jour);

        printf("Statut:");
        scanf(" %[^\n]s\n\n\n",S);

        printf("=========Tache:%d=========\n",n);
        printf("identifiat: %d\n",id);
        printf("Title: %s\n",T);
        printf("Description: %s\n",D);
        printf("Deadline: %d jour(s)\n",jour);
        printf("Statut: %s\n",S);
        n++;
    }
//Afficher la liste de toutes les tâches




}
int main()
{
    int choix1, choix2;

    do
    {
        afficher_Menu();

        printf("Entrer votre choix:");
        scanf("%d", &choix1);

        switch (choix1)
        {
        case 1 : nouvelle_tache();
                 printf("\n\n");
                 break;
        case 2 : Ajouter_plutache();
                 break;
            case 3 :
                trier();
                printf("Entrer votre choix:");
                scanf("%d", &choix2);








            }
        }
        while(choix1!=0);
        return 0;
    }
