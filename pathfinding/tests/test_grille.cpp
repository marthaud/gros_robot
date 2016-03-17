#include "../Grille.hpp"
#include <assert.h>
#include <iostream>

void test_constructeur()
{
   Grille my_grille ;

   int i ;
   int j ;
   std::cout << "Coordonée des Noeud ... " ;
   for (j=0 ; j<NBR_NOEUD_ORDONEE ; j++)
     {
       for (i=0 ; i<NBR_NOEUD_ABCISSE ; i++)
	 {
	   assert(my_grille.get_noeud(i,j)->get_abscisse() == i) ;
	   assert(my_grille.get_noeud(i,j)->get_ordonnee() == j) ;
	 }
     }
   std::cout << "OK" << std::endl ;
   std::cout << "Bordur Null ... " ;
   for (i=0 ; i<NBR_NOEUD_ABCISSE ; i++)
     {
       assert(my_grille.get_noeud(i,0)->get_next(BAS) == NULL) ;
       assert(my_grille.get_noeud(i,NBR_NOEUD_ORDONEE-1)->get_next(HAUT) == NULL) ;
     }
   for (i=0 ; i<NBR_NOEUD_ORDONEE ; i++)
     {
       assert(my_grille.get_noeud(0,i)->get_next(GAUCHE) == NULL) ;
       assert(my_grille.get_noeud(NBR_NOEUD_ABCISSE-1,i)->get_next(DROIT) == NULL) ;
     }
   std::cout << "OK\n" ;
   std::cout << "Suiven corespondent ... " ;
   for (j=1 ; j<NBR_NOEUD_ORDONEE-1 ; j++)
     {
       for (i=1 ; i<NBR_NOEUD_ABCISSE-1 ; i++)
	 {
	   assert(my_grille.get_noeud(i,j)->get_next(HAUT)
		  == my_grille.get_noeud(i,j+1)) ;
	   assert(my_grille.get_noeud(i,j)->get_next(BAS)
		  == my_grille.get_noeud(i,j-1)) ;
	   assert(my_grille.get_noeud(i,j)->get_next(GAUCHE)
		  == my_grille.get_noeud(i-1,j)) ;
	   assert(my_grille.get_noeud(i,j)->get_next(DROIT)
		  == my_grille.get_noeud(i+1,j)) ;
	 }
     }
   std::cout << "OK\n" ;
}

int main()
{
  test_constructeur() ;
  return 0 ;
}
