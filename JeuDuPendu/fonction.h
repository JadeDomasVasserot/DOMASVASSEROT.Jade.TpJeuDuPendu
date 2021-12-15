
#include<iostream>
#include<string>
#include <vector>
#include<ctime>

#ifndef FONCTION_H
#define FONCTION_H
void GetChar(char Lettre);
char GetCaractere(char Lettre);
int GetNombreAlleatoire(int Min, int Max);
void SetTableau(std::string Tableau[]);
/*std::string ChoisirMot(std::string Mots[], int Taille);*/
std::string ChoixMotFichier(std::string Mots[], int Taille);
void InitEtoile(std::string& Mot);
bool TestCaractere(char lettre, std::string mot, std::string& motCache);
bool TestGagne(std::string Mot, std::string MotCache, int coup);
bool PhraseGagne(std::string Mot, std::string MotCache, int coup);
void DessinerPendu(std::string DessinPendu[], int coup);
void SetPendu(std::string Pendu[]);
void AfficherTab(std::string TabJeu[]);
int AfficheIndi(int Taille);
#endif // !FONCTION_H



