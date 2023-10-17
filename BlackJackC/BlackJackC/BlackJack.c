#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genererCarte() {
    return rand() % 13 + 1; // Valeurs possibles de 1 à 13 (As à Roi)
}

int calculerValeurMain(int main[], int nbCartes) {
    int valeur = 0;
    int as = 0; // Compte le nombre d'As dans la main

    for (int i = 0; i < nbCartes; i++) {
        int carte = main[i];

        if (carte >= 10) {
            valeur += 10; // Cartes de 10 à Roi valent 10 points
        }
        else if (carte == 1) {
            valeur += 11; // As vaut 11 points par défaut
            as++;
        }
        else {
            valeur += carte;
        }
    }

    while (as > 0 && valeur > 21) {
        valeur -= 10; // Si la main dépasse 21, réduire la valeur des As de 10 points chacun
        as--;
    }

    return valeur;
}

int main() {
    srand(time(NULL));
    int mainJoueur[10]; 
    int mainCroupier[10]; 
    int nbCartesJoueur = 0;
    int nbCartesCroupier = 0;
    int continuerPartie = 1;

    printf("Bienvenue au jeu de Blackjack!\n");

    while (continuerPartie) {
        // Initialisation du jeu
        for (int i = 0; i < 10; i++) {
            mainJoueur[i] = 0;
            mainCroupier[i] = 0;
        }
        nbCartesJoueur = 0;
        nbCartesCroupier = 0;

        // Distribution des cartes initiales
        mainJoueur[nbCartesJoueur++] = genererCarte();
        mainCroupier[nbCartesCroupier++] = genererCarte();
        mainJoueur[nbCartesJoueur++] = genererCarte();
        mainCroupier[nbCartesCroupier++] = genererCarte();

        printf("Vos cartes : %d, %d\n", mainJoueur[0], mainJoueur[1]);
        printf("Carte visible du croupier : %d\n", mainCroupier[0]);

        // Tour du joueur
        while (1) {
            int valeurMainJoueur = calculerValeurMain(mainJoueur, nbCartesJoueur);

            if (valeurMainJoueur == 21) {
                printf("Blackjack! Vous avez gagne!\n");
                break;
            }
            else if (valeurMainJoueur > 21) {
                printf("Desole, vous avez dépasse 21. Vous avez perdu.\n");
                break;
            }

            printf("Voulez-vous prendre une autre carte ? (1 pour Oui, 0 pour Non) : ");
            int choix;
            scanf("%d", &choix);

            if (choix == 1) {
                mainJoueur[nbCartesJoueur++] = genererCarte();
                printf("Nouvelle carte : %d\n", mainJoueur[nbCartesJoueur - 1]);
            }
            else {
                break;
            }
        }

        // Tour du croupier
        while (1) {
            int valeurMainCroupier = calculerValeurMain(mainCroupier, nbCartesCroupier);

            if (valeurMainCroupier >= 17) {
                break;
            }

            mainCroupier[nbCartesCroupier++] = genererCarte();
        }

        printf("Main du joueur : ");
        for (int i = 0; i < nbCartesJoueur; i++) {
            printf("%d ", mainJoueur[i]);
        }
        printf("\n");

        printf("Main du croupier : ");
        for (int i = 0; i < nbCartesCroupier; i++) {
            printf("%d ", mainCroupier[i]);
        }
        printf("\n");

        int valeurMainJoueur = calculerValeurMain(mainJoueur, nbCartesJoueur);
        int valeurMainCroupier = calculerValeurMain(mainCroupier, nbCartesCroupier);

        if (valeurMainJoueur > 21) {
            printf("Vous avez dépasse 21. Vous avez perdu.\n");
        }
        else if (valeurMainCroupier > 21 || valeurMainJoueur > valeurMainCroupier) {
            printf("Felicitations, vous avez gagne!\n");
        }
        else if (valeurMainJoueur < valeurMainCroupier) {
            printf("Desole, vous avez perdu.\n");
        }
        else {
            printf("Match nul!\n");
        }

        printf("Voulez-vous jouer a nouveau ? (1 pour Oui, 0 pour Non) : ");
        scanf("%d", &continuerPartie);
    }

    printf("Merci d'avoir joue au Blackjack! Au revoir.\n");

    return 0;
}
