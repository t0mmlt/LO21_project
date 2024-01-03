#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef RULE_H /* permet d'éviter les redéfinitions en dehors de ces bornes */
#define RULE_H

// Structure pour représenter une proposition dans la prémisse
typedef struct Proposition {
    char value; // Valeur de la proposition
    struct Proposition *next; // Pointeur vers la prochaine proposition dans la prémisse
} Proposition;

// Structure pour représenter une règle
typedef struct {
    Proposition *premise; // Prémisse de la règle (pointeur sur le premier élément de la liste chaînée)
    char conclusion; // Conclusion de la règle (caractère unique)
} Rule;

// Fonctions de construction

/**
 * @brief Crée une règle vide.
 * 
 * @return Un pointeur vers la règle vide créée.
 */
Rule *create_empty_rule();

/**
 * @brief Ajoute une proposition à la fin de la prémisse d'une règle.
 * 
 * @param rule La règle à laquelle ajouter la proposition.
 * @param proposition La proposition à ajouter à la prémisse.
 */
void add_tail_proposition_to_premise(Rule* rule, char proposition);

/**
 * @brief Crée la conclusion d'une règle.
 * 
 * @param rule La règle à laquelle attribuer la conclusion.
 * @param terminaison Le caractère de conclusion à assigner.
 */
void create_conclusion_to_rule(Rule *rule, char terminaison);

/**
 * @brief Supprime une proposition de la prémisse d'une règle.
 * 
 * @param rule La règle de laquelle supprimer la proposition.
 * @param proposition La proposition à supprimer de la prémisse.
 */
void remove_proposition_to_premise(Rule *rule, char proposition);

// Fonctions d'observation

/**
 * @brief Vérifie si une proposition appartient à la prémisse d'une règle (fonction récursive).
 * 
 * @param premisse La prémisse à parcourir.
 * @param proposition La proposition à rechercher dans la prémisse.
 * @return true si la proposition est trouvée dans la prémisse, sinon false.
 */
bool if_proposition_belong_to_rule(Proposition *premisse, char proposition);

/**
 * @brief Vérifie si une proposition appartient à la prémisse d'une règle (fonction principale).
 * 
 * @param rule La règle à examiner.
 * @param proposition La proposition à rechercher dans la prémisse.
 * @return true si la proposition est trouvée dans la prémisse, sinon false.
 */
bool if_proposition_belong_to_rule_main(Rule *rule, char proposition);

/**
 * @brief Vérifie si la prémisse d'une règle est vide.
 * 
 * @param rule La règle à vérifier.
 * @return true si la prémisse est vide, sinon false.
 */
bool if_empty_premisse(Rule *rule);

// Fonctions d'accès

/**
 * @brief Obtient le premier élément de la prémisse d'une règle.
 * 
 * @param rule La règle dont on veut obtenir le premier élément de la prémisse.
 * @return Un pointeur vers le premier élément de la prémisse, NULL si vide.
 */
Proposition *get_head_of_premise(Rule *rule);

/**
 * @brief Obtient la conclusion d'une règle.
 * 
 * @param rule La règle dont on veut obtenir la conclusion.
 * @return La conclusion de la règle (caractère unique), '\0' si vide.
 */
char get_conclusion_of_rule(Rule *rule);

// Fonction d'affichage

/**
 * @brief Affiche la prémisse et la conclusion d'une règle.
 * 
 * @param rule La règle à afficher.
 */
void display_rule(Rule *rule);

#endif /* RULE_H */
