#include <stdio.h>

int id[100];
char name[100][50];
int age[100];
int urgency[100];
int doctor[100];
int total = 0;

int main() {
    int choice = 0;
    
    while (choice != 6) {
        printf("\n--- MENU ---\n");
        printf("1. Add Patient\n");
        printf("2. View Queue\n");
        printf("3. View Reports\n");
        printf("4. Save File\n");
        printf("5. Load File\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
    
    return 0;
}