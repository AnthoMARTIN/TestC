#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

class Livre {
public:
    Livre(const std::string& titre, const std::string& auteur, int annee) : titre(titre), auteur(auteur), annee(annee), emprunte(false) {}

    const std::string& getTitre() const {
        return titre;
    }

    const std::string& getAuteur() const {
        return auteur;
    }

    int getAnnee() const {
        return annee;
    }

    bool estEmprunte() const {
        return emprunte;
    }

    void emprunter() {
        emprunte = true;
    }

    void retourner() {
        emprunte = false;
    }

private:
    std::string titre;
    std::string auteur;
    int annee;
    bool emprunte;

class Bibliotheque {
public:
    void ajouterLivre(const std::string& titre, const std::string& auteur, int annee) {
        Livre livre(titre, auteur, annee);
        livres.push_back(livre);
    }

    void supprimerLivre(const std::string& titre) {
        for (auto it = livres.begin(); it != livres.end(); ++it) {
            if (it->getTitre() == titre) {
                livres.erase(it);
                break;
            }
        }
    }

    void rechercherLivre(const std::string& titre) {
        for (const Livre& livre : livres) {
            if (livre.getTitre() == titre) {
                std::cout << "Titre : " << livre.getTitre() << std::endl;
                std::cout << "Auteur : " << livre.getAuteur() << std::endl;
                std::cout << "Année : " << livre.getAnnee() << std::endl;
                std::cout << "Statut : " << (livre.estEmprunte() ? "Emprunté" : "Disponible") << std::endl;
                return;
            }
        }
        std::cout << "Livre non trouvé." << std::endl;
    }

    void emprunterLivre(const std::string& titre) {
        for (Livre& livre : livres) {
            if (livre.getTitre() == titre) {
                if (!livre.estEmprunte()) {
                    livre.emprunter();
                    std::cout << "Livre emprunté avec succès." << std::endl;
                }
                else {
                    std::cout << "Le livre est déjà emprunté." << std::endl;
                }
                return;
            }
        }
        std::cout << "Livre non trouvé." << std::endl;
    }

    void retournerLivre(const std::string& titre) {
        for (Livre& livre : livres) {
            if (livre.getTitre() == titre) {
                if (livre.estEmprunte()) {
                    livre.retourner();
                    std::cout << "Livre retourné avec succès." << std::endl;
                }
                else {
                    std::cout << "Le livre n'est pas emprunté." << std::endl;
                }
                return;
            }
        }
        std::cout << "Livre non trouvé." << std::endl;
    }

private:
    std::vector<Livre> livres;
};

int main() {
    Bibliotheque bibliotheque;
    int choix;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Ajouter un livre" << std::endl;
        std::cout << "2. Supprimer un livre" << std::endl;
        std::cout << "3. Rechercher un livre" << std::endl;
        std::cout << "4. Emprunter un livre" << std::endl;
        std::cout << "5. Retourner un livre" << std::endl;
        std::cout << "6. Quitter" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choix;

        if (choix == 1) {
            std::string titre, auteur;
            int annee;
            std::cout << "Entrez le titre du livre : ";
            std::cin.ignore();
            std::getline(std::cin, titre);
            std::cout << "Entrez l'auteur du livre : ";
            std::getline(std::cin, auteur);
            std::cout << "Entrez l'année de publication : ";
            std::cin >> annee;
            bibliotheque.ajouterLivre(titre, auteur, annee);
        }
        else if (choix == 2) {
            std::string titre;
            std::cout << "Entrez le titre du livre à supprimer : ";
            std::cin.ignore();
            std::getline(std::cin, titre);
            bibliotheque.supprimerLivre(titre);
        }
        else if (choix == 3) {
            std::string titre;
            std::cout << "Entrez le titre du livre à rechercher : ";
            std::cin.ignore();
            std::getline(std::cin, titre);
            bibliotheque.rechercherLivre(titre);
        }
        else if (choix == 4) {
            std::string titre;
            std::cout << "Entrez le titre du livre à emprunter : ";
            std::cin.ignore();
            std::getline(std::cin, titre);
            bibliotheque.emprunterLivre(titre);
        }
        else if (choix == 5) {
            std::string titre;
            std::cout << "Entrez le titre du livre à retourner : ";
            std::cin.ignore();
            std::getline(std::cin, titre);
            bibliotheque.retournerLivre(titre);
        }
        else if (choix == 6) {
            break;
        }
    }

    return 0;
}
};

