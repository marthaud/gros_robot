#include "dijkstra.hpp"

/*!
 * \return true if a > b , false else
 * \brief prend en compte l'infinit : INFINIT
 */
bool comparateur(float a, float b)
{
  if (a == INFINIT)
    return true ;
  if (b == INFINIT)
    return false ;
  return a > b ;
}

/*!
 * \return 0 good, 1 non path : A FAIRE
 */
int dijkstra(Grille* graph, Noeud* depart, Noeud* arriver)
{
  di_init_graph(graph) ;
  depart->distance_origine = 0.0 ;
  Noeud* cochon_inde ;
  while (arriver->is_black == false)
    {
      cochon_inde = di_choisir_noeud(graph) ;
      di_relachement(graph, cochon_inde) ;
    }
  return 0 ;
}

/*!
 * \brief met les prédecesseur a nul, distance a l'infinit et blanchie
 */
int di_init_graph(Grille* graph)
{
  int i ;
  for (i=0 ; i<NBR_NOEUD_ORDONEE*NBR_NOEUD_ABCISSE ; i++)
    {
      graph->grille[i].predecessor = NULL ;
      graph->grille[i].distance_origine = INFINIT ;
      graph->grille[i].is_black = false ;
    }
  return 0 ;
}

/*!
 * \brief complexité O(nbr de noeud)
 * \return noeud pas noir avec la plus petit distance
 */
#include <stdio.h>
Noeud* di_choisir_noeud(Grille* graph)
{
  Noeud sentinel ;
  sentinel.distance_origine = INFINIT ;
  Noeud* res = &sentinel ;
  int i ;
  for (i=0 ; i<NBR_NOEUD_ORDONEE*NBR_NOEUD_ABCISSE ; i++)
    { 
      if ((graph->grille[i].is_black == false)
	  && comparateur(res->distance_origine,
			   graph->grille[i].distance_origine))
	{
	  res = &(graph->grille[i]) ;
	}
    }
  return res ;
}

/*!
 * \brief traite sur les noeud suivent le noeud selectionée et le noircie
 */
int di_relachement(Grille* graph, Noeud* depart)
{
  int i ;
  float longueur_arete ;
  for (i=0 ; i<MAX_NEXT ; i++)
    {
      if (i>3)
	longueur_arete = 1.4 ;
      else
	longueur_arete = 1.0 ;
      if ((depart->next[i] != NULL) &&
	  comparateur(depart->next[i]->distance_origine,
		      depart->distance_origine+longueur_arete))
	{
	  depart->next[i]->predecessor = depart ;
	  depart->next[i]->distance_origine = depart->distance_origine + longueur_arete ;
	}
    }
  depart->is_black = true ;
  return 0 ;
}
