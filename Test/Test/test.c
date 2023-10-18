#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Personage
{
    char Name[50];
    int force;
    float taille;
    int pv;
    int vitesse;
};

void antho()
{

}

void afficherPersonage(struct Personage* personage)
{
    printf("%s - PV: %d, Force: %d\n", personage->Name, personage->pv, personage->force);
}

void attaquer(struct Personage* attaquant, struct Personage* cible)
{
    printf("%s attaque %s et inflige %d points de degats.\n", attaquant->Name, cible->Name, attaquant->force);
    cible->pv -= attaquant->force;
}

bool lireEntierLimite(int* valeur, const char* message, int limite)
{
    char buffer[100];
    while (true) {
        printf("%s", message);
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%d", valeur) == 1 && *valeur <= limite) {
            return true;
        }
        else {
            printf("Saisie invalide. Entrez un entier inferieur ou egal à %d.\n", limite);
        }
    }
}

bool lireFloatLimite(float* valeur, const char* message, float limite)
{
    char buffer[100];
    while (true) {
        printf("%s", message);
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%f", valeur) == 1 && *valeur <= limite) {
            return true;
        }
        else {
            printf("Saisie invalide. Entrez un nombre à virgule flottante inferieur ou egal a %f.\n", limite);
        }
    }
}

int main()
{
    struct Personage Antho;
    struct Personage Fury;

    // Initialisation d'Antho
    strcpy(Antho.Name, "Antho");
    lireEntierLimite(&Antho.force, "Entrez la force d'Antho (limite 20) : ", 20);
    lireFloatLimite(&Antho.taille, "Entrez la taille d'Antho (limite 3.0) : ", 3.0);
    lireEntierLimite(&Antho.pv, "Entrez les points de vie d'Antho (limite 100) : ", 100);
    lireEntierLimite(&Antho.vitesse, "Entrez la vitesse d'Antho (limite 20) : ", 20);

    // Initialisation de Fury
    strcpy(Fury.Name, "Fury");
    lireEntierLimite(&Fury.force, "Entrez la force de Fury (limite 20) : ", 20);
    lireFloatLimite(&Fury.taille, "Entrez la taille de Fury (limite 3.0) : ", 3.0);
    lireEntierLimite(&Fury.pv, "Entrez les points de vie de Fury (limite 100) : ", 100);
    lireEntierLimite(&Fury.vitesse, "Entrez la vitesse de Fury (limite 20) : ", 20);

    antho(&Antho);
    antho(&Fury);

    printf("Combat entre %s et %s !\n", Antho.Name, Fury.Name);

    // Déterminez l'ordre d'attaque
    struct Personage* attaquant;
    struct Personage* defenseur;

    if (Antho.vitesse > Fury.vitesse) {
        attaquant = &Antho;
        defenseur = &Fury;
    }
    else {
        attaquant = &Fury;
        defenseur = &Antho;
    }

    while (Antho.pv > 0 && Fury.pv > 0)
    {
        // Tour de l'attaquant
        attaquer(attaquant, defenseur);
        afficherPersonage(defenseur);

        // Vérifier si le défenseur est vaincu
        if (defenseur->pv <= 0)
        {
            printf("%s a ete vaincu. %s gagne !\n", defenseur->Name, attaquant->Name);
            break;
        }

        // Changer de rôle pour le prochain tour
        struct Personage* temp = attaquant;
        attaquant = defenseur;
        defenseur = temp;
    }

    return 0;
}
