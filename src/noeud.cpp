#include "noeud.hpp"
#include <iostream>

Noeud::Noeud()
{
  int i ;
  for (i=0 ; i<MAX_NEXT ; i ++)
    next[i] = NULL ;
  predecessor = NULL ;
  distance_origine = 0 ;
  is_black = false ;
}
