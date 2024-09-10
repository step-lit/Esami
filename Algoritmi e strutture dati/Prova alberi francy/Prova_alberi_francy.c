#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Prova_alberi_francy.h"

/* Crea una funzione che dato in ingresso un puntatore ad una struttura di tipo albero binario NULL, 
ed un numero generico di nodi (ad esempio 5) costruisca un albero binario con cotanti nodi di valore casuale. */

// srand(time(NULL));   


/* ---------------------------------------------------------------------------------------- */
/* STEP 1 */

void insert_nodo_albero_b(albero_b* a, int val) {
    nodo_a* nuovo_nodo = (nodo_a*)malloc(sizeof(nodo_a));
    nuovo_nodo->info = val;
    nuovo_nodo->parent = NULL;
    nuovo_nodo->left = NULL;
    nuovo_nodo->right = NULL;

    if( (*a) == NULL ) {
        (*a) = nuovo_nodo;
    }
    if( (*a)->left == NULL && val < (*a)->info ) {
        (*a)->left = nuovo_nodo;
        nuovo_nodo->parent = (*a);
    }
    if( (*a)->right == NULL && val > (*a)->info ) {
        (*a)->right = nuovo_nodo;
        nuovo_nodo->parent = (*a);
    }
    if( (*a)->left != NULL && val < (*a)->info ) { 
        insert_nodo_albero_b( &((*a)->left), val);
    }
    if( (*a)->right != NULL && val > (*a)->info ) {
        insert_nodo_albero_b( &((*a)->right), val);
    }
    return;
}

 
void crea_albero_binario_random(albero_b* albero, int numero_nodi, int max_value) {
    int random;
    //a all'inizio è nullo
    srand(time(NULL));
    
    printf("[ ");
    insert_nodo_albero_b(albero, (int)(max_value/2));
    for( int i=1; i < numero_nodi; i++ ) {
        random = rand()%(max_value+1);
        printf(" %d ", random);
        insert_nodo_albero_b(albero, random);
    }
    printf(" ]\n");
}


/* ---------------------------------------------------------------------------------------- */
/* STEP 2 */
//devo costruire un albero arbitrario con ingresso albero binario e numero di nodi
//la struttura albero binario si chiama albero_b o nodo_a
//la struttura albero arbitrario si chiama nodo_albero

int conta_nodi_sx_radice_albero_b(albero_b a) {
    if( a == NULL ) return 0;
    int cont = 0;
    nodo_a* x = a->left;
    while( x != NULL ) {
        cont++;
        x = x->left;
    }
    return cont;
}

int array_crescente(int* A, int length) {

}


void crea_albero_arbitrario_da_binario(nodo_albero** a_arb, albero_b* a_bin, int numero_nodi) {
    //inserimento radice
    if( (*a_bin) == NULL ) return; //controllo se la radice almeno esiste

    //inserimento nell'array dei puntatori della radice di a_bin e dei suoi figli sinistri 
    //creo l'array A_fsx
    int nodi_sx_rad = conta_nodi_sx_radice_albero_b( (*a_bin) ); //numero dei nodi tutti a sinistra a partire dalla radice
    nodo_a** A_fsx = (nodo_a**)calloc(nodi_sx_rad+1, sizeof(nodo_a*));

    nodo_a* left_node_temp = (*a_bin)->left;
    int i = 0; //iteratore per l'array
    while( left_node_temp != NULL ) {
        A_fsx[i] = left_node_temp;
        i++;
    }
    A_fsx[i+1] = (*a_bin); //ho messo anche la radice


    //adesso A_fsx ha tutti i valori di sinistra
    //inserisco nell'array il figlio destro della radice e di nuovo i suoi figli sinistri 
    if( (*a_bin)-> right != NULL ) { //se esiste procedo
        int nodi_sx_dx_rad = conta_nodi_sx_radice_albero_b( (*a_bin)-> right );
        int new_size = nodi_sx_rad + nodi_sx_dx_rad + 1; //conto anche il destro della radice che sarà incluso
        A_fsx = (nodo_a**)realloc(A_fsx, (new_size)*(sizeof(nodo_a*)) );

        

    }
    


    //inserimento del figlio destro della radice e dei relativi figli sinistri da a_bin






}
