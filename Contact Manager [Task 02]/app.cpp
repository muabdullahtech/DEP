#include <iostream>
#include <vector>
using namespace std;

class Contact
{
public:
    string name;
    long long phone_no;

    Contact()
    {
        name = "NONE";
        phone_no = 0;
    }
};

void menu();
void view_contacts(const vector<Contact> &contacts);
Contact add_contact();
bool del_contact(vector<Contact> &contacts);

int main()
{
    vector<Contact> contacts;
    int choice;

    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            view_contacts(contacts);
            break;
        case 2:
            contacts.push_back(add_contact());
            cout << endl;
            cout << "Contact Added Sucessfully" << endl;
            break;
        case 3:
            if (!del_contact(contacts))
            {
                cout << "Contact not found." << endl;
            }
            else
            {
                cout << "\n";
                cout << "           *                 *" << endl;
                cout << "********** * Contact Deleted * *********" << endl;
                cout << "           *                 *" << endl;
            }
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
}

void menu()
{
    cout << "\n";
    cout << "*************************************" << endl;
    cout << "*           Contact Manager         *" << endl;
    cout << "*************************************" << endl;
    cout << endl;
    cout << "1. View Contacts" << endl;
    cout << "2. Add a Contact" << endl;
    cout << "3. Delete a Contact" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}

void view_contacts(const vector<Contact> &contacts)
{
    if (contacts.empty())
    {
        system("cls");
        cout << endl;
        cout << "NO CONTACTS!!" << endl;
    }
    else
    {
        system("cls");
        cout << "\n";
        cout << "*************************************" << endl;
        cout << "*           Contact List            *" << endl;
        cout << "*************************************" << endl;
        for (const Contact &contact : contacts)
        {
            cout << endl;
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phone_no << endl;
        }
    }
}

Contact add_contact()
{
    system("cls");
    Contact tempContact;
    cout << "Enter the name: ";
    cin >> tempContact.name;
    cout << "Enter the Phone number: ";
    cin >> tempContact.phone_no;

    return tempContact;
}

bool del_contact(vector<Contact> &contacts)
{
    system("cls");
    long long trgt;
    cout << "Enter the number to be deleted: ";
    cin >> trgt;

    for (int i = contacts.size() - 1; i >= 0; --i)
    {
        if (contacts[i].phone_no == trgt)
        {
            contacts.erase(contacts.begin() + i);
            return true;
        }
    }
    return false;
}
