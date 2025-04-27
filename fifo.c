#include <stdio.h>
#include <stdbool.h>

void fifo(int pages[], int n, int frames) {  // pages[] : tableau contenant la séquence des pages à charger.
    int queue[frames];          // Contient les pages actuellement chargées
    int front = 0, rear = 0, count = 0, faults = 0;   // front et rear pour gérer les indices FIFO     
    bool found;  //  Dit si la page est déjà dans la mémoire.

    // Initialiser les cadres à -1 (vides)
    for (int i = 0; i < frames; i++) queue[i] = -1;

    // Parcourir chaque page de la séquence
    for (int i = 0; i < n; i++) {
        found = false;

        // Vérifier si la page est déjà dans les frames 

        for (int j = 0; j < frames; j++) {
            if (queue[j] == pages[i]) {  //On cherche la page dans la mémoire.
                found = true;         // Si elle est déjà là → pas de défaut de page.
                break;
            }
        }

        // Si la page n’est pas trouvée -> défaut de page
        if (!found) {
            queue[rear] = pages[i];                   // Remplacer la page à l’index actuel
            rear = (rear + 1) % frames;              // Passer au cadre suivant (circulaire)
            if (count < frames) count++;            // Mise à jour du compteur
            faults++;                              // Incrémenter les défauts
        }

        printf("Frames :");
        for (int j = 0; j < count; j++)
            printf("%d ", queue[(front + j) % frames]);
        printf("\n");
    }

    printf("Nombre total de defauts de page (FIFO): %d\n", faults);
}
