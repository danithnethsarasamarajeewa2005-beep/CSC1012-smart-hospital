#include <stdio.h>

int id[100], age[100], urgency[100], doctor[100], ward[100], bed[100], days[100];
char name[100][50];
float bill[100];
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
    
    float docFee = 1500.0;
    if (doctor[total] == 2) docFee = 2500.0;
    if (doctor[total] == 3) docFee = 4500.0;
    if (doctor[total] == 4) docFee = 5000.0;
    
    bill[total] = docFee;
    printf("Patient Saved! ID: PAT-%d | Initial Bill: LKR %.2f\n", id[total], bill[total]);
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