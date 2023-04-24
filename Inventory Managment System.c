#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
    char phoneNumber[20];
} Customer;

Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;

typedef struct {
    char name[50];
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

struct warehouse {
    int id;
    char manager[50];
    char address[100];
    char contact[20];
};

int warehouse() {
    struct warehouse w[4] = {
        {1, "ADITYA", "123 Main St", "555-1234"},
        {2, "GAURAV", "456 Elm St", "555-5678"},
        {3, "AKSHAJ", "789 Oak St", "555-9012"},
        {4, "SANYAM", "321 Pine St", "555-3456"}
    };

    printf("\t\t\t\t| ID | Manager\t | Address\t | Contact  |\n");

    for (int i = 0; i < 4; ++i) {
        printf("\t\t\t\t|  %d | %s\t | %s\t | %s |\n", w[i].id, w[i].manager, w[i].address, w[i].contact);
    }
    adminmenu();
}

void login(){
    char username[20];
    char password[20];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "adminpass") == 0) {
        printf("Welcome Administrator!\n");
        adminmenu();
    } else if (strcmp(username, "staff") == 0 && strcmp(password, "staffpass") == 0) {
        printf("Welcome Staff!\n");
        staffmenu();
    } else {
        printf("Invalid login credentials.\n");
           login();
        }
    return 0;
}

void logout(){
menuWindow();
}

void menuWindow(){

	int choice;
	printf("\n");

	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] Login                                    |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [2] EXIT                                     |");
    printf("\n\t\t\t\t________________________________________________\n\n");
    printf("\t\t\t\t CHOOSE A NUMBER IN THE BOX ABOVE:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: login();
		break;
		case 2: exit(0);
		break;
		default:
		printf("Invalid Choice!!!");
		menuWindow();

	}
}

void adminmenu(){
    int choice;
	printf("\n");

	printf("\n\t\t\t\t ADMIN MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] Warehouse Available                      |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [2] Products                                 |");
    printf("\n\t\t\t\t|______________________________________________|");
    printf("\n\t\t\t\t| [3] Logout                                   |");
    printf("\n\t\t\t\t|______________________________________________|\n\n");
    printf("\t\t\t\t\t CHOOSE A NUMBER IN THE BOX ABOVE:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: warehouse();
		break;
		case 2: product();
		break;
		case 3: logout();
		break;
		default:
		printf("Invalid Choice!!!");
		adminmenu();
	}
}

void staffmenu(){
    int choice;
	printf("\n");

	printf("\n\t\t\t\t STAFF MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] Product Available                        |");
    printf("\n\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t| [2] Client Details                           |");
    printf("\n\t\t\t\t|______________________________________________|");
    printf("\n\t\t\t\t| [3] Bill Generator                           |");
    printf("\n\t\t\t\t|______________________________________________|");
    printf("\n\t\t\t\t| [4] Logout                                   |");
    printf("\n\t\t\t\t|______________________________________________|\n\n");
    printf("\t\t\t\t\t CHOOSE A NUMBER IN THE BOX ABOVE:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: print_products();
                staffmenu();
		break;
		case 2: client();
		break;
		case 3: bill();
		break;
		case 4: logout();
		break;
		default:
		printf("Invalid Choice!!!");
		staffmenu();
	}
}

void bill() {
    print_products();
    float unit_price, quantity, total_price = 0, tax_rate, tax_amount, discount_rate, discount_amount;
    int payment_method;
    char choice, product_name[100], customer_name[100], customer_address[100];
    printf("\t\t\t\tEnter the customer name: ");
    scanf("%s", customer_name);
    printf("\t\t\t\tEnter the customer address: ");
    scanf("%s", customer_address);
    printf("\t\t\t\tEnter the tax rate (as a percentage): ");
    scanf("%f", &tax_rate);
    printf("\t\t\t\tEnter the discount rate (as a percentage): ");
    scanf("%f", &discount_rate);
    printf("\t\t\t\t\t\t---RECEIPT---\n");
    printf("\t\t\t\tCustomer name: %s\n", customer_name);
    printf("\t\t\t\tCustomer address: %s\n", customer_address);
    do {
        printf("\t\t\t\tEnter the product name: ");
        scanf("%s", product_name);
        printf("\t\t\t\tEnter the unit price: ");
        scanf("%f", &unit_price);
        printf("\t\t\t\tEnter the quantity: ");
        scanf("%f", &quantity);
        total_price += unit_price * quantity;
        printf("\t\t\t\t%s: %.2f x %.2f = %.2f\n", product_name, unit_price, quantity, unit_price * quantity);
        printf("\t\t\t\tDo you want to add another item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    tax_amount = total_price * tax_rate / 100;
    total_price += tax_amount;
    discount_amount = total_price * discount_rate / 100;
    total_price -= discount_amount;
    printf("\t\t\t\tChoose the payment method:\n");
    printf("\t\t\t\t1. Credit\n");
    printf("\t\t\t\t2. Online\n");
    printf("\t\t\t\t3. Cash\n\t\t\t\t");
    printf("\n\t\t\t\t Enter Your Choice: ");
    scanf("%d", &payment_method);
    switch (payment_method) {
        case 1:
            printf("\t\t\t\tCredit\n");
            break;
        case 2:
            printf("\t\t\t\tOnline\n");
            break;
        case 3:
            printf("\t\t\t\tCash\n");
            break;
        default:
            printf("\t\t\t\tInvalid\n");
            break;
    }
    printf("\t\t\t\tTax amount: %.2f\n", tax_amount);
    printf("\t\t\t\tDiscount amount: %.2f\n", discount_amount);
    printf("\t\t\t\tTotal price (including tax and discount): %.2f\n", total_price);
    printf("\t\t\t\tPayment method: %d", payment_method);
    printf("\n\t\t\t\t---END OF RECEIPT---\n");
    staffmenu();

}

void addCustomer() {
    if (numCustomers == MAX_CUSTOMERS) {
        printf("Cannot add more customers!\n");
        return;
    }

    Customer *customer = &customers[numCustomers++];

    printf("\n\t\t\t\t\tEnter name: ");
    scanf("%s", customer->name);
    printf("\n\t\t\t\t\tEnter age: ");
    scanf("%d", &customer->age);
    printf("\n\t\t\t\t\tEnter address: ");
    scanf("%s", customer->address);
    printf("\n\t\t\t\t\tEnter phone number: ");
    scanf("%s", customer->phoneNumber);
}

void removeCustomer() {
    int index;
    printCustomerDetails();

    printf("\n\t\t\t\t\tEnter customer index to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= numCustomers) {
        printf("\n\t\t\t\t\tInvalid index!\n");
        return;
    }

    for (int i = index; i < numCustomers - 1; i++) {
        customers[i] = customers[i + 1];
    }

    numCustomers--;
}

void updateCustomer() {
    int index;

    printf("\n\t\t\t\t\tEnter customer index to update: ");
    scanf("%d", &index);

    if (index < 0 || index >= numCustomers) {
        printf("\n\t\t\t\t\tInvalid index!\n");
        return;
    }

    Customer *customer = &customers[index];

    printf("\n\t\t\t\t\tEnter name: ");
    scanf("%s", customer->name);
    printf("\n\t\t\t\t\tEnter age: ");
    scanf("%d", &customer->age);
    printf("\n\t\t\t\t\tEnter address: ");
    scanf("%s", customer->address);
    printf("\n\t\t\t\t\tEnter phone number: ");
    scanf("%s", customer->phoneNumber);
}

void printCustomerDetails() {
    for (int i = 0; i < numCustomers; i++) {
        Customer *customer = &customers[i];
        printf("\n\t\t\t\t\tCustomer %d:\n", i);
        printf("\t\t\t\t\tName: %s\n", customer->name);
        printf("\t\t\t\t\tAge: %d\n", customer->age);
        printf("\t\t\t\t\tAddress: %s\n", customer->address);
        printf("\t\t\t\t\tPhone Number: %s\n", customer->phoneNumber);
    }
}

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Cannot add more products!\n");
        return;
    }

    Product* product = &products[num_products++];

    printf("\n\t\t\t\t\tEnter Product Name: ");
    scanf("%s", &product->name);
    printf("\n\t\t\t\t\tEnter price: ");
    scanf("%f", &product->price);
}

void remove_product() {
    int index;

    printf("\n\t\t\t\t\tEnter product index to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_products) {
        printf("\n\t\t\t\t\tInvalid index!\n");
        return;
    }

    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    num_products--;
}

void update_product(){
int index;

    printf("\n\t\t\t\t\tEnter product index to update: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_products) {
        printf("\n\t\t\t\t\tInvalid index!\n");
        return;
    }

    Product *product = &products[index];

    printf("\n\t\t\t\t\tEnter Product: ");
    scanf("%s", &product->name);
    printf("\n\t\t\t\t\tEnter price: ");
    scanf("%f", &product->price);
}

void print_products(){
    for (int i = 0; i < num_products; i++) {
        Product *product = &products[i];
        printf("\n\t\t\t\t\tProduct %d:\n", i);
        printf("\t\t\t\t\tProduct Name: %s\n", &product->name);
        printf("\t\t\t\t\tPrice: %f\n", product->price);
    }
}

void product() {
   int choice;

    while (1) {
        printf("\n\t\t\t\t PRODUCT MENU\n\t\t\t\t ______________________________________________");
        printf("\n\t\t\t\t| [1] Add Product                              |");
        printf("\n\t\t\t\t| _____________________________________________|");
        printf("\n\t\t\t\t| [2] Remove Product                          |");
        printf("\n\t\t\t\t|______________________________________________|");
        printf("\n\t\t\t\t| [3] Update Product                          |");
        printf("\n\t\t\t\t|______________________________________________|");
        printf("\n\t\t\t\t| [4] Print Product Details                   |");
        printf("\n\t\t\t\t|______________________________________________|");
        printf("\n\t\t\t\t| [5] Admin Menu                               |");
        printf("\n\t\t\t\t|______________________________________________|\n\n");
        printf("\t\t\t\t\t CHOOSE A NUMBER IN THE BOX ABOVE:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                print_products();
                remove_product();
                break;
            case 3:
                print_products();
                update_product();
                break;
            case 4:
                print_products();
                break;
            case 5:
                adminmenu();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

int client() {
    int choice;

    while (1) {
        printf("\n\t\t\t\t CUSTOMER MENU\n\t\t\t\t ______________________________________________");
        printf("\n\t\t\t\t| [1] Add Customer                             |");
        printf("\n\t\t\t\t| _____________________________________________|");
        printf("\n\t\t\t\t| [2] Remove Customer                          |");
        printf("\n\t\t\t\t|______________________________________________|");
        printf("\n\t\t\t\t| [3] Update Customer                          |");
        printf("\n\t\t\t\t|______________________________________________|");
        printf("\n\t\t\t\t| [4] Print Customer Details                   |");
        printf("\n\t\t\t\t|______________________________________________|");
        printf("\n\t\t\t\t| [5] Staff Menu                               |");
        printf("\n\t\t\t\t|______________________________________________|\n\n");
        printf("\t\t\t\t\t CHOOSE A NUMBER IN THE BOX ABOVE:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                removeCustomer();
                break;
            case 3:
                printCustomerDetails();
                updateCustomer();
                break;
            case 4:
                printCustomerDetails();
                break;
            case 5:
                staffmenu();
                break;
            default:
                printf("Invalid choice!\n");
                client();
        }
    }

    return 0;
}

int main(){
    printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      + WELCOME TO STORE INVENTORY MANAGEMENT SYSTEM +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    menuWindow();
}

