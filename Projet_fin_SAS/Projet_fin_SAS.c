#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nbrtache=0;
int jour_actuel;
char recherchetitle[200];
char identifiant[100];
char title[100][100];
char description[100][200];
char deadline[100];
char statut[100][40];
//cette fonction pour afficher le menu
void afficher_Menu()
{
    system("color 09");
    printf("******               Menu                ******\n");
    printf("===============================================\n\n");
    printf("1- Ajouter une nouvelle tache_________________|\n\n");
    printf("2- Ajouter plusieurs nouvelles taches_________|\n\n");
    printf("3- Afficher la liste de toutes les taches_____|\n\n");
    printf("4- Modifier une tache_________________________|\n\n");
    printf("5- Supprimer une tache par identifiant________|\n\n");
    printf("6- Rechercher les taches______________________|\n\n");
    printf("7- Statistiques_______________________________|\n\n");
    printf("8- Quitter____________________________________|\n\n");
}

//cette fonction pour afficher les choix  de trier des tâches
void trier()
{
    printf("--> 1 Trier les taches par ordre alphabetique\n");
    printf("--> 2 Trier les taches par deadline\n");
    printf("--> 3 Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
}

//cette fonction pour afficher les choix de modification d'une tâche(decription, statut, deadline)
void modification()
{
    printf("--> 1 Modifier la description d'une tache\n");
    printf("--> 2 Modifier le statut d'une tache\n");
    printf("--> 3 Modifier le deadline d'une tache\n");
}

//cette fonction pour afficher les choix de recherche
void recherche()
{
    printf("--> 1 Rechercher une tache par son Identifiant\n");
    printf("--> 2 Rechercher une tache par son Titre\n");
}

//cette fonction pour afficher les choix de statistiques
void statistique()
{
    printf("--> 1 Afficher le nombre total des taches\n");
    printf("--> 2 Afficher le nombre de taches completes et incompletes\n");
    printf("--> 3 Afficher le nombre de jours restants jusqu'au delai de chaque tache\n");
}

//ajouter nouvelle tâche
void nouvelle_tache()
{
    printf("Veuiller entrer la tache:\n");
    printf("\n");

    identifiant[nbrtache] = nbrtache + 1;

    printf("Titre: ");
    scanf(" %[^\n]",title[nbrtache]);

    printf("Description: ");
    scanf(" %[^\n]",description[nbrtache]);

    printf("Deadline (En jours) : ");
    scanf("%d",&deadline[nbrtache]);

    printf("Statut (a realiser/en cours/finalisee) : ");
    scanf(" %[^\n]", statut[nbrtache]);

    nbrtache++;
    printf("\n");

    printf("La tache Bien Ajoutee.\n");

}


//Ajouter plusieurs nouvelles tâches
void Ajouter_plutache()
{
    int nbrTacheAjouter;
    int i;
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
        scanf(" %[^\n]",title[nbrtache]);

        printf("Description: ");
        scanf(" %[^\n]",description[nbrtache]);

        printf("Deadline (En jours) : ");
        scanf("%d",&deadline[nbrtache]);

        printf("Statut (a realiser/en cours/finalisee) : ");
        scanf(" %[^\n]",statut[nbrtache]);

        nbrtache++;

        printf("\n");

        printf("La tache Bien Ajoutee.\n");

        printf("----------------------------\n\n");
    }
}


//Afficher la liste de toutes les tâches
//***Trier les taches par ordre alphabetique***
void Tri_Ordre_Alphabetique()
{
    int i, j;
    int tempJour;
    int temp;
    char tem[100];


    for(i=0; i<nbrtache-1; i++)
    {
        for(j=0; j<nbrtache-i-1; j++)
        {
            if(strcmp(title[j],title[j+1])>0)
            {
                temp = identifiant[j];
                identifiant[j] = identifiant[j + 1];
                identifiant[j + 1] = temp;

                strcpy(tem,title[j]);
                strcpy(title[j],title[j+1]);
                strcpy(title[j+1],tem);

                strcpy(tem,description[j]);
                strcpy(description[j],description[j+1]);
                strcpy(description[j+1],tem);

                tempJour = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempJour;

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
    int i, j;
    int temp;
    int tempe[100];
    char tempStatut[100];

    for(i=0; i<nbrtache-1; i++)
    {
        for(j=0; j<nbrtache-i-1; j++)
        {
            if (deadline[j]>deadline[j+1])
            {
                temp = identifiant[j];
                identifiant[j] = identifiant[j + 1];
                identifiant[j + 1] = temp;


                strcpy(tempe,title[j]);
                strcpy(title[j],title[j+1]);
                strcpy(title[j+1],tempe);


                strcpy(tempe,description[j]);
                strcpy(description[j],description[j+1]);
                strcpy(description[j+1],tempe);


                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;

                strcpy(tempStatut,statut[j]);
                strcpy(statut[j],statut[j+1]);
                strcpy(statut[j+1],tempStatut);

            }
        }
    }

}

//***Afficher les tâches dont le deadline est dans 3 jours ou moins***
void deadline_3jours()
{
    int i;
    printf("Les Taches dans le deadline de  3 jours ou moins :\n");
    for(i=0; i<nbrtache; i++)
    {
        if(deadline[i]<=3)
        {
            printf("--------Tache N%d--------\n",i+1);
            printf("Identifiant: %d\n",identifiant[i]);
            printf("Title: %s\n",title[i]);
            printf("Description: %s\n",description[i]);
            printf("Deadline: %d Jour(s)\n",deadline[i]);
            printf("statut: %s\n",statut[i]);
            printf("-------------------------\n");
            printf("\n\n");

        }
    }
}

//***Afficher les listes des taches***
void affiche_liste_tache()
{
    int i;

    printf("la liste de toutes les taches est:\n");

    for(i=0; i<nbrtache; i++)
    {
        printf("--------Tache N%d--------\n",i+1);
        printf("Identifiant: %d\n",identifiant[i]);
        printf("Title: %s\n",title[i]);
        printf("Description: %s\n",description[i]);
        printf("Deadline: %d Jour(s)\n",deadline[i]);
        printf("statut: %s\n",statut[i]);
        printf("-------------------------\n");
        printf("\n\n");
    }
}

//Modifier une tâche

void Modification_tache()
{
    char Nouvelle_Description[100];
    char Nouvelle_statut[100];
    int i, id;
    int choix04;
    int Nouvelle_deadline[100];

    modification();

    printf("Entrer votre choix:");
    scanf("%d", &choix04);


    switch(choix04)
    {
    case 1 :
        printf("Veuiller Entrer ID de Votre tache:");
        scanf("%d",&id);
        printf("\n");

        for(i=0; i<nbrtache; i++)
        {
            if(identifiant[i]==id)
            {

                printf("Veuiller Entrer votre modification:\n");
                scanf("%s",Nouvelle_Description);

                strcpy(description[i],Nouvelle_Description);
                printf("la modification est bien ajoutee\n");
                break;
            }
            else
                printf("Errour! ID %d de tache n'est pas exact",id);
        }
        break;

    case 2 :

        printf("Veuiller Entrer ID de Votre tache:");
        scanf("%d",&id);
        printf("\n");

        for(i=0; i<nbrtache; i++)
        {
            if(identifiant[i]==id)
            {
                printf("Veuiller Entrer votre modification:\n");
                scanf("%s",Nouvelle_statut);

                strcpy(description[i],Nouvelle_statut);

                printf("la modification est bien ajoutee\n");
            }

            else
                printf("Errour! ID %d de tache n'est pas exact",id);
        }
        break;

    case 3 :

        printf("Veuiller Entrer ID de Votre tache:");
        scanf("%d",&id);
        printf("\n");

        for(i=0; i<nbrtache; i++)
        {
            if(identifiant[i]==id)
            {
                printf("Veuiller Entrer votre modification:\n");
                scanf("%d",&Nouvelle_deadline);

                deadline[i]=Nouvelle_deadline;

                printf("la modification est bien ajoutee\n");
            }

            else
                printf("Errour! ID %d de tache n'est pas exact",id);
        }
        break;
    }

}

//Supprimer une tâche par identifiant
void supprimer_Tache_par_identifiant()
{
    int i, j;
    int id;

    printf("Veuiller Entrer ID de Votre tache:");
    scanf("%d",&id);
    printf("\n");

    for(i=0; i<nbrtache; i++)
    {
        if(id == i + 1)
        {
            for(j=0; j<nbrtache-1; j++)
            {
                strcpy(title[j],title[j+1]);
                strcpy(description[j],description[j+1]);
                deadline[j]=deadline[j+1];
                strcpy(statut[j],statut[j+1]);
            }
            nbrtache--;
            printf("la tache bien supprimer\n");
            break;
        }
    }
    printf("Auccun tache trouver par cette ID");

}

//Rechercher les Tâches
//***Recherche par Identifiant***
void rechrche_par_id()
{
    int i;
    int id;

    printf("Veuiller Entrer ID de Votre tache:");
    scanf("%d",&id);
    printf("\n");

    for(i=0; i<nbrtache; i++)
    {
        if(identifiant[i]==id)
        {
            printf("-------------------------\n");
            printf("Identifiant: %d\n",identifiant[i]);
            printf("Title: %s\n",title[i]);
            printf("Description: %s\n",description[i]);
            printf("Deadline: %d En jour(s)\n",deadline[i]);
            printf("statut: %s\n",statut[i]);
            printf("-------------------------\n");
        }
        else
            printf("Auccun tache declarer par cette identifiant\n");


    }
    printf("\n\n");

}
//***Recherche par Title***
void recherche_par_titre()
{
    int i;

    printf("Veuiller Entrer Titre de Votre tache:");
    scanf("%s",recherchetitle);
    printf("\n");

    for(i=0; i<nbrtache; i++)
    {
        if(strcmp(title[i],recherchetitle)==0)
        {
            printf("-------------------------\n");
            printf("Identifiant: %d\n",identifiant[i]);
            printf("Title: %s\n",title[i]);
            printf("Description: %s\n",description[i]);
            printf("Deadline: %d En jour(s)\n",deadline[i]);
            printf("statut: %s\n",statut[i]);
            printf("-------------------------\n");
        }
        else
            printf("Auccun tache declarer par cette title");



    }
}
//statistique
void NbrTach_Completes_Incompletes()
{
    int i;
    int nb_completes=0;
    int nb_incompletes=0;
    for (i = 0; i < nbrtache; i++)
    {
        if (strcmp(statut[i], "finalisee") == 0)
        {
            nb_completes++;
        }
        else
        {
            nb_incompletes++;
        }
    }
    printf("Nombre de taches completes : %d\n", nb_completes);
    printf("Nombre de taches incompletes : %d\n", nb_incompletes);
}

void affiche_Jours_restants()
{

    if (nbrtache > 0)
    {

        int valeurAbsolue;
        printf("Taches et nombre de jours restants jusqu'a la date limite :\n");

        for (int i = 0; i < nbrtache; i++)
        {
            int jours_restants = deadline[i];

            printf("-------- Tache N%d --------\n", i + 1);
            printf("Titre : %s\n", title[i]);
            printf("Description : %s\n", description[i]);
            printf("Deadline : %d jour(s)\n", deadline[i]);
            printf("Statut : %s\n", statut[i]);
            printf("Jours restants : %d jour(s)\n", valeurAbsolue = fabs(jours_restants));
            printf("-------------------------\n\n");
        }

    }
    else
    {
        printf("Aucune tache n'a ete ajoutee.\n");
    }

}


int main()
{
    int choix01, choix02, choix03, choix04;

    printf("  Y   Y  OOO  U   U  CCCC  OOO  DDDD   EEEE\n");
    printf("   Y Y  O   O U   U C     O   O D   D  E   \n");
    printf("    Y   O   O U   U C     O   O D   D  EEEE\n");
    printf("    Y   O   O U   U C     O   O D   D  E   \n");
    printf("    Y    OOO   UUU   CCCC  OOO  DDDD   EEEE\n");
    printf("\n\n");

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

        case 3:
            trier();
            printf("Entrer votre choix:");
            scanf("%d",&choix02);

            switch (choix02)
            {
            case 1:
                Tri_Ordre_Alphabetique();
                affiche_liste_tache();
                break;
            case 2:
                Tri_par_Deadline();
                affiche_liste_tache();
                break;
            case 3:
                deadline_3jours();
                break;
            default:
                printf("Choix invalide pour le tri.\n");
            }
            break;

        case 4 :
            Modification_tache();
            break;

        case 5 :
            supprimer_Tache_par_identifiant();
            break;

        case 6 :
            recherche();

            printf("Entrer votre choix:");
            scanf("%d",&choix03);
            printf("\n");

            switch(choix03)
            {
            case 1 :
                rechrche_par_id();
                break;

            case 2 :
                recherche_par_titre();
                break;
            }
            break;

        case 7 :
            statistique();

            printf("Entrer votre choix:");
            scanf("%d",&choix04);
            printf("\n");

            switch(choix04)
            {
            case 1 :
                affiche_liste_tache();
                break;
            case 2 :
                NbrTach_Completes_Incompletes();
                break;
            case 3 :
                affiche_Jours_restants();
                break;
            }
            break;

        case 8:
            printf("Au revoir !\n");
            break;

        default:
            printf("Choix invalide.\n");
            break;
        }
    }
    while(choix01!=8);

    return 0;
}
