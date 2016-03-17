#ifndef GRILL_H
#define GRILL_H

#include "./grille/Noeud.hpp"

// ATTENTION, ces une grille carré qui est codée (need MAX_NEXT = 4)

#define NBR_NOEUD_ABCISSE 40
#define NBR_NOEUD_ORDONEE 30

// podition des noeud suivent :
#define HAUT 0
#define DROIT 1
#define BAS 2
#define GAUCHE 3

class Grille
{
private :
  Noeud grille_tab[NBR_NOEUD_ORDONEE*NBR_NOEUD_ABCISSE] ;
  int taille ;

public :
  Grille() ;
  Noeud* get_noeud(int abscisse, int ordonnee) ;
  int get_taille() ;
};

#endif // GRILL_H
