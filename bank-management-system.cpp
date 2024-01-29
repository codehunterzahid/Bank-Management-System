#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstring>
#include <unistd.h>
using namespace std;

//structur for person to store data
    struct person{
        string name, ID, address,phone,cnic;
		long int cash;
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
        
        loadBankData();
    };
    

    void choice();
    void showDetails();
    void newAccount();
    void deposit();
    void withdraw();
    void deleteAccount();
    void Exit();
    void saveBankData();
    void loadBankData();
    
};

// Main function is here
int main(){

    Bank b;
    b.choice();
    b.saveBankData();
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
    	
    	Back:
        cout << "\nWelcome To Main Menu " << endl;
        cout << "--------------------" << endl;

        cout << "1. Create New Account " << endl;
        cout << "2. Deposit Amount" << endl;
        cout << "3. Withdraw Amount" << endl;
        cout << "4. Show Account Details " << endl;
        cout << "5. Close Account" << endl;
        cout << "6. Exit" << endl;

        
        cout << "Enter Your Choice : ";
        cin >> ch;

        system("CLS");

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

            case 4:
                Bank::showDetails();
            break;

            case 5:
                Bank::deleteAccount();
            break;

            case 6:
            	cout << "Thanks for Choosing Us!"<< endl;
            	saveBankData();
                Bank::Exit();
            break;

            default:
                cout << "Invalid Choice. please Try again." << endl;
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
	
	data[total].cash = 0;
	
    cout << "Enter Data of Person " << total + 1 << endl;

    cout << "\nEnter Account ID : ";
    cin >> data[total].ID;

    // check if id already exists
    for (int i = 0; i < total; i++) {
        if (data[total].ID == data[i].ID) {
            cout << "Account already exist on this ID." << endl;
            return;
        }
    }

    cout << "Enter Account Hoder name : ";
    cin.ignore();
    getline(cin, data[total].name);

    cout << "Enter Address : ";
    cin >> data[total].address;

    newPhone:
    cout << "Enter 11-Digit Phone Number : ";
    cin >> data[total].phone;

    // check if number < 11 digits
    if (data[total].phone.length() != 11) {
        cout << "Invalid Phone Number. Please enter an 11-digit number." << endl;
        goto newPhone;
        return;
    }

    newCnic:
    cout << "Enter Your 13-Digit CNIC Number : ";
    cin >> data[total].cnic;

    // check if number < 11 digits
    if (data[total].cnic.length() != 13) {
        cout << "Invalid CNIC. Please enter a 13-digit CNIC." << endl;
        goto newCnic;
        return;
    }


    total++;
    
    cout << "\nCreating Account";
    
    for(int i = 1; i < 4; i++){
    	cout<<".";
    	sleep(1);
	}

    cout<<"\nAccount Created Successfuly";
    sleep(2);
    
    system("CLS");
}


// Function for showing details of all the accounts
void Bank::showDetails() {
    
    cout << "Enter Id : ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (id == data[i].ID) {
        	system("CLS");
        	cout << "Account details of Person " << total << endl;
        	cout << "\nAccount ID : " << data[i].ID << endl;
            cout << "Account Holder Name : " << data[i].name << endl;
            cout << "Phone : " << data[i].phone << endl;
            cout << "CNIC :" << data[i].cnic << endl;
            cout << "Address : " << data[i].address << endl;
            cout << "Current Balance : " << data[i].cash << endl;
            return;
        }
    }

    cout << "Account not found. Please enter a valid Account ID." << endl;
    
    
}


// Function for depositing amount
void Bank::deposit() {
    int cash;

        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
            	
            	newCash:
                cout << "Enter Deposit Amount (Rs 500 - Rs 25000): ";
                cin >> cash;
                if (cash < 500 || cash > 25000) {
                    goto newCash;
                }

                data[i].cash += cash;

                cout << "Amount Deposited Successful" << endl;
                cout << "Account Holder :" << data[i].name << endl;
                cout << "Your New Balance is : " << data[i].cash << endl;
                return;
            }
        }

        cout << "Account not found. Please enter a valid Account ID." << endl;
}

// Function for withdrawing amount
void Bank::withdraw() {
    int cash;
    

        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                Amount:
                cout << "Enter Withdrawal Amount Multiple of 500:(Rs 500 - Rs 25000) : ";
                cin >> cash;
                if (cash > data[i].cash) {
                    cout << "Insufficient Balance." << endl;
                    cout << "Your Current Balance is : " << data[i].cash << endl;
                    goto Amount;
                } else if (cash < 500 || cash > 25000 || cash % 500 !=0) {
                    goto Amount;
                } else {
                    cout << "Withdraw Amount Successfuly" << endl;
                }

                data[i].cash -= cash;
                
                
                cout << "Account Holder :" << data[i].name << endl;
                cout << "Your New Balance is : " << data[i].cash << endl;

                return;
            }
        }

        cout << "Account not found. Please enter a valid Account ID." << endl;
}


// delete account

void Bank::deleteAccount() {
	
	
        cout << "Enter ID : ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (id == data[i].ID) {
                for (int j = i; j < total - 1; j++) {
                    data[j] = data[j + 1];
                }
                total--;

                cout << "Account Closed successfuly" << endl;

                return;
            }
        }

        cout << "No Such Record Found. Try again." << endl;
}


void Bank::saveBankData() 
{
    ofstream file("bank_data.txt");
    if (file.is_open()) 
	{
        file << total << endl;
        for (int i = 0; i < total; i++) {
            file << data[i].name << "|" << data[i].ID << "|" << data[i].address << "|" << data[i].phone << "|" << data[i].cnic << "|" << data[i].cash << endl;
        }
        cout << "Data saved successfully." << endl;
    } else {
        cerr << "Unable to open file for saving bank data.\n";
    }
}


void Bank::loadBankData() 
{
    ifstream file("bank_data.txt");
    if (file.is_open()) 
	{
        file >> total;
        file.ignore();  // Move to the next line
        for (int i = 0; i < total; i++) 
		{
            getline(file, data[i].name, '|');
            getline(file, data[i].ID, '|');
            getline(file, data[i].address, '|');
            getline(file, data[i].phone, '|');
            getline(file, data[i].cnic, '|');
            file >> data[i].cash;
            file.ignore();  // Move to the next line
        }
        file.close();
    } else {
        cerr << "Unable to open file for loading bank data.\n";
    }
}

// exit function
void Bank::Exit(){

    exit(0);
}