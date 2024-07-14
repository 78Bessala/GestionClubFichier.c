#include "Tp_inf132.h"
Membre NeuwMembre;
const float FRAIS_INSCRIPTION = 3000; // Les frais d'inscription par membre

void RechercherMembre(int number){
    FILE *Mem;
    Mem=fopen("Membres.txt","r");
    Club club;
    int i=0;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }

      while(fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])==9){
        if(club.listeDesMembre[i].numero==number){
            
            printf("............................................................\n");
            printf("NUMERO : %d\n",club.listeDesMembre[i].numero);
            printf("NOM : %s\n",club.listeDesMembre[i].nom);
            printf("PRENOM : %s\n",club.listeDesMembre[i].prenom);
            printf("ROLE : %s\n",club.listeDesMembre[i].role);
            printf("COORDONNEE: %s\n",club.listeDesMembre[i].coordon);
            printf("HORAIRE: %s\n",club.listeDesMembre[i].horaire);
            printf("TRANCHE 1 : %2.f\n",club.listeDesMembre[i].inscrip[0]);
            printf("TRANCHE 2 : %2.f\n",club.listeDesMembre[i].inscrip[1]);
            printf("TRANCHE 3 : %2.f\n",club.listeDesMembre[i].inscrip[2]);
            printf("............................................................\n");
        }
    }
    i++;
}
int verifiction(int num, Club club) {
    FILE *Mem = fopen("Membres.txt", "r");
    if (Mem == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return -1; // Indiquer une erreur potentielle
    }

    int i = 0;
    while (i < Max && fscanf(Mem, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",
                             &club.listeDesMembre[i].numero,
                             club.listeDesMembre[i].nom,
                             club.listeDesMembre[i].prenom,
                             club.listeDesMembre[i].role,
                             club.listeDesMembre[i].coordon,
                             club.listeDesMembre[i].horaire,
                             &club.listeDesMembre[i].inscrip[0],
                             &club.listeDesMembre[i].inscrip[1],
                             &club.listeDesMembre[i].inscrip[2]) != EOF) {
        if (club.listeDesMembre[i].numero == num) {
            fclose(Mem);
            printf("Un membre portant ce numero existe deja, veuillez entrer un autre numero : ");
            scanf("%d", &num);
            return verifiction(num, club);
        }
        i++;
    }

    fclose(Mem);
    return num;
} 
 void supprimerMembre(int nume) {
    FILE *Mem = fopen("Membres.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (Mem == NULL || temp == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

    Club club;
    int found = 0;
    int i = 0;

    while (fscanf(Mem, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",
                  &club.listeDesMembre[i].numero,
                  club.listeDesMembre[i].nom,
                  club.listeDesMembre[i].prenom,
                  club.listeDesMembre[i].role,
                  club.listeDesMembre[i].coordon,
                  club.listeDesMembre[i].horaire,
                  &club.listeDesMembre[i].inscrip[0],
                  &club.listeDesMembre[i].inscrip[1],
                  &club.listeDesMembre[i].inscrip[2]) != EOF) {

        if (club.listeDesMembre[i].numero != nume) {
            // Ecrire dans le fichier temporaire si le numéro ne correspond pas
            fprintf(temp, "%d;%s;%s;%s;%s;%s;%.2f;%.2f;%.2f\n",
                    club.listeDesMembre[i].numero,
                    club.listeDesMembre[i].nom,
                    club.listeDesMembre[i].prenom,
                    club.listeDesMembre[i].role,
                    club.listeDesMembre[i].coordon,
                    club.listeDesMembre[i].horaire,
                    club.listeDesMembre[i].inscrip[0],
                    club.listeDesMembre[i].inscrip[1],
                    club.listeDesMembre[i].inscrip[2]);
        } else {
            found = 1; // Marquer que le membre a été trouvé
        }
    }

    fclose(Mem);
    fclose(temp);

    // Remplacer l'ancien fichier par le nouveau
    remove("Membres.txt");
    rename("temp.txt", "Membres.txt");

    if (found) {
        printf("Membre ayant le numero %d a été supprimé.\n", nume);
    } else {
        printf("Membre ayant le numero %d non trouvé.\n", nume);
    }
}  
void ModifierMembre(int number){
    FILE *Mem;
    Mem=fopen("Membres.txt","r");
    Club club;
    int i=0,trouve=0,choix;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    while(fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])==9){
        if(club.listeDesMembre[i].numero==number){
            trouve=1;
            printf("............................................................\n");
            printf("NUMERO : %d\n",club.listeDesMembre[i].numero);
            printf("NOM : %s\n",club.listeDesMembre[i].nom);
            printf("PRENOM : %s\n",club.listeDesMembre[i].prenom);
            printf("ROLE : %s\n",club.listeDesMembre[i].role);
            printf("COORDONNEE: %s\n",club.listeDesMembre[i].coordon);
            printf("HORAIRE: %s\n",club.listeDesMembre[i].horaire);
            printf("TRANCHE 1 : %2.f\n",club.listeDesMembre[i].inscrip[0]);
            printf("TRANCHE 2 : %2.f\n",club.listeDesMembre[i].inscrip[1]);
            printf("TRANCHE 3 : %2.f\n",club.listeDesMembre[i].inscrip[2]);
            printf("............................................................\n");
            printf("\n\tQuelle information souhaitez vous modifier ? \n");
            printf("\t1. Numero \t2. Nom \t3. Prenom \t4. Role \t5. Coordonnee \t6. Horaire \t7.Tranche 1 \t.8 tranche 2 \t.9 Tranche 3\n");
            printf("Choix de modification : ");
            scanf("%d",&choix);
            switch(choix)
            {
                case 1 :
                    printf("Entrez le nouveau numero : ");
                    scanf("%d", &club.listeDesMembre[i].numero);
                    break;

                case 2 :
                    printf("Entrez le nouveau nom : ");
                    scanf("%s", club.listeDesMembre[i].nom);
                    break;

                case 3:
                    printf("Entrez le nouveau prenom: ");
                    scanf("%s", club.listeDesMembre[i].prenom);
                   break;

                case 4 :
                    printf("Entrez le nouvel role( choix disponible PRESIDENT || SECRETAIRE || CENSSEUR || CONSIELLER) : ");
                    scanf("%s",club.listeDesMembre[i].role);
                    break;

                case 5 : 
                    printf("Entrez les nouveuax coordonnees : ");
                    scanf("%s",club.listeDesMembre[i].coordon);
                    break;

                case 6 :
                    printf("Entrez la nouvelle horaire : ");
                    scanf("%s", club.listeDesMembre[i].horaire);
                    break;

                case 7 : 
                    printf("Entrez la nouvelle trache : ");
                    scanf("%f", &club.listeDesMembre[i].inscrip[0]);
                    break;

                case 8 :
                    printf("Entrez la nouvelle tranche: ");
                    scanf("%f", &club.listeDesMembre[i].inscrip[1]);
                    break;
                case 9:
                    printf("Entrez la nouvelle tranche: ");
                    scanf("%f", &club.listeDesMembre[i].inscrip[1]);
                     break;

                default : 
                    printf("Mauvaise valeur\n");
                    break;
            }


        }
        i++;
    }
    fclose(Mem);

if (trouve == 0)
    {
        printf("Aucun membre ayant le numero %d n'a ete trouve\n",number);
    }else{
        Mem=fopen("Membres.txt","w");
        if(Mem==NULL)
          return;
        for(i=0;i<Max;i++){
            if(club.listeDesMembre[i].numero != 0)
              fprintf(Mem,"%d;%s;%s;%s;%s;%s;%2.f;%2.f;%2.f\n",club.listeDesMembre[i].numero,club.listeDesMembre[i].nom,
                 club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,club.listeDesMembre[i].coordon,
                club.listeDesMembre[i].horaire,club.listeDesMembre[i].inscrip[0],club.listeDesMembre[i].inscrip[1],club.listeDesMembre[i].inscrip[2]);
            else
               break;
            

        }
        fclose(Mem);
    }
   printf("\nModification effectue avec success ! \n");
    sleep(2);
}
void EnregistrerMembre(Club*club,Membre membre){
    FILE *Mem;
    Mem=fopen("Membres.txt","a");
    if(Mem==NULL){
        printf("Erreur d'ouverture de fichier Membres.txt\n");
        return;
    }
    fprintf(Mem,"%d;%s;%s;%s;%s;%s;%2.f;%2.f;%2.f\n",membre.numero,membre.nom,membre.prenom,membre.role,membre.coordon,membre.horaire,membre.inscrip[0],membre.inscrip[1],membre.inscrip[2]);
    fclose(Mem);
    //calcule de la somme des frais d'incription
    float sommeInscription=membre.inscrip[0]+membre.inscrip[1]+membre.inscrip[2];
    //Actualition du fond de caisse du club
    club->fond_caisse +=sommeInscription;
    printf("Membre %d est enregistré success!",membre.numero);
    printf("Le fond de caisse actuel est de : %2.f\n",club->fond_caisse);
    sleep(2);
}
void AfficherMembre(){
    FILE*Mem;
    Mem=fopen("Membres.txt","r");
    Club club;
    int i=0;
    if(Mem == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    printf("-----------------|Liste des membres------------------\n\n");
    while( i<Max && fscanf(Mem,"%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",&club.listeDesMembre[i].numero,
    club.listeDesMembre[i].nom,club.listeDesMembre[i].prenom,club.listeDesMembre[i].role,
    club.listeDesMembre[i].coordon,club.listeDesMembre[i].horaire,&club.listeDesMembre[i].inscrip[0],
    &club.listeDesMembre[i].inscrip[1],&club.listeDesMembre[i].inscrip[2])!=EOF){
        printf("............................................................\n");
        printf("NUMERO : %d\n",club.listeDesMembre[i].numero);
        printf("NOM : %s\n",club.listeDesMembre[i].nom);
        printf("PRENOM : %s\n",club.listeDesMembre[i].prenom);
        printf("ROLE : %s\n",club.listeDesMembre[i].role);
        printf("COORDONNEE: %s\n",club.listeDesMembre[i].coordon);
        printf("HORAIRE: %s\n",club.listeDesMembre[i].horaire);
        printf("TRANCHE 1 : %2.f\n",club.listeDesMembre[i].inscrip[0]);
        printf("TRANCHE 2 : %2.f\n",club.listeDesMembre[i].inscrip[1]);
        printf("TRANCHE 3 : %2.f\n",club.listeDesMembre[i].inscrip[2]);
        i++;

    }
    fclose(Mem);
}
int VerificationBaremAtteint(Club *club) {
    float Somme = 0;
    int i = 0;
    FILE *Mem = fopen("Membres.txt", "r");
    if (Mem == NULL) {
        fprintf(stderr, "Erreur d'ouverture de fichier Membres.txt\n");
        return 0;
    }

    while (fscanf(Mem, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",
                  &club->listeDesMembre[i].numero,
                  club->listeDesMembre[i].nom,
                  club->listeDesMembre[i].prenom,
                  club->listeDesMembre[i].role,
                  club->listeDesMembre[i].coordon,
                  club->listeDesMembre[i].horaire,
                  &club->listeDesMembre[i].inscrip[0],
                  &club->listeDesMembre[i].inscrip[1],
                  &club->listeDesMembre[i].inscrip[2]) != EOF) {
        for (int j = 0; j < 3; j++) {
            Somme += club->listeDesMembre[i].inscrip[j];
        }
        i++;
    }
    fclose(Mem);

    if (Somme == FRAIS_INSCRIPTION)
        return 1;
    return 0;
}
int verificationMontant(Club *club, int barem) {
    float Som = 0;
    int i = 0;
    FILE *Mem = fopen("Membres.txt", "r");
    if (Mem == NULL) {
        fprintf(stderr, "Erreur d'ouverture de fichier Membres.txt\n");
        return 0;
    }

    while (fscanf(Mem, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f;%f;%f",
                  &club->listeDesMembre[i].numero,
                  club->listeDesMembre[i].nom,
                  club->listeDesMembre[i].prenom,
                  club->listeDesMembre[i].role,
                  club->listeDesMembre[i].coordon,
                  club->listeDesMembre[i].horaire,
                  &club->listeDesMembre[i].inscrip[0],
                  &club->listeDesMembre[i].inscrip[1],
                  &club->listeDesMembre[i].inscrip[2]) != EOF) {
        for (int j = 0; j < 3; j++) {
            Som += club->listeDesMembre[i].inscrip[j];
        }
        i++;
    }
    fclose(Mem);

    if (Som > barem)
        return 1;
    return 0;
}
Club MenuGestionMembres(Club club){
    system("clear");
    int choixM,numer;
    printf("--------------------|GESTION DES MEMBRES|-------------------\n\n");

    do{  
        printf("\t*******| BIEVENUE DANS LE MENU DE GESTIONS DES MEMBRES |************\n");
        printf("Que souhaitez vous faire ?\n");
        printf("\t0. Revenir au menu principale\n");
        printf("\t1. Enregistrer un membre\n");
        printf("\t2. Supprimer un membre\n");
        printf("\t3. Modifier les informations d'un membre\n"); // Ajouter une tranche par exemple
        printf("\t4. Afficher la liste des membres\n");
        printf("\t5.Rechercher un membre \n");
        printf("Votre choix : ");
        scanf("%d",&choixM);
        switch (choixM)
        {
        case 0: 
           printf("Veuillez Patientez.......................\n") ;
           sleep(2);
            break;
        case 1:
            printf("Veuillez entrer le numero du membre ");
            scanf("%d",&NeuwMembre.numero);
            NeuwMembre.numero=verifiction(NeuwMembre.numero,club);
            printf("Veuillez entrer le nom du membre : ");
            scanf("%s",NeuwMembre.nom);
            printf("Veuillez entrer le prenom du membre : ");
            scanf("%s",NeuwMembre.prenom);
            for(int i=0;i<3;i++){
                printf(" Veuillez entrer le montant No. %d:",(i+1));
                scanf("%f",&NeuwMembre.inscrip[i]);

            }
            printf("veuillez entrer les coordonnees du membre : ");
            scanf("%s",NeuwMembre.coordon);
            printf("veuillez l' horaire du membre ; ");
            scanf("%s",NeuwMembre.horaire);
            printf("Entrez le nouvel role( choix disponible PRESIDENT || SECRETAIRE || CENSSEUR || CONSIELLER ||MEMBRE) : ");
             scanf("%s",NeuwMembre.role);
            
             EnregistrerMembre(&club,NeuwMembre);
           /* printf("Veuillez entrer le numero du membre ");
            scanf("%d",&NeuwMembre.numero);
            NeuwMembre.numero=verifiction(NeuwMembre.numero,club);
            printf("Veuillez entrer le nom du membre : ");
            scanf("%s",NeuwMembre.nom);
            printf("Veuillez entrer le prenom du membre : ");
            scanf("%s",NeuwMembre.prenom);
            NeuwMembre.inscrip[0]=NeuwMembre.inscrip[1]=NeuwMembre.inscrip[2]=0;
            for(int i=0;i<3;i++){
                printf(" Veuillez entrer le montant No. %d:",(i+1));
                scanf("%f",&NeuwMembre.inscrip[i]);
                while(verificationMontant(NeuwMembre.inscrip,FRAIS_INSCRIPTION)!=0){
                  printf("Le montant maximal (pour toutes vos tranches) est de %d, veuillez modifier le montant : ",FRAIS_INSCRIPTION);
                  scanf("%f",&NeuwMembre.inscrip[i]);
                if(VerificationBaremAtteint(NeuwMembre.inscrip)==1){
                    break;
                }
                
                }  
            }
             printf("Entrez le nouvel role( choix disponible PRESIDENT || SECRETAIRE || CENSSEUR || CONSIELLER) : ");
             scanf("%s",NeuwMembre.role);
             */
            break;
        case 2:
           printf("Veuillez entrer le numero  du membre a supprimer\n");
           scanf("%d",&numer);
           supprimerMembre(numer);
            break;
        case 3:
           printf("Veuillez entrer le numero du membre \n");
           scanf("%d",&numer);
            ModifierMembre(numer);
            break;
        case 4:
            AfficherMembre();
            break;  
        case 5:
          printf("Veuillez entrer le numero du membre \n");
           scanf("%d",&numer);
           RechercherMembre( numer);
         break; 

        default:
           printf("Désolé cette fonctionnalité n'est pas disponible.Veuillez réessayer !!\n");
            break;
        }

    }while(choixM !=0);
    /*
    printf("Dans le besion de protection des données,vous devez suivre les etapes qui suivent\n");
    sleep(4);
    system("clear");
   */
 return club;
}