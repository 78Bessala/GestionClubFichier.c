#include "Tp_inf132.h"
equipe NouvelEquipement;
Reservations NouvelleReservation;
Dons liste_d;

void EnregEquipement(equipe nouv_eq){
    FILE*eq=fopen("Equipements.txt","a");
    if(eq==NULL){
        printf("Err d'aouverture du fichier\n");
        return;
    }
    fprintf(eq,"%s;%s;%d\n",nouv_eq.code,nouv_eq.nom,nouv_eq.disponible);
    fclose(eq);
    printf("equipement ayant le code %s est enregistre avec success\n",nouv_eq.code);

}
void Enregdons(Dons nouv_d,Club *club){
    FILE *don=fopen("Dons.txt","a");
     if(don==NULL){
        printf("Erreur d'aouverture du fichier\n");
        return;
    }
    fprintf(don,"%s;%2.f\n",nouv_d.donnateur,nouv_d.somme);
    fclose(don);
    printf("Le dons de Mr(Ms) %s est reçu avec succes\n",nouv_d.donnateur);
    club->fond_caisse +=nouv_d.somme;    
}


void Donnation(Club*club,equipe nouv_eq,Dons nouv_d){
     
 int choix;
    printf("\nQuel type de don souhaitez vous enregistrer ?\n");
    printf("\t1. Financier\n");
    printf("\t2. Materiel\n");
    printf("Choix : ");
    scanf("%d", &choix);

    while ((choix != 1) && (choix != 2))
    {
        printf("Veuiilez choisir soit 1, soit 2 : ");
        scanf("%d",&choix);
    }
    if(choix==2){
        printf("Veuillez entrer le code de l'equipement sur le format(23AZe)\n");
            scanf("%s",nouv_eq.code);
           verifictionseq(nouv_eq.code, club);
           printf("Entrer le nom de l'equipement\n");
           scanf("%s",nouv_eq.nom);
           printf("Entrer la quantite disponible\n");
           scanf("%d",&nouv_eq.disponible);
           
        EnregEquipement(nouv_eq);
      
    }else{
        printf("Entrer le nom du donnateur\n");
        scanf("%s",nouv_d.donnateur);
        printf("\n Combien souhaitez vous donner ? : ");
        scanf("%f", &nouv_d.somme);
        Enregdons( nouv_d,club);
        printf("\nDon de %2.f FCFA enregistre avec succes !\n\n",nouv_d.somme);
        printf("Le club %s vous remercie infiniment\n",club->nom);
        sleep(1);
    }
}
void supprimerEquip(char *cod){
      FILE *eq = fopen("Equipements.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (eq == NULL || temp == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

    Club club;
    int found = 0;
    int i = 0;

    while (fscanf(eq,"%[^;];%[^;];%d",club.listeDesEquipements[i].code,
    club.listeDesEquipements[i].nom,&club.listeDesEquipements[i].disponible)!=EOF) {

        if (strcmp(club.listeDesEquipements[i].code, cod)!=0) {
            // Ecrire dans le fichier temporaire si le numéro ne correspond pas
            fprintf(temp,"%s;%s;%d\n",club.listeDesEquipements[i].code,
            club.listeDesEquipements[i].nom,club.listeDesEquipements[i].disponible);
        } else {
            found = 1; // Marquer que le membre a été trouvé
        }
    }

    fclose(eq);
    fclose(temp);

    // Remplacer l'ancien fichier par le nouveau
    remove("Equipements.txt");
    rename("temp.txt", "Equipements.txt");

    if (found) {
        printf("Equipement ayant code %s a été supprimé.\n", cod);
    } else {
        printf("Equipement ayant le code %s non trouvé.\n", cod);
    }
}

void ModifierEq(char *cod){
    FILE *eq;
    eq=fopen("Equipements.txt","r");
    Club club;
    int i=0,baron=0,choice;
    if(eq==NULL){
        printf("Fichier inexistant\n");
        return;
    }
    while(fscanf(eq,"%[^;];%[^;];%d",club.listeDesEquipements[i].code,
    club.listeDesEquipements[i].nom,&club.listeDesEquipements[i].disponible)==3){
        if(strcmp(club.listeDesEquipements[i].code, cod)==0){
            baron=1;
            printf("............................................................\n");
            printf("CODE : %s\n",club.listeDesEquipements[i].code);
            printf("NOM : %s\n",club.listeDesEquipements[i].nom);
            printf("DISPONIBLE: %d\n",club.listeDesEquipements[i].disponible);
            printf("............................................................\n");
                        printf("\n\tQuelle information souhaitez vous modifier ? \n");
            printf("\t1. code \t2. nom \t3. Qunatite disponible \n");
            printf("Choix de modification : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                printf("Entrer le nouveau code : ");
                scanf("%s",club.listeDesEquipements[i].code);
                break;
            case 2:
               printf("Entrer le nouveau nom : ");
               scanf("%s",club.listeDesEquipements[i].nom);
               break;
            case 3:
                printf("Entrer la nouvelle quantite  disponible: ");
                scanf("%d",&club.listeDesEquipements[i].disponible);
                break;
            
            default:
               printf("Choix invalide !\n");
                break;
            }
        }
        i++;
    }
    fclose(eq);
if(baron==0){
    printf("Aucun equipement ayant le code %s n'a ete trouve\n",cod);
}else{
    eq=fopen("Equipements.txt","w");
    if(eq==NULL)
        return;
    for(i=0;i<Max;i++){
        if(strcmp(club.listeDesEquipements[i].code, "") != 0)
            fprintf(eq,"%s;%s;%d\n",club.listeDesEquipements[i].code,club.listeDesEquipements[i].nom,club.listeDesEquipements[i].disponible);
        else
          break;
    }
    fclose(eq);
}
 printf("\nModification effectue avec success ! \n");
    sleep(2);
}
void AffichereqTotal(){
    FILE *eq;
    eq = fopen("Equipements.txt", "r");
    Club club;
    int i = 0;

    if (eq == NULL) {
        printf("Fichier inexistant\n");
        return;
    }

    printf("--------------| Listes Totales des Equipements |-----------------\n\n");

    while (i < Max && fscanf(eq, "%[^;];%[^;];%d", club.listeDesEquipements[i].code,
           club.listeDesEquipements[i].nom, &club.listeDesEquipements[i].disponible) == 3) {
        printf("............................................................\n");
        printf("CODE : %s\n", club.listeDesEquipements[i].code);
        printf("NOM : %s\n", club.listeDesEquipements[i].nom);
        printf("DISPONIBLE: %d\n", club.listeDesEquipements[i].disponible);
        printf("............................................................\n");
        i++;
    }

    fclose(eq);
}

void verifictionseq(char *code, Club *club) {
    FILE *eq = fopen("Equipements.txt", "r");
    if (eq == NULL) {
        printf("Fichier inexistant\n");
        return;
    }

    printf("--------------|listes totales des equipements|-----------------\n\n");

    int i = 0;
    while (i < Max && fscanf(eq, "%4[^;];%19[^;];%d\n",
                                   club->listeDesEquipements[i].code,
                                   club->listeDesEquipements[i].nom,
                                   &club->listeDesEquipements[i].disponible) == 3) {
        if (strcmp(club->listeDesEquipements[i].code, code) == 0) {
            fclose(eq);
            printf("Un equipement portant ce code existe deja, veuillez entrer un autre code : ");
            scanf("%s", code);
            verifictionseq(code, club);  // Appel récursif pour vérifier à nouveau le nouveau code
            return;
        }
        i++;
    }

    fclose(eq);
    printf("Le code est valide et peut être utilisé.\n");
}





int verificationExistanceMembre(int nume, Club *club) {
    FILE *Mem = fopen("Membres.txt", "r");
    if (Mem == NULL) {
        printf("Erreur d'ouverture du fichier Membres.txt\n");
        return 1; // Indiquer une erreur potentielle
    }

    int i = 0;
    while (i < Max && fscanf(Mem, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",
                             &club->listeDesMembre[i].numero,
                             club->listeDesMembre[i].nom,
                             club->listeDesMembre[i].prenom,
                             club->listeDesMembre[i].role,
                             club->listeDesMembre[i].coordon,
                             club->listeDesMembre[i].horaire,
                             &club->listeDesMembre[i].inscrip[0],
                             &club->listeDesMembre[i].inscrip[1],
                             &club->listeDesMembre[i].inscrip[2]) != EOF) {
        if (club->listeDesMembre[i].numero==nume) {
            // Responsable trouvé
            fclose(Mem);
            return nume;
        }
        i++;
    }

    fclose(Mem);

    // Si on arrive ici, le responsable n'a pas été trouvé
    printf("Un membre ayant ce numero n'existe pas. Veuillez entrer à nouveau le nom de responsable à qui la tâche doit être attribuée : ");
    scanf("%d", &nume);
    return verificationExistanceMembre(nume, club); // Appeler récursivement pour revérifier
}
void FaireReserVation(Reservations nouv_Re){
    FILE *Reserve=fopen("Reservations.txt","a");
    if(Reserve==NULL){
        printf("Erreur d'ouverture du fichier\n");
    }
    fprintf(Reserve,"%s;%s;%d;%d;%s\n",nouv_Re.code_equipement,nouv_Re.designation,nouv_Re.quantite,nouv_Re.numero_membre,nouv_Re.date);
    fclose(Reserve);
}
void affEqDiso() {
    Club club = {0};
    FILE *eq = fopen("Equipements.txt", "r");
    FILE *Reserve = fopen("Reservations.txt", "r");
    if (eq == NULL || Reserve == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        if (eq != NULL) fclose(eq);
        if (Reserve != NULL) fclose(Reserve);
        return;
    }

    printf("########################################### Listes des equipements disponibles ####################################\n");

    int i = 0, j = 0;
    while (i < Max && fscanf(Reserve, "%[^;];%[^;];%d;%d;%[^\n]\n",
                club.listeDesReservation[i].code_equipement,
                club.listeDesReservation[i].designation,
                &club.listeDesReservation[i].quantite,
                &club.listeDesReservation[i].numero_membre,
                club.listeDesReservation[i].date) == 5) {
        
        while (j < Max && fscanf(eq, "%[^;];%[^;];%d\n",
                club.listeDesEquipements[j].code,
                club.listeDesEquipements[j].nom,
                &club.listeDesEquipements[j].disponible) == 3) {
            
            if (club.listeDesEquipements[j].disponible > club.listeDesReservation[i].quantite) {
                int result = club.listeDesEquipements[j].disponible - club.listeDesReservation[i].quantite;
                club.listeDesEquipements[j].disponible = result;
                printf("-------------------------------------------------------------\n");
                printf("CODE : %s\n", club.listeDesEquipements[j].code);
                printf("NOM : %s\n", club.listeDesEquipements[j].nom);
                printf("QUANTITE : %d\n", club.listeDesEquipements[j].disponible);
                printf("--------------------------------------------------------------\n");
            }
            j++;
        }
        if (j == 0) {
            printf("\n Aucun equipement n'est disponible\n");
        }
        rewind(eq);  // Reset eq file pointer to start for next iteration
        j = 0;  // Reset index for next iteration
        i++;
    }

    fclose(Reserve);
    fclose(eq);
}
void afficheEqOccupe() {
    Club club = {0};
    FILE *Mem = fopen("Membres.txt", "r");
    FILE *eq = fopen("Equipements.txt", "r");
    FILE *Reserve = fopen("Reservations.txt", "r");
    if (Mem == NULL || eq == NULL || Reserve == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

    printf("########################################### Listes des equipements reserves ####################################\n");

    int i = 0, j = 0, k = 0,trouve=0;
    while (i < Max && fscanf(Reserve, "%[^;];%[^;];%d;%d;%[^\n]\n",
                club.listeDesReservation[i].code_equipement,
                club.listeDesReservation[i].designation,
                &club.listeDesReservation[i].quantite,
                &club.listeDesReservation[i].numero_membre,
                club.listeDesReservation[i].date) == 5){
        
        while (j < Max && fscanf(eq, "%[^;];%[^;];%d\n",
                club.listeDesEquipements[j].code,
                club.listeDesEquipements[j].nom,
                &club.listeDesEquipements[j].disponible) == 3){
                   if(strcmp(club.listeDesEquipements[j].code,club.listeDesReservation[i].code_equipement)==0){
                    trouve=1;
                    printf("-------------------------------------------------------------\n");
                    printf("CODE : %s\n", club.listeDesEquipements[j].code);
                    printf("NOM : %s\n", club.listeDesEquipements[j].nom);
                    printf("QUANTITE RESERVE: %d\n", club.listeDesReservation[i].quantite);
                    printf("--------------------------------------------------------------\n");
                    printf("NUMERO DU MEMBRE AYANT FAIT LA RESERVATION : %d \n",club.listeDesReservation[i].numero_membre);
                        while( k<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[k].numero,
                       club.listeDesMembre[k].nom,club.listeDesMembre[k].prenom,club.listeDesMembre[k].role,
                       club.listeDesMembre[k].coordon,club.listeDesMembre[k].horaire,&club.listeDesMembre[k].inscrip[0],
                       &club.listeDesMembre[k].inscrip[1],&club.listeDesMembre[k].inscrip[2])!=EOF){
                               if(club.listeDesReservation[i].numero_membre==club.listeDesMembre[k].numero){
                                       printf("NOM DU MEMBRE AYANT RESERVER: %s\n",club.listeDesMembre[i].nom);
                                      break;
                              }else{
                                    printf("Aucun membre n'a le numero  : %d \n",club.listeDesReservation[i].numero_membre);
                      k++;        }
                      }
                   }
                  j++;
                }
        i++;
     }
     fclose(Mem);
     fclose(eq);
     fclose(Reserve);
    if(trouve==0)
        printf("Aucun equipement n' est reserve\n");
    else
       return; 
   
}
void changer_ladisponiblite(Club *club, const char *code) {
    FILE *eq = fopen("Equipements.txt", "r+");
    FILE *Reserve = fopen("Reservations.txt", "r");

    if (eq == NULL || Reserve == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        if (eq != NULL) fclose(eq);
        if (Reserve != NULL) fclose(Reserve);
        return;
    }

    int i = 0, j = 0;
    int found = 0;

    printf("########################################### Listes des equipements disponibles ####################################\n");

    while (i < Max && fscanf(Reserve, "%[^;];%[^;];%d;%d;%[^;]\n",
                                         club->listeDesReservation[i].code_equipement,
                                         club->listeDesReservation[i].designation,
                                         &club->listeDesReservation[i].quantite,
                                         &club->listeDesReservation[i].numero_membre,
                                         club->listeDesReservation[i].date) == 5) {
        if (strcmp(club->listeDesReservation[i].code_equipement, code) == 0) {
            rewind(eq);
            while (j < Max && fscanf(eq, "%[^;];%[^;];%d\n",
                                           club->listeDesEquipements[j].code,
                                           club->listeDesEquipements[j].nom,
                                           &club->listeDesEquipements[j].disponible) == 3) {
                if (strcmp(club->listeDesEquipements[j].code, code) == 0) {
                    if (club->listeDesEquipements[j].disponible < club->listeDesReservation[i].quantite) {
                        printf("Impossible de faire la reservation\n");
                    } else {
                        club->listeDesEquipements[j].disponible -= club->listeDesReservation[i].quantite;
                        fseek(eq, -sizeof(int), SEEK_CUR);
                        fprintf(eq, "%d\n", club->listeDesEquipements[j].disponible);
                        found = 1;
                    }
                    break;
                }
                j++;
            }
            if (found) break;
        }
        i++;
    }

    fclose(Reserve);
    fclose(eq);

    if (!found) {
        printf("Aucun equipement trouvé avec le code fourni\n");
    }
}


Club MenuGestionRessources(Club club){
     system("clear");
    int choixRessource;
    char codes[5];

    printf("-----------------------| GESTION DES RESSOURCES |-----------------------\n\n");
    do{
        printf("\t*******************************<< BIENVENU DANS MENU DE GESTION DES RESSOURCES >>**************************************\n");
        printf("Que souhaitez vous faire ?\n");
        printf("\t0. Revenir au menu principale\n");
        printf("\t1. Faire un don\n"); 
        printf("\t2. Enregistrer un equipement\n");
        printf("\t3. Supprimer un equipement\n");
        printf("\t4. Afficher la liste des equipements disponibles\n");
        printf("\t5. Afficher la liste des equipements reserve\n");
        printf("\t6. Afficher la liste total des equipements\n");
        printf("\t7. Reserver un equipement\n");
        printf("Votre choix : ");
        scanf("%d",&choixRessource);
        switch (choixRessource)
        {
        case 0:
            printf("Veuillez patientez...............................\n");
            sleep(2);
            break;
        case 1:
            Donnation(&club,NouvelEquipement,liste_d);
           break;
        case 2:
            printf("Veuillez entrer le code de l'equipement sur le format(23AZe)\n");
            scanf("%s",NouvelEquipement.code);
           verifictionseq(NouvelEquipement.code, &club);
           printf("Entrer le nom de l'equipement\n");
           scanf("%s",NouvelEquipement.nom);
           printf("Entrer la quantite disponible\n");
           scanf("%d",&NouvelEquipement.disponible);
           EnregEquipement(NouvelEquipement);
          break;
        case 3:
            printf("Entrer le code de l'equipement\n");
            scanf("%s",codes);
            supprimerEquip(codes);
           break;
        case 4:
           affEqDiso();
          break; 
        case 5:
          afficheEqOccupe();
          break;
        case 6:
           AffichereqTotal();
           break;
        case 7:
         FILE *eq=fopen("Equipements.txt","r");
         FILE *Mem=fopen("Membres.txt","r");
          if(eq==NULL){
            printf("\nNous n'avons aucun equipement en stock pour le moment\n");
             sleep(1);
             break;
          }
        
          if(Mem==NULL){
            printf("\nVeuillez enregistrer au moins un membre avant d'effectuer une reservation\n");
                sleep(1);
                break;
          }
          printf("Entrer le numero de l'equipement\n");
          scanf("%s",NouvelleReservation.code_equipement);
          verifictionseq(NouvelleReservation.code_equipement, &club);
          printf("Entrer le nom de l'equipement\n");
          scanf("%s",NouvelleReservation.designation);
          printf("Le nombre d'equipements a reserver\n");
          scanf("%d",&NouvelleReservation.quantite);
          printf("Entrez le numero du membre souhaitant effectuer la reservation : ");
          scanf("%d",&NouvelleReservation.numero_membre);
           if(verificationExistanceMembre(NouvelleReservation.numero_membre, &club)==0){
                printf("\nEchec de reservation : nous ne disposons d'aucun membre portant le numero '%d' \n", NouvelleReservation.numero_membre);
                sleep(1);
                break; 
           }
           printf("Entrez la date du jour sous le format (jj/mm/aaaa), Exemple : 03/05/2024 : ");
           scanf("%s",NouvelleReservation.date);

          FaireReserVation(NouvelleReservation);
           changer_ladisponiblite( &club,NouvelleReservation.code_equipement);
          break;
        
        default:
            printf("Désolé cette fonctionnalite n'est pas encore disponible.Veuillez reesayez!!\n");
            break;
        }
    }while(choixRessource!=0);
    return club;
}

