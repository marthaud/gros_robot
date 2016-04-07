#include "../src/grille.hpp"
#include <iostream>
#include <assert.h>

void test_constructeur()
{
  Grille my_grille ;
  int j ;
  int i ;
  std::cout << "Test good next ... " ;
   for (j=1 ; j<NBR_NOEUD_ORDONEE-1 ; j++)
     {
       for (i=1 ; i<NBR_NOEUD_ABCISSE-1 ; i++)
	 {
	   assert(my_grille.get_noeud(i,j)->next[HAUT]
		  == my_grille.get_noeud(i,j+1)) ;
	   assert(my_grille.get_noeud(i,j)->next[BAS]
		  == my_grille.get_noeud(i,j-1)) ;
	   assert(my_grille.get_noeud(i,j)->next[GAUCHE]
		  == my_grille.get_noeud(i-1,j)) ;
	   assert(my_grille.get_noeud(i,j)->next[DROIT]
		  == my_grille.get_noeud(i+1,j)) ;
	 }
     }
   std::cout << "OK\n" ;
   std::cout << "Bordur Null ... " ;
   for (i=0 ; i<NBR_NOEUD_ABCISSE ; i++)
     {
       assert(my_grille.get_noeud(i,0)->next[BAS] == NULL) ;
       assert(my_grille.get_noeud(i,NBR_NOEUD_ORDONEE-1)->next[HAUT] == NULL) ;
     }
   for (i=0 ; i<NBR_NOEUD_ORDONEE ; i++)
     {
       assert(my_grille.get_noeud(0,i)->next[GAUCHE] == NULL) ;
       assert(my_grille.get_noeud(NBR_NOEUD_ABCISSE-1,i)->next[DROIT] == NULL) ;
     }
   std::cout << "OK\n" ;
}

void test_print_distance_origine()
{
  Grille my_grille ;
  my_grille.print_distance_origine() ;
}

int main()
{
  test_constructeur() ;
  test_print_distance_origine() ;  
  return 0 ;
}
