#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int nombreMystere, nombreJoueur, essais = 0;

    // Initialisation de la génération de nombres aléatoires
    srand(time(0));

    // Génération du nombre mystère entre 1 et 100
    nombreMystere = (rand() % 100) + 1;

    printf("Bienvenue dans le jeu du nombre mystere entre 1 et 100.\n");

    do {
        printf("Entrez votre estimation : ");
        scanf("%d", &nombreJoueur);

        essais++;

        if (nombreJoueur < nombreMystere) {
            printf("Le nombre mystere est plus grand. Essayez a nouveau.\n");
        }
        else if (nombreJoueur > nombreMystere) {
            printf("Le nombre mystere est plus petit. Essayez a nouveau.\n");
        }
        else {
            printf("Felicitations ! Vous avez devine le nombre mystere (%d) en %d essais.\n", nombreMystere, essais);
        }
    } while (nombreJoueur != nombreMystere);

    return 0;
}
