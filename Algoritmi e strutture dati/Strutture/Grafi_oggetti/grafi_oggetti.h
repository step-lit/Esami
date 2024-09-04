#ifndef _GRAFI_OGGETTI_H
#define _GRAFI_OGGETTI_H

//sono necessarie perché altrimenti nodo ed arco non sono ancora conosciute per le prime strutture
typedef struct struct_nodo nodo;  // forward declaration
typedef struct struct_arco arco;  // forward declaration

//questa è una struttura, elemento di una lista che punta ad un arco
typedef struct struct_elem_arco {  
    struct struct_elem_arco* prev;
    struct struct_elem_arco* next;
    //puntatore all'arco corrispondente
    arco* info;
} elem_arco;


//questa è una struttura, elemento di una lista che punta ad un nodo
typedef struct struct_elem_nodo {
    struct struct_elem_nodo* prev;
    struct struct_elem_nodo* next;
    //puntatore al nodo corrispondente
    nodo* info;
} elem_nodo;

//struttura corrispondente ad un nodo
typedef struct struct_nodo {
    int color;
    //ogni nodo ha una lista di archi incidenti a quel nodo
    elem_arco* archi;  
    //pos è puntatore che indica la posizione del nodo nella lista "nodi" del grafo (punta all'indietro rispetto all'info di elem_nodo)
    elem_nodo* pos;     
} nodo;

//struttura corrispondente ad un arco (i,j)
typedef struct struct_arco {
    //puntatore al nodo i
    nodo* from;   
    //puntatore al nodo j
    nodo* to;
    //pos è un puntatore che indica la posizione dell'arco nella lista "archi" del grafo (punta all'indietro rispetto all'info di elem_arco)
    elem_arco* pos;
    //puntatore che indica la posizione dell'arco nella lista "archi" del nodo from
    elem_arco* frompos;
    //puntatore che indica la posizione dell'arco nella lista "archi" del nodo to
    elem_arco* topos;   
} arco;

//struttura corrispondente ad un grafo
typedef struct struct_grafo {
    int numero_nodi;
    int numero_archi;
    //nodi è una lista doppiamente concatenata, ogni elemento ha prev, next e un puntatore info ad un nodo
    elem_nodo* nodi; 
    //archi è una lista doppiamente concatenata, ogni elemento ha prev, next e un puntatore info ad un arco
    elem_arco* archi;
} grafo_o;

//funzione che costruisce un grafo, non ha bisogno di dimensione iniziale
grafo_o* new_graph_o();

nodo* add_nodo_grafo_o(grafo_o* g);

arco* add_arco_grafo_o(grafo_o* g, nodo* from, nodo* to);

void print_graph_o(grafo_o* g);


#endif 