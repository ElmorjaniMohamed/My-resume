#include <stdio.h>
#include <stdlib.h>


int nbrtache=0, i, j;
char identifiant[100];
char title[100][100];
char description[100][200];
char deadline[100][20];
char statut[100][40];
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
    printf("7- Statistiques\n\n");
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
    printf("Veuiller entrer la tache:\n");
    printf("\n");

    identifiant[nbrtache] = nbrtache + 1;

    printf("Titre: ");
    scanf("%s", title[nbrtache]);

    printf("Description: ");
    scanf("%s", description[nbrtache]);

    printf("Deadline (Ex: 12/03/2023) : ");
    scanf("%s", deadline[nbrtache]);

    printf("Statut (à realiser/en cours/finalisee) : ");
    scanf("%s", statut[nbrtache]);
    nbrtache++;

    printf("La tache Bien Ajoutee.\n");

}


//Ajouter plusieurs nouvelles tâches
void Ajouter_plutache()
{
    int nbrTacheAjouter;
    printf("Veuillez Entrer Votre nombre des taches:");
    scanf("%d",&nbrTacheAjouter);
    printf("\n");
    printf("Veuiller entrer les tache:\n");
    printf("\n");
    printf("----------------------------\n");
    for(i=0; i<nbrTacheAjouter; i++)
    {
        identifiant[nbrtache] = nbrtache + 1;

        printf("Titre: ");
        scanf("%s",title[nbrtache]);

        printf("Description: ");
        scanf("%s",description[nbrtache]);

        printf("Deadline (Ex: 12/03/2023) : ");
        scanf("%s",deadline[nbrtache]);

        printf("Statut (a realiser/en cours/finalisee) : ");
        scanf("%s",statut[nbrtache]);

        nbrtache++;

        printf("La tache Bien Ajoutee.\n");
        printf("----------------------------\n\n");
    }
}

//Afficher la liste de toutes les tâches
//***Trier les taches par ordre alphabetique***
void Tri_Ordre_Alphabetique()
{
    for(i=0; i<nbrtache-1; i++)
    {
        for(j=0; j<nbrtache-1; j++)
        {
            if (strcmp(title[j],title[j+1])> 0)
            {
                int tempTd = identifiant[j];
                identifiant[j] = identifiant[j + 1];
                identifiant[j + 1] = tempTd;


                char tem[100];
                strcpy(tem,title[j]);
                strcpy(title[j],title[j+1]);
                strcpy(title[j+1],tem);

                strcpy(tem,description[j]);
                strcpy(description[j],description[j+1]);
                strcpy(description[j+1],tem);


                strcpy(tem,deadline[j]);
                strcpy(deadline[j],deadline[j+1]);
                strcpy(deadline[j+1],tem);

                strcpy(tem,statut[j]);
                strcpy(statut[j],statut[j+1]);
                strcpy(statut[j+1],tem);

            }
        }
    }
}

//***Trier les taches par Deadline***
void Tri_par_Deadline()
{

}


//***Afficher les listes des taches***
void affiche_liste_tache()
{
    printf("la liste de toutes les taches est:\n");
    for(i=0; i<nbrtache; i++)
    {
        printf("--------Tache N%d--------\n",i);
        printf("Identifiant: %d\n",identifiant[i]);
        printf("Title: %s\n",title[i]);
        printf("Description: %s\n",description[i]);
        printf("Deadline: %s\n",deadline[i]);
        printf("statut: %s\n",statut[i]);
        printf("-------------------------\n");
        printf("\n\n");
    }
}
int main()
{
    int choix01, choix02;

    do
    {

        afficher_Menu();

        printf("Entrer votre choix:");
        scanf("%d", &choix01);

        switch (choix01)
        {
        case 1 :
            nouvelle_tache();
            break;
        case 2 :
            Ajouter_plutache();
            break;
        case 3 :
            trier();
            printf("Entrer votre choix:");
            scanf("%d", &choix02);
            switch(choix02)
            {
                case 1 : Tri_Ordre_Alphabetique();
                         affiche_liste_tache();
                case 2 : Tri_par_Deadline();

            }
        }
    }
    while(choix01!=8);


    return 0;
}
