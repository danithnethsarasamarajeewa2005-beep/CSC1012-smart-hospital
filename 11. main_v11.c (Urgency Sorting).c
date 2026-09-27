#include <stdio.h>

int id[100], age[100], urgency[100];
char name[100][50];
float bill[100];
int total = 0;

void addPatient() {
    id[total] = 1001 + total;
    printf("\nEnter Name: "); scanf(" %[^\n]", name[total]);
    printf("Enter Age: "); scanf("%d", &age[total]);
    printf("Urgency (1-Normal, 2-Urgent, 3-Critical): "); scanf("%d", &urgency[total]);
    bill[total] = 2000.0;
    total++;
}

void viewQueue() {
    if (total == 0) {
        printf("\nNo patients registered!\n");
        return;
    }
    
    int tempID[100];
    for(int i = 0; i < total; i++) tempID[i] = i;
    
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (urgency[tempID[j]] > urgency[tempID[i]]) {
                int t = tempID[i];
                tempID[i] = tempID[j];
                tempID[j] = t;
            }
        }
    }

    printf("\n--- QUEUE (SORTED BY URGENCY) ---\n");
    for (int i = 0; i < total; i++) {
        int k = tempID[i];
        printf("ID: PAT-%d | Name: %s | Urgency Level: %d\n", id[k], name[k], urgency[k]);
    }
}

int main() {
    int choice = 0;
    while (choice != 6) {
        printf("\n--- MENU ---\n1. Add Patient\n2. View Queue\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addPatient();
        if (choice == 2) viewQueue();
    }
    return 0;
}