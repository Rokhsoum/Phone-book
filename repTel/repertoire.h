/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   repertoire.h
 * Author: Rokhaya Soumare
 *
 * Created on 10 juillet 2022, 03:27
 */

#ifndef REPERTOIRE_H
#define REPERTOIRE_H

#define TAILLE_MAX      1000

#define false       0
#define true        1

#define SEEK_SET
#define SEEK_CUR
#define SEEK_END

struct Repertoire {
    int nbrCts;
    struct Contact *c;
};


void afficherRepertoire(struct Repertoire *r);

void afficherNbrCts(struct Repertoire r);

void ajouterContact(struct Repertoire *r, struct Contact c);

void trierRepertoire(struct Repertoire *r, struct Contact *c);

bool rechercher(struct Repertoire r, char *nom);

int getIndice(struct Repertoire r, struct Contact c);

void supprimerContact(struct Repertoire *r, struct Contact c);

void fusionnerRepertoire(struct Repertoire r1, struct Repertoire r2);




#endif /* REPERTOIRE_H */

