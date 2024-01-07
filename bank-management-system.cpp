#include<iostream>
#include<cstring>
using namespace std;

//structur for person to store data
    struct person{
        string name, ID, address;
        int pin, cash,phone;
    };

// A Class is define for Bank 
class Bank{
    private:

    int total;
    string id;

    person data[10];


    public:

    Bank(){
        total = 0;
    };

    void choice();
    void newAccount();


};

// Main function is here
int main(){

    Bank b;
    b.choice();
    return 0;
}

// A main menu section where all options are given
void Bank::choice(){
    int ch;

    while(1){
        cout << "Welcome To Main Menu " << endl;
        cout << "--------------------" << endl;

        cout << "1. New Account " << endl;
        cout << "2. Deposit Amount" << endl;
        cout << "3. Withdraw Amount" << endl;
        cout << "4. Balance Enquiry" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter Your Choice : ";
        cin >> ch;


        switch(ch){
            case 1:
                Bank::newAccount();
            break;
        }

    }
}

// Function for new account Creation

void Bank::newAccount(){

    cout << "\nEnter Data of Person " << total + 1 << endl;

    cout << "Enter Name : ";
    cin >> data[total].name;
    cout << "Enter ID : ";
    cin >> data[total].ID;
    cout << "Enter Address : ";
    cin >> data[total].address;
    cout << "Enter Pin : ";
    cin >> data[total].pin;
    cout << "Enter Cash : ";
    cin >> data[total].cash;
    cout << "Enter Phone : ";
    cin >> data[total].phone;


}