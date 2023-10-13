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
};

