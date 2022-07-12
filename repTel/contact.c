/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdbool.h>
#include "contact.h"



void afficherContact(struct Contact c) {
    
    printf("Le prenom de ce contact est: %s\n", c.firstName);
    printf("Le nom de ce contact est: %s\n", c.lastName);
    printf("Le numero de telephone de ce contact est: %s\n", c.phone);

}

/**
c'est la valeur de la variable contact que l'on veut modifier
et pas la variable en tant que tel d'où l'utilisation de pointeur
*/
void modifierNum(struct Contact *c) {
    
    printf("Entrez le prenom et le nom du contact que vous voulez modifier :\n ");
    scanf("%s", &c->firstName);
    scanf("%s", &c->lastName);

    printf("Entrez le nouveau numero de telephone: ");
    scanf("%s", &c->phone);

    printf("Le numero de telphone de %s %s a ete modifie avec succes.", c->firstName, c->lastName);

}


bool comparer(struct Contact c1, struct Contact c2) {
    
    if (c1.phone == c2.phone) {
        printf("Il s'agit du même contact\n");
    }
    else {
        printf("Ces deux contacts sont differents\n");
    }
    
    return true;
}


void permuteContact(struct Contact *c1, struct Contact *c2) {
    
    struct Contact temp = *c1;
    *c1 = *c2;
    *c2 = temp;

    printf("Ces contacts ont ete permutes avec succes.\n");

}

