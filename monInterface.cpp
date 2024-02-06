/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include "monInterface.h"

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	reinitialiserCanevas();
	effacerInformations();
}

void MonInterface::reinitialiserCanevas()
{
	ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	// fois que la commande de réinitialisation de canevas est choisie par l'usager.
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L a" << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;

	// Ensuite, on dessine ce qui a été généré dans Graphicus
	dessiner(os.str().c_str());
}


bool MonInterface::ouvrirFichier(const char* nom) {
	ifstream monFlux(nom);

	if (monFlux)
	{
		string Lettre = "I";
		while (monFlux >> Lettre) {
			if (Lettre == "L") {
				string status;
				monFlux >> status;
				caneva.ajouterCouche();
			}
			else if (Lettre == "R") {
				int x;
				int y;
				int l;
				int h;
				monFlux >> x;
				monFlux >> y;
				monFlux >> l;
				monFlux >> h;
				Rectangle* rectangle = new Rectangle(l, h, x, y);;
				caneva.ajouterForme(rectangle);
			}
			else if (Lettre == "K") {
				int x;
				int y;
				int c;
				monFlux >> x;
				monFlux >> y;
				monFlux >> c;
				Carre* carre = new Carre(c, x, y);
				caneva.ajouterForme(carre);
			}
			else if (Lettre == "C") {
				int x;
				int y;
				int r;
				monFlux >> x;
				monFlux >> y;
				monFlux >> r;
				Cercle* cercle = new Cercle(r, x, y);
				caneva.ajouterForme(cercle);
			}
		}
		updateScreen();
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		return false;
	}

}

bool MonInterface::sauvegarderFichier(const char* nom)
{
	ofstream monFlux(nom);
	
	if (monFlux)
	{
		caneva.afficher(monFlux);
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		return false;
	}
}

void MonInterface::reinitialiserCaneva()
{
	caneva.reinitialiser();
	updateScreen();
}

void MonInterface::coucheAjouter()
{
	caneva.ajouterCouche();
	updateScreen();
}

void MonInterface::coucheRetirer()
{
	caneva.supprimerCoucheActive();
	updateScreen();
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	caneva.translater(deltaX, deltaY);
	updateScreen();
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	Cercle* cercle = new Cercle(rayon, x, y);
	caneva.ajouterForme(cercle);
	updateScreen();
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	Rectangle* rectangle = new Rectangle(longueur,largeur, x, y );
	caneva.ajouterForme(rectangle);
	updateScreen();
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	Carre* carre = new Carre(cote,x,y);
	caneva.ajouterForme(carre);
	updateScreen();
}

void MonInterface::modePileChange(bool mode)
{

}

void MonInterface::retirerForme()
{
	
	caneva.retirerFormeActive();
	updateScreen();
}

void MonInterface::couchePremiere()
{
	caneva.activerCouche(0);
	updateScreen();
}

void MonInterface::couchePrecedente()
{
	caneva.activerCouche(caneva.getCoucheActive() - 1);
	updateScreen();
}

void MonInterface::coucheSuivante()
{
	caneva.activerCouche(caneva.getCoucheActive() + 1);
	updateScreen();
}

void MonInterface::coucheDerniere()
{
	caneva.activerCoucheDerniere();
	updateScreen();
}

void MonInterface::formePremiere()
{
	caneva.activerForme(0);
	updateScreen();
}

void MonInterface::formePrecedente()
{
	caneva.activerForme(caneva.getFormeActive() - 1);
}

void MonInterface::formeSuivante()
{
	caneva.activerForme(caneva.getFormeActive() + 1);
}

void MonInterface::formeDerniere()
{
	caneva.activerFormeDerniere();
}

void MonInterface::updateScreen()
{
	ostringstream stream;
	caneva.afficher(stream);
	string str = stream.str();
	const char* chr = str.c_str();
	dessiner(chr);
	updateInformations();
}

void MonInterface::updateInformations()
{
	Informations info;

	info.nbCouches = caneva.getNbCouches();
	info.nbFormesCanevas = caneva.getNbFormes();
	info.coucheActive = caneva.getCoucheActive();
	info.aireCanevas = caneva.aire();
	info.nbFormesCouche = caneva.getNbFormesCoucheActive();
	info.aireCouche = caneva.getAireCouche();
	info.formeActive = caneva.getFormeActive();
	info.coordX = caneva.getCoordXForme();
	info.coordY = caneva.getCoordYForme();
	info.aireForme = caneva.getAireFormeActive();

	setInformations(info);
}
