#include "fonction.h"
#include<iostream>
#include<string>
#include <vector>
#include<ctime>
#include<fstream>

using namespace std;
/*void SetTableau(string Tableau[]) {
	Tableau[0] = "un";
	Tableau[1] = "deux";
	Tableau[2] = "cinq";
	Tableau[3] = "rouge";
	Tableau[4] = "membre";
	Tableau[5] = "conseil";
	Tableau[6] = "donner";
	Tableau[7] = "reponse";
	Tableau[8] = "etat";
	Tableau[9] = "son";
	Tableau[10] = "armement";
	Tableau[11] = "peu";
	Tableau[12] = "apres";
	Tableau[13] = "vacances";
	Tableau[14] = "annonces";
	Tableau[15] = "mercredi";
	Tableau[16] = "evident";
	Tableau[17] = "regime";
	Tableau[18] = "affirmer";
	Tableau[19] = "arme";
}*/
char GetCaractere(char Lettre) {
	cout << "Proposer une lettre :  ";
	cin >> Lettre; // Lettre = getchar();
	return Lettre;
}

int GetNombreAlleatoire(int Min, int Max) {
	srand(time(0));
	int NombreAleatoire = rand()% Max + Min;
	return NombreAleatoire;
}

string ChoisirMot(string Mots[], int Taille) {
	int GetNombreAlleatoire(int Min, int Max);
	Taille =  GetNombreAlleatoire(0, 19);
	string Mot = Mots[Taille];
	return Mot;
}
string ChoixMotFichier(string Mots[], int Taille) {
	string Mot;
	ifstream Fichier("data.txt");
	if (Fichier)
	{	
		while (getline(Fichier, Mot)) 
		{
			Mots[Taille] = Mot;
			Taille++;
		}
		
		Mot = ChoisirMot(Mots, Taille);
		return Mot;
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

	}
	
}
int AfficheIndi(int Taille) {
	Taille = GetNombreAlleatoire(0, 19);
	int Indice = Taille;
	return Indice;
}
void InitEtoile(string& Mot) {
	for (int i = 0; i < Mot.size(); i++) {
		Mot[i] = '*';
	}
}
bool TestCaractere(char Lettre, string Mot, string& MotCache) {
	bool Testeur(false);
	for (int i = 0; i < Mot.size(); i++) {
		if (Mot[i] == Lettre) {
				MotCache[i] = Lettre;
				Testeur = true;
		}
	}
	return Testeur;
}
bool TestGagne(string Mot, string MotCache, int coup) {
	if (Mot == MotCache) {
		return true;
	}
	else {
		return false;
	}
}

bool PhraseGagne(string Mot, string MotCache, int coup) { // verifier
	if (Mot == MotCache) {
		cout <<
			"     ____\n"
			"    / __ )_________ __   ______ \n"
			"   / __  / ___/ __ `/ | / / __ \\ \n"
			"  / /_/ / /  / /_/ /| |/ / /_/ / \n"
			" /_____/_/   \\__,_/ |___/\\____/ \n"
			<< endl;
			
		cout << "Le joueur a gagner ! Bien joue vous avez decouvert toutes les lettres du mot secret : "
			<< Mot << " en " << coup << " coups. Bravo !! "<<endl;
		return true;
	}
	else {
		cout <<
			"     ______                        ____ \n"
			"    / ____/____ ___ ____  ___     / __ \\_   _____  _____ \n"
			"   / / __/ __ `/ __ `__ \\/ _ \\   / / / / | / / _ \\/ ___/ \n"
			"  / /_/ / /_/ / / / / / /  __/  / /_/ /| |/ /  __/ / \n"
			"  \\____/\\__,_/_/ /_/ /_/\\___/   \\____/ |___/\\___/_/ \n"
			<< endl;
		
		cout << "Vous avez perdu, desole !" << endl;
		return false;
	}
}
void SetPendu(string Pendu[]) {
	Pendu[10] = "";
	Pendu[9] = " \n"
		"    \n"
		"    \n"
		"    \n"
		"    \n"
		" _| \n";
	Pendu[8] = " \n"
		"	   \n"
		"	   \n"
		" |    \n"
		" |    \n"
		"_|_   \n";
	Pendu[7] =
		"	   \n"
		" |    \n"
		" |    \n"
		" |    \n"
		" |    \n"
		"_|_   \n";
	Pendu[6] =
		" _ _   \n"
		" |     \n"
		" |     \n"
		" |     \n"
		" |     \n"
		"_|_    \n";
	Pendu[5] =
		" _ _ _ _  \n"
		" |        \n"
		" |        \n"
		" |        \n"
		" |        \n"
		"_|_       \n";
	Pendu[4] =
		" _ _ _ _ _ \n"
		" |     |   \n"
		" |         \n"
		" |         \n"
		" |         \n"
		"_|_        \n";
	Pendu[3] =
		" _ _ _ _ _ \n"
		" |     |   \n"
		" |     o   \n"
		" |     |   \n"
		" |         \n"
		"_|_        \n";
	Pendu[2] =
		" _ _ _ _ _ \n"
		" |     |   \n"
		" |     o  \n"
		" |    /|\\ \n"
		" |			\n"
		"_|_		\n";
	Pendu[1] =
		" _ _ _ _ _ \n"
		" |     |   \n"
		" |     o   \n"
		" |    /|\\  \n"
		" |    / 	\n"
		"_|_        \n";
	Pendu[0] =
		" _ _ _ _ _ \n"
		" |     |   \n"
		" |     o   \n"
		" |    /|\\  \n"
		" |    / \\	\n"
		"_|_        \n"
		;


}
void DessinerPendu(string Pendu[], int coup) {
	cout <<  Pendu[coup ] << endl;
}

void AfficherTab(string TableauJeu[]) {
	
	for (int i = 0; i < 20; i++) {
		cout << TableauJeu[i] << endl;
	}
}
// max lettre 25