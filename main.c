/* Bus Reservation System and Snack Ordering System */

// Include all the required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bus information
struct Bus{
    int busNumber;
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
    float fare;
};

// Define a structure to store user login information
struct User{
    char username[50];
    char password[50];
};

// Define a structure to store snacks information
struct Snack{
    int snackId;
    char snackName[50];
    int snackPrice;
};

// Define a structure to store Admin information
struct Admin{
    char adminName[50];
    char password[50];
};

// Display main menu
void displayMainMenu(){
    printf("\n=== Main Menu ===\n");
    printf("1. User Login\n");
    printf("2. Admin Login\n");
    printf("3. Create User Account\n");
    printf("4. Create Admin Account\n");
    printf("5. EXIT\n");
    printf("Enter your choice: ");
}

// Display User menu
void displayUserMenu(){
    printf("\n=== User Menu ===\n");
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Ticket\n");
    printf("3. Check Bus Status\n");
    printf("4. Order Snacks\n");
    printf("5. Customer Support\n");
    printf("6. Available Buses\n");
    printf("7. Logout\n");
    printf("Enter your choice: ");
}

// Display Admin menu
void displayAdminMenu(){
    printf("\n=== Admin Menu ===\n");
    printf("1. Add Bus\n");
    printf("2. Delete Bus\n");
    printf("3. Add Snack\n");
    printf("4. Delete Snack\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to perform user login
int loginUser(struct User users[], int numUsers, char username[], char password[]){
    for (int i = 0; i < numUsers; i++){
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0){
            return i; // Return the index of the logged-in user
        }
    }
    return -1; // Return -1 if login fails
}

// Function to perform admin login
int loginAdmin(struct Admin admins[], int numAdmins, char adminName[], char password[]){
    for (int i = 0; i < numAdmins; i++){
        if (strcmp(admins[i].adminName, adminName) == 0 && strcmp(admins[i].password, password) == 0){
            return i; // Return the index of the logged-in Admin
        }
    }
    return -1; // Return -1 if login fails
}

// Function to book tickets
void bookTicket(struct Bus buses[], int numBuses){
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    // Find the bus with the given busNumber
    int busIndex = -1;
    for (int i = 0; i < numBuses; i++){
        if (buses[i].busNumber == busNumber){
            busIndex = i;
            break;
        }
    }

    if (busIndex == -1){
        printf("Bus with Bus Number %d not found.\n", busNumber);
    }
    else{
        printf("Enter Number of Seats: ");
        int seatsToBook;
        scanf("%d", &seatsToBook);

        if(seatsToBook<=0){
            printf("Enter Seats greater than 0");
        } else if (buses[busIndex].availableSeats < seatsToBook){
            printf("Sorry, only %d seats are available.\n", buses[busIndex].availableSeats);
        }
        else{
            buses[busIndex].availableSeats -= seatsToBook;
            printf("Total fare for %d seats = %.2f\n",seatsToBook,(seatsToBook*buses[busIndex].fare));
            printf("Booking successful! %d seats booked on Bus Number %d.\n", seatsToBook, busNumber);
        }
    }
}

// Function to cancel tickets
void cancelTicket(struct Bus buses[], int numBuses){
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    // Find the bus with the given busNumber
    int busIndex = -1;
    for (int i = 0; i < numBuses; i++){
        if (buses[i].busNumber == busNumber){
            busIndex = i;
            break;
        }
    }

    if (busIndex == -1){
        printf("Bus with Bus Number %d not found.\n", busNumber);
    }
    else{
        printf("Enter Number of Seats to Cancel: ");
        int seatsToCancel;
        scanf("%d", &seatsToCancel);

        if (seatsToCancel > (buses[busIndex].totalSeats - buses[busIndex].availableSeats)){
            printf("Error: You can't cancel more seats than were booked.\n");
        }
        else{
            buses[busIndex].availableSeats += seatsToCancel;
            printf("Cancellation successful! %d seats canceled on Bus Number %d.\n", seatsToCancel,
                   busNumber);
        }
    }
}

// Function to check bus status
void checkBusStatus(struct Bus buses[], int numBuses){
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    // Find the bus with the given busNumber
    int busIndex = -1;
    for (int i = 0; i < numBuses; i++){
        if (buses[i].busNumber == busNumber){
            busIndex = i;
            break;
        }
    }

    if (busIndex != -1){
        printf("\nBus Number: %d\n", buses[busIndex].busNumber);
        printf("Source: %s\n", buses[busIndex].source);
        printf("Destination: %s\n", buses[busIndex].destination);
        printf("Total Seats: %d\n", buses[busIndex].totalSeats);
        printf("Available Seats: %d\n", buses[busIndex].availableSeats);
        printf("Fare: %.2f\n", buses[busIndex].fare);
    }
    else{
        printf("Bus with Bus Number %d not found.\n", busNumber);
    }
}

// Function to display available snacks
void displaySnacks(struct Snack snacks[],int numSnacks){
    printf("\n============== Snacks Menu ==============\n");
    for(int i=0;i<numSnacks;i++){
        printf("%d.\t%s----> %d.Rs\n",snacks[i].snackId,snacks[i].snackName,snacks[i].snackPrice);
    }
    printf("100.\tEXIT\n");
}

// Function to buy snacks
void buySnacks(struct Snack snacks[],int numSnacks){
    int totalBill = 0;
    int snackChoice;

    while (1) {
        printf("\nEnter your choice (0-%d) or 100 to EXIT: ",numSnacks-1);
        scanf("%d", &snackChoice);

        if (snackChoice == 100) {
            if(totalBill>0){
                printf("\nYour total bill is: %d Rs\n", totalBill);
                printf("Thank you for your order!\n");
            }
            return;
        }

        if (snackChoice < 0 || snackChoice >= numSnacks) {
            printf("\nInvalid choice. Please select a valid snack.\n");
            continue;
        }

        int quantity;
        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        totalBill += snacks[snackChoice].snackPrice * quantity;
        printf("\nYou ordered %d x %s(s).\nCurrent total: %d Rs\n", quantity, snacks[snackChoice].snackName, totalBill);

        printf("\nOrder more or enter 10 to EXIT");
    }
}

// Function to display contact information of bus company
void displayContactInfo() {
    printf("\nContact Information:\n");
    printf("--------------------\n");
    printf("Phone Number (Main Office): 9348848383\n");
    printf("Alternate Contact: 9876543210\n");
    printf("Email ID: contact@company.com\n");
    printf("Customer Support Email: support@company.com\n");
    printf("Website: www.companybus.com\n\n");
}

// Function to add bus in the system
int addBus(struct Bus *buses,int numBuses){
    while(1){
        printf("\nEnter Bus Number: ");
        int bno;
            scanf("%d", &bno);

            int bnoExists = 0;
            for(int i = 0; i < numBuses; i++) {
                if(buses[i].busNumber == bno) {
                    printf("Bus Number already in use, choose another\n");
                    bnoExists = 1;
                    break;
                }
            }

            if(bnoExists) {
                continue;
            }
        
        buses[numBuses].busNumber = bno;

        getchar();

        printf("Enter Source: ");
        fgets(buses[numBuses].source, 50, stdin);
        buses[numBuses].source[strcspn(buses[numBuses].source, "\n")] = 0;

        printf("Enter Destination: ");
        fgets(buses[numBuses].destination, 50, stdin);
        buses[numBuses].destination[strcspn(buses[numBuses].destination, "\n")] = 0;

        printf("Enter Total Seats: ");
        scanf("%d", &buses[numBuses].totalSeats);
        buses[numBuses].availableSeats = buses[numBuses].totalSeats;

        printf("Enter Fare: ");
        scanf("%f", &buses[numBuses].fare);
        break;
    }
    numBuses++;
    return numBuses;
}

// Function to delete bus from the system
int deleteBus(struct Bus buses[], int numBuses) {
    printf("Enter the Bus Number to delete: ");
    int adchoice, index = -1;
    scanf("%d", &adchoice);

    for (int i = 0; i < numBuses; i++) {
        if (buses[i].busNumber == adchoice) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Bus number %d is not present and cannot be deleted.\n", adchoice);
        return numBuses;
    }

    for (int i = index; i < numBuses - 1; i++) {
        buses[i] = buses[i + 1];
    }

    printf("Bus with number %d successfully deleted.\n", adchoice);
    numBuses--;
    return numBuses;
}

// Function to add snack in the system
int AddSnack(struct Snack *snacks, int numSnacks) {
    while(1) {
        printf("\nEnter Snack ID: ");
        int snid;
        scanf("%d", &snid);

        int idExists = 0;
        for(int i = 0; i < numSnacks; i++) {
            if(snacks[i].snackId == snid) {
                printf("Snack ID already in use, choose another\n");
                idExists = 1;
                break;
            }
        }

        if(idExists) {
            continue;
        }

        snacks[numSnacks].snackId = snid;

        getchar();

        printf("Enter Snack Name: ");
        fgets(snacks[numSnacks].snackName, 50, stdin);
        snacks[numSnacks].snackName[strcspn(snacks[numSnacks].snackName, "\n")] = 0;

        printf("Enter Snack Price: ");
        int price;
        scanf("%d", &price);
        if (price<=0){
            printf("ERROR : Snack price should be greater than 0\n");
            continue;
        } else {
            snacks[numSnacks].snackPrice = price;
        }
        break;
    }
    numSnacks++;
    return numSnacks;
}

// Function to delete snack from the system
int deleteSnack(struct Snack snacks[],int numSnacks){
    printf("Enter the SnackID to delete snack: ");
    int adchoice, index = -1;
    scanf("%d", &adchoice);

    for (int i = 0; i < numSnacks; i++) {
        if (snacks[i].snackId == adchoice) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: SnackID %d is not present and cannot be deleted.\n", adchoice);
        return numSnacks;
    }

    for (int i = index; i < numSnacks - 1; i++) {
        snacks[i] = snacks[i + 1];
        snacks[i].snackId = snacks[i].snackId - 1;// when we delete then snackid of each snack id decremented
    }

    printf("Snack with SnackID %d successfully deleted.\n", adchoice);
    numSnacks--;
    return numSnacks;
}

// Function to create user account
int createUserAccount(struct User *users,int numUsers){
    getchar();

    printf("Enter User Name : ");
    fgets(users[numUsers].username, 50, stdin);
    users[numUsers].username[strcspn(users[numUsers].username, "\n")] = 0;

    printf("Enter Password : ");
    fgets(users[numUsers].password, 50, stdin);
    users[numUsers].password[strcspn(users[numUsers].password, "\n")] = 0;

    printf("\nUser Successfully Created\n");
    return numUsers+1;
}

// Function to create Admin account
int createAdminAccount(struct Admin *admins,int numAdmins){
    getchar();

    printf("Enter Admin Name : ");
    fgets(admins[numAdmins].adminName, 50, stdin);
    admins[numAdmins].adminName[strcspn(admins[numAdmins].adminName, "\n")] = 0;

    printf("Enter Password : ");
    fgets(admins[numAdmins].password, 50, stdin);
    admins[numAdmins].password[strcspn(admins[numAdmins].password, "\n")] = 0;
    printf("\nAdmin Successfully Created\n");
    return numAdmins+1;
}

// Function to display available buses at present
void displayAvailableBuses(struct Bus buses[], int numBuses) {
    printf("\nAvailable Buses:\n");
    for (int i = 0; i < numBuses; i++) {
        printf("Bus Number: %d, Source: %s, Destination: %s, Available Seats: %d\n", 
            buses[i].busNumber, buses[i].source, buses[i].destination, buses[i].availableSeats);
    }
}

// Function main(program execution starts from here) 
int main() {
    struct Bus buses[100] = {
        {101, "City A", "City B", 50, 50, 500.0},
        {102, "City C", "City D", 40, 40, 400.0},
        {103, "City E", "City F", 30, 30, 300.0}
    };
    int numBuses = 3; // Initialize with 3 buses and Store up to 100 buses

    struct Snack snacks[20] = {
        {0, "Tea", 10},
        {1, "Coffee", 20},
        {2, "Soft Drinks", 50},
        {3, "Instant Noodles", 100},
        {4, "Chips", 40},
        {5, "Cookies", 30},
        {6, "Sandwiches", 80},
        {7, "Chocolate", 20},
        {8, "Pastries", 30},
        {9, "Popcorn", 50}
    };

    int numSnacks = 10; // Initialize with 10 snacks and Store up to 20 snacks

    struct User users[100] = {
        {"user1", "pass1"},
        {"user2", "pass2"},
        {"user3", "pass3"}
    };

    int numUsers = 3; // Initialize with 3 users and Store up to 100 users

    struct Admin admins[100] = {
        {"admin1", "adminpass1"},
        {"admin2", "adminpass2"}
    };

    int numAdmins = 2; // Initialize with 2 admins and Store up to 100 admins

    int isRunning = 1;

    int loggedInUserIndex = -1;

    int loggedInAdminIndex = -1;

    while (isRunning) {
        displayMainMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // User login
                char username[50], password[50];
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                loggedInUserIndex = loginUser(users, numUsers, username, password);
                if (loggedInUserIndex != -1) {
                    printf("\nLogin successful!\n");
                    int userRunning = 1;
                    while (userRunning) {
                        displayUserMenu();
                        int userChoice;
                        scanf("%d", &userChoice);

                        switch (userChoice) {
                            case 1:
                                bookTicket(buses, numBuses);
                                break;
                            case 2:
                                cancelTicket(buses, numBuses);
                                break;
                            case 3:
                                checkBusStatus(buses, numBuses);
                                break;
                            case 4:
                                displaySnacks(snacks,numSnacks);
                                buySnacks(snacks,numSnacks);
                                break;
                            case 5:
                                displayContactInfo();
                                break;
                            case 6:
                                displayAvailableBuses(buses,numBuses);
                                break;
                            case 7:
                                userRunning = 0;
                                break;
                            default:
                                printf("\nInvalid choice. Try again.\n");
                                break;
                        }
                    }
                } else {
                    printf("\nInvalid username or password. Try again.\n");
                }
                break;
            }

            case 2: { // Admin login
                char adminName[50], password[50];
                printf("\nEnter admin name: ");
                scanf("%s", adminName);
                printf("Enter password: ");
                scanf("%s", password);

                loggedInAdminIndex = loginAdmin(admins, numAdmins, adminName, password);
                if (loggedInAdminIndex != -1) {
                    printf("\nAdmin login successful!\n");
                    int adminRunning = 1;
                    while (adminRunning) {
                        displayAdminMenu();
                        int adminChoice;
                        scanf("%d", &adminChoice);

                        switch (adminChoice) {
                            case 1:
                                if (numBuses >= 100) {
                                    printf("Cannot add more buses.\n");
                                } else {
                                    numBuses = addBus(buses,numBuses);
                                    printf("Bus added successfully!\n");
                                }
                                break;

                            case 2:
                                numBuses = deleteBus(buses,numBuses);
                                break;

                            case 3:
                                if (numSnacks >= 20) {
                                    printf("Cannot add more snacks.\n");
                                } else {
                                    numSnacks = AddSnack(snacks,numSnacks);
                                    printf("Snack added successfully!\n");
                                }
                                break;

                            case 4:
                                numSnacks = deleteSnack(snacks,numSnacks);
                                break;

                            case 5:
                                adminRunning = 0;
                                break;

                            default:
                                printf("\nInvalid choice. Try again.\n");
                                break;
                        }
                    }
                } else {
                    printf("\nInvalid admin name or password. Try again.\n");
                }
                break;
            }
            case 3:
                numUsers = createUserAccount(users,numUsers);
                break;

            case 4:
                numAdmins = createAdminAccount(admins,numAdmins);
                break;
            case 5: // Exit
                isRunning = 0;
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}
