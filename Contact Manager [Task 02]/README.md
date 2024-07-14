# Contact Manager

This is a simple Contact Manager application written in C++ that allows users to view, add, and delete contacts. The program uses a vector to store the contacts and provides a text-based menu for user interaction.

## Features

- **View Contacts**: Display all the contacts stored in the application.
- **Add a Contact**: Add a new contact with a name and phone number.
- **Delete a Contact**: Delete an existing contact by phone number.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++)

### Installation

1. Clone the repository or download the source code.

2. Compile the code using a C++ compiler:

    ```bash
    g++ -o contact_manager contact_manager.cpp
    ```

3. Run the compiled program:

    ```bash
    ./contact_manager
    ```

## Usage

When you run the program, a menu will be displayed with the following options:

1. View Contacts
2. Add a Contact
3. Delete a Contact
4. Exit

Enter the corresponding number to perform an action.

### Example

- **View Contacts**: Display all contacts. If no contacts are available, a message "NO CONTACTS!!" will be shown.

- **Add a Contact**: Enter the name and phone number when prompted. The contact will be added to the list.

- **Delete a Contact**: Enter the phone number of the contact you want to delete. If the contact is found, it will be deleted; otherwise, a message "Contact not found." will be displayed.

## Code Structure

- `Contact`: A class representing a contact with a name and phone number.
- `menu()`: Function to display the menu.
- `view_contacts(const vector<Contact>& contacts)`: Function to display all contacts.
- `add_contact()`: Function to add a new contact.
- `del_contact(vector<Contact>& contacts)`: Function to delete a contact by phone number.

## Author

- Muhammad Abdullah
