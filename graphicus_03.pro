TEMPLATE     = vcapp
TARGET       = graphicus_03
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h  canevas.h carre.h cercle.h coordonnee.h couche.h forme.h rectangle.h tests.h vecteur.h
SOURCES     += graphicus-03.cpp monInterface.cpp canevas.cpp carre.cpp cercle.cpp couche.cpp forme.cpp rectangle.cpp tests.cpp vecteur.cpp
INCLUDEPATH += .\GraphicusGUI
LIBS        += .\GraphicusGUI\graphicusGUI.lib
QT          += widgets 
