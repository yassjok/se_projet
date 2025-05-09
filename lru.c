#include <stdio.h>

// Fonction utilitaire pour trouver la page LRU
int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos; // Renvoie l'index de la page la moins récemment utilisée
}

// Simulation de la pagination avec LRU
void lru(int pages[], int n, int frames) {
    int temp[frames];       // Cadres mémoire
    int counter = 0;        // Compteur global du temps
    int time[frames];       // Dernier accès de chaque page
    int faults = 0, pos, flag1, flag2;

    // Initialisation
    for (int i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        flag1 = flag2 = 0;

        // Chercher si la page existe dans les cadres
        for (int j = 0; j < frames; ++j) {
            if (temp[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1; // Page trouvée
                break;
            }
        }

        // Si la page n’existe pas, chercher un cadre vide
        if (!flag1) {
            for (int j = 0; j < frames; ++j) {
                if (temp[j] == -1) {
                    counter++;
                    faults++;
                    temp[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Sinon, remplacer la page la moins récemment utilisée
        if (!flag2) {
            pos = findLRU(time, frames);
            counter++;
            faults++;
            temp[pos] = pages[i];
            time[pos] = counter;
        }

        // Affichage
        printf("Cadres: ");
        for (int j = 0; j < frames; ++j) {
            if (temp[j] != -1)
                printf("%d ", temp[j]);
        }
        printf("\n");
    }

    printf("Nombre total de defauts de page (LRU): %d\n", faults);
}
