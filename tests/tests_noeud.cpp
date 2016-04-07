#include "../src/noeud.hpp"
#include <assert.h>
#include <stdlib.h>

void test_constructeur()
{
  Noeud my_Noeud ;
  assert(my_Noeud.is_black == false) ;
  assert(my_Noeud.predecessor == NULL) ;
  int i ;
  for (i=0 ; i<MAX_NEXT ; i ++)
    assert(my_Noeud.next[i] == NULL) ;
}

int main()
{
  test_constructeur() ;
  return 0 ;
}
