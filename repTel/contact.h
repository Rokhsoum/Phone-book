/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   contact.h
 * Author: Rokhaya Soumare
 *
 * Created on 9 juillet 2022, 23:15
 */

#include <stdbool.h>

#ifndef CONTACT_H
#define CONTACT_H

#define false       0
#define true        1

struct Contact {
    char firstName[30];
    char lastName[20];
    char phone[15];
};

void afficherContact(struct Contact c);

void modifierNum(struct Contact *c);

bool comparer(struct Contact c1, struct Contact c2);

void permuteContact(struct Contact *c1, struct Contact *c2);


#endif /* CONTACT_H */

