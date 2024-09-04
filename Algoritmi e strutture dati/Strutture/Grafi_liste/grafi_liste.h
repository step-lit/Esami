#ifndef _GRAFI_LISTE_H
#define _GRAFI_LISTE_H

typedef struct grafo_l grafo_l; //è necessario quando vado ad includere i file h in entrambi, altrimenti non riconosce subito le strutture

#include "../Liste_d/liste_d.h"
#include "../Grafi_matrice/grafi_matrice.h"

typedef struct grafo_l {

    int numero_nodi;
    nodo** a;

} grafo_l;

grafo_l* new_graph_l(int numero_nodi); //devo passargli a differenza delle tabelle hash la grandezza dell'array, nella struct tabella ho già m ed n

void new_edge_graph_l(grafo_l* g, int i, int tj);  //gli int from e to indicano da dove parte e dove finisce l'arco

void del_edge_graph_l(grafo_l* g, int i, int j);

void print_graph_l(grafo_l* g);

//funzione che trasforma un grafo liste in un grafo matrice di adiacenza
grafo_m* grafo_l_into_m(grafo_l* g);


#endif