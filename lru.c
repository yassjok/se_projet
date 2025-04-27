#include <stdio.h>


int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;    // On parcourt le tableau time[] 
    for (int i = 1; i < n; ++i) {     // contient le moment où chaque page a été utilisée pour la dernière fois).
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;    
        }
    }
    return pos;  // On retourne la position de la page 
}

// Simulation de la pagination avec LRU

void lru(int pages[], int n, int frames) {
    int temp[frames];       // Cadres mémoire
    int counter = 0;        // Compteur global du temps
    int time[frames];       // Dernier accès de chaque page
    int faults = 0, pos, flag1, flag2;   // Variables temporaires

    // Initialisation  touts les frames sont vides 

    for (int i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        flag1 = flag2 = 0;

        // Chercher si la page existe dans les frames
        for (int j = 0; j < frames; ++j) {
            if (temp[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1; // Page trouvée
                break;
            }
        }

        // Si la page n’existe pas, chercher une frame vide
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
        printf("Frames : ");
        for (int j = 0; j < frames; ++j) {
            if (temp[j] != -1)
                printf("%d ", temp[j]);
        }
        printf("\n");
    }

    printf(" Nombre total de defauts de page (LRU): %d\n", faults);
}
