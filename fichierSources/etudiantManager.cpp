#include "etudiantManager.h"
#include <iostream>
#include <cstdarg>
#include <string>

Etudiant creerUnEtudiant(int numeroDeLetudiant)
{
	std::cout << "Creation de L'etudiant n* " << numeroDeLetudiant << std::endl;
	Etudiant etudiant;
	std::cin.ignore();
	std::cout << "Entrez le nom de l'etudiant: ";
	std::cin.getline(etudiant.nom, 50);
	std::cout << "Combien de notes ? ";
	std::cin >> etudiant.nombreDeNotes;
	// Allocation dynamique de la mémoire pour les notes 
	etudiant.notes = new float[etudiant.nombreDeNotes];
	
	for (int i = 0; i < etudiant.nombreDeNotes; i++) {
		std::cout << "Entrez la note n^ " << i + 1 << ":";
		std::cin >> etudiant.notes[i];
	}

	// Affichage des informations de l'étudiant
	std::cout << "Voici l'etudiant que vous venez de creer " << std::endl;

	std::cout << "Nom : " << etudiant.nom << std::endl;
	std::cout << "Notes : ";
	for (int i = 0; i < etudiant.nombreDeNotes; ++i) {
		std::cout << etudiant.notes[i] << " ";
	}
	std::cout << std::endl;
	return etudiant;
}

float calculDeLaMoyenne(int nombreDeNotes, float* notes) {
	if (nombreDeNotes == 0) {
		std::cout << "On ne peut determiner la moyenne de 0" << std::endl;
		return 0.f;
	}

	float sum = 0.f;
	for (int i = 0; i < nombreDeNotes; i++) {
		sum += notes[i];
	}
	return sum / nombreDeNotes;
}

float findMaxNote(int nombreDeNotes, float* notes) {
	if (nombreDeNotes == 0) {
		std::cout << "Aucune note pour trouver le maximum." << std::endl;
		return 0.f;
	}

	float maxNote = notes[0];
	for (int i = 1; i < nombreDeNotes; i++) {
		if (notes[i] > maxNote) {
			maxNote = notes[i];
		}
	}
	return maxNote;
}

void gestionDesEtudiant() {
    int nombreDetudiants;
    std::cout << "==== Bienvenue dans l'interface de gestion des étudiants ====" << std::endl;
    std::cout << "Veuillez entrer le nombre d'étudiants que vous souhaitez gérer : ";
    std::cin >> nombreDetudiants;

    Etudiant* etudiants = new Etudiant[nombreDetudiants];

    std::cout << "Création de " << nombreDetudiants << ((nombreDetudiants > 1) ? " étudiants" : " étudiant") << " : " << std::endl;
    for (int i = 0; i < nombreDetudiants; i++) {
        etudiants[i] = creerUnEtudiant(i + 1);
    }

    bool continuer = true;
    while (continuer) {
        std::cout << "\n=== Menu ===" << std::endl;
        std::cout << "y - Calculer la moyenne d'un étudiant." << std::endl;
        std::cout << "m - Trouver la note maximale d'un étudiant." << std::endl;
        std::cout << "q - Quitter le programme." << std::endl;

        char command;
        std::cin >> command;

        switch (command) {
        case 'y': {
            std::cout << "Entrez le numéro de l'étudiant : ";
            int numeroDeLetudiant;
            std::cin >> numeroDeLetudiant;
            Etudiant etudiant = getEtudiantByIndex(numeroDeLetudiant - 1, nombreDetudiants, etudiants);
            if (etudiant.nombreDeNotes > 0) {
                float moyenne = calculDeLaMoyenne(etudiant.nombreDeNotes, etudiant.notes);
                std::cout << "Moyenne de l'étudiant n* " << numeroDeLetudiant << " : " << moyenne << std::endl;
            }
        } break;

        case 'm': {
            std::cout << "Entrez le numéro de l'étudiant : ";
            int numeroDeLetudiant;
            std::cin >> numeroDeLetudiant;
            Etudiant etudiant = getEtudiantByIndex(numeroDeLetudiant - 1, nombreDetudiants, etudiants);
            if (etudiant.nombreDeNotes > 0) {
                float maxNote = findMaxNote(etudiant.nombreDeNotes, etudiant.notes);
                std::cout << "Note maximale de l'étudiant n* " << numeroDeLetudiant << " : " << maxNote << std::endl;
            }
        } break;

        case 'q':
            continuer = false;
            break;

        default:
            std::cout << "Commande inconnue. Veuillez réessayer." << std::endl;
        }
    }

    // Libération de la mémoire
    for (int i = 0; i < nombreDetudiants; i++) {
        delete[] etudiants[i].notes;
    }
    delete[] etudiants;
}

Etudiant getEtudiantByIndex(int index, int nombreDetudiants, Etudiant* etudiants) {
	if (index < 0 || index >= nombreDetudiants) {
		std::cerr << "L'étudiant n° " << index + 1 << " n'existe pas." << std::endl;
		return Etudiant{};
	}
	return etudiants[index];
}

