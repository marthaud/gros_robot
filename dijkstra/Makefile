CFLAGS = -Wall -Werror -g -O0

Noeud.o : grille/Noeud.cpp
	g++ $(CFLAGS) -c -o $@ $<

Grille.o : grille/Grille.cpp
	g++ $(CFLAGS) -c -o $@ $<

test_grille.o : ./tests/test_grille.cpp
	g++ $(CFLAGS) -c -o $@ $<
test_grille : test_grille.o Grille.o Noeud.o
	g++ -o $@ $^
