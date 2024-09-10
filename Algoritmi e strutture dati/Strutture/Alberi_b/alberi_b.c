#include <stdio.h>
#include <stdlib.h>
#include "alberi_b.h"
#include <math.h>
#define COUNT 10
#define max(a, b) ((a) > (b) ? (a) : (b))  //utilizzo una macro per il calcolo di max tra due interi

/****************************************************/
/********************* VERIFICA *********************/
/****************************************************/

//verifico che è un albero vuoto
//in realtà non servirebbe una funzione, basterebbe fare root == NULL nel main! (funzione superflua)
int is_albero_b_empty(albero_b a) {
    return a == NULL;
}

//verifica che un nodo_a abbia due figli
int two_children_b(nodo_a* n) {
    if( n == NULL ) return 0;
    return n->left != NULL && n->right != NULL;
}

//verifica che un nodo_a sia una foglia
int nodo_a_foglia_b(nodo_a* n) {
    if( n == NULL ) return 0;
    return n->left == NULL && n->right == NULL;
}

//funzione che verifica se l'albero binario è un cammino, ovvero tutti i nodi hanno grado 1 a parte l'ultima foglia
int cammino_albero_b(albero_b a) {
    //l'albero vuoto è un cammino
    if( a == NULL ) return 1;
    //adesso il mio albero è un cammino se la radice non ha entrambi i figli
    if( a->left != NULL && a->right != NULL ) return 0;
    //se sono qui la radice ha solo figlio destro o solo figlio sinistro o non ha proprio figli
    return cammino_albero_b(a->left) && cammino_albero_b(a->right);
}

//funzione che verifica se un albero binario è completo sfruttando altezza e condizione sui nodi
int completo_albero_b_altezza(albero_b a, int h) {
    //un albero binario e' completo se il numero di nodi dell'albero è uguale a 2^(h+1)-1
    return (int)(pow(2.0, (double)(h+1) )) - 1 == conta_nodi_albero_b(a);
    //return potenza_albero_b(h) - 1 == conta_nodi_albero_b(a);
}

//funzione che verifica se esiste un nodo foglia a profondità h (prof parte da 0 per la verifica)
int verifica_nodo_prof_ricorri(albero_b a, int prof, int h) {
    if( a == NULL ) return 0;
    if( nodo_a_foglia_b(a) && prof == h ) return 1;

    int sx = verifica_nodo_prof_ricorri(a->left, prof+1, h);
    if( sx != 0 ) return 1;

    int dx = verifica_nodo_prof_ricorri(a->right, prof+1, h);
    return dx;

    //return ( ( verifica_nodo_prof_ricorri(a->left, prof+1, h) + verifica_nodo_prof_ricorri(a->right, prof+1, h) ) >= 1 ) ? 1 : 0;
}

//funzione di supporto a verifica_nodo_prof_ricorri (imposto prof a 0)
int verifica_nodo_prof(albero_b a, int h) {
    return verifica_nodo_prof_ricorri(a, 0, h);
}

/****************************************************/
/******************* INSERIMENTO ********************/
/****************************************************/

//punta_n è un puntatore ad un puntatore di tipo nodo_a*
//la funzione aggiunge un nuovo figlio (sinistro o destro va deciso nello specificare l'indirizzo da passare a punta_n)
nodo_a* aggiungi_figlio_b(nodo_a* parent, nodo_a** punta_n, int n) {
    nodo_a* nuovo_nodo_a = (nodo_a*)malloc(sizeof(nodo_a));
    nuovo_nodo_a->parent = parent;
    nuovo_nodo_a->left = nuovo_nodo_a->right = NULL;
    nuovo_nodo_a->info = n;

    /* inizialmente root == NULL (l'albero è vuoto) quindi inserisco nuovo_nodo_a come radice dell'albero attraverso (*punta_n)
       ovvero vado a modificare il contenuto di root tramite punta_n!
       punta_n all'inizio avrà l'indirizzo di root che punta al primo nodo_a (NULL)
       per ulteriori aggiunte punta_n avrà al suo interno l'indirizzo della zona di memoria (left o right) di un nodo_a dove andare a fare l'inserimento
       per esempio come primo inserimento posso mettere che punta_n è &root (aggiungo la radice), poi posso mettere che punta_n è &(root->left) per fare l'inserimento a sinistra del nodo_a radice */

    (*punta_n) = nuovo_nodo_a;
}

//inserimento in albero binario di ricerca
void inserimento_abr(albero_b* a, int value) {

    nodo_a* nuovo_nodo_a = (nodo_a*)malloc(sizeof(nodo_a));
    nuovo_nodo_a->info = value;
    nuovo_nodo_a->left = NULL;
    nuovo_nodo_a->right = NULL;
    nuovo_nodo_a->parent = NULL;

    if( (*a) == NULL ) {
        (*a) = nuovo_nodo_a;
    }
    if ( (*a)->left == NULL && value < (*a)->info ) {
        (*a)->left = nuovo_nodo_a;
        nuovo_nodo_a->parent = (*a);
    }
    if ( (*a)->right == NULL && value > (*a)->info ) {
        (*a)->right = nuovo_nodo_a;
        nuovo_nodo_a->parent = (*a);
    }
    if ( (*a)->left != NULL && value < (*a)->info ) {
        inserimento_abr( &((*a)->left), value);
    }
    if ( (*a)->right != NULL && value > (*a)->info ) {
        inserimento_abr( &((*a)->right) , value);
    }
    return;
}



/****************************************************/
/********************* RICERCA **********************/
/****************************************************/

//ricerca di un nodo_a con campo info == n all'interno dell'albero con visita in preordine
nodo_a* cerca_albero_b_preordine(albero_b a, int n) {
    //caso base dell'albero vuoto
    if( a == NULL) return NULL;
    //processo il nodo_a radice perché in preordine si processa il nodo_a in entrata e poi i figli
    if( a->info == n ) return a;
    
    //chiamo ricorsivamente sul figlio sinistro la ricerca, che mi darà l'indirizzo del nodo_a cercato o null (lo metto in sx)
    nodo_a* sx = cerca_albero_b_preordine(a->left, n);
    //se ho trovato il nodo_a a sinistra non mi interessa di cercare a destra, altrimenti se la ricorsione ritorna NULL non posso fermarmi, devo ancora cercare a destra!
    //ritorno sx solo se è diverso da NULL, ovvero ho trovato quello che cerco!
    if( sx != NULL ) return sx;

    //sono qui se a sinistra non ho trovato nulla
    nodo_a* dx = cerca_albero_b_preordine(a->right, n);

    //la ricerca ricorsiva sul nodo_a di destra è l'ultima che eseguo
    //dx dopo la ricorsione può essere l'indirizzo del nodo_a cercato oppure NULL
    //se non ho trovato il nodo_a devo comunque ritornare NULL alla fine della funzione, perciò ritorno direttamente dx 

    /* Modo prolisso per fare la stessa cosa
    
       if( dx != NULL ) return dx;
       return NULL;                          */ 

    return dx;
}

//ricerca di un nodo_a con campo info == n all'interno dell'albero con visita in postordine
nodo_a* cerca_albero_b_postordine(albero_b a, int n) {
    if( a == NULL) return NULL;
    //processo il nodo_a di sinistra prima di processare il nodo_a in cui entro
    nodo_a* sx = cerca_albero_b_postordine(a->left, n);
    if( sx != NULL ) return sx;

    nodo_a* dx = cerca_albero_b_postordine(a->right, n);
    if( dx != NULL ) return dx;
    
    //la verifica la faccio sempre sul nodo_a principale e gestisco sx e dx ricorsivamente
    //questo perché se richiamo ricorsivamente la funzione sul sinistro di root poi per ogni nodo_a lui si sposta a sinistra e non va bene
    if( a->info == n ) return a;
    //visto che il nodo_a centrale è l'ultimo che controllo se non lo trovo neanche qui ritorno NULL
    else return NULL;
}

//ricerca di un nodo_a con campo info == n all'interno dell'albero con visita simmetrica
nodo_a* cerca_albero_b_simmetrica(albero_b a, int n) {
    if( a == NULL) return NULL;
    //simmetrica: prima sx, poi n, poi dx
    //processo il nodo_a a sinistra della radice ricorsivamente
    nodo_a* sx = cerca_albero_b_simmetrica(a->left, n);
    if( sx != NULL ) return sx;

    //processo il nodo_a centrale e se non lo trovo non faccio ancora nulla perché devo controllare a destra!
    if( a->info == n ) return a;

    nodo_a* dx = cerca_albero_b_simmetrica(a->right, n);
    //stesso discorso per la ricerca in preordine! ritorno dx in ogni caso, anche se dx è NULL perché è l'ultimo controllo che faccio
    return dx;
}



/****************************************************/
/******************** CONTEGGIO *********************/
/****************************************************/

//funzione che conta quanti sono i nodi dell'albero in postordine
int conta_nodi_albero_b(albero_b a) {
    //caso base albero vuoto
    if( a == NULL ) return 0;

    int sx = conta_nodi_albero_b(a->left);
    int dx = conta_nodi_albero_b(a->right);

    //gestione in postordine del conteggio
    return 1 + sx + dx;

    // return 1 + conta_nodi_albero_b(a->left) + conta_nodi_albero_b(a->right); in preordine
  
    /*

    int sx = conta_nodi_albero_b(a->left);
    return 1 + sx + conta_nodi_albero_b(a->right);
  
    */
}



/****************************************************/
/********************* CALCOLO **********************/
/****************************************************/

//funzione che calcola l'altezza dell'albero utilizzando l'indice prof
int altezza_albero_b_ricorri(albero_b a, int prof) {
    if( a == NULL ) return -1;
    if( a->left == NULL && a->right == NULL ) return prof; 
    int hsx = altezza_albero_b_ricorri(a->left, prof+1); 
    int hdx = altezza_albero_b_ricorri(a->right, prof+1);
    if( hsx > hdx) return hsx;
    return hdx; // hsx <= hdx

}

//funzione di supporto per poter inizializzare la profondità del nodo_a radice a 0 in altezza_albero_b_ricorri
int altezza_albero_b(albero_b a){
    return altezza_albero_b_ricorri(a, 0); //la lancio sulla radice a profondità 0
}

/*  esempio di albero con sottoalbero sx piu' grande/piccolo di dx
          o radice
         / \
        o   o   
       /    
      o      
*/

//funzione che calcola l'altezza dell'albero senza l'indice prof
int altezza_albero_b2(albero_b a){
    if( a == NULL ) return -1;
    //sto sulla radice
    int hsx = altezza_albero_b2(a->left);
    int dsx = altezza_albero_b2(a->right);
    if( hsx > dsx ) return hsx+1;
    return dsx+1;
}

//funzione che calcola l'altezza dell'albero senza l'indice prof in preordine
int altezza_albero_b2_preordine(albero_b a){
    if( a == NULL ) return -1;
    //sto sulla radice
    int hsx = 1 + altezza_albero_b2(a->left);
    int dsx = 1 + altezza_albero_b2(a->right);
    return (hsx > dsx) ? hsx : dsx;
}

//utilizzo la libreria math.h per la funzione max
int altezza_albero_b2_max(albero_b a) {
    if( a == NULL ) return -1;
    //sto sulla radice
    return 1 + max(altezza_albero_b2(a->left), altezza_albero_b2(a->right)); //utilizzo la macro max
}

//somma dei valori all'interno dell'albero
int somma_albero_b(albero_b a) {
    if( a == NULL ) return 0;
    return a->info + somma_albero_b(a->left) + somma_albero_b(a->right);
}

//calcola la media dei valori all'interno dell'albero
float media_albero_b(albero_b a) {
    if( a == NULL ) {
        printf("L'albero e' vuoto percio' non è possibile calcolare la media!\n");
        exit(1);
    }
    int s = (somma_albero_b(a));
    int c = (conta_nodi_albero_b(a));
    return (float)s/(float)c;
}

//funzione che prende l'altezza dell'albero e calcola la potenza 2^(h+1) per poter capire se l'albero è completo
int potenza_albero_b(int altezza) {
    int valore = 2;
    for(int i=0; i<altezza; i++) { // semplificazione di i=1 i<altezza+1
        valore = valore*2; 
    }
    return valore;
}


//calcola quanti nodi all'interno dell'albero hanno due figli
int due_figli_albero_b(albero_b a) {
    if( a == NULL ) return 0;
    int sx = due_figli_albero_b(a->left);
    int dx = due_figli_albero_b(a->right);
    if( two_children_b(a) ) 
        return 1 + sx + dx;
    //ci può essere il caso in cui la radice non abbia due nodi, però c'è sempre il caso di un sottoalbero con nodi che soddisfano la condizione
    else
        return sx + dx;
    // equivalentemente "return two_children(a) + sx + dx;"
    // questo perché se la condizione è vera ritorna uno altrimenti 0, quindi è la stessa cosa!
} 

//conta il numero di foglie all'interno di un albero
int conta_foglie_albero_b(albero_b a) {
    if( a == NULL ) return 0;
    int sx = conta_foglie_albero_b(a->left);
    int dx = conta_foglie_albero_b(a->right);
    if( nodo_a_foglia_b(a) ) 
        return 1 + sx + dx;
    //ci può essere il caso in cui la radice non abbia due nodi, però c'è sempre il caso di un sottoalbero con nodi che soddisfano la condizione
    else
        return sx + dx;
}

//funzione che ritorna il numero di nodi che verificano la condizione nipote->info == nonno->info
int valore_nonno_albero_b(albero_b a) {
    if( a == NULL ) {
        return 0;
    }
    int counter = 0;
    if ( a->parent != NULL && a->parent->parent != NULL ) {
        if (a->info == a->parent->parent->info) {
            counter++;
        }
    }
    counter += valore_nonno_albero_b(a->left);
    counter += valore_nonno_albero_b(a->right);

    return counter;
}

//versione della funzione valore_nonno_albero senza counter
int valore_nonno_albero_b2(albero_b a) {
    if( a == NULL ) {
        return 0;
    }
    int sx = valore_nonno_albero_b2(a->left);
    int dx = valore_nonno_albero_b(a->right);
    if ( a->parent != NULL && a->parent->parent != NULL) {
        if ( a->info == a->parent->parent->info ) {
            return 1 + sx + dx;
        }
    }
    return sx + dx;
}

//conta il numero di nodi che hanno quattro nipoti all'interno dell'albero
int quattro_nipoti_albero_b2(albero_b a) {
    if( a == NULL ) {
        return 0;
    }
    int sx = quattro_nipoti_albero_b2(a->left);
    int dx = quattro_nipoti_albero_b2(a->right);
    if ( (a->left != NULL && a->left->left != NULL && a->left->right != NULL) && 
         (a->right != NULL && a->right->left != NULL && a->right->right != NULL) ) {
            return 1 + sx + dx;
    }
    return sx + dx;
}

//funzione che calcola il grado di parentela tra due nodi
//parentela in base alla profondità dei nodi
int parentela_albero_b(albero_b a, nodo_a* n1, nodo_a* n2) {
    item* lista_n1 = lista_cammino_albero_b(a, n1);
    item* lista_n2 = lista_cammino_albero_b(a, n2);

    int nodi_lista_n1 = conta_nodi_lista_s(lista_n1);
    int nodi_lista_n2 = conta_nodi_lista_s(lista_n2);

    if ( nodi_lista_n1 > nodi_lista_n2 )
        return nodi_lista_n1 - nodi_lista_n2;
    else 
        return nodi_lista_n2 - nodi_lista_n1; 
}

//parentela = lunghezza distanza archi tra i due nodi
int parentela_albero_b2(albero_b a, nodo_a* n1, nodo_a* n2) {
    item* lista_n1 = lista_cammino_albero_b(a, n1);
    item* lista_n2 = lista_cammino_albero_b(a, n2);

    while( lista_n1->info == lista_n2->info ) {
        lista_n1 = lista_n1->next;
        lista_n2 = lista_n2->next;
    }
    return conta_nodi_lista_s(lista_n1) + conta_nodi_lista_s(lista_n2);
}



/****************************************************/
/***************** DECALLOCAZIONE *******************/
/****************************************************/

//dealloca l'albero e tutti i suoi nodi
void dealloca_albero_b(albero_b* a) {
    if( (*a) == NULL ) return;
    dealloca_albero_b( &((*a)->left) );
    dealloca_albero_b( &((*a)->right) );
    //qui ho deallocato il nodo_a sinistro e destro di a
    free((*a));  //libero il nodo_a in memoria
    (*a) = NULL; //chi mi ha lanciato si trova con il puntatore NULL
}



/****************************************************/
/****************** CANCELLAZIONE *******************/
/****************************************************/

//cancella il sottoalbero del nodo_a n (omette la deallocazione)
void pota_albero_b(albero_b* a, nodo_a* n) {
    if( (*a) == NULL) {
        printf("L'albero e' vuoto, non posso cancellare nulla!\n");
        exit(1);
    }
    if( (*a) == n )  (*a) = NULL;
    pota_albero_b(&( (*a)->left ), n);
    pota_albero_b(&( (*a)->right ), n);
}

//cancella tutti i nodi con profondità = h ed i nodi associati (omette la deallocazione)
void pota_albero_b_prof_ricorri(albero_b* a, int prof, int h) {
    if( (*a) == NULL) {
        printf("L'albero e' vuoto, non posso cancellare nulla!\n");
        exit(1);
    }
    if( prof == h ) (*a) = NULL; //qui sto sulla radice e prof vale ancora 0
    pota_albero_b_prof_ricorri(&( (*a)->left ), prof+1, h);
    pota_albero_b_prof_ricorri(&( (*a)->right ), prof+1, h);
}

//funzione di supporto a pota_albero_b_prof_ricorri per inizializzare la profondità a 0
void pota_albero_b_prof(albero_b* a, int h) {
    pota_albero_b_prof_ricorri(a, 0, h);
}



/****************************************************/
/********************** STAMPA **********************/
/****************************************************/

//stampa l'albero con visita simmetrica
void parentetica_simmetrica(albero_b a) {
    if( a == NULL) {
        printf("( )");
        return;
    }
    printf("( ");
    parentetica_simmetrica(a->left);

    printf("%d", a->info);

    parentetica_simmetrica(a->right);
    printf(" )");
}

//stampa l'albero con visita in preordine
void parentetica_preordine(albero_b a) {
    if( a == NULL) {
        printf("( )");
        return;
    }
    printf("( ");
    printf("%d", a->info);

    parentetica_preordine(a->left);

    parentetica_preordine(a->right);
    printf(" )");
}

//stampa fra per alberi binari
void print2DUtil(albero_b root, int space) {
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(albero_b root) {
    // Pass initial space count as 0
    print2DUtil(root, 0);
}



/****************************************************/
/**************** DA ALBERO A LISTA *****************/
/****************************************************/

//funzione che crea una lista con i nodi dell'albero dalla radice fino al nodo_a n (i nodi del cammino)
item* lista_cammino_albero_b(albero_b a, nodo_a* n) {
    if ( a == NULL || n == NULL ) {
        printf("La lista e' vuota o n = NULL, non posso creare una lista con il cammino dal nodo_a n!\n");
        exit(1);
    }
    //adesso la lista esiste
    //do per scontato che il nodo_a n ci sia
    item* new_lista = (item*)malloc(sizeof(item));
    new_lista->info = n->info;
    new_lista->next = NULL;
    
    item* l = new_lista;
    while ( n->parent != NULL ) {
        n = n->parent;
        l->next = (item*)malloc(sizeof(item));
        l = l->next;
        l->info = n->info;
        l->next = NULL;
    }
    //arrivato qui new_lista contiene i nodi del cammino da n alla radice, bisogna invertirla!
    item* inversa = inversa_lista_s(new_lista);
    dealloca_lista_s(&new_lista);

    return inversa;
}





/****************************************************/
/********** ESERCITAZIONI ALBERI BINARI *************/
/****************************************************/

//verifica che un nodo ha i figli con il valore uguale
int verifica_figli_valore_uguale(nodo_a* n) {
    if( n == NULL ) return 0;
    return n->left->info == n->right->info;
}

//Conta il numero dei nodi di un albero binario che hanno entrambi i figli e tali che i due figli hanno la stessa info
int conta_nodi_due_figli_stesso_valore(albero_b a) {
    if(a == NULL ) return 0;
    int cont = 0;
    if( two_children_b(a) && verifica_figli_valore_uguale(a) ) cont++;

    return cont + conta_nodi_due_figli_stesso_valore(a->left) + conta_nodi_due_figli_stesso_valore(a->right);
}

//Determina se esiste una foglia di un albero binario che abbia il campo info uguale a zero.
int verifica_foglia_info_0(albero_b a) {
    if( a == NULL ) return 0;
    if( nodo_a_foglia_b(a) && a->info == 0 ) return 1;

    int sx = verifica_foglia_info_0(a->left);
    if( sx == 1 ) return 1;

    int dx = verifica_foglia_info_0(a->right);
    return dx;
}

//Verifica che tutti i valori dei campi info di un primo albero binario siano contenuti in un secondo albero binario.

int* array_valori_nodi_albero(albero_b a, int* A, int indice) {
    if( a == NULL ) return NULL;
    A[indice] = a->info;

    //in un albero binario devo prima controllare di avere left e right, in quello arbitrario se scorro con left_child != NULL non serve!
    if( a->left != NULL) {
        A = array_valori_nodi_albero(a->left, A, indice+1);
    }
    if( a->right != NULL ) {
        A = array_valori_nodi_albero(a->right, A, indice+1);
    }

    return A;
}

int* creazione_array_valori_nodi_albero(albero_b a) {
    if( a == NULL ) return NULL;
    int length = conta_nodi_albero_b(a);
    int* array = (int*)calloc(length,sizeof(int));
    
    array = array_valori_nodi_albero(a, array, 0);
    
    return array;
}

//verifica esistenziale del valore nell'array
int esistenza_valore_array(int* A, int length, int val) {
    for( int i=0; i < length; i++ ) {
        if( A[i] == val ) return 1;
    }
    return 0;
}

int verifica_alberi_stessi_valori(albero_b a1, albero_b a2) {
    if( a1 == NULL || a2 == NULL ) return 0;
    if( conta_nodi_albero_b(a1) != conta_nodi_albero_b(a2) ) return 0; //se hanno numero nodi diversi ritorno 0 a prescindere!
    int* A1 = creazione_array_valori_nodi_albero(a1);
    int* A2 = creazione_array_valori_nodi_albero(a2);

    int dimensione_a1 = conta_nodi_albero_b(a1);
    int cont = 0; //contatore per i valori uguali che trovo
    for( int i=0; i < dimensione_a1; i++ ) {
        cont += esistenza_valore_array(A2, dimensione_a1, A1[i]);
        
    }
    return cont == dimensione_a1;
}

