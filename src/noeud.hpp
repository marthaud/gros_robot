#ifndef NOEUD_HPP
#define NOEUD_HPP

#define MAX_NEXT 4 // grille carré

#define INFINIE -1

struct Noeud
{
  Noeud* next[MAX_NEXT] ;
  Noeud* predecessor ;
  bool is_black ;
  int distance_origine ;
  
  Noeud() ; 
};

/*!
 * return true if distance n1 > n2 
 */
bool diff_dist_orig(Noeud* n1, Noeud* n2) ;

#endif // NOEUD_HPP

