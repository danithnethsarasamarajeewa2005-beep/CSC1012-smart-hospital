#include <stdio.h>

int id[100];
char name[100][50];
int age[100];
int urgency[100];
int doctor[100];
int ward[100];
int bed[100];
int days[100];
int total = 0;

void addPatient() {
    id[total] = 1001 + total;
    
    printf("\nEnter Patient Name: ");
    scanf(" %[^\n]", name[total]);
    
    printf("Enter Age: ");
    scanf("%d", &age[total]);
    
    printf("Enter Urgency Level (1-Normal, 2-Urgent, 3-Critical): ");
    scanf("%d", &urgency[total]);
    
    printf("Select Doctor (1-General, 2-Child, 3-Heart, 4-Brain): ");
    scanf("%d", &doctor[total]);
    
    int admit;
    printf("Admit to Ward? (1-Yes, 0-No): ");
    scanf("%d", &admit);
    
    if (admit == 1) {
        printf("Select Ward (1-General, 2-Child, 3-Surgery, 4-ICU): ");
        scanf("%d", &ward[total]);
        printf("Enter Bed Number: ");
        scanf("%d", &bed[total]);
        printf("Enter Days: ");
        scanf("%d", &days[total]);
    } else {
        ward[total] = 0;
        bed[total] = 0;
        days[total] = 0;
    }
    
    printf("Patient Saved! ID: PAT-%d\n", id[total]);
    total++;
}

int main() {
    int choice = 0;
    while (choice != 6) {
        printf("\n--- MENU ---\n1. Add Patient\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addPatient();
    }
    return 0;
}