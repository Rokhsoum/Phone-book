/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Rokhaya Soumare
 *
 * Created on 9 juillet 2022, 22:53
 */

#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

/*
 * 
 */
int main(void) {
    
    struct Contact c1 = {"Lyly", "Diassou", "0765945726"};

    afficherContact(c1);

    modifierNum(&c1);
    printf("Le nouveau numero de telephone Lyly Diassou est: %s\n ", c1.phone);

    struct Contact c2 = {"Roro", "Soudia", "0607202216"};
    comparer(c1, c2);

    printf("Le numero de telephone de c1 est: %s et celui de c2 est: %s\n", c1.phone, c2.phone);
    permuteContact(&c1, &c2);
    printf("Le numero de telephone de c1 est maintenant : %s et celui de c2 est: %s\n", c1.phone, c2.phone);


    return (EXIT_SUCCESS);
}

