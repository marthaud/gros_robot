#ifndef GRILLE_HPP
#define GRILLE_HPP

#define MAX_NEXT 4 // grille carré

class Noeud
{
private :
  int noeud_abscisse ;
  int noeud_ordonnee ;
  Noeud* noeud_next[MAX_NEXT] ;

public :
  Noeud() ;
  int get_abscisse() ;
  int get_ordonnee() ;
  int set_coordonnee(int abscisse, int ordonnee) ;
  int set_next(Noeud* suivent, int position) ;
  Noeud* get_next(int position) ; // num_suivent =indice dans le tab next
};

#endif // GRILLE_HPP
