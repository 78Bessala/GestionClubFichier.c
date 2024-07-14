#include "Tp_inf132.h"
 Tache Ntache;

void rechercheTache(int number){
      FILE *Tach;
    Tach=fopen("Taches.txt","r");
    Club club;
    int i=0,baron=0;
    if(Tach==NULL){
        printf("Fichier inexistant\n");
        return;
    }
    while(fscanf(Tach,"%d;%[^;];%f;%[^;];%[^;];%[^;]",&club.listeDesTaches[i].numero,
    club.listeDesTaches[i].libelle,&club.listeDesTaches[i].bud_dep,club.listeDesTaches[i].statut,
    club.listeDesTaches[i].dateFin,club.listeDesTaches[i].responsable)==6){
        if(club.listeDesTaches[i].numero==number){
            baron=1;
            printf("............................................................\n");
            printf("NUMERO : %d\n",club.listeDesTaches[i].numero);
            printf("LIBELLE : %s\n",club.listeDesTaches[i].libelle);
            printf("BUDGET DE DEPENSE: %2.f\n",club.listeDesTaches[i].bud_dep);
            printf("STATUT: %s\n",club.listeDesTaches[i].statut);
            printf("DATE DE FIN: %s\n",club.listeDesTaches[i].dateFin);
            printf("RESPONSABLE: %s\n",club.listeDesTaches[i].responsable);
            printf("............................................................\n");
        }
        i++;
    }
    if(baron!=1)
       printf("La tache ayant le numero %d n'existe pas!\n",number);
     
}

int verifictions(int num, Club club) {
    FILE *Tach = fopen("Taches.txt", "r");
    if (Tach == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return -1; // Indiquer une erreur potentielle
    }

    int i = 0;
    while (i < Max && fscanf(Tach,"%d;%[^;];%f;%[^;];%[^;];%[^;]",&club.listeDesTaches[i].numero,
    club.listeDesTaches[i].libelle,&club.listeDesTaches[i].bud_dep,club.listeDesTaches[i].statut,
    club.listeDesTaches[i].dateFin,club.listeDesTaches[i].responsable)!=EOF ) {
        if (club.listeDesTaches[i].numero == num) {
            fclose(Tach);
            printf("Une Tache portant ce numero existe deja, veuillez entrer un autre numero : ");
            scanf("%d", &num);
            return verifictions(num, club);
        }
        i++;
    }

    fclose(Tach);
    return num;
}

 void supprimerTache(int nume) {
    FILE *Tach = fopen("Taches.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (Tach == NULL || temp == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

    Club club;
    int found = 0;
    int i = 0;

    while (fscanf(Tach,"%d;%[^;];%f;%[^;];%[^;];%[^;]",&club.listeDesTaches[i].numero,
    club.listeDesTaches[i].libelle,&club.listeDesTaches[i].bud_dep,club.listeDesTaches[i].statut,
    club.listeDesTaches[i].dateFin,club.listeDesTaches[i].responsable)!=EOF) {

        if (club.listeDesTaches[i].numero != nume) {
            // Ecrire dans le fichier temporaire si le numéro ne correspond pas
            fprintf(temp,"%d;%s;%2.f;%s;%s;%s\n",
            club.listeDesTaches[i].numero,club.listeDesTaches[i].libelle,club.listeDesTaches[i].bud_dep,
            club.listeDesTaches[i].statut,club.listeDesTaches[i].dateFin,club.listeDesTaches[i].responsable);
        } else {
            found = 1; // Marquer que le membre a été trouvé
        }
    }

    fclose(Tach);
    fclose(temp);

    // Remplacer l'ancien fichier par le nouveau
    remove("Taches.txt");
    rename("temp.txt", "Taches.txt");

    if (found) {
        printf("Tache ayant le numero %d a été supprimé.\n", nume);
    } else {
        printf("Tache ayant le numero %d non trouvé.\n", nume);
    }
} 

void ModifierTache(int number){
    FILE *Tach;
    Tach=fopen("Taches.txt","r");
    Club club;
    int i=0,baron=0,choice;
    if(Tach==NULL){
        printf("Fichier inexistant\n");
        return;
    }
    while(fscanf(Tach,"%d;%[^;];%f;%[^;];%[^;];%[^;]",&club.listeDesTaches[i].numero,
    club.listeDesTaches[i].libelle,&club.listeDesTaches[i].bud_dep,club.listeDesTaches[i].statut,
    club.listeDesTaches[i].dateFin,club.listeDesTaches[i].responsable)==6){
        if(club.listeDesTaches[i].numero==number){
            baron=1;
            printf("............................................................\n");
            printf("NUMERO : %d\n",club.listeDesTaches[i].numero);
            printf("LIBELLE : %s\n",club.listeDesTaches[i].libelle);
            printf("BUDGET DE DEPENSE: %2.f\n",club.listeDesTaches[i].bud_dep);
            printf("STATUT: %s\n",club.listeDesTaches[i].statut);
            printf("DATE DE FIN: %s\n",club.listeDesTaches[i].dateFin);
            printf("RESPONSABLE: %s\n",club.listeDesTaches[i].responsable);
            printf("............................................................\n");
                        printf("\n\tQuelle information souhaitez vous modifier ? \n");
            printf("\t1. Numero \t2. libelle \t3. budget de tache \t4. statut \t5. date de fin \t6. Responsable\n");
            printf("Choix de modification : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                printf("Entrer le nouveau numero : ");
                scanf("%d",&club.listeDesTaches[i].numero);
                break;
            case 2:
               printf("Entrer le nouveau libelle : ");
               scanf("%s",club.listeDesTaches[i].libelle);
               break;
            case 3:
                printf("Entrer le nouveau budget : ");
                scanf("%f",&club.listeDesTaches[i].bud_dep);
                break;
            case 4:
               printf("Entrer le nouveau statut : ");
                scanf("%s",club.listeDesTaches[i].statut);
               break;
             case 5:
                printf("Entrer la nouvelle date  de fin : ");
                scanf("%s",club.listeDesTaches[i].dateFin);
                break;
            case 6:
               printf("Entrer le nom nouveau du responsable : ");
                scanf("%s",club.listeDesTaches[i].responsable);
               break;
            
            default:
               printf("Choix invalide !\n");
                break;
            }
        }
        i++;
    }
    fclose(Tach);
if(baron==0){
    printf("Aucune tache ayant le numero %d n'a ete trouve\n",number);
}else{
    Tach=fopen("Taches.txt","w");
    if(Tach==NULL)
        return;
    for(i=0;i<Max;i++){
        if(club.listeDesTaches[i].numero!=0)
            fprintf(Tach,"%d;%s;%2.f;%s;%s;%s\n",
            club.listeDesTaches[i].numero,club.listeDesTaches[i].libelle,club.listeDesTaches[i].bud_dep,
            club.listeDesTaches[i].statut,club.listeDesTaches[i].dateFin,club.listeDesTaches[i].responsable);
        else
          break;
    }
    fclose(Tach);
}
 printf("\nModification effectue avec success ! \n");
    sleep(2);
}
void AfficherTache(){
    FILE*Tach;
    Tach=fopen("Taches.txt","r");
    Club club;
    int i=0;
    if(Tach== NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    printf("-----------------|Liste des taches------------------\n\n");
    while( i<Max && fscanf(Tach,"%d;%[^;];%f;%[^;];%[^;];%[^;]",&club.listeDesTaches[i].numero,
    club.listeDesTaches[i].libelle,&club.listeDesTaches[i].bud_dep,club.listeDesTaches[i].statut,
    club.listeDesTaches[i].dateFin,club.listeDesTaches[i].responsable)==6){
        printf("............................................................\n");
        printf("NUMERO : %d\n",club.listeDesTaches[i].numero);
        printf("LIBELLE : %s\n",club.listeDesTaches[i].libelle);
        printf("BUDGET DE DEPENSE: %2.f\n",club.listeDesTaches[i].bud_dep);
        printf("STATUT: %s\n",club.listeDesTaches[i].statut);
        printf("DATE DE FIN: %s\n",club.listeDesTaches[i].dateFin);
        printf("RESPONSABLE: %s\n",club.listeDesTaches[i].responsable);
        
        i++;

    }
    fclose(Tach);

}
void CreerTaches(Tache Tuch){
    FILE *Tach=fopen("Taches.txt","a");
    if(Tach==NULL){
        printf("Erreur d'ouverture du fichier\n");
    }
    fprintf(Tach,"%d;%s;%2.f;%s;%s;%s\n",Tuch.numero,Tuch.libelle,Tuch.bud_dep,Tuch.statut,Tuch.dateFin,Tuch.responsable);
    fclose(Tach);


}



char *verificationResp(char *respo, Club *club) {
    FILE *Mem = fopen("Membres.txt", "r");
    if (Mem == NULL) {
        printf("Erreur d'ouverture du fichier Membres.txt\n");
        return NULL; // Indiquer une erreur potentielle
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
        if (strcmp(club->listeDesMembre[i].nom, respo) == 0) {
            // Responsable trouvé
            fclose(Mem);
            return respo;
        }
        i++;
    }

    fclose(Mem);

    // Si on arrive ici, le responsable n'a pas été trouvé
    printf("Un membre portant ce nom n'existe pas. Veuillez entrer à nouveau le nom de responsable à qui la tâche doit être attribuée : ");
    scanf("%s", respo);
    return verificationResp(respo, club); // Appeler récursivement pour revérifier
}

Club MenuGestionTaches(Club club){
    system("clear");
    int choixT,n;
    printf("--------------------|GESTION DES TACHES|-------------------\n\n");
    do{
         printf("\t*******| BIEVENUE DANS LE MENU DE GESTIONS DES TACHES |************\n");
        printf("Que souhaitez vous faire ?\n");
        printf("\t0. Revenir au menu principale\n");
        printf("\t1. Assigner une tache\n");
        printf("\t2. Supprimer une tache\n");
        printf("\t3. Modifier les informations d'une tache\n"); // Ajouter une tranche par exemple
        printf("\t4. Afficher la liste des taches\n");
        printf("\t5.Rechercher une tache\n");
        printf("Votre choix : ");
        scanf("%d",&choixT);
        switch (choixT)
        {
        case 0:
            printf("Veuillez patientez................................\n");
            sleep(2);
            break;
        case 1:
        printf("Entrer le numero de la tache : ");
        scanf("%d",&Ntache.numero);
       Ntache.numero= verifictions(Ntache.numero,club);
        printf("Entrer le libelle : ");
        scanf("%s",Ntache.libelle);
        printf("le budget de la tache : ");
        scanf("%f",&Ntache.bud_dep);
        printf("le statut de tache : ");
        scanf("%s",Ntache.statut);
        printf("la date de fin sur le format (20/02/2024) : ");
        scanf("%s",Ntache.dateFin);
        printf("le responsable de la tache : ");
        scanf("%s",Ntache.responsable);
    // Vérifier si le responsable existe 
    
    if (verificationResp(Ntache.responsable, &club) == NULL) {
        printf("Erreur: Le responsable n'existe pas.\n");
       break;
    }
        CreerTaches(Ntache);
         break;
        case 2:
          printf("Veuillez entrer le numero de la tache a supprimé\n");
          scanf("%d",&n);
          supprimerTache(n);
          break;
        case 3:
            printf("Veuillez entrer le numero de la tache a modifier\n");
            scanf("%d",&n);
            ModifierTache(n);
           break;
        case 4:
            AfficherTache();
           break;
        case 5:
            printf("Veuillez entrer le numero de la tache a  rechercher\n");
            scanf("%d",&n);
            rechercheTache(n);
           break;
        
        default:
            printf("Désolé cette fonction n'est pas disponible. Veuillez réssayez!!\n");
            break;
        }

    }while(choixT!=0);
    return club;
}