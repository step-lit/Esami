#ifndef _GRAFI_MATRICE_H
#define _GRAFI_MATRICE_H

typedef struct grafo_m grafo_m; //è necessario quando vado ad includere i file h in entrambi, altrimenti non riconosce subito le strutture

#include "../Grafi_liste/grafi_liste.h"

typedef struct grafo_m {
    //in una matrice di adiacienza (array di array) l’elemento in posizione (i,j) (riga,colonna) segnala se esiste l’arco (i,j)
    int** m; //chiamiamo m l'array di array matrice di adiacienza   
    int numero_nodi; 

} grafo_m;

grafo_m* new_graph_m(int numero_nodi); //devo passargli a differenza delle tabelle hash la grandezza dell'array, nella struct tabella ho già m ed n

void new_edge_graph_m(grafo_m* g, int from, int to);  //gli int from e to indicano da dove parte e dove finisce l'arco

void del_edge_graph_m(grafo_m* g, int from, int to);

void print_graph_m(grafo_m* g);

//funzione che trasforma un grafo matrice in un grafo liste equivalente
grafo_l* grafo_m_into_l(grafo_m* g);

#endif