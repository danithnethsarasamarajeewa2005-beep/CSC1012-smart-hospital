#include <stdio.h>

int id[100], age[100], urgency[100];
char name[100][50];
float bill[100];
int total = 0;

void addPatient() {
    id[total] = 1001 + total;
    printf("\nEnter Name: "); scanf(" %[^\n]", name[total]);
    printf("Enter Age: "); scanf("%d", &age[total]);
    printf("Urgency: "); scanf("%d", &urgency[total]);
    printf("Bill: "); scanf("%f", &bill[total]);
    total++;
}

void saveFile() {
    FILE *fp = fopen("patients.txt", "w");
    if (fp == NULL) return;
    fprintf(fp, "%d\n", total);
    for (int i = 0; i < total; i++) {
        fprintf(fp, "%d;%s;%d;%d;%.2f\n", id[i], name[i], age[i], urgency[i], bill[i]);
    }
    fclose(fp);
    printf("Data saved!\n");
}

void loadFile() {
    FILE *fp = fopen("patients.txt", "r");
    if (fp == NULL) {
        printf("No file found!\n");
        return;
    }
    fscanf(fp, "%d\n", &total);
    for (int i = 0; i < total; i++) {
        fscanf(fp, "%d;%[^;];%d;%d;%f\n", &id[i], name[i], &age[i], &urgency[i], &bill[i]);
    }
    fclose(fp);
    printf("Data loaded!\n");
}

int main() {
    int choice = 0;
    while (choice != 6) {
        printf("\n--- MENU ---\n1. Add Patient\n4. Save File\n5. Load File\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addPatient();
        if (choice == 4) saveFile();
        if (choice == 5) loadFile();
    }
    return 0;
}