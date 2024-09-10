#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "strutture.h"

/****************************************************/
/****************** FUNZIONI GRAFO ******************/
/****************************************************/

//funzione di creazione grafo
grafo* new_graph() {

   grafo* g = (grafo*)malloc(sizeof(grafo));
   g->numero_nodi = 0;
   g->numero_archi = 0;
   g->nodi = NULL;
   g->archi = NULL;

   return g;
}

//funzione per aggiungere un nodo alla lista dei nodi del grafo
nodo* aggiungi_nodo_grafo(grafo* g, int value){

    nodo* new = (nodo*)malloc(sizeof(nodo));
    new->color = 0;
    new->archi = NULL;
    new->value = value;

    // lo aggiungo alla lista dei nodi del grafo
    //
    elem_nodi* ln = (elem_nodi*)malloc(sizeof(elem_nodi));
    ln->prev = NULL;  // lo inserirò all'inizio della lista dei nodi
    ln->next = g->nodi;
    if( g->nodi != NULL ) {     // se c'era già un nodo nel grafo...
          g->nodi->prev = ln;   // ...il suo prev sono io
    }
    ln->info = new;  // il blocchetto punta al nodo...
    new->pos = ln;   //...e il nodo punta al blocchetto
    g->nodi = ln;
    g->numero_nodi++;
    
    return new;
}


/* mette l'arco "a" in testa alla lista puntata da "pla"
   e ritorna il blocchettino della lista */

elem_archi* aggiungi_arco_a_lista(elem_archi** pla, arco* a) {

    elem_archi* new = (elem_archi*)malloc(sizeof(elem_archi));
    new->prev = NULL; // lo metto all'inizio della lista
    new->next = (*pla);  // il primo blocchetto che era già in lista
    if ((*pla)!=NULL) {  // c'era già un elemento in lista
        (*pla)->prev = new;
    }
    (*pla) = new;
    new->info = a;
    return new;
}

//funzione che aggiunge un nuovo arco nelle liste del grafo e dei nodi from e to relativi all'arco
arco* aggiungi_arco_grafo(nodo* from, nodo* to, grafo* g) {

     arco* new = (arco*)malloc(sizeof(arco));
     new->from = from;
     new->to = to;
     new->pos = aggiungi_arco_a_lista(&(g->archi), new);
     new->frompos = aggiungi_arco_a_lista(&(from->archi), new);
     new->topos = aggiungi_arco_a_lista(&(to->archi), new);

     g->numero_archi++;
     return new;
}

//funzione di stampa del grafo
void print_graph(grafo* g) {

    printf("Nodi totali: %d\n", g->numero_nodi);
    printf("Lista dei nodi: \n");

    elem_nodi* ln = g->nodi;
    while( ln != NULL ) {
    	printf("[Nodo: %-5d - Address: %p] \n", ln->info->value, ln->info);
    	ln = ln->next;
    }

    printf("\nArchi totali: %d\n", g->numero_archi);
    printf("Lista degli archi: \n");

    elem_archi* la = g->archi;
    while( la != NULL ) {
    	printf("[Indirizzo arco: %p]  =====  [Nodo from %-5d : %p] --->  [Nodo to %-5d : %p]\n",la->info, la->info->from->value, la->info->from, la->info->to->value, la->info->to);
    	la = la->next;
    }
}

/****************************************************/
/***************** FUNZIONI ALBERO ******************/
/****************************************************/

//funzione di aggiunta figli (o radice)
nodo_albero* aggiungi_figlio_albero(nodo_albero** pn, int val) {

    nodo_albero* new = (nodo_albero*)malloc(sizeof(nodo_albero));
    new->info = val;
    new->left_child = NULL;
    new->parent = (*pn);
    if( (*pn) == NULL ) {
        new->right_sibling = NULL;
        (*pn) = new;
    } else {
        new->right_sibling = (*pn)->left_child;
        (*pn)->left_child = new;
    }
    return new;
}

//funzione che conta quanti nodi ci sono in un albero
int conta_nodi_albero(nodo_albero* n) {

    if( n == NULL ) return 0;

    int cont = 1;  // conto il nodo corrente
    nodo_albero* f = n->left_child;
    while( f != NULL ) {
        cont += conta_nodi_albero(f);
        f = f->right_sibling;
    }
    return cont;
}

//funzione di stampa ricorsiva
void stampa_outline_ricorri(nodo_albero* n, int prof) {
    if( n == NULL ) return;
    int i;
    for(i = 0; i < prof; i++){
        printf("  ");
    }
    printf("%d\n",n->info);
    nodo_albero* x = n->left_child;
    while( x != NULL ) {
       stampa_outline_ricorri(x,prof+1);
       x = x->right_sibling;
    }
}

//funzione di supporto alla stampa per impostare la profondità iniziale a 0
void stampa_outline(nodo_albero* n) {
    stampa_outline_ricorri(n, 0);
}





/****************************************************/
/***************** FUNZIONI ESAME *******************/
/****************************************************/

/*          GRAFO          */

//funzione di visita DFS che scende nella lista archi del nodo puntato da elem e conta quanti sono i nodi collegati ad esso
int visita_DFS_nodo_grafo(elem_nodi* elem, int color) {
    if( elem->info->color != 0) return -1;

    elem->info->color = color; //visito il primo nodo cambiando il colore
    int result = 1;

    elem_archi* lista_archi_nodo = elem->info->archi; //ora lista_archi_nodo ha l'indirizzo del primo arco del nodo
    while( lista_archi_nodo != NULL ) {
        //cerco di capire se il mio nodo è il from o il to dell'arco
        
        if( elem->info == lista_archi_nodo->info->from ) { //se sono il from allora processo il nodo to
            if( lista_archi_nodo->info->to->color == 0 ) //se il colore di to è zero faccio la dfs su di lui
                result += visita_DFS_nodo_grafo(lista_archi_nodo->info->to->pos, color); //passo alla funzione l'indirizzo dell'elem nodo associato al nodo to tramite pos
        }
        else { //altrimenti sto processando il from
            if( lista_archi_nodo->info->from->color == 0 ) 
                result += visita_DFS_nodo_grafo(lista_archi_nodo->info->from->pos, color);
        }
        //una volta che ho processato il from o il to dell'arco passo al prossimo arco
        lista_archi_nodo = lista_archi_nodo->next;
    }
    return result;
}

//resetta il colore dei nodi del grafo
void reset_color_graph(grafo* g) {
    if( g == NULL ) return;
    elem_nodi* x = g->nodi;
    while( x != NULL ) {
        x->info->color = 0;
        x = x->next;
    }
}

//funzione che ritorna un array di interi che contiene il numero di nodi connessi con indice colore
int* conta_componenti_connesse_DFS_grafo(grafo* g) {
    if( g == NULL) return NULL;

    //il numero di nodi e di archi totali stanno già nel grafo
    int* A = (int*)calloc(g->numero_nodi, sizeof(int));

    reset_color_graph(g); //resetto i colori dei nodi del grafo
    int color = 1; 
    elem_nodi* nodo_grafo = g->nodi;
    while( nodo_grafo != NULL ) {
        int nodi_colore = visita_DFS_nodo_grafo(nodo_grafo, color);
        if( nodi_colore != -1) { //se ritorna -1 il nodo è da saltare (colore != 0)
            A[color] = nodi_colore; //l'indice dell'array è il colore che parte da zero con zero nodi, in ogni cella c'è il numero di nodi con quel colore
            color++;
        }
        nodo_grafo = nodo_grafo->next;
    }

    return A;
}

/*       STAMPA ARRAY      */

void stampa_array_colore(int* A, int length) {
    printf("Array colore:\n");
    for( int i=0; i < length; i++ ){
        printf("A[%d]: %d\n", i, A[i]);
    }
    printf("\n");
}

void stampa_array_figli_nodi(int* A, int length) {
    printf("\n");
    printf("Array figli nodi:\n");
    for( int i=0; i < length; i++ ){
        printf("A[%d]: %d\n", i, A[i]);
    }
    printf("\n");
}

/*          ALBERO         */

//funzione che conta i figli di un nodo dell'albero passato come parametro
int conta_figli_nodo_albero(nodo_albero* n) {
    if( n == NULL ) return 0;

    int cont = 0;
    nodo_albero* x = n->left_child;
    while( x != NULL ) {
        cont++;
        x = x->right_sibling;
    }
    return cont;
}

//funzione che conta i figli per ogni nodo, utilizza un array ed un indice che viene incrementato per gli inserimenti successivi
int* conta_tutti_nodi_albero(nodo_albero* n, int indice, int* A) {
    if( n == NULL ) return NULL;

    int cont = conta_figli_nodo_albero(n); //conto il primo
    A[indice] = cont;

    nodo_albero* x = n->left_child;
    while( x != NULL ) {
        indice++; //aumento l'indice dell'array poiché sto visitando un nuovo nodo
        A = conta_tutti_nodi_albero(x, indice, A); //A è un array dove l'indice mi indica il nodo ed il valore indica il numero dei suoi figli
        x = x->right_sibling;
    }
    return A;
}

//funzione che riporta in un array i risultati della funzione che conta i figli per ogni nodo
int* crea_array_figli_nodi_albero(nodo_albero* a) {
    if( a == NULL) return NULL;
    int numero_nodi = conta_nodi_albero(a);
    int* A = (int*)calloc(numero_nodi, sizeof(int));

    A = conta_tutti_nodi_albero(a, 0, A);

    return A;
}

//funzione che verifica se esiste nel grafo una componente connessa con tanti nodi quanti sono i figli di uno dei nodi nell'albero
int verifica(grafo* g, nodo_albero* a) {
    int* A_c = conta_componenti_connesse_DFS_grafo(g); //array componenti connesse
    int* A_f = crea_array_figli_nodi_albero(a);        //array figli nodi

    int i, j;

    for( i=0; i < g->numero_nodi; i++ ) {
        for( j=0; j < conta_nodi_albero(a); j++) {
            if( A_c[i] == A_f[j] && A_c[i] != 0 ) { //se trovo due valori uguali e non sono 0 l'ho trovato
                printf("La componente connessa %d ha la stessa cardinalita' del nodo %d dell'albero! \n", i, j);
                return 1;
            }
        }
    }
    return 0;
}


/* UTILIZZATA PER L'ESAME ASD-2023-02-16-270-9cfu-B.pdf */
//il resto per il grafo è identico!
int conta_foglie_albero(nodo_albero* n) {
    if( n == NULL ) return 0;
    int cont = 0;
    if( n->left_child == NULL ) cont++;

    nodo_albero* x = n->left_child;
    while( x != NULL ) {
        cont += conta_foglie_albero(x);
        x = x->right_sibling;
    }
    return cont;
}

//funzione che ritorna un nuovo albero binario di ricerca con tanti nodi pari alle componenti connesse del grafo
//ogni nodo avrà al suo interno il numero di nodi della componente
nodo_a* abr_da_grafo(grafo* g) {
    int* A_c = conta_componenti_connesse_DFS_grafo(g); //array componenti connesse
    
    nodo_a* nuovo_abr = NULL; //inizialmente l'albero è vuoto

    for( int i=0; i < g->numero_nodi; i++ ) {
        if( A_c[i] != 0) {
            inserimento_abr(&nuovo_abr, A_c[i]); //lo prendo dal file alberi binari
        }
    }
    return nuovo_abr;
}








