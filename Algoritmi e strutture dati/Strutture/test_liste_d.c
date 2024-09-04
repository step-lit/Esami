#include <stdio.h>
#include <stdlib.h>
#include "Liste_d/liste_d.h"

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main() {
  lista_d head = NULL;

  insert_lista_d(&head,1);
  insert_lista_d(&head,2);
  insert_lista_d(&head,3);
  stampa_lista_d(head);

  //inserisco come terzo
  nodo* x1 = head->next->next;
  insert_before_d(&head, 4, x1);
  stampa_lista_d(head);

  //inserisco come primo
  x1 = head;
  insert_before_d(&head, 5, x1);
  stampa_lista_d(head);

  //inserisco in lista vuota
  //lista_d head_vuota = NULL;
  //insert_before_d(&head_vuota, 5, x3);
  x1 = head->next->next;
  insert_after_d(&head, 7, x1);
  stampa_lista_d(head);

  x1 = head;
  insert_after_d(&head, 6, x1);
  stampa_lista_d(head);

  x1 = head->next->next->next->next->next->next;
  insert_after_d(&head, 24, x1);
  stampa_lista_d(head);

  cancella_lista_d(&head, 3);
  stampa_lista_d(head);

  nodo* x2 = head;
  printf("Precedente %p\n", x2->prev);
  printf("Successivo %p\n", x2->next);

  cancella_lista_d(&head, 5);
  stampa_lista_d(head);

  x2 = head;
  printf("Precedente v2 %p\n", x2->prev);
  printf("Successivo v2 %p\n", x2->next);
  
  x2 = head->next->next->next->next->next;  
  printf("Precedente v3 %p\n", x2->prev);
  printf("Successivo v3 %p\n", x2->next);

  cancella_lista_d(&head, 24);
  stampa_lista_d(head);

  x2 = head->next->next->next->next;
  printf("Precedente v4 %p\n", x2->prev);
  printf("Successivo v4 %p\n", x2->next);

  printf("L'indirizzo del nodo che contiene 7 e': %p\n", search_lista_d_elem(head, 7));
  printf("L'indirizzo del nodo che contiene 6 e': %p\n", search_lista_d_elem(head, 6));
  printf("L'indirizzo del nodo che contiene 1 e': %p\n", search_lista_d_elem(head, 1));
  printf("L'indirizzo del nodo che contiene 8 e': %p\n", search_lista_d_elem(head, 8));

  nodo* x3 = head;
  printf("Esiste un primo nodo nella lista? %d\n", search_lista_d_(head, x3));

  x3 = head->next->next->next;
  printf("Esiste un quarto nodo nella lista? %d\n", search_lista_d_(head, x3));

  x3 = head->next->next->next->next;
  printf("Esiste un quinto nodo nella lista? %d\n", search_lista_d_(head, x3));

  x3 = head->next->next->next->next->next;
  printf("Esiste un sesto nodo nella lista? %d\n", search_lista_d_(head, x3));

}