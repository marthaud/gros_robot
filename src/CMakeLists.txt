set (CMAKE_CXX_FLAGS "-Wall -Werror")

add_library (grille noeud.cpp grille.cpp)
add_library (dijkstra dijkstra.cpp)