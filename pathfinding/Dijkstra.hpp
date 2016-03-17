#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Grille.hpp"

struct position
{
  int abcisse ;
  int ordonnee ;
};

struct dij_noeud_info
{
  struct position predecesseur ;
  int longeur_chemin ;
  bool est_noir ;
};

struct position* dijkstra(Grille table, struct position* stok_res,
			  struct position depar) ;

#endif // DIJKSTRA_HPP
