#ifndef _STRUTTURE_H
#define _STRUTTURE_H

#include "../../Strutture/Alberi_b/alberi_b.h"

typedef struct nodo_struct nodo;
typedef struct arco_struct arco;

typedef struct elem_lista_nodi {
struct elem_lista_nodi* prev;
struct elem_lista_nodi* next;
nodo* info;
} elem_nodi; // elemento di una lista di nodi

typedef struct elem_lista_archi {
struct elem_lista_archi* prev;
struct elem_lista_archi* next;
arco* info;
} elem_archi; // elemento di una lista di archi

typedef struct nodo_struct {
elem_nodi* pos; /* posizione nodo nella
lista del grafo */
elem_archi* archi; // lista archi incidenti
int color;
int value;
} nodo;

typedef struct arco_struct {
elem_archi* pos; // pos. arco lista grafo
nodo* from;
nodo* to;
elem_archi* frompos; // pos. arco nodo from
elem_archi* topos; // pos. arco nodo to
} arco;

typedef struct {
int numero_nodi;
int numero_archi;
elem_archi* archi; // lista degli archi
elem_nodi* nodi; // lista dei nodi
} grafo;
/* struttura per l’albero di grado arbitrario */

typedef struct nodo_albero_struct {
struct nodo_albero_struct* parent;
struct nodo_albero_struct* left_child;
struct nodo_albero_struct* right_sibling;
int info;
} nodo_albero;

//funzioni di supporto per la creazione di un grafo di test
grafo* new_graph();
nodo* aggiungi_nodo_grafo(grafo* g, int value);
arco* aggiungi_arco_grafo(nodo* from, nodo* to, grafo* g);
void print_graph(grafo* g);

//funzioni di supporto per la creazione di un albero di test
nodo_albero* aggiungi_figlio_albero(nodo_albero** pn, int val);
int conta_nodi_albero(nodo_albero* n);
int conta_nodi_albero_iterativo(nodo_albero* n);
void stampa_outline(nodo_albero* n);


/* STRUTTURE E FUNZIONI AGGIUNTIVE DA SCRIVERE ALL'ESAME */
int visita_DFS_nodo_grafo(elem_nodi* elem, int color);
void reset_color_graph(grafo* g);
int* conta_componenti_connesse_DFS_grafo(grafo* g);
void stampa_array_colore(int* A, int length);

int* crea_array_figli_nodi_albero(nodo_albero* a);
void stampa_array_figli_nodi(int* A, int length);
int* conta_tutti_nodi_albero(nodo_albero* n, int indice, int* A);
int conta_figli_nodo_albero(nodo_albero* n);

int verifica(grafo* g, nodo_albero* a);

/*ALTRO ESAME ASD-2023-02-16-270-9cfu-B */
int conta_foglie_albero(nodo_albero* n);

/*ALTRO ESAME ASD-2023-01-25-270-9cfu */
nodo_a* abr_da_grafo(grafo* g);


#endif