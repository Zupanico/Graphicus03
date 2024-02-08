/********
 * Fichier: graphicus-02.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"
#include <QApplication>
#include "monInterface.h"

using namespace std;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MonInterface gui("Graphicus-03");
	return app.exec();
}

