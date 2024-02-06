TEMPLATE     = vcapp
TARGET       = graphicus_03
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h  canevas.h carre.h cercle.h coordonnee.h couche.h forme.h rectangle.h tests.h vecteur.h
SOURCES     += graphicus-02.cpp monInterface.cpp canevas.cpp carre.cpp cercle.cpp couche.cpp forme.cpp rectangle.cpp tests.cpp vecteur.cpp
INCLUDEPATH += ../GraphicusGUI
LIBS        += C:\Users\merci\OneDrive\Documents\_uni\S2\APP3\Graphicus-03\Graphicus-02\GraphicusGUI\graphicusGUI.lib
QT          += widgets 
