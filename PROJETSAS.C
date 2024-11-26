#include <stdio.h>
#include <string.h>

typedef enum {
    BASSE,
    HAUTE
} Priorite;

typedef struct {
    char titre[100];
    char description[100];
    char date_echeance[20];
    Priorite priorite;
} Tache;

Tache taches[100];
int nmbr_taches=0,i;

void ajouter(int prio) {
    printf("Ajout d'une nouvelle tâche :\n");
    printf("Titre : ");
    getchar();
    fgets(taches[nmbr_taches].titre, sizeof(taches[nmbr_taches].titre),stdin);
    printf("Description : ");
    fgets(taches[nmbr_taches].description, sizeof(taches[nmbr_taches].description),stdin);
    printf("Date d'échéance (JJ/MM/AAAA) : ");
    fgets(taches[nmbr_taches].date_echeance, sizeof(taches[nmbr_taches].date_echeance),stdin);
    printf("Priorité (1 = Haute, 0 = Basse) : ");
    scanf("%d",&prio);
    taches[nmbr_taches].priorite = (prio == 1) ? HAUTE : BASSE;
    nmbr_taches++;
}

void modifier(int index) {
    printf("Modifier une tâche :\n");
    printf("Entrez l'index de la tâche à modifier (1 à %d) : ", nmbr_taches);
    scanf("%d", &index);

    if (index < 1 || index >nmbr_taches) {
        printf("Index invalide.\n");
        return;
    }

    printf("Modification de la tâche %d :\n", index);
    printf("Nouveau titre : ");
    getchar();
    fgets(taches[index-1].titre,sizeof(taches[index-1].titre),stdin);
    printf("Nouvelle description : ");
    fgets(taches[index-1].description,sizeof(taches[index-1].description),stdin);
    printf("Nouvelle date d'échéance (JJ/MM/AAAA) : ");
    fgets(taches[index-1].date_echeance,sizeof(taches[index-1].date_echeance),stdin);
    printf("Nouvelle priorité (1 = Haute, 0 = Basse) : ");
    int prio;
    scanf("%d", &prio);
    taches[index-1].priorite = (prio == 1) ? HAUTE : BASSE;
}
void supprimer(int index) {
    printf("Supprimer une tâche :\n");
    printf("Entrez l'index de la tâche à supprimer (1 à %d) : ",nmbr_taches);
    scanf("%d", &index);

    if (index < 0 || index >nmbr_taches) {
        printf("Index invalide.\n");
        return;
    }
    for (i=index;i<=nmbr_taches;i++) {
        taches[i-1]=taches[i];
    }
    nmbr_taches--;
    printf("supression avec succes \n");
}

int main() {

return 0;

}
