#include <stdio.h>
#include <stdlib.h>
#include "Grafi_matrice/grafi_matrice.h"

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main () {

    grafo_m* grafo_matrice = new_graph_m(10);

    new_edge_graph_m(grafo_matrice,0,1);
    new_edge_graph_m(grafo_matrice,0,2);
    new_edge_graph_m(grafo_matrice,3,3);

    print_graph_m(grafo_matrice);

    new_edge_graph_m(grafo_matrice,10,10);
    del_edge_graph_m(grafo_matrice,10,10);
    del_edge_graph_m(grafo_matrice,3,3);
    
    print_graph_m(grafo_matrice);

    grafo_l* grafo_liste = grafo_m_into_l(grafo_matrice);

    print_graph_l(grafo_liste); //stampo il nuovo grafo liste creato da quello matrice

}