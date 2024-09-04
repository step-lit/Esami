#include <stdio.h>
#include <stdlib.h>


int main() {

  int x = 6;
  int* punta = &x;

  //otteniamo l'indirizzo del puntatore punta (notiamo che usiamo &)
  printf("L'indirizzo di punta e': %p\n", &punta);      

  //otteniamo l'indirizzo contenuto nella variabile punta (puntatore)          
  printf("L'indirizzo contenuto dentro punta e': %p\n", punta);

  //utilizziamo la formattazione per i puntatori %p
  printf("L'indirizzo di x e': %p\n", &x);

  //utilizziamo la formattazione per gli interi %d
  printf("L'indirizzo di x e': %d\n", &x);

  
  printf("Il contenuto di x e': %d\n", x);
  x = 7;   

  //accediamo al valore di x tramite il puntatore con l'indirezione * e visualizziamo il cambiamento
  printf("Il contenuto di x e': %d\n", *punta);

  printf("\n");

}
