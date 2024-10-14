# Bus Reservation System and Snack Ordering System

# Introduction
This project is a C-based console application that simulates a Bus Reservation System with an additional feature to order snacks for the journey. The system allows users to create accounts, book and cancel tickets, check bus status, order snacks, and access customer support. Admins have the ability to manage buses and snacks, including adding and removing them from the system.

# Table of Contents
- [Features](#features)
  - [User Features](#user-features)
  - [Admin Features](#admin-features)
- [Structures](#structures)
  - [Bus](#bus)
  - [User](#user)
  - [Snack](#snack)
  - [Admin](#admin)
- [How the Program Works](#how-the-program-works)
  - [Main Menu](#main-menu)
  - [User Menu](#user-menu)
  - [Admin Menu](#admin-menu)
  - [Snack Ordering](#snack-ordering)
- [How to Run](#how-to-run)
- [Sample Users and Admins](#sample-users-and-admins)
- [Limitations](#limitations)
- [Future Improvements](#future-improvements)
- [Execution](#execution)
  - [User Login Testing](#user-login-testing)
  - [Admin Login Testing](#admin-login-testing)
  - [Create User Account Testing](#create-user-account-testing)
  - [Create Admin Account Testing](#create-admin-account-testing)
  - [Exit Testing](#exit-testing)

# Features

# User Features
- **User Login**: Users can log in with their username and password.
- **Book a Ticket**: Users can book tickets for available buses.
- **Cancel a Ticket**: Users can cancel previously booked tickets.
- **Check Bus Status**: View bus details including available seats and fare.
- **Order Snacks**: Browse and order snacks, with the system calculating the total bill dynamically.
- **Customer Support**: Access contact information for customer assistance.
- **Available Buses**: View a list of available buses and their current seat availability.
- **Logout**: Users can log out and return to the main menu.

# Admin Features
- **Admin Login**: Admins can log in using admin credentials.
- **Add Bus**: Admins can add new buses to the system.
- **Delete Bus**: Admins can remove buses from the system.
- **Add Snack**: Admins can add new snacks to the system.
- **Delete Snack**: Admins can remove snacks from the system.
- **Exit Admin Mode**: Admins can return to the main menu.

# Structures

# Bus
Stores bus details:
- `busNumber`: The unique bus identifier.
- `source`: Starting point of the journey.
- `destination`: End point of the journey.
- `totalSeats`: Total number of seats in the bus.
- `availableSeats`: Number of seats still available.
- `fare`: Ticket price per seat.

# User
Stores user details:
- `username`: The username for login.
- `password`: The password for login.

# Snack
Stores snack details:
- `snackId`: Unique identifier for each snack.
- `snackName`: Name of the snack.
- `snackPrice`: Price of the snack, should always be greater than 0.

# Admin
Stores admin login information:
- `adminName`: Admin's username.
- `password`: Admin's password.

# How the Program Works

# Main Menu
From the Main Menu, users can:
- Log in as a User.
- Log in as an Admin.
- Create a new User account.
- Create a new Admin account.
- Exit the program.

# User Menu
Once logged in as a User, the user can:
- **Book a Ticket**: Select a bus, specify the number of seats to book, and view the calculated fare.
- **Cancel a Ticket**: Cancel seats from a previously booked bus.
- **Check Bus Status**: Check current bus status, including available seats and fare by entering the bus number.
- **Order Snacks**: Browse through the snack menu and place orders, with the total bill calculated at the end.
- **Customer Support**: View contact information for assistance.
- **Available Buses**: List all available buses and their seat availability.

# Admin Menu
Once logged in as an Admin, the admin can:
- **Add Bus**: Provide details such as bus number, source, destination, total seats, and fare to add a bus.
- **Delete Bus**: Remove a bus from the system by entering the bus number.
- **Add Snack**: Add new snacks with their respective name and price.
- **Delete Snack**: Remove snacks by entering their snack ID.

# Snack Ordering
Users can order multiple snacks in a single session, with the total bill calculated dynamically based on the items and their quantities.

# How to Run
1. Clone the repository.
2. Navigate to the project directory.
3. Compile the code using a C compiler.
4. Run the executable: `main.c`.

# Sample Users and Admins
The program comes pre-initialized with the following sample accounts:

# Sample Users:
1) username: user1, password: pass1
2) username: user2, password: pass2
3) username: user3, password: pass3

# Sample Admins:
1) adminName: admin1, password: adminpass1
2) adminName: admin2, password: adminpass2

You can create more users and admins through the system menus.

# Limitations:
1) The application is console-based, with no graphical user interface (GUI).
2) Data persistence is not implemented, meaning all data resets when the program closes.


# Future Improvements:
1) Implement file storage to retain data between sessions.
2) Add more robust input validation for security and usability.
3) Improve user messaging and prompts.
4) Develop a GUI to enhance user experience.
5) Enhance bus search functionality, including filters by date and time.

# Execution

# User Login Testing

=== Main Menu ===
1. User Login
2. Admin Login
3. Create User Account
4. Create Admin Account
5. EXIT

Enter your choice: 1

Enter username: user1

Enter password: pass1


Login successful!

=== User Menu ===
1. Book a Ticket
2. Cancel a Ticket
3. Check Bus Status
4. Order Snacks
5. Customer Support
6. Available Buses
7. Logout

Enter your choice: 1

Enter Bus Number: 101

Enter Number of Seats: 2

Total fare for 2 seats = 1000.00

Booking successful! 2 seats booked on Bus Number 101.


=== User Menu ===
1. Book a Ticket
2. Cancel a Ticket
3. Check Bus Status
4. Order Snacks
5. Customer Support
6. Available Buses
7. Logout

Enter your choice: 2

Enter Bus Number: 101

Enter Number of Seats to Cancel: 1

Cancellation successful! 1 seats canceled on Bus Number 101.


=== User Menu ===
1. Book a Ticket
2. Cancel a Ticket
3. Check Bus Status
4. Order Snacks
5. Customer Support
6. Available Buses
7. Logout

Enter your choice: 3

Enter Bus Number: 103

Bus Number: 103

Source: City E

Destination: City F

Total Seats: 30

Available Seats: 30

Fare: 300.00


=== User Menu ===
1. Book a Ticket
2. Cancel a Ticket
3. Check Bus Status
4. Order Snacks
5. Customer Support
6. Available Buses
7. Logout

Enter your choice: 4

============== Snacks Menu ==============

0.      Tea----> 10.Rs
1.      Coffee----> 20.Rs
2.      Soft Drinks----> 50.Rs
3.      Instant Noodles----> 100.Rs
4.      Chips----> 40.Rs
5.      Cookies----> 30.Rs
6.      Sandwiches----> 80.Rs
7.      Chocolate----> 20.Rs
8.      Pastries----> 30.Rs
9.      Popcorn----> 50.Rs
100.      EXIT--->

Enter your choice (0-9) or 100 to EXIT: 2

Enter Quantity: 2

You ordered 2 x Soft Drinks(s).

Current total: 100 Rs

Order more or enter 10 to EXIT

Enter your choice (0-9) or 100 to EXIT: 4

Enter Quantity: 2

You ordered 2 x Chips(s).

Current total: 180 Rs

Order more or enter 10 to EXIT

Enter your choice (0-9) or 100 to EXIT: 100

Your total bill is: 180 Rs

Thank you for your order!

=== User Menu ===
1. Book a Ticket
2. Cancel a Ticket
3. Check Bus Status
4. Order Snacks
5. Customer Support
6. Available Buses
7. Logout

Enter your choice: 5

Contact Information:
--------------------
Phone Number (Main Office): 9348848383

Alternate Contact: 9876543210

Email ID: contact@company.com

Customer Support Email: support@company.com

Website: www.companybus.com



=== User Menu ===
1. Book a Ticket
2. Cancel a Ticket
3. Check Bus Status
4. Order Snacks
5. Customer Support
6. Available Buses
7. Logout

Enter your choice: 6

Available Buses:

Bus Number: 101, Source: City A, Destination: City B, Available Seats: 49

Bus Number: 102, Source: City C, Destination: City D, Available Seats: 40

Bus Number: 103, Source: City E, Destination: City F, Available Seats: 30


=== User Menu ===
1. Book a Ticket
2. Cancel a Ticket
3. Check Bus Status
4. Order Snacks
5. Customer Support
6. Available Buses
7. Logout

Enter your choice: 7

# Admin Login Testing

=== Main Menu ===
1. User Login
2. Admin Login
3. Create User Account 
4. Create Admin Account
5. EXIT

Enter your choice: 2   

Enter admin name: admin1

Enter password: adminpass1


Admin login successful!

=== Admin Menu ===
1. Add Bus
2. Delete Bus
3. Add Snack
4. Delete Snack
5. Exit

Enter your choice: 1

Enter Bus Number: 104

Enter Source: City G

Enter Destination: City H

Enter Total Seats: 50

Enter Fare: 500

Bus added successfully!


=== Admin Menu ===
1. Add Bus
2. Delete Bus
3. Add Snack
4. Delete Snack
5. Exit

Enter your choice: 2

Enter the Bus Number to delete: 104

Bus with number 104 successfully deleted.


=== Admin Menu ===
1. Add Bus
2. Delete Bus
3. Add Snack
4. Delete Snack
5. Exit

Enter your choice: 3

Enter Snack ID: 10

Enter Snack Name: Burger

Enter Snack Price: 100

Snack added successfully!


=== Admin Menu ===
1. Add Bus
2. Delete Bus
3. Add Snack
4. Delete Snack
5. Exit

Enter your choice: 4

Enter the SnackID to delete snack: 10

Snack with SnackID 10 successfully deleted.


=== Admin Menu ===
1. Add Bus
2. Delete Bus
3. Add Snack
4. Delete Snack
5. Exit

Enter your choice: 5

# Create User Account Testing

=== Main Menu ===
1. User Login
2. Admin Login
3. Create User Account 
4. Create Admin Account
5. EXIT

Enter your choice: 3

Enter User Name : vishwajeet

Enter Password : pass123


User Successfully Created

=== Main Menu ===
1. User Login
2. Admin Login
3. Create User Account
4. Create Admin Account
5. EXIT

Enter your choice: 1

Enter username: vishwajeet

Enter password: pass123


Login successful!

# Create Admin Account Testing

=== Main Menu ===
1. User Login
2. Admin Login
3. Create User Account 
4. Create Admin Account
5. EXIT

Enter your choice: 4   

Enter Admin Name : admin4

Enter Password : adminpass4


Admin Successfully Created

=== Main Menu ===
1. User Login
2. Admin Login
3. Create User Account
4. Create Admin Account
5. EXIT

Enter your choice: 2

Enter admin name: admin4

Enter password: adminpass4


Admin login successful!

# Exit Testing

=== Main Menu ===
1. User Login
2. Admin Login
3. Create User Account 
4. Create Admin Account
5. EXIT

Enter your choice: 5   

Exiting program. Goodbye!
