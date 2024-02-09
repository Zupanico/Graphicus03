/********
 * Fichier: monInterface.h
 * Auteurs: Mathieu Mercier, Nicolas Garant
 * Date: 10 janvier 2024
 * Description: La classe MonInterface teste l'interface usager GraphicusGUI.
 *
 * Copyright 2024 Département de génie électrique et génie informatique
 *                Université de Sherbrooke
 ********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "GraphicusGUI/graphicusGUI.h"
#include <ostream>
#include <fstream>
#include "canevas.h"
#include "cercle.h"
#include "carre.h"
#include "rectangle.h"

class MonInterface : public GraphicusGUI
{
public:
	MonInterface(const char *theName = nullptr);
	virtual void reinitialiserCanevas();
	bool ouvrirFichier(const char*);
	bool sauvegarderFichier(const char*);
	void reinitialiserCaneva();
	void coucheAjouter();
	void coucheRetirer();
	void coucheTranslater(int deltaX, int deltaY);
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int longueur, int largeur);
	void ajouterCarre(int x, int y, int cote);
	void modePileChange(bool mode);
	void retirerForme();
	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();
	void formePremiere();
	void formePrecedente();
	void formeSuivante();
	void formeDerniere();
private:
	void updateScreen();
	void updateInformations();
	Canevas caneva;
};

#endif // MONINTERFACE_H
