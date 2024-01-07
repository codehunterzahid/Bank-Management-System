#include <iostream>

using namespace std;
// To store Person data
class BankAccount 
{
private:
    string accountNumber;
    string accountHolderName;
    float balance;

public:
    BankAccount() 
	{
        balance = 0.0;
    }
    
// Function for Creating Account
    void createAccount() 
	{
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);
        cout << "Account Created Successfully!" << endl;
    }

//Function Fro Depositing
    void deposit()
	{
        float amount;
        cout << "Enter Deposit Amount: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit Successful. Your New Balance is : Rs " << balance << endl;
    }

//Function For withdraw
    void withdraw() 
	{
        float amount;
        cout << "Enter Withdrawal Amount:(Rs 500 - Rs 25000) :";
        cin >> amount;
        if (amount >= 500 && amount <= 25000 && amount <= balance) 
		{
            balance -= amount;
            cout << "Withdrawal Successful. Your New Balance is: Rs " << balance << endl;
        } else {
            cout << "Invalid Withdrawal Amount or Insufficient Balance." << endl;
        }
    }

//Finction for close account
    void closeAccount() 
	{
        accountNumber = "";
        accountHolderName = "";
        balance = 0.0;
        cout << "Account Closed Successfully!" << endl;
    }

//Function for balance Inquiry
    void balanceInquiry() 
	{
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs " << balance << endl;
    }
};

// Main Body

int main()
{
//Header
	cout<<"\t\t\tWelcome To Ripha's Bank"<<endl;
	cout<<"\t\t\t:::::::::::::::::::::::"<<endl;

// Choice Declare for switch
	int choice;
    BankAccount account;

    do 
	{
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Balance Inquiry\n";
        cout << "5. Close Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                account.createAccount();
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.balanceInquiry();
               break;
        	case 5:
                account.closeAccount();
                break;
		    case 6:
                cout << "Thanks for Choosing us!!" << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } 
	while (true);

    return 0;
}

