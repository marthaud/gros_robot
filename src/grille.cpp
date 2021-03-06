#include "grille.hpp"

int rentre_dans_gille(int i)
{
  return i>=0 && i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ;
}

int dans_meme_ligne(int i, int j)
{
  return i/NBR_NOEUD_ABCISSE == j/NBR_NOEUD_ABCISSE ;
}

Grille::Grille()
{
  int i ;
  for (i=0 ; i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ; i++)
    {
      //grille_tab[i].set_coordonnee(i%NBR_NOEUD_ABCISSE, i/NBR_NOEUD_ABCISSE) ;
      if (rentre_dans_gille(i+NBR_NOEUD_ABCISSE))
	grille[i].next[HAUT] = &grille[i+NBR_NOEUD_ABCISSE] ;
      if (dans_meme_ligne(i, i+1) && rentre_dans_gille(i+1))
	grille[i].next[DROIT] = &grille[i+1] ;
      if (rentre_dans_gille(i-NBR_NOEUD_ABCISSE))
	grille[i].next[BAS] = &grille[i-NBR_NOEUD_ABCISSE] ;
      if (dans_meme_ligne(i, i-1) && rentre_dans_gille(i-1))
	grille[i].next[GAUCHE] = &grille[i-1] ;
    }
  if (MAX_NEXT == 8)
    {
      for (i=0 ; i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ; i++)
	{
	  if (dans_meme_ligne(i+NBR_NOEUD_ABCISSE, i+NBR_NOEUD_ABCISSE-1) && rentre_dans_gille(i+NBR_NOEUD_ABCISSE-1))
	    grille[i].next[HAUT_GAUCHE] = &grille[i+NBR_NOEUD_ABCISSE-1] ;
	  if (dans_meme_ligne(i+NBR_NOEUD_ABCISSE, i+NBR_NOEUD_ABCISSE+1) && rentre_dans_gille(i+NBR_NOEUD_ABCISSE+1))
	    grille[i].next[HAUT_DROIT] = &grille[i+NBR_NOEUD_ABCISSE+1] ;
	  if (dans_meme_ligne(i-NBR_NOEUD_ABCISSE, i-NBR_NOEUD_ABCISSE-1) && rentre_dans_gille(i-NBR_NOEUD_ABCISSE-1))
	    grille[i].next[BAS_GAUCHE] = &grille[i-NBR_NOEUD_ABCISSE-1] ;
	  if (dans_meme_ligne(i-NBR_NOEUD_ABCISSE, i-NBR_NOEUD_ABCISSE+1) && rentre_dans_gille(i-NBR_NOEUD_ABCISSE+1))
	    grille[i].next[BAS_DROIT] = &grille[i-NBR_NOEUD_ABCISSE+1] ;
	}
    }
}

Noeud* Grille::get_noeud(int abscisse, int ordonnee)
{
  return &grille[ordonnee*NBR_NOEUD_ABCISSE+abscisse] ;
}

#include <stdio.h>
void Grille::print_distance_origine()
{
  int i ;
  int j ;
  for(j=NBR_NOEUD_ORDONEE-1 ; j>=0 ; j--)
    {
      for(i=0 ; i<NBR_NOEUD_ABCISSE ; i++)
	printf("%2.f|", get_noeud(i, j)->distance_origine) ;
      printf("\n") ;
    }
}

int Grille::isoler_bloc(int abscisse, int ordonnee, int long_abscisse , int long_ordonnee)
{
  int i ;
  int j ;
  for (i=0 ; i<long_abscisse ; i++)
    {
      for (j=0 ; j<long_ordonnee ; j++)
	get_noeud(i+abscisse, j+ordonnee)->isoler() ;
    }
  return 0 ;
}
