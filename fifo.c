#include <stdio.h>
#include <stdbool.h>

// Simulation de la pagination avec FIFO
void fifo(int pages[], int n, int frames) {
    int queue[frames]; // Contient les pages actuellement chargées
    int front = 0, rear = 0, count = 0, faults = 0;
    bool found;

    // Initialiser les cadres à -1 (vides)
    for (int i = 0; i < frames; i++) queue[i] = -1;

    // Parcourir chaque page de la séquence
    for (int i = 0; i < n; i++) {
        found = false;

        // Vérifier si la page est déjà dans les cadres
        for (int j = 0; j < frames; j++) {
            if (queue[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // Si la page n’est pas trouvée -> défaut de page
        if (!found) {
            queue[rear] = pages[i];                     // Remplacer la page à l’index actuel
            rear = (rear + 1) % frames;                 // Passer au cadre suivant (circulaire)
            if (count < frames) count++;                // Incrémenter si cadre vide
            faults++;                                   // Compter le défaut
        }

        // Affichage des cadres
        printf("Cadres: ");
        for (int j = 0; j < count; j++)
            printf("%d ", queue[(front + j) % frames]);
        printf("\n");
    }

    printf("Nombre total de défauts de page (FIFO): %d\n", faults);
}
