#include <stdio.h>
#include <stdlib.h>
#include "grafi_liste.h"


//funzione che crea un nuovo grafo con liste di adiacenza
grafo_l* new_graph_l(int numero_nodi) {

    grafo_l* g = (grafo_l*)malloc(sizeof(grafo_l));
    g->numero_nodi = numero_nodi;
    g->a = (nodo**)calloc(g->numero_nodi,sizeof(nodo*)); //non inizializzo i nodi a null perché effettuo una calloc (già lo fa da sola)!
    //non creo in questo caso nodi iniziali da inserire (a differenza degli array nelle matrici di adiacenza)
    //questo perché utilizzo la funzione di insterimento che inserisce già dei nuovi nodi
    return g;
}

//funzione che inserisce un nuovo elemento nel grafo
void new_edge_graph_l(grafo_l* g, int i, int j) {
    //l'arco (i,j) ha il primo nodo i corrispondente ad un elemento del primo array (puntatore alla lista)
    //invece j è il valore dell'altro nodo che va inserito nel nodo della lista
    insert_lista_d(&((g->a[i])), j);  //si può fare anche g->a+i

}

//funzione che stampa un grafo con liste di adiacenza
void print_graph_l(grafo_l* g) {

   int i;
   for(i = 0 ; i < g->numero_nodi; i++) {
   	   printf("[%d]", i);
   	   nodo* x = g->a[i];
       while( x != NULL ) {
            printf("->(%d)", x->info);
            x = x->next;
       }
   	   printf("\n");
    }
}

//funzione che trasforma un grafo liste in un grafo matrice di adiacenza
grafo_m* grafo_l_into_m(grafo_l* g) {

    grafo_m* grafo_matrice = new_graph_m(g->numero_nodi);
    int i;
    for( i=0; i < g->numero_nodi; i++ ) {
        nodo* x = g->a[i];
        while( x != NULL ) {
            new_edge_graph_m(grafo_matrice, i, x->info);
            x = x->next;
        }
    }
    return grafo_matrice;
}