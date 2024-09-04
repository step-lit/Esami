#include <stdio.h>
#include <stdlib.h>
#include "Grafi_oggetti/grafi_oggetti.h"



int main () {

    grafo_o* grafo_oggetti = new_graph_o();
    print_graph_o(grafo_oggetti);
    nodo* n1 = add_nodo_grafo_o(grafo_oggetti);
    nodo* n2 = add_nodo_grafo_o(grafo_oggetti);
    nodo* n3 = add_nodo_grafo_o(grafo_oggetti);

    print_graph_o(grafo_oggetti);

    arco* a1 = add_arco_grafo_o(grafo_oggetti, n1, n2);
    arco* a2 = add_arco_grafo_o(grafo_oggetti, n1, n3);

    print_graph_o(grafo_oggetti);
}