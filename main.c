 #include "Tp_inf132.h"
int main(){
    
    int choixClub;
    Club club;
    club.fond_caisse=0;
    printf("\t************************* |BIENVENU DANS LE PROGRAMME DE GESTION D'UN CLUB| *************\n\n");
    sleep(2);
    printf("Donnez un nom a votre club : ");
    scanf("%s",club.nom);
    system("clear");
    do{
        system("clear");
        printf("-----------------------| GESTION DU CLUB %s |-----------------------\n\n", club.nom);
        printf("Veuillez choisir un menu\n");
        printf("\t0.Quitter le logiciel\n");
        printf("\t1. Gestion des Membres\n");
        printf("\t2. Gestion des Taches\n");
        printf("\t3. Gestion des ressources\n");
        printf("\t4. Statistiques\n");
        printf("Votre choix : ");
        scanf("%d",&choixClub);
        switch (choixClub)
        {
        case 0:
            printf("Merci pour votre visite et a la prochaine ! 😊 👌 \n");
            sleep(2);
            system("clear");
            printf("\t Sortie du logiciel...........................\n");
            sleep(2);
            break;
        case 1:
           club=MenuGestionMembres(club);
           break;

        case 2:
           club=MenuGestionTaches(club);
           break;
        case 3:
           club=MenuGestionRessources(club);
           break;
        case 4:
          club=MenuStatisque(club);
          break;
        default:
             printf("Désolé cette fonctionnalité n'est disponible. Veuillez reessayez!!\n");
           
            break;
        }

    }while(choixClub!=0);
    
  
   
    return 0;
}