#ifndef _ALBERI_B
#define _ALBERI_B

#include "../Liste_s/liste_s.h"

typedef struct n {
    struct n* parent;
    struct n* left;
    struct n* right;
    int info;
} nodo;

typedef nodo* albero_b; //posso usare albero_b al posto di nodo*

//uso albero_b perché passo la radice dell'albero
int is_albero_b_empty(albero_b a);

//uso nodo* per ricordarmi che potrebbe essere un nodo qualsiasi dell'albero
int two_children_b(nodo* n);

//punta_n è un puntatore ad un altro puntatore al nodo
nodo* aggiungi_figlio_b(nodo* parent, nodo** punta_n, int n);

nodo* cerca_albero_b_preordine(albero_b a, int n);
nodo* cerca_albero_b_postordine(albero_b a, int n);
nodo* cerca_albero_b_simmetrica(albero_b a, int n);

int conta_nodi_albero_b(albero_b a);

int cammino_albero_b(albero_b a);

int altezza_albero_b(albero_b a);
int altezza_albero_b2(albero_b a);
int altezza_albero_b2_max(albero_b a);
int altezza_albero_b2_preordine(albero_b a);

int somma_albero_b(albero_b a);

float media_albero_b(albero_b a);

int completo_albero_b_altezza(albero_b a, int h);

int potenza_albero_b(int altezza);

void dealloca_albero_b(albero_b* a);

void pota_albero_b(albero_b* a, nodo* n);
void pota_albero_b_prof_ricorri(albero_b* a, int prof, int h);
void pota_albero_b_prof(albero_b* a, int h);

void parentetica_simmetrica(albero_b a);
void parentetica_preordine(albero_b a);

int due_figli_albero_b(albero_b a);
int conta_foglie_albero_b(albero_b a);

int valore_nonno_albero_b(albero_b a);
int valore_nonno_albero_b2(albero_b a);

int quattro_nipoti_albero_b2(albero_b a);

item* lista_cammino_albero_b(albero_b a, nodo* n);

int parentela_albero_b(albero_b a, nodo* n1, nodo* n2);
int parentela_albero_b2(albero_b a, nodo* n1, nodo* n2);

#endif

//file per le dichiarazioni di metodi e strutture/variabili