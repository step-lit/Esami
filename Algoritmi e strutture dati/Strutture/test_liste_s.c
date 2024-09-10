#include <stdio.h>
#include <stdlib.h>
#include "Liste_s/liste_s.h"

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main() {
    
    //puntatore al primo elemento della lista inizialmente vuoto!
    item* head = NULL; 
    //tutti inserimenti in testa
    insert_lista_s(&head, 5); 
    insert_lista_s(&head, 2);
    head = insert_lista_s_valore(head, 15);
    head = insert_lista_s_valore(head, 7);
    stampa_lista_s(head);
    printf("La somma degli elementi contenuti in lista e' : %d\n", somma_due_lista_s(head));
    printf("La somma degli elementi contenuti in lista e' : %d\n", somma_uno_lista_s(head));
    //da qui capisco che nella funzione somma se mando avanti il puntatore l non vado a modificare la lista, in alcuni casi è importante però usare il item di supporto per non perdere il riferimento al primo elemento!
    stampa_lista_s(head);
    printf("L'elemento massimo nella lista e' : %d\n", massimo_lista_s(head));
    head = insert_lista_s_valore(head, 10);
    stampa_lista_s(head);
    printf("L'elemento massimo nella lista e' : %d\n", massimo_lista_s(head));
    
    item* x = head->next->next;
    cancella_lista_s(&head, x);
    stampa_lista_s(head);

    insert_lista_s(&head, 6); 
    insert_lista_s(&head, 2);
    insert_lista_s(&head, 3); 
    stampa_lista_s(head);
    
    cancella_lista_s_elem(&head, 2);
    stampa_lista_s(head);

    printf("La ricerca di 2 nella lista produce NULL? %d\n", search_lista_s(head, 2) == NULL );
    printf("La ricerca di 6 nella lista produce NULL? %d\n", search_lista_s(head, 6) == NULL );

    printf("La lista adesso ha %d nodi!\n", conta_nodi_lista_s(head));


    /*      ESERCITAZIONI LISTE      */
    printf("Il minimo valore contenuto nella lista e' %d\n", calcola_minimo_lista(head));
    printf("Il massimo valore e' il doppio del minimo contenuto nella lista? %d\n", verifica_max_min(head));
    cancella_lista_s_elem(&head, 3);
    printf("Ho cancellato 3!\n");
    printf("Il massimo valore e' il doppio del minimo contenuto nella lista? %d\n", verifica_max_min(head));

    
    
}