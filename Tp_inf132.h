#ifndef CLUB_H
#define CLUB_H
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<unistd.h>
 #define Max 100

  //dons
typedef struct Dons {
    char donnateur[50];
    float somme;
} Dons;
//EQUIPEMENT
typedef struct equipement {
    char code[8];
    char nom[50];
    int disponible;
} equipe;
//tache
typedef struct {
    int numero;
    char libelle[100];
    float bud_dep;
    char statut[20];
    char dateFin[20];
    char responsable[50];
} Tache;
//membre
typedef struct membre{
    int numero;
    char nom[50];
    char prenom[50];
    char role[50];
    char coordon[50];
    char horaire[50];
    float inscrip[3];
} Membre;
//Reservation
typedef struct Reservation{
    char code_equipement[8];
    char designation[20];
    int quantite;
    int numero_membre;
    char date[20];
}Reservations;
//club
typedef struct club{
    char nom[10];
    Membre listeDesMembre[Max];
    equipe listeDesEquipements[Max];
    Dons listeDesdons[Max];
    Tache listeDesTaches[1000];
    Reservations listeDesReservation[1000];
    float fond_caisse;
}Club;
//implementation des membres
void RechercherMembre(int number);
void EnregistrerMembre(Club *club,Membre membre);
void AfficherMembre();
void ModifierMembre(int number);
void supprimerMembre(int nume);
int verifiction(int num,Club club);
int VerificationBaremAtteint(Club *club);
int verificationMontant(Club *club, int barem);
 Club MenuGestionMembres(Club club);

//Implementation de la partie tache
int verifictions(int num, Club club);
void rechercheTache(int number);
void supprimerTache(int nume);
void ModifierTache(int number);
void AfficherTache();
char *verificationResp(char *respo, Club *club);
void CreerTaches(Tache Tuch);
  Club MenuGestionTaches(Club club);

//Implementation des ressources
void changer_ladisponiblite(Club *club, const char *code);
//void changer_ladisponiblite(Club club,char *code);
void afficheEqOccupe();
void affEqDiso();
void FaireReserVation(Reservations nouv_Re);
int verificationExistanceMembre(int nume, Club *club);
void AffichereqTotal();
//void ModifierEq(char *cod);
void supprimerEquip(char *cod);
void Donnation(Club*club,equipe nouv_eq,Dons nouv_d);
void Enregdons(Dons nouv_d,Club *club);
void EnregEquipement(equipe nouv_eq);
void verifictionseq(char *code, Club *club);
 Club MenuGestionRessources(Club club);

// implementation de la statistique
void AfficherPourcentageInsolvable(Club club);
void AfficherPourcentageEnRegle(Club club);
void afficheEnRegle(Club club);
void afficheInsolvable(Club club);
void afficherEffectif();
void AfficherFondDeCaisse(Club club);
 Club MenuStatisque(Club club);
#endif // !CLUB_H