#ifndef NOEUD_HPP
#define NOEUD_HPP

#define MAX_NEXT 8 // grille carré

#define INFINIE -1

// podition des noeud suivent :
#define HAUT 0
#define DROIT 1
#define BAS 2
#define GAUCHE 3
#define HAUT_DROIT 4
#define HAUT_GAUCHE 5
#define BAS_GAUCHE 6
#define BAS_DROIT 7

struct Noeud
{
  Noeud* next[MAX_NEXT] ;
  Noeud* predecessor ;
  bool is_black ;
  float distance_origine ;
  
  Noeud() ;
  int isoler() ;
};

/*!
 * return true if distance n1 > n2 
 */
bool diff_dist_orig(Noeud* n1, Noeud* n2) ;

#endif // NOEUD_HPP

