#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tabelle_hash.h"

//funzione che crea una nuova tabella hash
tabella* new_tabella() {
    tabella* new_tabella = (tabella*)malloc(sizeof(tabella));
    new_tabella->m = 4;
    new_tabella->n = 0;
    //la calloc vuole il secondo valore al suo interno
    new_tabella->T = (item**)calloc(new_tabella->m,sizeof(item*));
    for(int i=0; i < new_tabella->m; i++) {
        new_tabella->T[i] = NULL;  //ho allocato con una calloc quindi sono già tutti zeri ma lo facciamo comunque per sicurezza
    }
    new_tabella->irr = (sqrt(5.0) - 1.0)*0.5;

    return new_tabella;
}

//aggiunge un nuovo elemento nella tabella
void add_tabella(tabella* thash, int key, int val) {

    //vedo se il fattore di carico supera un numero troppo alto per raddoppiare la tabella
    //fattore di carico: alfa = n / m      lo calcolo in float
    if( ((float)(thash->n))/((float)(thash->m)) >= 3.0 ) {
        //inizio a raddoppiare la tabella creandone proprio una nuova
        printf("Raddoppio la tabella!\n");
        printf("\n");
        int old_m = thash->m;
        thash->m = thash->m * 2; //raddoppio la dimensione nella vecchia tabella
        item** new_T = (item**)calloc(thash->m,sizeof(item*));	//creo una nuova tabella con dimensione thash->m * 2 perché l'ho cambiato
        for(int i = 0 ; i < old_m; i++) {
            item* x = thash->T[i];
            while(x != NULL) {
                //mi creo un riferimento al next del nodo perché poi mi serve dopo per riaggiornare il puntatore x
                //x->next viene sostituito con NULL o con il nodo che sta nella nuova lista perciò perderei il nodo successivo
                item* x_next = x->next;
                int new_row = mult_hash(thash, x->key); //calcolo il nuovo indice con l'm aggiornato
                x->next = new_T[new_row]; //x->next viene sostituito con NULL o con il nodo che sta già nella nuova lista con indice new_row
                //faccio un inserimento in testa nella nuova lista della nuova tabella
                new_T[new_row] = x;
                x = x_next;
            }
        }
        free(thash->T); //prima libero la tabella corrente, poi collego la nuova!
        thash->T = new_T;

    }

    int row = mult_hash(thash, key); //calcolo la funzione hash della chiave, il risultato sarà l'indice della mia tabella
    //cerco prima se il nodo con quella chiave già esiste
    item* x = thash->T[row];
    while( x != NULL ) {
        if( x->key == key ) {
            printf("C'e' gia' un elemento con la chiave %d\n", key);
            x->info = val;
            return;
        }
        x = x->next;
    }
    //sono qui se non ho trovato già la chiave

    //inserimento di un nuovo nodo se non esiste la chiave
    thash->n++; //devo ricordarmi di incrementare il valore n!!!
    item* new_nodo = (item*)malloc(sizeof(item));
    new_nodo->key = key;
    new_nodo->info = val;
    new_nodo->next = thash->T[row];
    thash->T[row] = new_nodo;

}

//ricerca di un nodo con chiave key all'interno della tabella
item* search_tabella(tabella* thash, int key) {
        //RICORDA!! per inserimento, ricerca e cancellazione si usa la funzione hash
        //per la stampa puoi usare il for
        int row = mult_hash(thash, key);
        item* x = thash->T[row];
        while( x != NULL ) {
            if( x->key == key ) {
                printf("Ho trovato l'elemento con chiave %d\n", key);
                return x;
            }
            x = x->next;
        }
    return NULL;
}

//funzione di stampa della tabella
void stampa_tabella(tabella* thash) {
    //qui posso fare un ciclo for per stampare
    for( int i=0; i<thash->m; i++) {
        //stampo prima l'indice dell'array
        printf("%d: ", i);
        item* x = thash->T[i];
        while( x != NULL ) {
            printf("[%d,%d] ", x->key, x->info);
            x = x->next;
        }
        printf("\n");
    }
}

//funzione hash con metodo della moltiplicazione
int mult_hash(tabella* thash, int key) {
    double temp = key*(thash->irr);
    temp = temp - floor(temp);
    temp = (thash->m)*temp;
    return (int)temp;
}