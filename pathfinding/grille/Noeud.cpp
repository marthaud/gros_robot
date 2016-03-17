#include "Noeud.hpp"
#include <iostream>

Noeud::Noeud()
{
  noeud_abscisse = 0 ;
  noeud_ordonnee = 0 ;
  int i ;
  for (i=0 ; i<MAX_NEXT ; i ++)
    noeud_next[i] = NULL ;
}

int Noeud::get_abscisse()
{
  return noeud_abscisse ;
}

int Noeud::get_ordonnee()
{
  return noeud_ordonnee ;
}

int Noeud::set_coordonnee(int abscisse, int ordonnee)
{
  noeud_abscisse = abscisse ;
  noeud_ordonnee = ordonnee ;
  return 0 ;
}

int Noeud::set_next(Noeud* suivent, int position)
{
  noeud_next[position] = suivent ;
  return 0 ;
}

Noeud* Noeud::get_next(int suivent)
{
  return noeud_next[suivent] ; 
}
