#include <stdio.h>
#include <stdlib.h>
#include "liste_s.h"

/****************************************************/
/**************** INSERIMENTO IN TESTA **************/
/****************************************************/

//inserimento in testa alla lista senza ritornare il nuovo elemento come puntatore item*
void insert_lista_s_riferimento(item** node, int n){
    item* nuovo_item = (item*)malloc(sizeof(item));
    nuovo_item->info = n;
    nuovo_item->next = (*node);
    (*node) = nuovo_item;
}

//inserimento in testa alla lista che ritorna il puntatore al nuovo elemento della lista
item* insert_lista_s_valore(item* node, int n){
    item* nuovo_item = (item*)malloc(sizeof(item));
    nuovo_item->info = n;
    nuovo_item->next = node;
    
    //la mia funzione prende in ingresso l'indirizzo contenuto dentro head, ovvero quello del primo elemento della lista (che può anche essere null!)
    //devo perciò ritornare l'indirizzo del nuovo elemento della lista da dover inserire dentro "head" del main, quindi ci sarà un head = insert_lista_s(head,x);
    //questo perché se nella funzione facessi node = nuovo_item non starei modificando l'indirizzo contenuto dentro head nel main!!!!!
    return nuovo_item;
}

//inserimento in testa alla lista per riferimento utilizzando il typedef lista_s per un puntatore item*
void insert_lista_s(lista_s* l, int n){
    item* nuovo_item = (item*)malloc(sizeof(item));
    nuovo_item->info = n;
    nuovo_item->next = (*l);
    //avendo passato alla funzione l'indirizzo di head (e non quello contenuto dentro head) attraverso l'indirezione (*l) posso gestire il contenuto di head (l è un puntatore ad un puntatore item*)
    (*l) = nuovo_item;
}

/****************************************************/
/*********************** SOMMA **********************/
/****************************************************/

int somma_uno_lista_s(lista_s l) {
    int somma = 0;
    while( l != NULL) {
        somma += l->info;
        l = l->next;
    }
    return somma;
}

//creo un puntatore item* secondario per non andare a far scorrere l, in teoria non serve perché head l'ho passato per "valore" (ho passato l'indirizzo contenuto in head)
int somma_due_lista_s(lista_s l) {
    int somma = 0;
    item* x = l;
    while( x != NULL) {
        somma += x->info;
        x = x->next;
    }
    return somma;
}

/****************************************************/
/********************** MASSIMO *********************/
/****************************************************/

int massimo_lista_s(lista_s l) {

    if ( l == NULL ) {
        printf("funzione massimo_lista_s lanciata su lista vuota!\n");
        exit(1);
    }

    int max = l->info;
    l = l->next;
    while( l != NULL ) {
        if( l->info > max ) {
            max = l->info;
        }
        l = l->next;
    }
    return max;
}   

/****************************************************/
/***************** GESTISCI LISTA *******************/
/****************************************************/

//utilizzo una funzione ricorsiva per poter deallocare ogni item
void dealloca_lista_s(lista_s* l) {
    if( (*l) == NULL ) return;
    dealloca_lista_s(&((*l)->next));
    free(*l);
    (*l) = NULL;
}

//crea una lista inversa a quella in ingresso a parametro
lista_s inversa_lista_s(lista_s l) {
    lista_s inversa = NULL;
    while ( l != NULL ) {
        insert_lista_s(&inversa, l->info);
        l = l->next;
    }
    return inversa;
}

//stampa classica
void stampa_lista_s(lista_s l) {
    while( l != NULL ) {
        if( l->next != NULL)
           printf(" [%d] -> ", l->info);
        else
           printf(" [%d] ", l->info);          
        l = l->next;
    }
    printf("\n");
}

//stampa degli indirizzi di memoria dei nodi
void stampa_lista_locazioni_s(lista_s l) {
    while( l != NULL ) {
        if( l->next != NULL)
           printf("[%p]->", l);
        else
           printf("[%p]", l);          
        l = l->next;
    }
    printf("\n");
}

/****************************************************/
/******************* CANCELLAZIONI ******************/
/****************************************************/

//cancellazione di un item in particolare (viene passato l'indirizzo del item sempre tramite puntatore)
void cancella_lista_s(lista_s* l, item* i) {
     if ( (*l) == NULL || i == NULL) {
        printf("Errore: la lista e' vuota oppure il item di riferimento è NULL!\n");
        exit(1);
     }
     //cancellazione in testa
     if ( i == (*l) ) {
        //(*l)->next vorrebbe dire (*(*l)).next, ovvero con *l accedo al contenuto di head (l'indirizzo del primo elemento della lista) e con la seconda indirezione ai campi della struttura del primo item!!!!
        (*l) = (*l)->next;
     }
     //se non è in testa lo vado a cercare ma uso un item di supporto per non spostare il puntato da head
     item* corrente = (*l);
     //devo controllare il next di corrente perché devo fermarmi ad un item prima, altrimenti non riesco a fare il salto di item!!!
     while( corrente->next != i ){  //qui non contemplo la possibilità che il nodo non ci sia!!!!
        corrente = corrente->next;
     }
     corrente->next = i->next;
     free(i);
}

//cancellazione di un item con un campo info specifico (cancella tutte le copie dell'elemento v all'interno della lista)
void cancella_lista_s_elem(lista_s* l, int n) {
     if ( (*l) == NULL ) {
        printf("Errore: la lista e' vuota!!\n");
        exit(1);
     }
     if ( (*l)->info == n ) {
        item* dealloca = (*l);
        (*l) = (*l)->next;
        free(dealloca);
     }
     item* corrente = (*l);
     while( corrente->next != NULL ) {
        if (corrente->next->info == n) {
            item* dealloca = corrente->next;
            corrente->next = corrente->next->next;
            free(dealloca);
        }
        else
            corrente = corrente->next; 
     }
}    

/****************************************************/
/******************* RICERCA ELEM *******************/
/****************************************************/

//funzione che cerca un elemento e ne ritorna l'indirizzo dell' item che lo contiene
//in questo caso non serve fare un controllo sulla lista nulla perché se l è NULL a prescindere non viene mai eseguito il while e viene ritornato NULL direttamente!
item* search_lista_s(lista_s l, int n) {
    item* x = l;
    while( x != NULL) {
        if ( x->info == n) return x;
        x = x->next;
    }
    return NULL;
}

/****************************************************/
/******************** CONTEGGIO *********************/
/****************************************************/

//conta quanti elementi ci sono in comune tra due liste
int comuni_liste_s(lista_s l1, lista_s l2) {
    if( l1 == NULL || l2 == NULL) {
        printf("Una delle due liste o entrambe sono NULL!\n");
        exit(1);
    }
    int contatore = 0;
    item* x = l1;
    while( x != NULL) {
        item* y = l2;
        while( y != NULL) {
            if( x->info == y->info ) {
                contatore++;
                break;
            }
            y = y->next;
        }
        x = x->next;
    }
    return contatore;
}

int conta_nodi_lista_s(lista_s l) {
    if ( l == NULL ) return 0;
    //se sono qui ho almeno un elemento
    int contatore = 0; 
    while ( l != NULL ) {
        contatore++; 
        l = l->next;
    }
    return contatore;
}








/****************************************************/
/*************** ESERCITAZIONE LISTE S***************/
/****************************************************/

//calcola il minimo nella lista
int calcola_minimo_lista_s(lista_s l) {
    if( l == NULL ) {
        printf("Errore: la lista e' vuota!\n");
        return -1;
    }
    int min = l->info;
    l = l->next;
    while( l != NULL ) {
        if( l->info < min )
            min = l->info;
        l = l->next;
    }
    return min;
}

//verifica che max = 2 * min
int verifica_max_min_lista_s(lista_s l) {
    int max = massimo_lista_s(l);
    int min = calcola_minimo_lista_s(l);

    return max == 2*min;
}

//inserimento di un nodo alla fine della lista
void insert_end_lista_s(lista_s* l, int val) {
    item* nuovo_nodo = (item*)malloc(sizeof(item));
    nuovo_nodo->info = val;
    nuovo_nodo->next = NULL;

    if( l == NULL ) (*l) = nuovo_nodo;
    item* corrente = (*l);
    while( corrente->next != NULL ) {
        corrente = corrente->next;
    }
    corrente->next = nuovo_nodo;
}

