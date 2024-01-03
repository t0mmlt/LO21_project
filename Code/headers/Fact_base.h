#include "../headers/Rule.h"
#include "../headers/knowledge_base.h"
#include <stdio.h>
#include <stdlib.h>

typedef Proposition *Fact_base;

// Création d'une Fact_base vide
Fact_base * create_empty_fact_base() {
    return NULL; // Une Fact_base vide est simplement représentée par un pointeur NULL
}

// Ajout d'une proposition à la Fact_base
void add_proposition_to_fact_base(Fact_base *fact_base, char proposition_value) {
    Proposition *new_proposition = (Proposition *)malloc(sizeof(Proposition));
    if (new_proposition == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire pour la proposition.\n");
        exit(EXIT_FAILURE);
    }

    new_proposition->value = proposition_value;
    new_proposition->next = NULL;

    // Si la Fact_base est vide, la nouvelle proposition devient le premier élément
    if (*fact_base == NULL) {
        *fact_base = new_proposition;
    } else {
        // Sinon, parcourir la Fact_base jusqu'à la fin pour ajouter la nouvelle proposition
        Proposition *current = *fact_base;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_proposition;
    }
}

// Affichage de la Fact_base
void display_fact_base(Fact_base fact_base) {
    printf("Fact_base: ");
    while (fact_base != NULL) {
        printf("%c ", fact_base->value);
        fact_base = fact_base->next;
    }
    printf("\n");
}
