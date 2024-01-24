#include<iostream>
#include<cstring>
#include <unistd.h>
using namespace std;

//structur for person to store data
    struct person{
        string name, ID, address,phone;
		double cash;
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
    void deleteAccount();
    void Exit();
};

// Main function is here
int main(){

    Bank b;
    b.choice();
    return 0;
}



// A main menu section where all options are given
void Bank::choice(){

    string username,password;
    username = "kali";
    password = "kali";
    
	    
	start:
		
		system("CLS");
	string usrn,pswd;

	cout<<"\n\n\t\tBank Accounts Management Portal"<<endl;

    cout<<  "\n\n\t\t|--------LOG IN--------|"<<endl;

	cout<<"\n\n\n\t\tEnter username: ";

	cin>>usrn;

	cout<<"\t\tEnter password: ";

	cin>>pswd;

	if(usrn==username&&pswd==password)

	{

        system("CLS");

    int ch;

    while(1){

        cout << "\nWelcome To Main Menu " << endl;
        cout << "--------------------" << endl;

        cout << "1. New Account " << endl;
        cout << "2. Show Details " << endl;
        cout << "3. Deposit Amount" << endl;
        cout << "4. Withdraw Amount" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Exit" << endl;

        Back:
        cout << "Enter Your Choice : ";
        cin >> ch;

        system("CLS");

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
                Bank::deleteAccount();
            break;

            case 6:
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

  	cout<<"\n\t\t\aInvalid username please try again";

  	sleep(3);

  	goto start;

  }

  else if(pswd!=password)

  {

  	cout<<"\n\t\t\aInvalid password please try again";

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

void Bank::newAccount() {
    cout << "Enter Data of Person " << total + 1 << endl;
    
    
    newId:
    cout << "\nEnter ID : ";
    cin >> data[total].ID;
    
    // check if id already exist
    for (int i = 0; i < total; i++) {
        if (data[total].ID == data[i].ID) {
            cout << "ID already exists. Please use different ID." << endl;
            goto newId;
            return;
        }
    }

    cout << "Enter Name : ";
    cin >> data[total].name;
    
    cout << "Enter Address : ";
    cin >> data[total].address;
    
    newPhone:
    cout << "Enter Phone : ";
    cin >> data[total].phone;
    
    // check if number < 11 digits
    if (data[total].phone.length() < 11) {
        cout << "Phone number must have 11 digits." << endl;
        goto newPhone;
        return;
    }
    
    
    cout << "Enter Cash : ";
    cin >> data[total].cash;

    total++;
    
    system("CLS");
}


// Function for showing details of all the accounts
void Bank::showDetails() {
	
    if (total == 0) {
        cout << "Create an account first.\n" << endl;
        return;
    }
    
    again:
    cout << "Enter Id : ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (id == data[i].ID) {
        	system("CLS");
        	cout << "Account details of Person " << total << endl;
        	cout << "\nID : " << data[i].ID << endl;
            cout << "Name : " << data[i].name << endl;
            cout << "Address : " << data[i].address << endl;
            cout << "Cash : " << data[i].cash << endl;
            cout << "Phone : " << data[i].phone << endl;
            return;
        }
    }

    cout << "Wrong ID, Try Again." << endl;
    goto again;
    
}


// Function for depositing amount
void Bank::deposit() {
    int cash;
    
    if (total == 0) {
        cout << "Create an account first.\n" << endl;
        return;
    }

    while (true) {
        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                cout << "Enter Amount B/W (500-2500): ";
                cin >> cash;
                if (cash < 500) {
                    cout << "Enter Amount Greater Than 500 : ";
                    cin >> cash;
                }

                data[i].cash += cash;

                cout << "Amount Deposited" << endl;
                cout << "Account Holder :" << data[i].name << endl;
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
    
    if (total == 0) {
        cout << "Create an account first.\n" << endl;
        return;
    }

    while (true) {
        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                Amount:
                cout << "Enter Amount B/W (500-25000): ";
                cin >> cash;
                if (cash > data[i].cash) {
                    cout << "Insufficient Balance" << endl;
                    cout << "Your Current Balance: " << data[i].cash << endl;
                    goto Amount;
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
                
                
                cout << "Account Holder :" << data[i].name << endl;
                cout << "Your New Cash : " << data[i].cash << endl;

                return;
            }
        }

        cout << "Invalid ID. Try again." << endl;
    }
}


// delete account

void Bank::deleteAccount() {
	
	if (total == 0) {
        cout << "Create an account first.\n" << endl;
        return;
    }
	
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
