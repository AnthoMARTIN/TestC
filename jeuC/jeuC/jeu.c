#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int joueur, ordinateur;
    int continuerPartie = 1;

    printf("Jouons a Pierre-Papier-Ciseaux !\n");

    while (continuerPartie) {
        printf("Choisissez votre coup :\n");
        printf("1. Pierre\n");
        printf("2. Papier\n");
        printf("3. Ciseaux\n");
        printf("Votre choix : ");
        scanf("%d", &joueur);

        // Génération du choix de l'ordinateur (aléatoire)
        srand(time(NULL));
        ordinateur = rand() % 3 + 1;

        // Affichage des choix
        printf("Vous avez choisi : ");
        switch (joueur) {
        case 1:
            printf("Pierre\n");
            break;
        case 2:
            printf("Papier\n");
            break;
        case 3:
            printf("Ciseaux\n");
            break;
        default:
            printf("Choix invalide\n");
            continue;
        }

        printf("L'ordinateur a choisi : ");
        switch (ordinateur) {
        case 1:
            printf("Pierre\n");
            break;
        case 2:
            printf("Papier\n");
            break;
        case 3:
            printf("Ciseaux\n");
            break;
        }

        // Détermination du gagnant
        if (joueur == ordinateur) {
            printf("Egalite !\n");
        }
        else if ((joueur == 1 && ordinateur == 3) || (joueur == 2 && ordinateur == 1) || (joueur == 3 && ordinateur == 2)) {
            printf("Vous avez gagne !\n");
        }
        else {
            printf("L'ordinateur a gagne !\n");
        }

        // Demande de continuer la partie
        printf("Voulez-vous jouer a nouveau ? (1 pour Oui, 0 pour Non) : ");
        scanf("%d", &continuerPartie);
    }

    printf("Merci d'avoir joue a Pierre-Papier-Ciseaux ! Au revoir.\n");

    return 0;
}

