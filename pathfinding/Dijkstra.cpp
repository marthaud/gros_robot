#include "Dijkstra.hpp"
#include <vector>

int trans_b2_b1(struct position)
{
  return position.abscisse+position.ordonnee*NBR_NOEUD_ABCISSE ;
  // voir Grille.hpp pour les corespondance
}

struct position* dijkstra(Grille* table, struct position* stok_res,
			  struct position depar, struct position arriver)
{
  struct dij_noeud_info dij_grille_info[table->get_taille()] ;
  for (i=0 ; i<table->get_taille() ; i++)
    dij_grille_info[i].est_noir = false ;
  vector<struct dij_noeud_info*> gris() ;
  struct dij_noeud_info sentinel ;
  dij_grille_info.push_back(&sentinel) ;

  dij_grille_info[trans_b2_b1(depar)].longeur_chemin = 0 ;
  dij_grille_info[trans_b2_b1(depar)].predecesseur = depar ;

  position act = depar ;

  while ((act.abscisse != arriver.abscisse) && (act.ordonnee != arriver.ordonnee))
    {
      
    }
}
