#include <iostream>
#include <string>
#include <random>

class perso {
public:
    std::string name;
    int pv;
    int niveau; 
    int force;

    perso(const std::string& charName, int charpv, int charniveau, int charforce)
        : name(charName), pv(charpv), niveau(charniveau), force(charforce) {}

    void PrintInfo() {
        std::cout << "Nom : " << name << std::endl;
        std::cout << "Sante : " << pv << std::endl;
        std::cout << "Niveau : " << niveau << std::endl;
        std::cout << "Force : " << force << std::endl;
    }

    void Attack(perso& target, int damage) {
        std::cout << name << " attaque " << target.name << " et inflige " << damage << " points de degats." << std::endl;
        target.pv -= damage;
        std::cout << target.name << " a maintenant " << target.pv << " points de vie restants." << std::endl;
    }

    void NormalAttack(perso& target) {
        Attack(target, force);
    }

    int SpecialAttack(perso& target) {
        std::random_device rd; // Ca sert à générer des nombres aléatoires
        std::default_random_engine engine(rd());
        std::uniform_int_distribution<int> distribution(0, 1); // nombre aléatoires 0 et 1

        int damageMultiplier = distribution(engine) == 1 ? 2 : 0;

        int damage = force * damageMultiplier;

        std::cout << name << " tente une attaque speciale sur " << target.name;
        if (damageMultiplier == 2) {
            std::cout << " et inflige " << damage << " points de degats (double)!" << std::endl;
        }
        else {
            std::cout << " mais rate l'attaque speciale!" << std::endl;
        }

        target.pv -= damage;
        std::cout << target.name << " a maintenant " << target.pv << " points de vie restants." << std::endl;
        return damage; // Retourne les dégâts infligés
    }

    bool IsAlive() {
        return pv > 0;
    }
};

int main() {
    int force1, force2;

    std::cout << "Entrez la force d'Antho : ";
    std::cin >> force1;

    std::cout << "\nEntrez la force de Matheo : ";
    std::cin >> force2;

    perso player1("Antho", 100, 1, force1);
    perso player2("Matteo", 100, 1, force2);

    while (player1.IsAlive() && player2.IsAlive()) {
        int choice;

        std::cout << "\nTour de " << player1.name << std::endl;
        std::cout << "\n1. Attaque normale" << std::endl;
        std::cout << "\n2. Attaque speciale" << std::endl;
        std::cout << "\nChoisissez une attaque (1 ou 2) : ";
        std::cin >> choice;

        if (choice == 1) {
            player1.NormalAttack(player2);
        }
        else if (choice == 2) {
            int damage = player1.SpecialAttack(player2);
            if (damage == 0) {
                std::cout << "L'attaque speciale a echoue!" << std::endl;
            }
        else {
                std::cout << "Choix invalide. Utilisation de l'attaque normale." << std::endl;
                player1.NormalAttack(player2);
            }

        if (!player2.IsAlive()) {
                std::cout << player2.name << " est KO !" << std::endl;
                break;
            }

            std::cout << "\nTour de " << player2.name << std::endl;
            std::cout << "\n1. Attaque normale" << std::endl;
            std::cout << "\n2. Attaque speciale" << std::endl;
            std::cout << "\nChoisissez une attaque (1 ou 2) : ";
            std::cin >> choice;

            if (choice == 1) {
                player2.NormalAttack(player1);
            }
            else if (choice == 2) {
                int damage = player2.SpecialAttack(player1);
                if (damage == 0) {
                    std::cout << "L'attaque speciale a echoue!" << std::endl;
                }
            }
            else {
                std::cout << "Choix invalide. Utilisation de l'attaque normale." << std::endl;
                player2.NormalAttack(player1);
            }

            if (!player1.IsAlive()) {
                std::cout << player1.name << " est KO !" << std::endl;
                break;
            }
        }
    }
    if (player1.IsAlive())
        std::cout << player1.name << " a gagne !" << std::endl;
    else if (player2.IsAlive())
        std::cout << player2.name << " a gagne !" << std::endl;
    else
        std::cout << "Match nul !" << std::endl;

    return 0;

}