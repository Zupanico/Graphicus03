/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "tests.h"
// #include "vecteur.cpp"

void Tests::tests_unitaires_formes()
{
   // Construction
   Rectangle r1(1, 1, 2, 2); // Rectangle
   Carre cr1(1, 2, 2);       // Carre
   Cercle c1(1, 2, 2);       // Cercle

   // get
   // printf("%i,%i \n", r1.getAncrage().x, r1.getAncrage().y);   // affiche les points d'ancrage du rectangle en X,Y
   // printf("%i,%i \n", cr1.getAncrage().x, cr1.getAncrage().y); // affiche les points d'ancrage du carre en X,Y
   // printf("%i,%i \n", c1.getAncrage().x, c1.getAncrage().y);   // affiche les points d'ancrage du cercle en X,Y

   // afficher
   c1.afficher(cout);
   r1.afficher(cout);
   cr1.afficher(cout);
   printf("\n TRANSLATION!! \n");
   // translater
   c1.translater(3, 3);
   r1.translater(3, 3);
   cr1.translater(3, 3);
   c1.afficher(cout);
   r1.afficher(cout);
   cr1.afficher(cout);
}

void Tests::tests_unitaires_vecteur()
{

}

void Tests::tests_unitaires_couche()
{
   /*
   Couche c;
   Rectangle *ptr = new Rectangle(2, 5);
   Carre *ptrCarre = new Carre(4);
   c.ajout(ptr);
   c.ajout(ptrCarre);
   c.ChangementEtat('N');
   // cout << c.aireTotale();
   c.viderCouche();
   c.afficher(cout);

   // cout << c.getForme(0);
   */
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl;
   Canevas c;
   cout << "Etape 1 activer couche 2 : " << c.activerCouche(2) << endl << endl;
   
   Cercle *cerclePtr1 = new Cercle(5, 0, 1);
   Carre *carrePtr1 = new Carre(6, 1, 2);
   Rectangle *rectanglePtr1 = new Rectangle(4, 9, 2, 3);

   cout << "Ajout cercle (r = 5, x = 0, y = 1) : " << c.ajouterForme(cerclePtr1) << endl;
   cout << "Ajout carre (c = 6, x = 1, y = 2) : " << c.ajouterForme(carrePtr1) << endl;
   cout << "Ajout rectangle (l = 4, h = 9, x = 2, y = 3) : " << c.ajouterForme(rectanglePtr1) << endl;
   

   cout << endl << "Etape 2 activer couche 1 : " << c.activerCouche(1) << endl;

   Rectangle *rectanglePtr2 = new Rectangle(12,3);

   cout << "Ajout rectangle : " << c.ajouterForme(rectanglePtr2) << endl;

   cout << endl << "Etape 3 affichage canevas" << endl << endl;
   c.afficher(cout);

   cout << endl << "Etape 4 calcul aire totale : "<< c.aire() << endl;
   
   cout << endl << "Etape 5 activer couche 0 : " << c.activerCouche(0) << endl;

   Rectangle *rectanglePtr5 = new Rectangle(1, 1);
   Carre *carrePtr5 = new Carre(1);
   Cercle *cerclePtr5 = new Cercle(1);

   cout << "Ajout rectangle (l = 1, h = 1) : " << c.ajouterForme(rectanglePtr5) << endl;
   cout << "Ajout carre (c = 1) : " << c.ajouterForme(carrePtr5) << endl;
   cout << "Ajout cercle (r = 1) : " << c.ajouterForme(cerclePtr5) << endl;

   cout << endl << "Etape 6 activer couche 2 : " << c.activerCouche(2) << endl;

   cout << endl << "Appliquer translation  (x = 2, y = 1) : " << c.translater(2,1) << endl;

   cout << endl << "Etape 7 affichage canevas" << endl << endl;

   c.afficher(cout);

   cout << endl << "Etape 8 calcul aire totale : "<< c.aire() << endl;
   
   cout << endl << "Etape 9 activer couche 0 : " << c.activerCouche(0) << endl;

   cout << endl << "Retirer la deuxieme forme : " << c.retirerForme(1) << endl;

   cout << endl << "Etape 10 reinitialiser la couche 1 : " << c.reinitialiserCouche(1) << endl;

   cout << endl << "Etape 11 activer couche 4 : " << c.activerCouche(4) << endl;

   cout << endl << "Etape 12 affichage canevas" << endl << endl;

   c.afficher(cout);

   cout << endl << "Etape 13 calcul aire totale : "<< c.aire() << endl;

   cout << endl << "Etape 14 reinitialiser le canvas : " << c.reinitialiser() << endl;

   cout << endl << "Etape 15 affichage canevas" << endl << endl;

   c.afficher(cout);

   cout << endl << "Etape 16 calcul aire totale : "<< c.aire() << endl;
   
   cout << endl << "Etape 17 activer couche 3 : " << c.activerCouche(3) << endl;

   Carre *carrePtr17 = new Carre(10,10,10);

   cout << "Ajout carre (c = 10, x = 10, y = 10) : " << c.ajouterForme(carrePtr17) << endl;
   cout << "Ajout forme null: " << c.ajouterForme(nullptr) << endl;

   cout << endl << "Etape 18 activer couche 6 : " << c.activerCouche(6) << endl;

   cout << endl << "Etape 19 affichage canevas" << endl << endl;

   c.afficher(cout);

   cout << endl << "Etape 20 calcul aire totale : "<< c.aire() << endl;

   cout << endl;


   
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;
   // Il faut ajouter les operations realisant ce scenario de test.
}
