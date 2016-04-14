#ifndef GRILLE_HPP
#define GRILLE_HPP

#include "noeud.hpp"

#define NBR_NOEUD_ABCISSE 40
#define NBR_NOEUD_ORDONEE 30


struct Grille
{
  Noeud grille[NBR_NOEUD_ORDONEE*NBR_NOEUD_ABCISSE] ;

  Grille() ;
  Noeud* get_noeud(int abscisse, int ordonnee) ;
  void print_distance_origine() ;
  int isoler_bloc(int abscisse, int ordonnee, int long_abscisse , int long_ordonnee) ;
};

#endif // GRILLE_HPP
