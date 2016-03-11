#include "../Grille.hpp"


int rentre_dans_gille(int i)
{
  return i>0 && i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ;
}

// les case sont rengée ligne par ligne
Grille::Grille()
{
  int i ;
  for (i=0 ; i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ; i++)
    {
      grille_tab[i].set_coordonnee(i%NBR_NOEUD_ABCISSE, i/NBR_NOEUD_ABCISSE) ;
      if (rentre_dans_gille(i+NBR_NOEUD_ABCISSE))
	grille_tab[i].set_next(grille_tab[i+NBR_NOEUD_ABCISSE], HAUT) ;
      if (rentre_dans_gille(i+1))
	grille_tab[i].set_next(grille_tab[i+1], DROIT) ;
      if (rentre_dans_gille(i-NBR_NOEUD_ABCISSE))
	grille_tab[i].set_next(grille_tab[i-NBR_NOEUD_ABCISSE], BAS) ;
      if (rentre_dans_gille(i-1))
	grille_tab[i].set_next(grille_tab[i-1], GAUCHE)
    }
}

Noeud* GRILLE::get_noeud(int abscisse, int ordonnee)
{
  return &grille_tab[abscisse*NBR_NOEUD_ABCISSE+ordonnee] ;
}
