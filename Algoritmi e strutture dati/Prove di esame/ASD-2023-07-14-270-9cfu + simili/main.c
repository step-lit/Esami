#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "strutture.h"

int main() {

    /* CREAZIONE DI UN GRAFO CON OGGETTI E RIFERIMENTI*/
    grafo* graph_test_1 = new_graph();

    // prima componente connessa
    nodo* nodo_1 = aggiungi_nodo_grafo(graph_test_1, 1);
    nodo * nodo_2 = aggiungi_nodo_grafo(graph_test_1, 2);
    nodo * nodo_3 = aggiungi_nodo_grafo(graph_test_1, 3);
    nodo * nodo_4 = aggiungi_nodo_grafo(graph_test_1, 4);
    nodo * nodo_5 = aggiungi_nodo_grafo(graph_test_1, 5);
 

    // seconda componente connessa
    nodo * nodo_6 = aggiungi_nodo_grafo(graph_test_1, 6);  
    nodo * nodo_7 = aggiungi_nodo_grafo(graph_test_1, 7);
    nodo * nodo_8 = aggiungi_nodo_grafo(graph_test_1, 8);
    nodo * nodo_9 = aggiungi_nodo_grafo(graph_test_1, 9);
    nodo * nodo_10 = aggiungi_nodo_grafo(graph_test_1, 10);
    nodo * nodo_11 = aggiungi_nodo_grafo(graph_test_1, 11);

    // nodo isolato
    nodo * nodo_12 = aggiungi_nodo_grafo(graph_test_1, 12);

    // nodo isolato
    nodo * nodo_13 = aggiungi_nodo_grafo(graph_test_1, 13); 

    // prima componente connessa
    arco* arco_1 = aggiungi_arco_grafo(nodo_1, nodo_2, graph_test_1);
    arco* arco_2 = aggiungi_arco_grafo(nodo_2, nodo_3, graph_test_1);
    arco* arco_3 = aggiungi_arco_grafo(nodo_3, nodo_4, graph_test_1);
    arco* arco_4 = aggiungi_arco_grafo(nodo_4, nodo_5, graph_test_1);

    // seconda componente connessa
    arco* arco_5 = aggiungi_arco_grafo(nodo_6, nodo_7, graph_test_1);
    arco* arco_6 = aggiungi_arco_grafo(nodo_7, nodo_8, graph_test_1);
    arco* arco_7 = aggiungi_arco_grafo(nodo_7, nodo_9, graph_test_1);
    arco* arco_8 = aggiungi_arco_grafo(nodo_8, nodo_10, graph_test_1);
    arco* arco_9 = aggiungi_arco_grafo(nodo_9, nodo_10, graph_test_1);
    arco* arco_10 = aggiungi_arco_grafo(nodo_10, nodo_11, graph_test_1);

    graph_test_1->numero_archi = 10;
    graph_test_1->numero_nodi = 13;

    //stampa del grafo
    //print_graph(graph_test_1);


    /*CREAZIONE DI UN ALBERO CON NUMERO DI FIGLI ARBITRARIO*/
    nodo_albero* tree_test_1 = NULL;
    nodo_albero* root = aggiungi_figlio_albero(&tree_test_1, 1);
    // altezza 1
    nodo_albero* node_1_4 = aggiungi_figlio_albero(&root, 4);
    nodo_albero* node_1_3 = aggiungi_figlio_albero(&root, 3);
    nodo_albero* node_1_2 = aggiungi_figlio_albero(&root, 2);
    // altezza 2
    nodo_albero* node_2_6 = aggiungi_figlio_albero(&(root->left_child), 6);
    nodo_albero* node_2_5 = aggiungi_figlio_albero(&(root->left_child), 5);
    nodo_albero* node_2_8 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling), 8);
    nodo_albero* node_2_7 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling), 7);
    // altezza 3
    nodo_albero* node_3_14 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling->left_child), 14);
    nodo_albero* node_3_13 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling->left_child), 13);
    nodo_albero* node_3_12 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling->left_child), 12);
    nodo_albero* node_3_11 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling->left_child), 11);
    nodo_albero* node_3_10 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling->left_child), 10);
    nodo_albero* node_3_9 = aggiungi_figlio_albero(&(root->left_child->right_sibling->right_sibling->left_child), 9);

    //stampa dell'albero
    //stampa_outline(tree_test_1);

    int* array_colore = conta_componenti_connesse_DFS_grafo(graph_test_1);
    stampa_array_colore(array_colore, graph_test_1->numero_nodi);

    int* array_figli_nodi = crea_array_figli_nodi_albero(tree_test_1);
    stampa_array_figli_nodi(array_figli_nodi, conta_nodi_albero(tree_test_1));

    printf("Il numero di nodi dell'albero tree_test1 e': %d\n", conta_nodi_albero(tree_test_1));
    printf("Il numero di nodi dell'albero tree_test1 e': %d\n", conta_nodi_albero_iterativo(tree_test_1));

    printf("La verifica ha risultato positivo? %d\n", verifica(graph_test_1, tree_test_1));
    printf("Il numero di foglie dell'albero e' %d\n", conta_foglie_albero(tree_test_1));

    nodo_a* test_abr_1 = abr_da_grafo(graph_test_1);
    print2D(test_abr_1);


    printf("Esiste un nodo a profondità 2? %d", verifica_nodo_prof(test_abr_1, 2));



    return 0;

}