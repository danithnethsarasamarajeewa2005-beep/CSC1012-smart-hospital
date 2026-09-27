#include <stdio.h>

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