#include <stdio.h>
#include <stdlib.h>
#include "grafi_matrice.h"

//funzione che crea un nuovo grafo e ne ritorna l'indirizzo
grafo_m* new_graph_m(int numero_nodi) {
    grafo_m* g = (grafo_m*)malloc(sizeof(grafo_m));
    g->numero_nodi = numero_nodi;
    g->m = (int**)calloc(g->numero_nodi,sizeof(int*)); //lo creo con la calloc così ho tutto settato a NULL (in questo caso sono puntatori)
    for(int i=0; i < g->numero_nodi; i++) {
        //accedo agli elementi dell'array m che sono di tipo int* (perché è una matrice)
        g->m[i] = (int*)calloc(g->numero_nodi,sizeof(int));
    }
    return g;
}

//funzione che crea un nuovo arco dati due interi from e to
void new_edge_graph_m(grafo_m* g, int from, int to) {
    if( g->m == NULL ) {
        printf("Errore: Il grafo è vuoto!\n");
        return;
    }
    if( from >= g->numero_nodi || to >= g->numero_nodi ) {
        printf("Errore: Inserimento in un arco non esistente!\n");
        printf("Per favore inserire dei valori minori di %d!\n", g->numero_nodi);
        return;
    }
    g->m[from][to] = 1; //non devo scorrere l'array con i for
}

//funzione che cancella un arco dati due interi from e to
void del_edge_graph_m(grafo_m* g, int from, int to) {
    if( g->m == NULL ) {
        printf("Errore: Il grafo è vuoto!\n");
        return;
    }
    if( from >= g->numero_nodi || to >= g->numero_nodi ) {
        printf("Errore: Cancellazione di un arco non esistente!\n");
        printf("Per favore inserire dei valori minori di %d!\n", g->numero_nodi);
        return;
    }
    g->m[from][to] = 0;
}

//funzione che trasforma un grafo matrice in un grafo liste equivalente
grafo_l* grafo_m_into_l(grafo_m* g) {
    //creo un grafo liste vuoto
    grafo_l* grafo_liste = new_graph_l(g->numero_nodi);
    int i,j;
    for( i = 0; i < g->numero_nodi; i++ ) {
        for( j=0; j < g->numero_nodi; j++) {
            //per ogni 1 che trovo nella matrice inserisco un nodo nel grafo liste
            //non si pone il problema tra grafo diretto e indiretto, li inserisco comunque se ci sono
            if( g->m[i][j] > 0 ) { //in questo caso contemplo la possibilità di matrisce con pesi dell'arco
                //ci sta un arco tra i e j
                new_edge_graph_l(grafo_liste, i, j);

            }
        }
    }
    return grafo_liste;
}

//funzione che stampa un grafo
void print_graph_m(grafo_m* g) {
    int i,j;
    for( i=0; i < g->numero_nodi; i++ ) {
        for( j=0; j < g->numero_nodi; j++) {
            printf("  %d", g->m[i][j]); 
        }
        printf("\n");
    }

}