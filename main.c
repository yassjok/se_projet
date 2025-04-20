#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "lru.h"

#define MAX 50  // Taille maximale de la séquence de pages

int main() {
    int pages[MAX], n, frames, i;

    // Saisie du nombre total de pages
    printf(" Entrez le nombre total de pages : ");
    scanf("%d", &n);

    // Saisie de la séquence des pages
    printf(" Entrez la sequence des pages :\n");
    for (i = 0; i < n; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    // Saisie du nombre de frames disponibles
    printf(" Entrez le nombre de cadres (frames) : ");
    scanf("%d", &frames);

    // Appel de FIFO
    printf("\n Algorithme  FIFO \n");
    fifo(pages, n, frames);

    // Appel de LRU
    printf("\n Algorithme  LRU \n");
    lru(pages, n, frames);

    return 0;
}
