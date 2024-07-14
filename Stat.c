#include "Tp_inf132.h"
const float FRAIS_INSCRIPTIONS = 3000; // Les frais d'inscription par membre

void AfficherPourcentageInsolvable(Club club){
      float pourcentage;
          FILE*Mem;
    Mem=fopen("Membres.txt","r");
    
    int i=0,total=0,compteur=0;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
   while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        compteur +=1;
        i++;
    }
    fclose(Mem);
   Mem=fopen("Membres.txt","r");
    while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        float somme=club.listeDesMembre[i].inscrip[0]+club.listeDesMembre[i].inscrip[1]+club.listeDesMembre[i].inscrip[2];
        if(somme<FRAIS_INSCRIPTIONS){
          total +=1;

        }
        i++;
    }
   fclose(Mem);
    pourcentage=(100*total)/compteur;
    printf("Il y'a exactement %.2f %% des membres actuels ayant pas  paye la totalite de leur frais d'inscription\n",pourcentage);
    sleep(2);
}
void AfficherPourcentageEnRegle(Club club){
    float pourcentage;
          FILE*Mem;
    Mem=fopen("Membres.txt","r");
    
    int i=0,total=0,compteur=0;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
   while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        compteur +=1;
        i++;
    }
    fclose(Mem);
   Mem=fopen("Membres.txt","r");
    while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        float somme=club.listeDesMembre[i].inscrip[0]+club.listeDesMembre[i].inscrip[1]+club.listeDesMembre[i].inscrip[2];
        if(somme==FRAIS_INSCRIPTIONS){
          total +=1;

        }
        i++;
    }
   fclose(Mem);
    pourcentage=(100*total)/compteur;
    printf("Il y'a exactement %.2f %% des membres actuels 'ont  paye la totalite de leur frais d'inscription\n",pourcentage);
    sleep(2);
}
void afficheEnRegle(Club club){
       FILE*Mem;
    Mem=fopen("Membres.txt","r");
    
    int i=0,trouve=0;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    printf("\n####### LISTE DES MEMBRES EN REGLE DU CLUB #######\n\n");

    while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        float somme=club.listeDesMembre[i].inscrip[0]+club.listeDesMembre[i].inscrip[1]+club.listeDesMembre[i].inscrip[2];
        if(somme==FRAIS_INSCRIPTIONS){
            trouve=1;
           printf("............................................................\n");
            printf("NUMERO : %d\n",club.listeDesMembre[i].numero);
            printf("NOM : %s\n",club.listeDesMembre[i].nom);
            printf("PRENOM : %s\n",club.listeDesMembre[i].prenom);
            printf("ROLE : %s\n",club.listeDesMembre[i].role);
            printf("MONTANT DEJA PAYE : %2.f ",somme);

        }
        i++;
    }
    fclose(Mem);
    if (trouve == 0)
        printf("Aucun membre n'est  en regle\n");
    else
        printf("**************************\n");
    sleep(2);
}
void afficheInsolvable(Club club){
       FILE*Mem;
    Mem=fopen("Membres.txt","r");
    
    int i=0,trouve=0;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    printf("\n####### LISTE DES INSOLVABLES DU CLUB #######\n\n");

    while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        float somme=club.listeDesMembre[i].inscrip[0]+club.listeDesMembre[i].inscrip[1]+club.listeDesMembre[i].inscrip[2];
        if(somme<FRAIS_INSCRIPTIONS){
            trouve=1;
           printf("............................................................\n");
            printf("NUMERO : %d\n",club.listeDesMembre[i].numero);
            printf("NOM : %s\n",club.listeDesMembre[i].nom);
            printf("PRENOM : %s\n",club.listeDesMembre[i].prenom);
            printf("ROLE : %s\n",club.listeDesMembre[i].role);
            printf("MONTANT DEJA PAYE : %2.f ",somme);

        }
        i++;
    }
    fclose(Mem);
    if (trouve == 0)
        printf("Tous les membres actuels sont en regle\n");
    else
        printf("**************************\n");
    sleep(2);
}
void afficherEffectif(){
     FILE*Mem;
    Mem=fopen("Membres.txt","r");
    Club club;
    int i=0;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    int compteur=0;
    while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        compteur +=1;
        i++;
    }
    fclose(Mem);
  printf("L'effectif total du club est : %d ",compteur);
}
void AfficherFondDeCaisse(Club club)
{
    printf("\nFOND DE CAISSE DU CLUB : %2.f FCFA\n",club.fond_caisse);
    sleep(1);
}
Club MenuStatisque(Club club){
    system("clear");
    int choixStat;

    printf("-----------------------| STATISTIQUES DU CLUB |-----------------------\n\n");
    do{
        printf("  -------------------------| BIENVENUE DANS LE MENUE DE LA STATISTIQUE |-------------------------------------\n");
        printf("Que souhaitez vous faire ?\n");
        printf("\t0. Revenir au menu principale\n");
        printf("\t1. Afficher le fond de caisse du club\n"); 
        printf("\t2. Afficher les membres n'ayant pas paye la totalite de leur inscription\n");
        printf("\t3. Afficher les membres ayant paye la totalite de leur inscription\n");
        printf("\t4. Pourcentage des membres en regles\n");
        printf("\t5. Pourcentage des personnes qui ne sont pas en regle\n");
        printf("\t6. Effectif total du club\n");
        printf("Votre choix : ");
        scanf("%d",&choixStat);
        switch (choixStat)
        {
        case 0 :
            printf("Veuillez patientez...................................................\n");
            sleep(2);
            break;
        case 1:
           AfficherFondDeCaisse(club);
           break;
        case 2 :
            afficheInsolvable( club);
            break;
        case 3:
            afficheEnRegle(club);
           break;
        case 4:
            AfficherPourcentageEnRegle(club);
            break;
        case 5:
            AfficherPourcentageInsolvable(club);
           break;
        case 6:
            afficherEffectif();
          break;
        
        default:
            printf("Choix invalide.veuillez reessayez\n");
            break;
        }

        
    }while(choixStat!=0);
    return club;
}