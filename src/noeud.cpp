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

int Noeud::isoler()
{
  int i ;
  int j ;
  for (i=0 ; i<MAX_NEXT ; i ++)
    {
      if (next[i] != NULL)
	{
	  j = (i+2)%4 ;
	  if (i>3)
	    j += 4 ;
	  next[i]->next[j] = NULL ;
	  next[i] = NULL ;
	}
    }
  return 0 ;
}
