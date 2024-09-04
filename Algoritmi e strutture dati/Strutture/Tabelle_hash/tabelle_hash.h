#ifndef _TABELLE_HASH
#define _TABELLE_HASH

//struttura per i nodi delle liste interne alla tabella
typedef struct i {

    int key;
    int info;
    struct i* next;

} item;

//creo una struttura tabella (non è necessario definire il nome struct "qualcosa" perché non ho nessun puntatore alla prossima tabella)
typedef struct {

    item** T;
    int m;
    int n;
    double irr;

} tabella;

tabella* new_tabella();

void add_tabella(tabella* thash, int key, int val);

//funzione hash
int mult_hash(tabella* thash, int key);

item* search_tabella(tabella* thash, int key);

void stampa_tabella(tabella* thash);



#endif