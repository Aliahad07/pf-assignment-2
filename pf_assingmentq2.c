#include <stdio.h>
#include <string.h> 
long long cnic = 0; 
char name[50] = {0}; 
int cart_count = 0;
float customer_cart[100][2]; 
float total = 0.0f; 

#define MAX_NAME_LEN 50
#define PROMO_CODE_STR "Eid2025"
#define DISCOUNT_RATE 0.25f

void display_menu(){ 
    printf("\n==== Menu ====\n");
    printf("1. Enter Personal Information\n");
    printf("2. Show Inventory\n");
    printf("3. Add Products to Cart\n");
    printf("4. Show Bill\n");
    printf("5. Show Final Invoice\n");
    printf("6. Exit\n"); 
}

void personal_info(){
    long long temp_cnic;
    char temp_name[MAX_NAME_LEN];
    int valid_input;

    printf("\n--- 1. Enter Personal Information ---\n");
        do {
        valid_input = 1;
        printf("Enter CNIC (13 digits, no dashes): ");
        if (scanf("%lld", &temp_cnic) != 1) { 
            printf("[ERROR] Invalid input. CNIC must be a number.\n");
            scanf("%*[^\n]");
            valid_input = 0;
        }
        scanf("%*c"); 

    } while (valid_input == 0);
    
    printf("Enter Full Name (max %d chars): ", MAX_NAME_LEN - 1); 
    
    if (scanf(" %49[^\n]", temp_name) != 1) {
        printf("[ERROR] Failed to read name. Input aborted.\n");
        scanf("%*[^\n]");
        scanf("%*c");
        return;
    }
    
    cnic = temp_cnic;
    strcpy(name, temp_name); 

    printf("SUCCESS: Customer information stored.\n");
    printf("Your CNIC is: %lld\n", cnic);
    printf("Your name is: %s\n", name);
}

void diplayInventory(int product_code[], int quantity[], float price_per_piece[], int *count){
    printf("\n------- INVENTORY -------\n");
    printf("sr.no | product code | quantity | price\n");
    for(int i=0; i < *count; i++){
        printf("%5d | %12d | %8d | %6.2f |\n", i + 1, product_code[i], quantity[i], price_per_piece[i]);
    }
}

void add_items(int product_code[], int quantity[], float price[], int *count){
    
    int item_code;
    int item_qty;
    int index_found = -1; 
    
    printf("\n--- 3. Add Products to Cart ---\n");
    printf("Enter item code to add to the cart: ");
    
    if (scanf("%d", &item_code) != 1 || item_code <= 0) { 
        printf("[ERROR] Invalid input for item code.\n");
        scanf("%*[^\n]"); 
        scanf("%*c");
        return;
    }
    scanf("%*c");
    
    for(int i = 0; i < *count; i++){
        if(product_code[i] == item_code){
            index_found = i;
            break; 
        }
    }
    
    if (index_found == -1) {
        printf("[ERROR] Item %d not found in the store!\n", item_code);
        return;
    }
    
    printf("Item found! Current stock: %d. Price: %.2f\n", quantity[index_found], price[index_found]);
    printf("Enter the quantity of this item: ");
    if (scanf("%d", &item_qty) != 1 || item_qty <= 0) { 
        printf("[ERROR] Invalid quantity input.\n");
        scanf("%*[^\n]"); 
        scanf("%*c"); 
        return;
    }
    scanf("%*c"); 
    if(item_qty <= quantity[index_found]){
        customer_cart[cart_count][0] = (float)product_code[index_found]; 
        customer_cart[cart_count][1] = (float)item_qty * price[index_found];
        
        cart_count++;
        quantity[index_found] -= item_qty; 
        
        printf("SUCCESS: %d units of item %d added successfully! Cart Total: %.2f\n", item_qty, item_code, customer_cart[cart_count-1][1]);
    }
    else {
        printf("[ERROR] Invalid quantity! Requested: %d, Available: %d.\n", item_qty, quantity[index_found]);
    }
}
void show_bill(){
    
    printf("\n==== Bill of Your Shopping ====\n");
    
    char promo_code[10];
    int has_voucher; 
    
    float subtotal = 0.0f;
    
    for(int i = 0; i < cart_count; i++){
        subtotal += customer_cart[i][1];
    }
    
    total = subtotal; 
    
    printf("Your subtotal is: %.2f\n", subtotal); 
    
    printf("Do you have a voucher? (1 for yes, 0 for no): ");
    
    if (scanf("%d", &has_voucher) != 1) { 
        printf("[ERROR] Invalid input for discount. Assuming no voucher.\n");
        has_voucher = 0;
        scanf("%*[^\n]"); 
        scanf("%*c");
    } else {
        scanf("%*c"); 
    }
    if(has_voucher != 1 && has_voucher != 0){
        printf("Invalid choice for voucher. No discount applied.\n");
    }
    else if(has_voucher == 1){
        printf("Enter promo code: ");
        if (scanf("%9s", promo_code) != 1) {
            printf("[ERROR] Failed to read promo code.\n");
        } else {
            if(strcmp(promo_code, PROMO_CODE_STR) == 0){
                total = subtotal * (1.0f - DISCOUNT_RATE); 
                printf("25%% discount applied due to promo code (%s)!\n", PROMO_CODE_STR);
            } else {
                printf("Invalid promo code. No discount applied.\n");
            }
        }
    } 
    printf("Your final total after discount is: PKR %.2f\n", total); 
}
void final_invoice(){  
    printf("\n--- Final Invoice ---\n");
    printf("Name: %s\n", name);
    printf("CNIC: %lld\n", cnic); 
    printf("\nYour total bill is: PKR %.2f\n", total); 
}
int main(){
    int product_code[100] = {1, 2, 3, 4, 5, 6, 7, 10, 19, 100};
    int quantity[100] = {12, 32, 1, 4, 5, 6, 22, 33, 4, 5};
    float prices[100] = {12.4, 43.5, 65.9, 12.54, 32.1, 23.2, 11.0, 3.4, 112.0, 54.9};
    int number_of_products = 10;
    int choice;
    personal_info(); 
    do{
        display_menu();
        printf("Enter option (1-6): \n");
                if (scanf("%d", &choice) != 1) {
            printf("[ERROR] Invalid input. Please enter a number.\n");
            choice = 0; 
            scanf("%*[^\n]");
        }
        switch (choice)
        {
            case 1:
                personal_info(); 
                break;
            case 2:
                diplayInventory(product_code, quantity, prices, &number_of_products);
                break;
            case 3:
                add_items(product_code, quantity, prices, &number_of_products);
                break;
            case 4:
                show_bill();
                break;
            case 5:
                final_invoice();
                break;
            case 6: 
                printf("Exiting from program.\n");
                printf("Visit us again!\n");
                break;
            default:
                printf("Invalid choice! Please select an option from 1 to 6.\n");
                break;
        }
    } while (choice != 6); 

    return 0;
}