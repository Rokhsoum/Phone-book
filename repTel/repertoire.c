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


void afficherRepertoire(struct Repertoire r) {
    /**
    FILE* repTel = NULL;
    char contacts[TAILLE_MAX] = "";
    
    repTel = fopen("repTel.txt", "r");
    
    if(repTel != NULL) {
        printf("Voici les contacts de votre repertoire telephonique:\n");
        while (fgets(contacts, TAILLE_MAX, repTel) != NULL) {
            printf("%s", contacts);
        }
    }
    else {
        printf("Impossible d'ouvrir le repertoire telephonique demande.");
    }
    
    fclose(repTel);
    */
    
    int i;
    for (i = 0; i < r.nbrCts; i++) {
        printf("Voici les contacts de votre repertoire telephonique:\n");
        printf("%s %s: %s\n", r.c[i].firstName, r.c[i].lastName, r.c[i].phone);
    }
}


void afficherNbrCts(struct Repertoire r) {
   
    printf("VOtre répertoire contient %d contacts\n", r.nbrCts);
    
}

void ajouterContact(struct Repertoire *r, struct Contact c) {
    FILE* repTel = NULL;
    
    repTel = fopen("repTel.txt", "a+");
    r->nbrCts = 1;
    
    if(repTel != NULL) {
        
        printf("Entrez le prenom et le nom du contact que vous voulez ajouter :\n ");
        scanf("%s", &c.firstName);
        scanf("%s", &c.lastName);

        printf("Entrez son numero de telephone: ");
        scanf("%s", &c.phone);

        fprintf(repTel, "%s %s %s", c.firstName, c.lastName, c.phone);

        r->nbrCts++;

        printf("Le contact %s %s a ete ajoute avec succes dans votre repertoir.", c.firstName, c.lastName);
    }
    else {
        printf("Impossible d'ajouter ce contact dans ce repertoire telephonique.");
    }
    
    fclose(repTel);
}


void trierRepertoire(struct Repertoire *r, struct Contact *c) {
    int i, j;
    char temp[50][50];

    FILE* repTel = NULL;
    
    repTel = fopen("repTel.txt", "a+");
    r->nbrCts = 1;
    
    if(repTel != NULL) {
        for (i = 0; i < r->nbrCts; i++) {
            for (j = i+1; j < r->nbrCts; j++) {
                if(strcmp(c[i].lastName, c[i].lastName) > 0) {
                    strcpy(temp[i], c[i].lastName);
                    strcpy(c[i].lastName, c[j].lastName);
                    strcpy(c[j].lastName, temp[i]);
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

bool rechercher(struct Repertoire r, char *nom) {
    
    if (r.c->lastName == nom) {
        printf("Le contact demandé est le suivant: %s %s %s\n", r.c->lastName, r.c->firstName, r.c->phone);
    }
    else {
        printf("Ce nom ne figue pas dans votre repertoire");
    }
    
    return true;
}

int getIndice(struct Repertoire r, struct Contact c)  {
    
}

void supprimerContact(struct Repertoire *r, struct Contact c) {
    
}
