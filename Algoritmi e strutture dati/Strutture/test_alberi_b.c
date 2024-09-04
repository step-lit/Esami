#include <stdio.h>
#include <stdlib.h>
#include "Alberi_b/alberi_b.h"

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main () {
    //creo un albero vuoto di profondità 2
    albero_b root2 = NULL;
    //nel secondo campo devo mettere l'indirizzo del puntatore al campo dove voglio inserire il nodo
    aggiungi_figlio_b(NULL, &root2, 1);  //(parent , punta_n, numero)
    //voglio inserire un figlio sinistro alla radice
    aggiungi_figlio_b(root2, &(root2->left), 2);
    aggiungi_figlio_b(root2, &(root2->right), 3);

    aggiungi_figlio_b(root2->left, &(root2->left->left), 4);
    aggiungi_figlio_b(root2->right, &(root2->right->left), 5);

    /*           1
                / \
               2   3             
              /   /
             4   5     

    */

    printf("La radice ha due figli? %d\n", two_children_b(root2));
    printf("Il figlio sinistro della radice ha due figli? %d\n", two_children_b(root2->left));

    printf("Ho trovato 100 in preordine? %d\n", cerca_albero_b_preordine(root2,100) != NULL);
    printf("Ho trovato 5 in preordine? %d\n", cerca_albero_b_preordine(root2,5) != NULL);

    printf("Ho trovato 100 in postordine? %d\n", cerca_albero_b_postordine(root2,100) != NULL);
    printf("Ho trovato 5 in postordine? %d\n", cerca_albero_b_postordine(root2,5) != NULL);

    printf("Ho trovato 100 simmetrica? %d\n", cerca_albero_b_simmetrica(root2,100) != NULL);
    printf("Ho trovato 5 simmetrica? %d\n", cerca_albero_b_simmetrica(root2,5) != NULL);

    printf("Nell'albero ci sono %d nodi\n",  conta_nodi_albero_b(root2));

    printf("L'albero dalla radice e' un cammino? %d\n", cammino_albero_b(root2));
    printf("L'albero radicato su root2->left e' un cammino? %d\n", cammino_albero_b(root2->left));

    printf("L'albero ha un'altezza pari a %d\n", altezza_albero_b(root2));
    printf("L'albero ha un'altezza pari a %d\n", altezza_albero_b2(root2));
    printf("L'albero ha un'altezza in preordine pari a %d\n", altezza_albero_b2_preordine(root2));   
    
    //creo un albero vuoto di profondità 3
    nodo* root3 = NULL;
    int counter = 0;

    // Costruzione albero di profondità 3
    aggiungi_figlio_b(NULL, &root3, counter++);

    aggiungi_figlio_b(root3, &(root3->left), counter++);
    aggiungi_figlio_b(root3, &(root3->right), counter++);

    aggiungi_figlio_b(root3->left, &(root3->left->left), counter++);
    aggiungi_figlio_b(root3->left, &(root3->left->right), counter++);
    aggiungi_figlio_b(root3->right, &(root3->right->left), counter++);
    aggiungi_figlio_b(root3->right, &(root3->right->right), counter++);

    aggiungi_figlio_b(root3->left->left, &(root3->left->left->left), counter++);
    aggiungi_figlio_b(root3->left->left, &(root3->left->left->right), counter++);
    aggiungi_figlio_b(root3->left->right, &(root3->left->right->left), counter++);
    aggiungi_figlio_b(root3->left->right, &(root3->left->right->right), counter++);
    aggiungi_figlio_b(root3->right->left, &(root3->right->left->left), counter++);
    aggiungi_figlio_b(root3->right->left, &(root3->right->left->right), counter++);
    aggiungi_figlio_b(root3->right->right, &(root3->right->right->left), counter++);
    aggiungi_figlio_b(root3->right->right, &(root3->right->right->right), counter++);

    printf("L'albero ha un'altezza pari a %d\n", altezza_albero_b(root3));
    printf("L'albero ha un'altezza pari a %d\n", altezza_albero_b2(root3));
    printf("L'albero ha un'altezza in preordine pari a %d\n", altezza_albero_b2_preordine(root3));   

    printf("Nell'albero ci sono %d nodi\n",  conta_nodi_albero_b(root3));


    //creo un albero sbilanciato di prova
    nodo* root_prova = NULL;
    counter = 0;

    // Costruzione albero di profondità 3
    aggiungi_figlio_b(NULL, &root_prova, counter++);

    aggiungi_figlio_b(root_prova, &(root_prova->left), counter++);
    aggiungi_figlio_b(root_prova, &(root_prova->right), counter++);

    aggiungi_figlio_b(root_prova->left, &(root_prova->left->right), counter++);
    aggiungi_figlio_b(root_prova->right, &(root_prova->right->left), counter++);
    aggiungi_figlio_b(root_prova->right, &(root_prova->right->right), counter++);

    
    aggiungi_figlio_b(root_prova->left->right, &(root_prova->left->right->left), counter++);
    aggiungi_figlio_b(root_prova->right->right, &(root_prova->right->right->right), counter++);

    aggiungi_figlio_b(root_prova->right->right->right, &(root_prova->right->right->right->left), counter++);

    printf("L'albero ha un'altezza pari a %d\n", altezza_albero_b(root_prova));
    printf("L'albero ha un'altezza pari a %d\n", altezza_albero_b2(root_prova));
    printf("L'albero ha un'altezza in preordine pari a %d\n", altezza_albero_b2_preordine(root_prova));   

    printf("Nell'albero ci sono %d nodi\n",  conta_nodi_albero_b(root_prova));

    printf("L'albero dalla radice e' un cammino? %d\n", cammino_albero_b(root_prova));
    printf("L'albero radicato su root_prova->left e' un cammino? %d\n", cammino_albero_b(root_prova->left));
    printf("L'albero radicato su root_prova->right e' un cammino? %d\n", cammino_albero_b(root_prova->right));
    printf("L'albero radicato su root_prova->right->right e' un cammino? %d\n", cammino_albero_b(root_prova->right->right));

    printf("L'albero ha un'altezza b_max pari a %d\n", altezza_albero_b2_max(root_prova));

    printf("La somma dei valori all'interno dell'albero root2 e' : %d\n", somma_albero_b(root2));   
    printf("Nell'albero ci sono %d nodi\n",  conta_nodi_albero_b(root2));   
    printf("La media dei valori all'interno dell'albero root2 e' : %f\n", media_albero_b(root2)); //ricordare %f per i float mi raccomando!!!

    int altezza = altezza_albero_b2(root2);
    printf("L'albero root2 e' un albero completo? %d\n", completo_albero_b_altezza(root2, altezza));

    altezza = altezza_albero_b2(root3);
    printf("L'albero root3 e' un albero completo? %d\n", completo_albero_b_altezza(root3, altezza));

    altezza = altezza_albero_b2(root_prova);
    printf("L'albero root_prova e' un albero completo? %d\n", completo_albero_b_altezza(root_prova, altezza));

    parentetica_simmetrica(root2);
    printf("\n");
    parentetica_preordine(root2);
    printf("\n");

    albero_b root4 = NULL;
    //nel secondo campo devo mettere l'indirizzo del puntatore al campo dove voglio inserire il nodo
    aggiungi_figlio_b(NULL, &root4, 1);  //(parent , punta_n, numero)
    //voglio inserire un figlio sinistro alla radice
    aggiungi_figlio_b(root4, &(root4->left), 2);
    aggiungi_figlio_b(root4, &(root4->right), 5);

    aggiungi_figlio_b(root4->left, &(root4->left->left), 1);
    aggiungi_figlio_b(root4->left, &(root4->left->right), 3);
    aggiungi_figlio_b(root4->right, &(root4->right->left), 1);
    aggiungi_figlio_b(root4->right, &(root4->right->right), 4);

    aggiungi_figlio_b(root4->left->left, &((root4->left->left)->left), 3);
    aggiungi_figlio_b(root4->left->left, &((root4->left->left)->right), 2);
    aggiungi_figlio_b(root4->left->right, &((root4->left->right)->left), 2);
    aggiungi_figlio_b(root4->left->right, &((root4->left->right)->right), 4);
    aggiungi_figlio_b(root4->right->left, &((root4->right->left)->left), 7);
    aggiungi_figlio_b(root4->right->left, &((root4->right->left)->right), 5);
    aggiungi_figlio_b(root4->right->right, &((root4->right->right)->left), 6);
    aggiungi_figlio_b(root4->right->right, &((root4->right->right)->right), 5);

    parentetica_preordine(root4);
    printf("\n");
    printf("L'albero root4 ha %d nodi che soddisfano la condizione nipote->info == nonno->info!\n", valore_nonno_albero_b(root4));
    printf("L'albero root4 ha %d nodi che soddisfano la condizione nipote->info == nonno->info!\n", valore_nonno_albero_b2(root4));
    printf("L'albero root4 ha %d nodi che hanno quattro nipoti!\n", quattro_nipoti_albero_b2(root4));
    printf("L'albero root2 ha %d nodi che hanno quattro nipoti!\n", quattro_nipoti_albero_b2(root2));
    printf("L'albero root3 ha %d nodi che hanno quattro nipoti!\n", quattro_nipoti_albero_b2(root3));

    //posso usare le liste perché le ho incluse nel file h
    item* lista_cammino_b = lista_cammino_albero_b(root2, root2->right->left);
    stampa_lista_s(lista_cammino_b);

    lista_cammino_b = lista_cammino_albero_b(root4, (root4->right->left)->right);
    stampa_lista_s(lista_cammino_b);

    printf("La parentela b2 tra i due nodi 5 e 3 e' %d\n", parentela_albero_b2(root4, (root4->left->left)->left, root4->right));
    printf("La parentela b tra i due nodi 5 e 3 e' %d\n", parentela_albero_b(root4, (root4->left->left)->left, root4->right));


    //creo un albero vuoto di profondità 2
    albero_b root5 = NULL;
    //nel secondo campo devo mettere l'indirizzo del puntatore al campo dove voglio inserire il nodo
    aggiungi_figlio_b(NULL, &root5, 1);  //(parent , punta_n, numero)
    //voglio inserire un figlio sinistro alla radice
    aggiungi_figlio_b(root5, &(root5->left), 2);
    aggiungi_figlio_b(root5, &(root5->right), 3);

    aggiungi_figlio_b(root5->left, &(root5->left->left), 4);
    aggiungi_figlio_b(root5->left, &(root5->left->right), 5);

    altezza = altezza_albero_b2(root5);
    printf("L'albero root5 e' un albero completo? %d\n", completo_albero_b_altezza(root5, altezza));

}