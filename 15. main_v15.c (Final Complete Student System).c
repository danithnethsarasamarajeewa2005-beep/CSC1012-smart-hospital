#include <stdio.h>

int id[100], age[100], urgency[100], doctor[100], ward[100], bed[100], days[100];
char name[100][50];
float bill[100];
int total = 0;

void addPatient() {
    id[total] = 1001 + total;
    
    printf("\nEnter Name: "); scanf(" %[^\n]", name[total]);
    printf("Enter Age: "); scanf("%d", &age[total]);
    printf("Urgency Level (1-Normal, 2-Urgent, 3-Critical): "); scanf("%d", &urgency[total]);
    printf("Select Doctor (1-General, 2-Child, 3-Heart, 4-Brain): "); scanf("%d", &doctor[total]);
    
    float docFee = 1500.0;
    if (doctor[total] == 2) docFee = 2500.0;
    if (doctor[total] == 3) docFee = 4500.0;
    if (doctor[total] == 4) docFee = 5000.0;
    
    float extraFee = 0;
    if (urgency[total] == 2) extraFee = docFee * 0.20;
    if (urgency[total] == 3) extraFee = docFee * 0.50;
    
    int admit;
    printf("Admit to Ward? (1-Yes, 0-No): "); scanf("%d", &admit);
    float wardFee = 0;
    
    if (admit == 1) {
        printf("Ward (1-General, 2-Child, 3-Surgery, 4-ICU): "); scanf("%d", &ward[total]);
        printf("Bed Number: "); scanf("%d", &bed[total]);
        printf("Days: "); scanf("%d", &days[total]);
        
        float rate = 3000.0;
        if (ward[total] == 2) rate = 6000.0;
        if (ward[total] == 3) rate = 12000.0;
        if (ward[total] == 4) rate = 25000.0;
        wardFee = days[total] * rate;
    } else {
        ward[total] = 0; bed[total] = 0; days[total] = 0;
    }
    
    float subTotal = docFee + extraFee + wardFee;
    float discount = 0;
    if (age[total] < 5 || age[total] > 65) discount = subTotal * 0.15;
    
    bill[total] = subTotal - discount;
    
    printf("\n--- BILL RECEIPT ---\n");
    printf("Patient ID : PAT-%d\n", id[total]);
    printf("Name       : %s\n", name[total]);
    printf("Total Fee  : LKR %.2f\n", bill[total]);
    printf("--------------------\n");
    
    total++;
}

void viewQueue() {
    if (total == 0) {
        printf("\nNo patients in queue!\n");
        return;
    }
    
    int tempID[100];
    for (int i = 0; i < total; i++) tempID[i] = i;
    
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (urgency[tempID[j]] > urgency[tempID[i]]) {
                int t = tempID[i];
                tempID[i] = tempID[j];
                tempID[j] = t;
            }
        }
    }

    printf("\n--- PATIENT QUEUE ---\n");
    for (int i = 0; i < total; i++) {
        int k = tempID[i];
        printf("ID: PAT-%d | Name: %s | Urgency: %d | Bill: LKR %.2f\n", id[k], name[k], urgency[k], bill[k]);
    }
}

void viewReports() {
    if (total == 0) {
        printf("\nNo data available!\n");
        return;
    }
    float income = 0;
    for (int i = 0; i < total; i++) income += bill[i];
    
    printf("\n--- REPORTS ---\n");
    printf("Total Patients: %d\n", total);
    printf("Total Revenue : LKR %.2f\n", income);
}

void saveFile() {
    FILE *fp = fopen("patients.txt", "w");
    if (fp == NULL) return;
    fprintf(fp, "%d\n", total);
    for (int i = 0; i < total; i++) {
        fprintf(fp, "%d;%s;%d;%d;%d;%d;%d;%d;%.2f\n", id[i], name[i], age[i], urgency[i], doctor[i], ward[i], bed[i], days[i], bill[i]);
    }
    fclose(fp);
    printf("Data saved to file!\n");
}

void loadFile() {
    FILE *fp = fopen("patients.txt", "r");
    if (fp == NULL) return;
    fscanf(fp, "%d\n", &total);
    for (int i = 0; i < total; i++) {
        fscanf(fp, "%d;%[^;];%d;%d;%d;%d;%d;%d;%f\n", &id[i], name[i], &age[i], &urgency[i], &doctor[i], &ward[i], &bed[i], &days[i], &bill[i]);
    }
    fclose(fp);
    printf("Data loaded from file!\n");
}

int main() {
    int choice = 0;
    
    while (choice != 6) {
        printf("\n=== HOSPITAL SYSTEM MENU ===\n");
        printf("1. Register Patient\n");
        printf("2. View Priority Queue\n");
        printf("3. View Reports\n");
        printf("4. Save Data\n");
        printf("5. Load Data\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewQueue(); break;
            case 3: viewReports(); break;
            case 4: saveFile(); break;
            case 5: loadFile(); break;
            case 6: printf("Exiting Program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}