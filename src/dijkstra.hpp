#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "grille.hpp"
#include "noeud.hpp"
#include "stdlib.h"

#define INFINIT -1.0

bool comparateur(int a, int b) ;

int dijkstra(Grille* graph, Noeud* depart, Noeud* arriver) ;

int di_init_graph(Grille* graph) ;

Noeud* di_choisir_noeud(Grille* graph) ;

int di_action(Grille* graph, Noeud* depart) ;

#endif // DIJKSTRA_HPP
