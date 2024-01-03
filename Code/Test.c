#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/Rule.h" /*attention a la redondance dans l'inclusion des fichiers (resolu avec define et endif)*/
#include "headers/Knowledge_Base.h"


int main() {
    // Création d'une règle vide
    Rule *my_rule = create_empty_rule();

    // Ajout de propositions à la prémisse de la règle
    add_tail_proposition_to_premise(my_rule, 'A');
    add_tail_proposition_to_premise(my_rule, 'B');
    add_tail_proposition_to_premise(my_rule, 'C');

    // Affichage de la règle
    printf("Après l'ajout des propositions : \n");
    display_rule(my_rule);

    // Vérification si la proposition 'B' appartient à la prémisse de la règle
    char proposition_a_verifier = 'B';
    if (if_proposition_belong_to_rule_main(my_rule, proposition_a_verifier)) {
        printf("La proposition '%c' appartient à la prémisse.\n", proposition_a_verifier);
    } else {
        printf("La proposition '%c' n'appartient pas à la prémisse.\n", proposition_a_verifier);
    }

    // Suppression de la proposition 'B' de la prémisse de la règle
    remove_proposition_to_premise(my_rule, 'B');

    // Affichage de la règle après la suppression
    printf("Après la suppression de la proposition 'B' : \n");
    display_rule(my_rule);

    // Vérification si la prémisse est vide
    if (if_empty_premisse(my_rule)) {
        printf("La prémisse est vide.\n");
    } else {
        printf("La prémisse n'est pas vide.\n");
    }

    // Récupération de la tête de la prémisse et affichage
    Proposition *head = get_head_of_premise(my_rule);
    if (head != NULL) {
        printf("Tête de la prémisse : %c\n", head->value);
    } else {
        printf("La prémisse est vide.\n");
    }

    // Récupération de la conclusion de la règle et affichage
    char conclusion = get_conclusion_of_rule(my_rule);
    if (conclusion != '\0') {
        printf("Conclusion de la règle : %c\n", conclusion);
    } else {
        printf("La conclusion n'est pas définie.\n");
    }

    // Libération de la mémoire allouée pour la règle et ses propositions
    Proposition *current = my_rule->premise;
    while (current != NULL) {
        Proposition *temp = current;
        current = current->next;
        free(temp);
    }
    free(my_rule);

    return 0;
}

/*
int main() {
    // Création d'une base de connaissances vide
    KB *my_KB = create_empty_KB();

    // Création d'une règle
    Rule *my_rule = (Rule *)malloc(sizeof(Rule));
    if (my_rule != NULL) {
        my_rule->premise = NULL; // On suppose que la prémisse est vide
        my_rule->conclusion = 'A'; // Conclusion de la règle

        // Ajout de la règle à la base de connaissances
        add_tail_rule_to_KB(my_KB, my_rule);

        // Accès à la règle en tête de la base de connaissances
        Rule *head_rule = get_head_rule(my_KB);
        if (head_rule != NULL) {
            printf("Règle en tête de la base de connaissances : Conclusion = %c\n", head_rule->conclusion);
        } else {
            printf("La base de connaissances est vide ou la règle en tête est NULL.\n");
        }
    } else {
        printf("Erreur lors de l'allocation de mémoire pour la règle.\n");
    }

    return 0;
}
*/