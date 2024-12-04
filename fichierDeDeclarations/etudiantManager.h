#pragma once


struct  Etudiant
{
	char nom[50];
	float* notes;
	int nombreDeNotes;
};

Etudiant creerUnEtudiant(int numeroDeLetudiant=0);
float calculDeLaMoyenne(int nombreDeNotes, float* notes);
float findMaxNote(int nombreDeNote, float* notes);
void gestionDesEtudiant();
Etudiant getEtudiantByIndex(int index, int nombreDetudiants, Etudiant* etudiants);