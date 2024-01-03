#ifndef KNOWLEDGE_BASE_H
#define KNOWLEDGE_BASE_H

#include "Rule.h"


// Structure pour représenter une base de connaissances
typedef struct Knowledge_Base {
    Rule *rule; // Pointeur vers une règle
    struct Knowledge_Base *next; // Pointeur vers la base de connaissances suivante
} KB;

// Fonction de construction

/**
 * @brief Crée une base de connaissances vide.
 * 
 * @return Un pointeur vers une base de connaissances vide.
 */
KB *create_empty_KB();

// Fonctions d'observation

// Ajoute une règle à une base de connaissances
void add_tail_rule_to_KB(KB *knowledge_base, Rule *rule);

// Fonctions d'accès

/**
 * @brief Accède à la règle en tête de la base de connaissances.
 * 
 * @param knowledge_base La base de connaissances à examiner.
 * @return Un pointeur vers la règle en tête de la base de connaissances, NULL si vide.
 */
Rule *get_head_rule(KB *knowledge_base);

#endif /* KNOWLEDGE_BASE_H */