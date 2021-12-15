#include<iostream>
#include<string>
#include <vector>
#include "fonction.h"
#include<ctime>

using namespace std;

int main() {
	string Tab[20];
	/*SetTableau(Tab);
	AfficherTab(Tab); Vérifier La fonction SetTableau*/
	int Taille(0);
	string DessinPendu[11];
	SetPendu(DessinPendu);
	cout << " Voici le jeu du pendu ! Bon jeu ! " << endl;
	int ContinueJeu(0);
	cout << "    ------- MENU -------    " << endl;
	cout << "VOULEZ-VOUS DEMARRER UNE PARTIE (entrez 0 pour quitter ou 1 pour jouer) ";
	cin >> ContinueJeu;
	while (ContinueJeu == 1) {
		/*string Mot = ChoisirMot(Tab, Taille);*/
		string Mot = ChoixMotFichier(Tab, Taille);
		string MotEtoile = Mot;
		InitEtoile(MotEtoile);
		int coup(10);
		while (TestGagne(Mot, MotEtoile, coup) != true && coup > 0) {
			char LettreJeu = 'x';
			cout << "Il vous reste " << coup << " chance(s) a jouer pour gagner ! " << endl;
			DessinerPendu(DessinPendu, coup);
			cout << "Le mot secret est : " << MotEtoile << endl;
			LettreJeu = GetCaractere(LettreJeu);
			TestCaractere(LettreJeu, Mot, MotEtoile);
			if (TestCaractere(LettreJeu, Mot, MotEtoile) == false) {
				coup = coup - 1;

			}
		}
		if (coup == 0) {
			DessinerPendu(DessinPendu, coup);
		}
		PhraseGagne(Mot, MotEtoile, coup);
		ContinueJeu = 0;
		cout << "Si vous voulez rejouer ! Entrer 1 ! ";
		cin >> ContinueJeu;
	}
	cout << "Fin de la partie ! " << endl;
}