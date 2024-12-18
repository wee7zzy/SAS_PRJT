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
void afficher() {
    if (nmbr_taches==0) {
        printf("Aucune tâche à afficher.\n");
    }
    for (i=0;i<nmbr_taches;i++) {
        printf("\nTitre: %s\n", taches[i].titre);
        printf("Description: %s\n", taches[i].description);
        printf("Date d'échéance: %s\n", taches[i].date_echeance);
        printf("Priorité: %s\n", (taches[i].priorite==HAUTE) ? "Haute" : "Basse");
        printf("---------------------------\n");
    }
}
void filtrer(){
    int p;
    printf("entrer la priorite voulait afficher(0 pour basse 1 pour haute) :");
    scanf("%d",&p);
    for(i=0;i<nmbr_taches;i++){
        if (nmbr_taches==0 || (taches[i].priorite!=1 && taches[i].priorite!=0)) {
            printf("Aucune tâche à afficher.\n");
        }else{
            if(taches[i].priorite==p){
                printf("les taches avec haute priorite : \n %s \n %s \n %s \n %d \n",taches[i].titre,taches[i].description,taches[i].date_echeance,taches[i].priorite);
            }
            else {
                if(taches[i].priorite==p){
                
                    printf("les taches avec basse priorite :\n %s \n %s \n %s \n %d \n",taches[i].titre,taches[i].description,taches[i].date_echeance,taches[i].priorite);
                }
            }
            
        }
    }
}

int main() {
int choix,prio=-1,index=-1;

    do {
        printf("\nGestion des tâches\n");
        printf("1. Ajouter une tâche\n");
        printf("2. Modifier une tâche\n");
        printf("3. Supprimer une tâche\n");
        printf("4. Afficher toutes les tâches\n");
        printf("5. filtre les taches\n");
        printf("6. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                ajouter(prio);
                break;
            case 2:
                modifier(index);
                break;
            case 3:
                supprimer(index);
                break;
            case 4:
                afficher();
                break;
            case 5:
                filtrer();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while(choix!=6);

return 0;

}
