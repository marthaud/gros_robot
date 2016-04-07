#include "dijkstra.hpp"

/*!
 * \return true if a > b , false else
 * \brief prend en compte l'infinit : INFINIT
 */
bool comparateur(int a, int b)
{
  if (a == INFINIT)
    return true ;
  if (b == INFINIT)
    return false ;
  return a > b ;
}
#include <iostream>
int dijkstra(Grille* graph, Noeud* depart, Noeud* arriver)
{
  di_init_graph(graph) ;
  depart->distance_origine = 0 ;
  Noeud* cochon_inde ;
  while (arriver->distance_origine == INFINIT)
    {
      //graph->print_distance_origine() ;
      //std::cout << "\n\n" ;
      cochon_inde = di_choisir_noeud(graph) ;
      di_action(graph, cochon_inde) ;
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
Noeud* di_choisir_noeud(Grille* graph)
{
  Noeud* res = &(graph->grille[0]);
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
int di_action(Grille* graph, Noeud* depart)
{
  int i ;
  for (i=0 ; i<MAX_NEXT ; i++)
    {
      if ((depart->next[i] != NULL) &&
	  comparateur(depart->next[i]->distance_origine,
		      depart->distance_origine))
	{
	  depart->next[i]->predecessor = depart ;
	  depart->next[i]->distance_origine = depart->distance_origine + 1 ;
	}
    }
  depart->is_black = true ;
  return 0 ;
}
