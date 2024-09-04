#include <stdio.h>
#include <stdlib.h>
#include "grafi_oggetti.h" 

//funzione per la creazione di un nuovo grafo
grafo_o* new_graph_o() {
    grafo_o* g = (grafo_o*)malloc(sizeof(grafo_o));
    g->numero_nodi = 0;
    g->numero_archi = 0;
    g->nodi = NULL; //è una lista di tipo elem_nodo, ovvero di elementi che punteranno ai nodi
    g->archi = NULL; //è una lista di tipo elem_arco, ovvero di elementi che punteranno agli archi

    return g;
}

//funzione che aggiunge un nodo alla lista "nodi" del grafo (sarà il campo info di un elem_nodo)
nodo* add_nodo_grafo_o(grafo_o* g) {
    nodo* nuovo_nodo = (nodo*)malloc(sizeof(nodo));
    nuovo_nodo->color = 0;
    nuovo_nodo->archi = NULL; //non ho nessun arco per ora

    //aggiungo il nuovo nodo alla lista dei nodi del grafo (lista nodi di tipo elem_nodo)
    elem_nodo* ln = (elem_nodo*)malloc(sizeof(elem_nodo));
    ln->prev = NULL; //il nodo andrà in testa alla lista ln
    ln->next = g->nodi; //g->nodi punta al primo elemento (che può essere null o qualcosa)
    if( g->nodi != NULL ) { //se c'era già un nodo nel grafo
        g->nodi->prev = ln;  //punto ln con il suo pref
    }
    ln->info = nuovo_nodo; //il blocchetto punta al nodo
    nuovo_nodo->pos = ln; //il nodo punta al blocchetto della lista elem_nodo
    g->nodi = ln; //aggiorno il primo elemento della lista "nodi" del grafo
    g->numero_nodi++; //

    return nuovo_nodo;
}    

//funzione che non dichiaro fuori, la posso usare solo in questo file
//mette l'arco "a" in testa alla lista puntata da pla e ritorna il blocchettino della lista
elem_arco* add_arco_a_lista(elem_arco** pla, arco* a) {
    elem_arco* nuovo_arco = (elem_arco*)malloc(sizeof(elem_arco));
    nuovo_arco->prev = NULL; //l'arco andrà in testa alla lista;
    nuovo_arco->next = (*pla); //il primo blocchetto puntato dalla lista
    if( (*pla) != NULL ) { //c'era già un elemento in lista
        (*pla)->prev = nuovo_arco;
    }
    (*pla) = nuovo_arco;
    nuovo_arco->info = a; //inserisco l'indirizzo dell'arco a da puntare

    return nuovo_arco;
}


//funzione che aggiunge un arco alle 3 liste di destinazione ("archi" del grafo e liste "archi" dei nodi from e to)
arco* add_arco_grafo_o(grafo_o* g, nodo* from, nodo* to) {
    arco* new_arco = (arco*)malloc(sizeof(arco));
    new_arco->from = from;
    new_arco->to = to;
    //aggiungo l'arco alla lista "archi" del grafo
    new_arco->pos = add_arco_a_lista(&(g->archi), new_arco);
    //aggiungo l'arco alla lista "archi" del nodo from
    new_arco->frompos = add_arco_a_lista(&(from->archi), new_arco);
    //aggiungo l'arco alla lista "archi" del nodo from
    new_arco->topos = add_arco_a_lista(&(to->archi), new_arco);
    g->numero_archi++;

    return new_arco;
}


//funzione per la stampa del grafo
void print_graph_o(grafo_o* g) {
    printf("Numero nodi = %d\n", g->numero_nodi);
    printf("Lista nodi\n");
    elem_nodo* ln = g->nodi;
    while( ln != NULL ) {
        printf(" %p ", ln->info);
        ln = ln->next;
    }
    printf("\n");

    printf("Numero archi = %d\n", g->numero_nodi);
    printf("Lista archi\n");
    elem_arco* la = g->archi;
    while( la != NULL ) {
        //voglio stamparmi l'indirizzo dell'arco e gli indirizzi dei nodi (i,j) a cui è riferito
        printf(" %p da %p a %p\n", la->info, la->info->from, la->info->to);
        la = la->next;
    }
    printf("\n");
}