#
# Auteur: C.-A. Brunet
# Date: 04 janvier 2024
# Modifie par : ...
# Date : ...
# Description: compilation de graphicus-02. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-02: graphicus-02.o vecteur.o tests.o  couche.o canevas.o forme.o rectangle.o cercle.o carre.o 
	g++ -o graphicus-02 vecteur.o tests.o canevas.o couche.o forme.o rectangle.o cercle.o carre.o  graphicus-02.o

graphicus-02.o: graphicus-02.cpp tests.h
	g++ -c graphicus-02.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h 
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h forme.h vecteur.h 
	g++ -c couche.cpp

forme.o: forme.cpp forme.h
	g++ -c forme.cpp

rectangle.o: rectangle.cpp rectangle.h forme.h
	g++ -c rectangle.cpp

carre.o: carre.cpp carre.h rectangle.h forme.h
	g++ -c carre.cpp

cercle.o: cercle.cpp cercle.h forme.h
	g++ -c cercle.cpp

vecteur.o: vecteur.cpp vecteur.h
	g++ -c vecteur.cpp

tests.o: tests.cpp vecteur.h tests.h canevas.h couche.h forme.h 
	g++ -c tests.cpp	

clean:
	rm  -f *.o
