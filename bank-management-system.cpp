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
    void showDetails();
    void newAccount();
    void deposit();
    void withdraw();
    void checkBalance();
    void deleteAccount();
    void Exit();
};

// Main function is here
int main(){

    Bank b;
    b.choice();
    return 0;
}

// Function to clear screen for better user experience
void clearScreen() {
    cout << "\033[H\033[J";
}

// A main menu section where all options are given
void Bank::choice(){
    int ch;

    while(1){
        cout << "Welcome To Main Menu " << endl;
        cout << "--------------------" << endl;

        cout << "1. New Account " << endl;
        cout << "2. Show Details " << endl;
        cout << "3. Deposit Amount" << endl;
        cout << "4. Withdraw Amount" << endl;
        cout << "5. Balance Enquiry" << endl;
        cout << "6. Delete Account" << endl;
        cout << "7. Exit" << endl;

        Back:
        cout << "Enter Your Choice : ";
        cin >> ch;

        clearScreen();

        switch(ch){
            case 1:
                Bank::newAccount();
            break;

            case 2:
                Bank::showDetails();
            break;

            case 3:
                Bank::deposit();
            break;

            case 4:
                Bank::withdraw();
            break;

            case 5:
                Bank::checkBalance();
            break;

            case 6:
                Bank::deleteAccount();
            break;

            case 7:
                Bank::Exit();
            break;

            default:
                cout << "Invalid Choice" << endl;
                goto Back;
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

// Function for showing details of all the accounts
void Bank::showDetails(){
    idAgain:
    cout << "Enter Id : ";
    cin >> id;

    for(int i = 0; i < total; i++){
        if(id == data[i].ID){
            cout << "Name : " << data[i].name << endl;
            cout << "ID : " << data[i].ID << endl;
            cout << "Address : " << data[i].address << endl;
            cout << "Pin : " << data[i].pin << endl;
            cout << "Cash : " << data[i].cash << endl;
            cout << "Phone : " << data[i].phone << endl;
        } else{
            cout << "Invalid ID" << endl;
            goto idAgain;
        }
    }
}

void Bank::deposit(){

    int cash;
    idForDeposit:
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
            goto idForDeposit;
        }


        data[i].cash+=cash;

    cout << "Amount Deposited" << endl;
    cout << "Your New Cash : " << data[i].cash << endl;
    }
}

void Bank::withdraw(){
    int cash;

    again:
    cout << "Enter ID : ";
    cin >> id;

    for (int i = 0; i < total; i++){
        if(id == data[i].ID){

            Amount:
            cout << "Enter Amount : ";
            cin >> cash;
            if(cash>data[i].cash){
                cout << "Insufficient Balance" << endl;
                cout << data[i].cash << endl;
            } else if(cash < 500){
                cout << "Enter Amount Greater Than 500 : ";
                goto Amount;
            } else if(cash > 25000){
                cout << "Enter Amount Less Than 25000 At 1 time : ";
                goto Amount;
            } else{
                cout << "Withdraw Successfull" << endl;
            }
        } else{
            cout << "Invalid ID Try again : " << endl;
            goto again;
        }


        data[i].cash-=cash;

    cout << "Amount Withdrawn" << endl;
    cout << "Your New Cash : " << data[i].cash << endl;
    }

}

void Bank::checkBalance(){

    check:
    cout << "Enter ID : ";
    cin >> id; 

    for(int i = 0; i < total; i++){
        if(id == data[i].ID){
            cout << "Consumer Name :" << data[i].name << endl;
            cout << "Your Cash : " << data[i].cash << endl;
        } else{
            cout << "Invalid ID" << endl;
            goto check;
        }
    }
}

void Bank::deleteAccount(){

    cout << "Enter ID : ";
    cin >> id;

    for(int i=0; i < total; i++){
        if(id == data[i].ID){
            for(int j = i; j < total - 1; j++){
                data[j] = data[j+1];
            }
            total--;
            cout << "Account Deleted" << endl;
        } else{
            cout << "No Such Record Found : " << endl;
            break;
        }
    }
}


void Bank::Exit(){

    exit(0);
}