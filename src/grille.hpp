#ifndef GRILLE_HPP
#define GRILLE_HPP

#include "noeud.hpp"

#define NBR_NOEUD_ABCISSE 40
#define NBR_NOEUD_ORDONEE 30

// podition des noeud suivent :
#define HAUT 0
#define DROIT 1
#define BAS 2
#define GAUCHE 3

struct Grille
{
  Noeud grille[NBR_NOEUD_ORDONEE*NBR_NOEUD_ABCISSE] ;

  Grille() ;
  Noeud* get_noeud(int abscisse, int ordonnee) ;
  void print_distance_origine() ;
};

#endif // GRILLE_HPP
