#ifndef _ALBERI_B
#define _ALBERI_B

#include "../Liste_s/liste_s.h"

typedef struct n {
    struct n* parent;
    struct n* left;
    struct n* right;
    int info;
} nodo_a;

typedef nodo_a* albero_b; //posso usare albero_b al posto di nodo_a*

//uso albero_b perché passo la radice dell'albero
int is_albero_b_empty(albero_b a);

//uso nodo_a* per ricordarmi che potrebbe essere un nodo_a qualsiasi dell'albero
int two_children_b(nodo_a* n);

//punta_n è un puntatore ad un altro puntatore al nodo_a
nodo_a* aggiungi_figlio_b(nodo_a* parent, nodo_a** punta_n, int n);

//inserimento in un abr 
void inserimento_abr(albero_b* a, int value);

nodo_a* cerca_albero_b_preordine(albero_b a, int n);
nodo_a* cerca_albero_b_postordine(albero_b a, int n);
nodo_a* cerca_albero_b_simmetrica(albero_b a, int n);

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

void pota_albero_b(albero_b* a, nodo_a* n);
void pota_albero_b_prof_ricorri(albero_b* a, int prof, int h);
void pota_albero_b_prof(albero_b* a, int h);

void parentetica_simmetrica(albero_b a);
void parentetica_preordine(albero_b a);

void print2DUtil(albero_b root, int space);
void print2D(albero_b root);

int due_figli_albero_b(albero_b a);
int conta_foglie_albero_b(albero_b a);

int valore_nonno_albero_b(albero_b a);
int valore_nonno_albero_b2(albero_b a);

int quattro_nipoti_albero_b2(albero_b a);

item* lista_cammino_albero_b(albero_b a, nodo_a* n);

int parentela_albero_b(albero_b a, nodo_a* n1, nodo_a* n2);
int parentela_albero_b2(albero_b a, nodo_a* n1, nodo_a* n2);

int verifica_nodo_prof_ricorri(albero_b a, int prof, int h);
int verifica_nodo_prof(albero_b a, int h);


/* ESERCITAZIONI ALBERI */
int conta_nodi_due_figli_stesso_valore(albero_b a);
int verifica_figli_valore_uguale(nodo_a* n);

int verifica_foglia_info_0(albero_b a);

int* array_valori_nodi_albero(albero_b a, int* A, int indice);
int* creazione_array_valori_nodi_albero(albero_b a);
int esistenza_valore_array(int* A, int length, int val);
int verifica_alberi_stessi_valori(albero_b a1, albero_b a2);


#endif

//file per le dichiarazioni di metodi e strutture/variabili