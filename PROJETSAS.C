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

int main() {

return 0;

}
