#include<iostream>
#include<string>
using namespace std;

#define MAX 1000 

// Address Book
// Defines the structure of the address book and the personnel information in the address book. 
// The address book can contain a maximum of 1000 persons

struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Address;

};

struct AddressBook
{
    
    struct Person personArray[MAX];
    int m_Size;
};

// Menu Interface

void showMenu() {
    cout << "***************************************"<< endl;
    cout << "*****     1. Add a new contact    *****"<< endl;
    cout << "*****     2. Display a contact    *****"<< endl;
    cout << "*****     3. Delete  a contact    *****"<< endl;
    cout << "*****     4. Search  a contact    *****"<< endl;
    cout << "*****     5. Modify  a contact    *****"<< endl;
    cout << "*****     6. Delete all contacts  *****"<< endl;
    cout << "*****   0. Exit the Address Book   *****"<< endl;
    cout << "****************************************"<< endl;
}

// Add a new contact
void addPerson(AddressBook* abs){
    if (abs->m_Size == MAX) {
        cout << "Contacts is full" << endl;
        return;
    }else {
        // New contact's name
        string name;
        cout << "Please enter the name: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // New contact's gender
        int sex = 0;
        cout << "Please enter the gender: " << endl;
        cout << "1 --- male" << endl;
        cout << "2 --- female" << endl;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout <<"Please enter again"<<endl;
        }

        // New contact's age
        int age;
        cout << "Please enter the age: " << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // New contact's phone number
        string phone;
        cout << "Please enter the phone number: " << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // New contact's address
        string address;
        cout << "Please enter the address: " << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_Address = address;

        // Updating the number of contacts
        abs->m_Size++;

        cout << "Complete!" << endl;

        system ("pause");
        system ("cls");
    }

}

// Displaying the contact
void showPerson (AddressBook* abs){
    //check size, if it is 0 which means the contacts is empty
    if(abs->m_Size<=0){
        cout << "The Address Bokk is empty" << endl;
    }else {
        for (int i=0; i < abs->m_Size; i++){
        cout << "Name：" << abs->personArray[i].m_Name << "\t";
        cout << "Gender：" << ((abs->personArray[i].m_Sex == 1) ? "Male" : "Female") << "\t";
        cout << "Age：" << abs->personArray[i].m_Age << "\t";
        cout << "Phone：" << abs->personArray[i].m_Phone << "\t";
        cout << "Address：" << abs->personArray[i].m_Address << endl;

        }
    }
    system("pause");
    system("cls");
}

//Check whether the contact exists
int isExist (AddressBook* abs, string name){
    for (int i=0; i< abs->m_Size; i++){
        if (abs->personArray[i].m_Name== name){
            return i;
        }
    }
    return -1;
}

//Delet contacts
void deletePerson(AddressBook* abs) {
    cout << "Please enter the name of the contact you want to delete：" << endl;
    string name;
    cin >> name;
 
    int ret = isExist(abs, name);
    if (ret != -1) {
        //find the contact, and delete
        for (int i = 0; i < abs->m_Size; i++) {
            //move the data forward
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;//upate the size
        cout << "Deletion complete!" << endl;
    }
    else {
        cout << "No such person!" << endl;
    }
 
    system("pause");
    system("cls");
}

//Search contacts
void selectPerson(AddressBook* abs) {
    cout << "Please enter the name of the contact you want to find：" << endl;
    string name;
    cin >> name;
 
    int ret = isExist(abs, name);
    if (ret != -1) {
        cout << "Name：" << abs->personArray[ret].m_Name << "\t";
        cout << "Gender：" << ((abs->personArray[ret].m_Sex == 1) ? "Male" : "Female") << "\t";
        cout << "Age：" << abs->personArray[ret].m_Age << "\t";
        cout << "Phone：" << abs->personArray[ret].m_Phone << "\t";
        cout << "Address：" << abs->personArray[ret].m_Address << endl;
    }
    else {
        cout << "No such person!" << endl;
    }
    system("pause");
    system("cls");
}

//Edit contacts
void editPerson(AddressBook* abs) {
    cout << "Please enter the name of the contact you want to edit：" << endl;
    string name;
    cin >> name;
 
    int ret = isExist(abs, name);
    if (ret != -1) {
        string name;
        cout << "Please enter the name：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
 
        
        int sex = 0;
        cout << "Please enter the gender：" << endl;
        cout << "1 --- male" << endl;
        cout << "2 --- female" << endl;
        while (true) {
            
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "Incorrect gender input, please re-enter!" << endl;
        }
 
        //Age
        int age;
        cout << "Please enter the age：" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;
        //Phone
        string phone;
        cout << "Please enter the phone number：" << endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        //住址
        string addres;
        cout << "Please enter the address：" << endl;
        cin >> addres;
        abs->personArray[ret].m_Address = addres;
        cout << "Edition complete！" << endl;
    }
    else {
        cout << "No such person！" << endl;
    }
    system("pause");
    system("cls");
}

//Delete all contacts
void cleanPerson(AddressBook* abs) {
    abs->m_Size = 0;
    cout << "Address book cleared！：" << endl;
    system("pause");
    system("cls");
}




int main() {
    AddressBook abs;
    abs.m_Size = 0;

    int select = 0;  // Variables entered by the user
    while (true) {
        showMenu();
        cin >> select;

        switch (select){
            case 1:
                addPerson(&abs);
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                deletePerson(&abs);
                break;
            case 4:
                selectPerson(&abs);
                break;
            case 5:
                editPerson(&abs);
                break;
            case 6:
                cleanPerson(&abs);
                break;
            case 0:
                cout << "Have a good day!" << endl;
                system("pause");
                return 0;
                break;

            default:
                break;
            
        }

    }
}

