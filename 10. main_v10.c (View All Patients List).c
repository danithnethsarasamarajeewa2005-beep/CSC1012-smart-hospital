#include <stdio.h>

int id[100], age[100], urgency[100], doctor[100], ward[100], bed[100], days[100];
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
        printf("\nNo patients registered yet!\n");
        return;
    }
    printf("\n--- PATIENT LIST ---\n");
    for (int i = 0; i < total; i++) {
        printf("ID: PAT-%d | Name: %s | Age: %d | Urgency: %d\n", id[i], name[i], age[i], urgency[i]);
    }
}

int main() {
    int choice = 0;
    while (choice != 6) {
        printf("\n--- MENU ---\n1. Add Patient\n2. View List\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addPatient();
        if (choice == 2) viewQueue();
    }
    return 0;
}