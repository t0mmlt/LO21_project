#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/Rule.h"
#include "../headers/Fact_base.h"

// Prototype de la fonction pour afficher les faits déduits
void display_deduced_facts(KB *knowledge_base);

void inference_engine(Fact_base *facts, KB *knowledge_base) {
    bool new_fact_added = true;

    // Boucle principale du moteur d'inférence
    while (new_fact_added != false) {
        new_fact_added = false; // Réinitialise le booléen pour la nouvelle itération
        KB *current_rule = knowledge_base;

        // Parcourt chaque règle dans la base de connaissances
        while (current_rule != NULL) {
            Proposition *proposition = current_rule->rule->premise;
            bool all_premise_facts = true;

            // Vérifie si chaque élément de *facts appartient à la prémisse de la règle actuelle
            Proposition *current_fact = *facts;
            while (current_fact != NULL) {
                if (if_proposition_belong_to_rule(proposition, current_fact->value) == false) {
                    all_premise_facts = false;
                    break;
                }
                current_fact = current_fact->next;
            }

            // Si toutes les propositions de la prémisse sont des faits
            if (all_premise_facts == true) {
                Proposition *premise = get_head_of_premise(current_rule->rule);

                // Supprime les propositions de la prémisse de la règle validée
                while (premise != NULL) {
                    remove_proposition_to_premise(current_rule->rule, premise->value);
                    premise = premise->next;
                }
            }
            proposition = proposition->next;
        }
    }
}


int main() {
    // Création d'une base de faits vide
    Fact_base *facts = create_empty_fact_base();

    // Ajout de propositions à la base de faits
    add_proposition_to_fact_base(facts, 'A');
    add_proposition_to_fact_base(facts, 'B');
    add_proposition_to_fact_base(facts, 'C');

    // Affichage de la base de faits
    display_fact_base(*facts);

    // Création d'une base de connaissances vide
    KB *knowledge_base = create_empty_KB();

    // Création de règles et ajout à la base de connaissances
    Rule *rule1 = create_empty_rule();
    add_tail_proposition_to_premise(rule1, 'A');
    add_tail_proposition_to_premise(rule1, 'B');
    create_conclusion_to_rule(rule1, 'X');
    add_tail_rule_to_KB(knowledge_base, rule1);

    Rule *rule2 = create_empty_rule();
    add_tail_proposition_to_premise(rule2, 'B');
    add_tail_proposition_to_premise(rule2, 'C');
    create_conclusion_to_rule(rule2, 'Y');
    add_tail_rule_to_KB(knowledge_base, rule2);

    // Appliquer le moteur d'inférence pour déduire de nouveaux faits
    inference_engine(facts, knowledge_base);

    // Afficher les faits déduits
    display_deduced_facts(knowledge_base);

    // Libérer la mémoire si nécessaire (libérer les faits et la base de connaissances)
    // ...

    return 0;
}

// Fonction pour afficher les faits déduits
void display_deduced_facts(KB *knowledge_base) {
    printf("Deduced Facts: ");

    KB *current_rule = knowledge_base;

    // Parcourir la base de connaissances
    while (current_rule != NULL) {
        // Vérifier si la prémisse de la règle est vide en utilisant if_empty_premisse
        if (if_empty_premisse(current_rule->rule)) {
            // Afficher les conclusions de la règle
            printf("%c ", get_conclusion_of_rule(current_rule->rule));
        }

        current_rule = current_rule->next; // Passer à la règle suivante
    }

    printf("\n");
}
