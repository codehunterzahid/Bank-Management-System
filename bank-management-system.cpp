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
    void deposit();
    void withdraw();


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

            case 2:
                Bank::deposit();
            break;

            case 3:
                Bank::withdraw();
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

    total++;
}

void Bank::deposit(){

    int cash;
    back:
    cout << "Enter ID : ";
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if(id == data[i].ID){
            cout << "Enter Amount : ";
            cin >> cash;
            if(cash < 500){
                cout << "Enter Amount Greater Than 500 : ";
                cin >> cash;
            }
        } else{
            cout << "Invalid ID Try again : " << endl;
            goto back;
        }


        data[i].cash+=cash;

    cout << "Amount Deposited" << endl;
    cout << "Your New Cash : " << data[i].cash << endl;
    }
}

void Bank::withdraw(){
    int cash;

    cout << "Enter ID : ";
    cin >> id;

    back:
    for (int i = 0; i < total; i++){
        if(id == data[i].ID){

            Amount:
            cout << "Enter Amount : ";
            cin >> cash;
            if(cash>data[i].cash){
                cout << "Insufficient Balance" << endl;
                goto Amount;
            } else if(cash < 500){
                cout << "Enter Amount Greater Than 500 : ";
                cin >> cash;
            } else if(cash > 25000){
                cout << "Enter Amount Less Than 25000 At 1 time : ";
                cin >> cash;
            } else{
                cout << "Withdraw Successfull" << endl;
            }
        } else{
            cout << "Invalid ID Try again : " << endl;
            goto back;
        }


        data[i].cash-=cash;

    cout << "Amount Withdrawn" << endl;
    cout << "Your New Cash : " << data[i].cash << endl;
    }

}
