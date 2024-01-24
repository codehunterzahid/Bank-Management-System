#include<iostream>
#include<cstring>
#include <unistd.h>
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
    // cout << "\033[H\033[J";
        #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}


// A main menu section where all options are given
void Bank::choice(){

    string username,password;
    cout<<"\n\n\t\tBank Management System"<<endl;

    cout << "\n\n\n\t\t|************************|"<<endl;
    cout<<  "\n\t\t|--------Register--------|"<<endl;
    cout << "\n\t\t|************************|"<<endl;

	cout<<"\n\t\tEnter new username: ";

	cin>>username;

	cout<<"\t\tEnter new password: ";

	cin>>password;

	cout<<"\t\tYour new id is creating please wait";

	for(int i=0;i<6;i++)

	{

		cout<<".";

		sleep(1);

	}

	cout<<"\n\t\tYour id created successfully";

	sleep(2);

	start:

	clearScreen();

	string usrn,pswd;

	cout<<"\n\n\t\tBank Management System"<<endl;

    cout << "\n\n\n\t\t|************************|"<<endl;
    cout<<  "\n\t\t|--------LOG IN--------|"<<endl;
    cout << "\n\t\t|************************|"<<endl;

	cout<<"\n\t\tEnter username: ";

	cin>>usrn;

	cout<<"\t\tEnter password: ";

	cin>>pswd;

	if(usrn==username&&pswd==password)

	{

        clearScreen();

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
else if(usrn!=username)

  {

  	cout<<"\t\t\aInvalid username please try again";

  	sleep(3);

  	goto start;

  }

  else if(pswd!=password)

  {

  	cout<<"\t\t\aInvalid password please try again";

  	sleep(3);

  	goto start;

  }

  else{

  	cout<<"\t\t\aInvalid username and password";

  	sleep(3);

  	goto start;

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
            return;
        }
    }
    cout << "Check Your ID or Create Account First" << endl;
    return;
}

// Function for depositing amount
void Bank::deposit() {
    int cash;

    while (true) {
        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                cout << "Enter Amount : ";
                cin >> cash;
                if (cash < 500) {
                    cout << "Enter Amount Greater Than 500 : ";
                    cin >> cash;
                }

                data[i].cash += cash;

                cout << "Amount Deposited" << endl;
                cout << "Your New Cash : " << data[i].cash << endl;
                return;
            }
        }

        cout << "Invalid ID. Try again." << endl;
    }
}

// Function for withdrawing amount
void Bank::withdraw() {
    int cash;

    while (true) {
        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                Amount:
                cout << "Enter Amount : ";
                cin >> cash;
                if (cash > data[i].cash) {
                    cout << "Insufficient Balance" << endl;
                    cout << "Your Current Balance: " << data[i].cash << endl;
                } else if (cash < 500) {
                    cout << "Enter Amount Greater Than 500 : ";
                    goto Amount;
                } else if (cash > 25000) {
                    cout << "Enter Amount Less Than 25000 At 1 time : ";
                    goto Amount;
                } else {
                    cout << "Withdraw Successful" << endl;
                }

                data[i].cash -= cash;

                cout << "Amount Withdrawn" << endl;
                cout << "Your New Cash : " << data[i].cash << endl;

                return;
            }
        }

        cout << "Invalid ID. Try again." << endl;
    }
}

// check balance function
void Bank::checkBalance() {
    while (true) {
        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                cout << "Consumer Name: " << data[i].name << endl;
                cout << "Your Cash : " << data[i].cash << endl;

                return;
            }
        }

        cout << "Invalid ID. Try again." << endl;
    }
}

// delete account
void Bank::deleteAccount() {
    while (true) {
        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                for (int j = i; j < total - 1; j++) {
                    data[j] = data[j + 1];
                }
                total--;

                cout << "Account Deleted" << endl;

                return;
            }
        }

        cout << "No Such Record Found. Try again." << endl;
    }
}

// exit function
void Bank::Exit(){

    exit(0);
}