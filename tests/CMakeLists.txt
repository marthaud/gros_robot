set (CMAKE_CXX_FLAGS "-Wall -Werror")

add_executable (tests_noeud tests_noeud.cpp)
target_link_libraries (tests_noeud grille)

add_executable (tests_grille tests_grille.cpp)
target_link_libraries (tests_grille grille)

add_executable (tests_dijkstra tests_dijkstra.cpp)
target_link_libraries (tests_dijkstra dijkstra grille)
