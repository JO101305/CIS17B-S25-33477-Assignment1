#include <iostream>
using namespace std;

class BankAccount
{
private:
    string accountHolderName; // Stores the name of the account holder
    double balance; // Stores the balance amount in the account
    bool accountCreated; // Flag to check if an account has been created

public:
    BankAccount()
    {
        accountCreated = false; // Initially, no account is created
    }

    void createAccount(string name, double initialBalance)
    {
        if (initialBalance < 0)
        {
            throw invalid_argument("Initial balance cannot be negative.");
        }
        accountHolderName = name;
        balance = initialBalance;
        accountCreated = true;
        cout << "\nAccount created successfully!\n";
    }

    void deposit(double amount)
    {
        if (!accountCreated)
        {
            cout << "No account found! Create an account first.\n" << endl;
            return;
        }
        if (amount < 0)
        {
            throw invalid_argument("Deposit amount cannot be negative.");
        }
        balance += amount;
        cout << "Deposit successful! New balance: $" << balance << "\n" << endl;
    }

    void withdraw(double amount)
    {
        if (!accountCreated)
        {
            cout << "No account found! Create an account first.\n" << endl;
            return;
        }
        if (amount < 0)
        {
            throw invalid_argument("Withdrawal amount cannot be negative.");
        }
        if (amount > balance)
        {
            cout << "Insufficient funds!\n" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawal successful! New balance: $" << balance << "\n" << endl;
    }

    void displayBalance()
    {
        if (!accountCreated)
        {
            cout << "No account found! Create an account first.\n" << endl;
            return;
        }
        cout << "Current balance: $" << balance << "\n" << endl;
    }

    bool isAccountCreated()
    {
        return accountCreated;
    }
};

int main()
{
    BankAccount account;
    int choice;
    string name;
    double amount;
    
    cout << "Welcome to Simple Bank System" << endl;
    
    while (true)
    {
        // Display menu options based on whether an account exists
        if (!account.isAccountCreated())
        {
            cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Exit\n" << endl;
        }
        else
        {
            cout << "1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Exit\n" << endl;
        }
        
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                if (!account.isAccountCreated())
                {
                    // Creating a new account
                    cout << "Enter account holder name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter initial deposit: ";
                    cin >> amount;
                    try
                    {
                        account.createAccount(name, amount);
                    }
                    catch (exception& e)
                    {
                        cout << "Error: " << e.what() << "\n" << endl;
                    }
                }
                else
                {
                    // Depositing money if the account already exists
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    try
                    {
                        account.deposit(amount);
                    }
                    catch (exception& e)
                    {
                        cout << "Error: " << e.what() << "\n" << endl;
                    }
                }
                break;

            case 2:
                // Withdraw money from account
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                try
                {
                    account.withdraw(amount);
                }
                catch (exception& e)
                {
                    cout << "Error: " << e.what() << "\n" << endl;
                }
                break;

            case 3:
                // Display account balance
                account.displayBalance();
                break;

            case 4:
                // Exit the system
                cout << "Thank you for using Simple Bank System!\n" << endl;
                return 0;

            default:
                // Invalid menu choice
                cout << "Invalid choice! Please enter a number between 1 and 4.\n" << endl;
        }
    }
}