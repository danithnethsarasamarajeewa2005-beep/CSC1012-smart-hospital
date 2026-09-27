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
    printf("Enter Bill: "); scanf("%f", &bill[total]);
    total++;
}

void viewReports() {
    if (total == 0) {
        printf("\nNo data to show!\n");
        return;
    }
    float totalIncome = 0;
    for (int i = 0; i < total; i++) {
        totalIncome += bill[i];
    }
    printf("\n--- HOSPITAL REPORT ---\n");
    printf("Total Patients: %d\n", total);
    printf("Total Income  : LKR %.2f\n", totalIncome);
}

int main() {
    int choice = 0;
    while (choice != 6) {
        printf("\n--- MENU ---\n1. Add Patient\n3. Reports\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addPatient();
        if (choice == 3) viewReports();
    }
    return 0;
}