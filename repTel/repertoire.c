/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "contact.h"
#include "repertoire.h"


void afficherRepertoire(struct Repertoire *r) {

    FILE* repTel = NULL;
    
    repTel = fopen("repTel.txt", "r");
    
    if(repTel != NULL) {
        printf("Voici les contacts de votre repertoire telephonique:\n");
        for (int i = 0; i < r->nbrCts; i++) {
            while (fread(&r->c[i], sizeof(r->c[i]), 1, repTel) == 1) {
                printf("%s %s: %s\n", r->c[i].firstName, r->c[i].lastName, r->c[i].phone);
            }
        }
    }
    else {
        printf("Impossible d'ouvrir le repertoire telephonique demande.");
    }
    
    fclose(repTel);
}


void afficherNbrCts(struct Repertoire r) {
   
    printf("VOtre répertoire contient %d contacts\n", r.nbrCts);
    
}

void ajouterContact(struct Repertoire *r, struct Contact c1) {
    FILE* repTel = NULL;
    
    repTel = fopen("repTel.txt", "a+");
    r->nbrCts = 1;
    
    if(repTel != NULL) {
        
        printf("Entrez le prenom et le nom du contact que vous voulez ajouter :\n ");
        scanf("%s", &c1.firstName);
        scanf("%s", &c1.lastName);

        printf("Entrez son numero de telephone:\n");
        scanf("%s", &c1.phone);

        fseek(repTel, 0, SEEK_END);
        fprintf(repTel, "%s %s %s", c1.firstName, c1.lastName, c1.phone);
        fflush(stdin);
        
        fclose(repTel);

        r->nbrCts++;

        printf("Le contact %s %s a ete ajoute avec succes dans votre repertoire.", c1.firstName, c1.lastName);
    }
    else {
        printf("Impossible d'ajouter ce contact dans ce repertoire telephonique.");
    }
}


void trierRepertoire(struct Repertoire *r) {
    int i, j;
    char temp[50][50];

    FILE* repTel = NULL;
    
    repTel = fopen("repTel.txt", "a+");
    r->nbrCts = 1;
    
    if(repTel != NULL) {
        for (i = 0; i < r->nbrCts; i++) {
            for (j = i+1; j < r->nbrCts; j++) {
                if(strcmp(r->c[i].lastName, r->c[i].lastName) > 0) {
                    strlcpy(temp[i], r->c[i].lastName, 20);
                    strlcpy(r->c[i].lastName, r->c[j].lastName, 20);
                    strlcpy(r->c[j].lastName, temp[i], 20);
                }
            }
        }
    }
    else {
        printf("Impossible de trier ce repertoire par ordre alphabetique.");
    }
    
    fclose(repTel);

    afficherRepertoire(r);   
}

bool rechercher(struct Repertoire r, char name[20]) {
    
    FILE* repTel = NULL;
    
    repTel = fopen("repTel.txt", "r");
    
    if(repTel != NULL) {
        printf("Entrez le nom de la personne que vous voulez rechercher\n");
        scanf("%s", &name);
        while(fread(&r.c, sizeof(r.c), 1, repTel) == 1) {
            if (strcmp(r.c->lastName, name) == 0) {
                printf("Le contact demandé est le suivant: %s %s %s\n", r.c->lastName, r.c->firstName, r.c->phone);
            }
            else {
                printf("Ce nom ne figue pas dans votre repertoire");
            }
        }
    }
    fclose(repTel);
    
    return true;
}

/**
int getIndice(struct Repertoire r, struct Contact c) {
    
    FILE* repTel = NULL;
    int indice;
    r.nbrCts = 1;
    
    repTel = fopen("repTel.txt", "r");
    
    if(repTel != NULL) {
        printf("Entrez le nom du contact dont vous voulez l'indice:\n");
        scanf("%s", &r.c->lastName);
        
        fgets(str, repTel);
        while(str != NULL) {
            if (strcmp(fgets(repTel), (r.c->firstName r.c->lastName r.c->phone)) == 0) {
                indice = r.nbrCts;
            }
        }
    }
    fclose(repTel);
    
    return indice;        
}
*/   

void supprimerContact(struct Repertoire *r, struct Contact c1) {
    
    FILE* repTel = NULL;
    FILE* repTel_temp = NULL;
    //char name = c1.lastName;
    int deleteC;
    
    repTel = fopen("repTel.txt", "r");
    
    if(repTel != NULL) {
        repTel_temp = fopen("repTel_temp", "a+");
        
        if (repTel_temp != NULL) {
            printf("Entrez le nom du contact que vous voulez supprimer:\n");
            scanf("%d", &c1.lastName);
            fflush(stdin);
            
            while (fread(r->c, sizeof(r->c), 1, repTel) == 1) {
                if(strcmp(r->c->lastName, c1.lastName) != 0) {
                    //fwrite(r->c, sizeof(r->c), 1, repTel_temp);
                    fprintf(repTel_temp, "%s %s %s", r->c->firstName, r->c->lastName, r->c->phone);
                }
                
                if(strcmp(r->c->lastName, c1.lastName) == 0) {
                    deleteC = 1;
                }
            }
        }
        else {
            printf("Impossible d ouvrir le fichier repTel\n");
        }
        fclose(repTel_temp);
    }
    else {
            printf("Impossible d ouvrir le fichier repTel_temp\n");
        }
    fclose(repTel);
    
    if (deleteC != 1) {
        printf("Pas de contact enregistré à supprimer.\n");
    }
    
    remove("repTel");
    rename("repTel", "repTel_temp");
    
    printf("Le contact %s %s a été suprimmé avec succes\n", c1.firstName, c1.lastName);
    
    /**
    c = getc(repTel);
    
    if(repTel != NULL) {
        while (c != EOF) {
            printf("%c", c);
            c = getc(repTel);
        }
        
        rewind(repTel);
        
        printf("Vueillez entrer l indice du contact que vous voulez supprimer:\n");
        scanf("%d", &c1.indice);
        c1.indice = c1.indice + 1;
        
        repTel_temp = fopen("repTel_temp", "w");
        
        if (repTel_temp != NULL) {
            c = getc(repTel);
            while (c != EOF) {
                c = getc(repTel);
                if (c == '\n') {
                    r->nbrCts++;
                    if (r->nbrCts != c1.indice) {
                        putc(c, repTel_temp);
                    }
                }
            }
        }
        
        fclose(repTel);
        fclose(repTel_temp);
        
        remove(repTel);
        rename(repTel, repTel_temp);
    }
    */
}


void fusionnerRepertoire(struct Repertoire r1, struct Repertoire r2) {
    
    //FILE *r1, *r2, *r3;
    
    
}
