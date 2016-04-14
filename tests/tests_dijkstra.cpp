#include "../src/dijkstra.hpp"
#include <iostream>
#include <assert.h>

void test_di_choisir_noeud()
{
  Grille my_grille ;
  Noeud* my_noeud = my_grille.get_noeud(2, 8) ;
  std::cout << "sans infinit ... " ;
  int i ;
  for (i=0 ; i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ; i++)
    my_grille.grille[i].distance_origine = 10 ;
  my_noeud->distance_origine = 5 ;
  Noeud* res = di_choisir_noeud(&my_grille) ;
  assert(res == my_noeud) ;
  std::cout << "OK\n" ;
  std::cout << "avec infinit ... " ;
  my_grille.get_noeud(4, 9)->distance_origine = INFINIT  ;
  res = di_choisir_noeud(&my_grille) ;
  assert(res == my_noeud) ;
  std::cout << "OK\n" ;
}

void test_di_action()
{
  Grille my_grille ;
  Noeud* my_noeud = my_grille.get_noeud(2, 8) ;
  int i ;
  for (i=0 ; i<NBR_NOEUD_ABCISSE*NBR_NOEUD_ORDONEE ; i++)
    my_grille.grille[i].distance_origine = 10 ;
  my_noeud->distance_origine = 2 ;
  my_noeud->next[GAUCHE]->distance_origine = 1 ;
  my_noeud->next[BAS] = NULL ;
  my_noeud->next[DROIT]->distance_origine = INFINIT ;
  di_action(&my_grille, my_noeud) ;
  std::cout << "plus loin ; infinit ; moins loin ; NULL ... " ;
  assert(my_noeud->next[HAUT]->distance_origine == 3) ;
  assert(my_noeud->next[HAUT]->predecessor == my_noeud) ;
  std::cout << "OK ; " ;
  assert(my_noeud->next[DROIT]->distance_origine == 3) ;
  assert(my_noeud->next[DROIT]->predecessor == my_noeud) ;
  std::cout << "OK ; " ;
  assert(my_noeud->next[GAUCHE]->distance_origine == 1) ;
  assert(my_noeud->next[GAUCHE]->predecessor != my_noeud) ;
  std::cout << "OK ; " ;
  assert(my_noeud->next[BAS] == NULL) ;
  std::cout << "OK" ;
  std::cout << "\n" ;
  
}

void test_dijkstra()
{
  Grille my_grille ;
  my_grille.isoler_bloc(5, 0, 3, 5) ;
  my_grille.isoler_bloc(9, 2, 3, 9) ;
  dijkstra(&my_grille, my_grille.get_noeud(3, 2), my_grille.get_noeud(15, 2)) ;
  
  Noeud* parcour = my_grille.get_noeud(15, 2) ;
  while (parcour != my_grille.get_noeud(3, 2))
    {
      parcour->distance_origine = 0 ;
      parcour = parcour->predecessor ;
    }
  
  my_grille.print_distance_origine() ; 
  //assert(my_grille.get_noeud(5, 2)->predecessor == my_grille.get_noeud(4, 2)) ;
  //assert(my_grille.get_noeud(4, 2)->predecessor == my_grille.get_noeud(3, 2)) ;
  std::cout << std::endl ;
}

int main()
{
  test_di_choisir_noeud() ;
  test_di_action() ;
  test_dijkstra() ;
  return 0 ;
}


/*
  test_di_choisir_noeud: PROBLEME: res reste sur la premier valeur de la grille 
  : &(graph->grille[0])
 */
