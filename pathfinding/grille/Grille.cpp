#include "../Grille.hpp"


int rentre_dans_gille(int i)
{
  return i>0 && i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ;
}

int dans_meme_ligne(int i, int j)
{
  return i/NBR_NOEUD_ABCISSE == j/NBR_NOEUD_ABCISSE ;
}

// les case sont rengée ligne par ligne
Grille::Grille()
{
  int i ;
  for (i=0 ; i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ; i++)
    {
      grille_tab[i].set_coordonnee(i%NBR_NOEUD_ABCISSE, i/NBR_NOEUD_ABCISSE) ;
      if (rentre_dans_gille(i+NBR_NOEUD_ABCISSE))
	grille_tab[i].set_next(&grille_tab[i+NBR_NOEUD_ABCISSE], HAUT) ;
      if (dans_meme_ligne(i, i+1) && rentre_dans_gille(i+1))
	grille_tab[i].set_next(&grille_tab[i+1], DROIT) ;
      if (rentre_dans_gille(i-NBR_NOEUD_ABCISSE))
	grille_tab[i].set_next(&grille_tab[i-NBR_NOEUD_ABCISSE], BAS) ;
      if (dans_meme_ligne(i, i-1) && rentre_dans_gille(i-1))
	grille_tab[i].set_next(&grille_tab[i-1], GAUCHE) ;
    }

  taille = NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ;
}

Noeud* Grille::get_noeud(int abscisse, int ordonnee)
{
  return &grille_tab[ordonnee*NBR_NOEUD_ABCISSE+abscisse] ;
}

int Grille::get_taille()
{
  return taille ;
}
