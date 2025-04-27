#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "lru.h"

#define MAX 50  // Taille maximale de la séquence de pages

int main() {
    int pages[MAX], n, frames, i;
    char choix ;
do {

    printf(" Entrez le nombre total de pages : ");
    scanf("%d", &n);

   
    printf(" Entrez la sequence des pages :\n");
    for (i = 0; i < n; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

   
    printf(" Entrez le nombre de frames (cadre) : ");
    scanf("%d", &frames);
    
    
    printf("\n Algorithme  FIFO \n");
    fifo(pages, n, frames);
    
    
    printf("\n Algorithme  LRU \n");
    lru(pages, n, frames);

    printf("Voulez Vous Faire un autre essay (Y/N) ");
    scanf("%s",&choix);

}while((choix=='Y')|| (choix=='y'));
    return 0;
}
