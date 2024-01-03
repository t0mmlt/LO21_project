#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/knowledge_base.h"


///////////////////////////////  Fonction de construction  ///////////////////////////////

// Fonction pour créer une base de connaissances vide
KB *create_empty_KB() {
    KB *empty_KB; // Déclaration d'un pointeur vers une base de connaissances vide
    empty_KB = (KB *)malloc(sizeof(KB)); // Allocation de mémoire pour une base de connaissances

    if (empty_KB != NULL) { // Vérification si l'allocation de mémoire a réussi
        empty_KB->rule = NULL; // Initialise la règle à NULL car la base est vide
        empty_KB->next = NULL; // Initialise le pointeur suivant à NULL car il n'y a pas d'autres bases
    }
    return empty_KB; // Retourne le pointeur vers la base de connaissances vide créée
}


///////////////////////////////  Fonctions d'observation  ///////////////////////////////


/*en gros la meme chose que dans rule.h mais on remonte d'un crans*/


// Fonction pour ajouter une règle à une base de connaissances
void add_tail_rule_to_KB(KB *knowledge_base, Rule *rule) {
    if (knowledge_base != NULL && rule != NULL) {
        KB *new_KB = (KB *)malloc(sizeof(KB)); // Alloue de la mémoire pour une nouvelle base de connaissances

        if (new_KB != NULL) {
            new_KB->rule = rule; // Attribue la règle à la nouvelle base de connaissances
            new_KB->next = NULL; // Initialise le pointeur suivant à NULL

            // --- cette partie permet de stocker dans une BC la regle ainsi que le pointeur vers son suivant ---

            // Si la base de connaissances est vide, la nouvelle base devient la première
            if (knowledge_base->rule == NULL && knowledge_base->next == NULL) {
                knowledge_base->rule = rule;
                knowledge_base->next = NULL;
                free(new_KB); // Libère la mémoire de la nouvelle base de connaissances car elle n'est plus nécessaire
            } else {
                KB *current = knowledge_base;
                while (current->next != NULL) {
                    current = current->next; // Trouve la dernière base de connaissances dans la liste
                }
                current->next = new_KB; // Ajoute la nouvelle base à la fin de la liste
            }
        }
    }
}

///////////////////////////////  Fonctions d'accès  ///////////////////////////////

// Fonction pour accéder à la règle en tête de la base de connaissances
Rule *get_head_rule(KB *knowledge_base) {
    if (knowledge_base != NULL && knowledge_base->rule != NULL) { // verification que la BC n'est pas vide
        return knowledge_base->rule; // Retourne la règle en tête de la base de connaissances (soit le pointeur Rule = premier element de la liste de regles)
    }
    return NULL; // Si la base de connaissances est vide, retourne NULL
}

