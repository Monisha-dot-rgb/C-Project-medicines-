#include <stdio.h>
#include <stdlib.h> 


struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
    char expiry_date[15]; 
};

void display_menu();
void add_medicine();
void view_inventory();
void search_medicine();
void update_stock();

int main() {
    int choice;
    
    printf("--- Welcome to PharmaCare Inventory System ---\n");

    do {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
             
             while (getchar() != '\n');
             choice = -1;
        }

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_stock();
                break;
            case 0:
                printf("\nExiting PharmaCare. Thank you!\n");
                exit(0);
            default:
                printf("\n** Invalid choice. Please try again (0-4). **\n");
        }
    } while (choice != 0);

    return 0;
}

void display_menu() {
    printf("\n\n*** MAIN MENU ***\n");
    printf("1. Add New Medicine\n");
    printf("2. View All Inventory\n");
    printf("3. Search Medicine (by ID)\n");
    printf("4. Update Stock Quantity\n");
    printf("0. Exit Program\n");
    printf("-----------------\n");
}

void add_medicine() {
    struct Medicine new_med;
    FILE *file_ptr;

    printf("\n--- Add New Medicine ---\n");
    
    printf("Enter Medicine ID: ");
    scanf("%d", &new_med.id);
    printf("Enter Name (No Spaces): ");
    scanf("%s", new_med.name);
    printf("Enter Price: ");
    scanf("%f", &new_med.price);
    printf("Enter Quantity: ");
    scanf("%d", &new_med.quantity);
    printf("Enter Expiry Date (DD-MM-YYYY): ");
    scanf("%s", new_med.expiry_date);
    
    
    printf("\nMedicine ID %d added successfully!\n", new_med.id);
    printf("\n");
}

void view_inventory() {
    struct Medicine med;
    FILE *file_ptr;

    printf("\n--- Current Inventory ---\n");
    printf("ID\tName\t\tPrice\tQuantity\tExpiry\n");
    printf("--------------------------------------------------\n");

    
             printf("%d\t%s\t\t%.2f\t%d\t\t%s\n", med.id, med.name, med.price, med.quantity, med.expiry_date);
    
    printf("\n[NOTE: File handling is not yet fully implemented to display data.]\n");
}

void search_medicine() {
    int search_id;
    struct Medicine med;
    FILE *file_ptr;
    int found = 0;

    printf("\n--- Search Medicine ---\n");
    printf("Enter Medicine ID to search: ");
    scanf("%d", &search_id);
             if (med.id == search_id) {
                 printf("\nMedicine Found:\n");
                 printf("Name: %s\n", med.name);
                 printf("Price: %.2f\n", med.price);
                 printf("Stock Left: %d\n", med.quantity);
                 printf("Expiry: %s\n", med.expiry_date);
                 found = 1;
                 
             }
    
    if (!found) {
        printf("\n** Error: Medicine ID %d not found in inventory. **\n", search_id);
    }
}

void update_stock() {
    printf("\n--- Update Stock Quantity ---\n");
    printf("This feature requires advanced File Handling (reading, modifying, and rewriting the record).\n");
    printf("You will need to implement fseek() and possibly a temporary file for robust updates.\n");
    printf("[Feature currently disabled]\n");
}

 