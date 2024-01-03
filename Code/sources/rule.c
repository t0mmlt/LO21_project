#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/Rule.h"


///////////////////////////////  Fonctions de construction  ///////////////////////////////

Rule *create_empty_rule() {
    Rule *empty_rule; // Déclaration d'un pointeur vers une règle vide
    empty_rule = (Rule *)malloc(sizeof(Rule)); // Allocation de mémoire pour une structure Rule

    if (empty_rule != NULL) { // Vérification si l'allocation de mémoire a réussi
        empty_rule->premise = NULL; // Initialisation de la prémisse à NULL
        empty_rule->conclusion = '\0'; // Initialisation de la conclusion à '\0'
    }
    return empty_rule; // Retourne le pointeur vers la règle vide créée
}

// Fonction pour ajouter en queue une proposition à la prémisse d'une règle
void add_tail_proposition_to_premise(Rule* rule, char proposition) {
    Proposition* new_proposition = (Proposition*)malloc(sizeof(Proposition));

    if (new_proposition != NULL) { // Vérification si l'allocation de mémoire a réussi
        new_proposition->value = proposition; // Initialisation de la valeur de la proposition
        new_proposition->next = NULL; // Initialisation du pointeur next à NULL

        // Ajout de la proposition à la fin de la prémisse
        if (rule->premise == NULL) {
            rule->premise = new_proposition; // Si la prémisse est vide, la nouvelle proposition devient la prémisse
        } else {
            Proposition* current = rule->premise;
            while (current->next != NULL) { // parcours de la liste simplement chainée
                current = current->next; // Passage à l'élément suivant de la liste
            }
            current->next = new_proposition; // Ajout de la proposition à la fin de la liste
        }
    }
}

// Fonction qui crée la conclusion d'une règle
void create_conclusion_to_rule(Rule *rule, char terminaison) {
    if (rule->conclusion == '\0') { // Vérifie si la conclusion n'est pas déjà définie
        rule->conclusion = terminaison; // Définit la conclusion de la règle
    }
}

// Fonction qui supprime la proposition de la prémisse d'une règle
void remove_proposition_to_premise(Rule *rule, char proposition) {
    Proposition *current = rule->premise;
    Proposition *prev = NULL; // initialisation d'un pointeur qui représentera l'élément précédent (i-1) lors du parcours de la liste

    while (current != NULL) {
        if (current->value == proposition) { // Recherche de la proposition à supprimer
            if (prev == NULL) {
                rule->premise = current->next; // Si la proposition à supprimer est en tête, mise à jour de la prémisse
            } else {
                prev->next = current->next; // Sinon, relier le précédent au suivant pour supprimer la proposition
            }
            free(current); // Libération de la mémoire de la proposition supprimée
            return;
        }
        prev = current; // Stockage du précédent pour la suppression
        current = current->next;
    }
}

///////////////////////////////  Fonctions d'observation  ///////////////////////////////

// Fonction récursive pour tester si une proposition appartient à la prémisse d'une règle
bool if_proposition_belong_to_rule(Proposition *premisse, char proposition) {
    if (premisse == NULL) {
        return false; // Si la prémisse est vide, retourne false
    } else {
        if (premisse->value == proposition) {
            return true; // Si la proposition est trouvée dans la prémisse, retourne true
        } else {
            return if_proposition_belong_to_rule(premisse->next, proposition); // Appel récursif avec la proposition suivante
        }
    }
}

// Fonction principale pour appeler la fonction récursive avec la prémisse de la règle
bool if_proposition_belong_to_rule_main(Rule *rule, char proposition) {
    if (rule == NULL || rule->premise == NULL) {
        return false; // Si la règle ou la prémisse est vide, retourne false
    } else {
        return if_proposition_belong_to_rule(rule->premise, proposition); // Appel initial à la fonction récursive
    }
}

// Fonction pour vérifier si la prémisse d'une règle est vide
bool if_empty_premisse(Rule *rule) {
    if (rule->premise == NULL) {
        return true; // Si la prémisse est vide, retourne true
    } else {
        return false; // Sinon, retourne false
    }
}

///////////////////////////////  Fonctions d'accès  ///////////////////////////////


// Fonction pour obtenir la tête de la prémisse d'une règle
Proposition *get_head_of_premise(Rule *rule) {
    if (rule != NULL && rule->premise != NULL) { // On s'assure que la regle et la prémisse ne sont pas vide avant de renvoyer quoi que ce soit
        return rule->premise; // Retourne le pointeur vers la première proposition de la prémisse
    }
    return NULL; // Si la règle ou la prémisse est vide, retourne NULL
}

// Fonction pour obtenir la conclusion d'une règle
char get_conclusion_of_rule(Rule *rule) {
    if (rule != NULL && rule->conclusion != '\0') {
        return rule->conclusion; // Retourne la conclusion de la règle
    }
    return '\0'; // Si la règle ou la conclusion est vide, retourne '\0'
}

///////////////////////////////  Fonction d'affichage  ///////////////////////////////

// Fonction pour afficher la prémisse et la conclusion d'une règle
void display_rule(Rule *rule) {
    Proposition *current = rule->premise;

    printf("Prémisse de la règle : ");
    while (current != NULL) { // Parcours de la liste
        printf("%c ", current->value); // Affiche la valeur de chaque proposition de la prémisse
        current = current->next; 
    }
    printf("\n");

    printf("Conclusion de la règle : ");
    printf("%c\n", rule->conclusion); // Affiche la conclusion de la règle
}