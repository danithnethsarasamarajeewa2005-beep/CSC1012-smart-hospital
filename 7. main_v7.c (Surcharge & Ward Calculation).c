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
    printf("Doctor (1-General, 2-Child, 3-Heart, 4-Brain): "); scanf("%d", &doctor[total]);
    
    float docFee = 1500.0;
    if (doctor[total] == 2) docFee = 2500.0;
    if (doctor[total] == 3) docFee = 4500.0;
    if (doctor[total] == 4) docFee = 5000.0;
    
    float extraFee = 0;
    if (urgency[total] == 2) extraFee = docFee * 0.20;
    if (urgency[total] == 3) extraFee = docFee * 0.50;
    
    int admit;
    printf("Admit? (1-Yes, 0-No): "); scanf("%d", &admit);
    float wardFee = 0;
    
    if (admit == 1) {
        printf("Ward (1-General, 2-Child, 3-Surgery, 4-ICU): "); scanf("%d", &ward[total]);
        printf("Days: "); scanf("%d", &days[total]);
        
        float rate = 3000.0;
        if (ward[total] == 2) rate = 6000.0;
        if (ward[total] == 3) rate = 12000.0;
        if (ward[total] == 4) rate = 25000.0;
        
        wardFee = days[total] * rate;
    }
    
    bill[total] = docFee + extraFee + wardFee;
    printf("Bill Calculated: LKR %.2f\n", bill[total]);
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