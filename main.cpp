#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Account {
    string password;
    double balance;
};

map<string, Account> accounts;

void createAccount() {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    if (accounts.find(userId) != accounts.end()) {
        cout << "Account with this user id already exists!\n";
        return;
    }
    cout << "Please enter your password: ";
    cin >> password;
    accounts[userId] = {password, 0.0}; // Initialize account with 0 balance
    cout << "Thank You! Your account has been created!\n";
}

bool login(string &loggedInUser) {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    if (accounts.find(userId) != accounts.end() && accounts[userId].password == password) {
        loggedInUser = userId;
        cout << "Access Granted!\n";
        return true;
    } else {
        cout << "*** LOGIN FAILED! ***\n";
        return false;
    }
}

void depositMoney(string &userId) {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    accounts[userId].balance += amount;
    cout << "Deposit successful!\n";
}

void withdrawMoney(string &userId) {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;
    if (amount > accounts[userId].balance) {
        cout << "Insufficient funds!\n";
    } else {
        accounts[userId].balance -= amount;
        cout << "Withdrawal successful!\n";
    }
}

void requestBalance(string &userId) {
    cout << "Your balance is $" << accounts[userId].balance << ".\n";
}

int main() {
    char option;
    string loggedInUser;

    cout << "Hi! Welcome to the ATM Machine!\n";

    while (true) {
        cout << "Please select an option from the menu below:\n";
        cout << "1 -> Create New Account\n";
        cout << "2 -> Login\n";
        cout << "3 -> Quit\n";
        cout << "> ";
        cin >> option;

        if (option == '3') {
            cout << "Thank you for using the ATM Machine. Goodbye!\n";
            break;
        } else if (option == '1') {
            createAccount();
        } else if (option == '2') {
            if (login(loggedInUser)) {
                while (true) {
                    cout << "1 -> Withdraw Money\n";
                    cout << "2 -> Deposit Money\n";
                    cout << "3 -> Request Balance\n";
                    cout << "4 -> Quit\n";
                    cout << "> ";
                    cin >> option;

                    if (option == '4') {
                        cout << "Thank you! Goodbye!\n";
                        break;
                    } else if (option == '1') {
                        withdrawMoney(loggedInUser);
                    } else if (option == '2') {
                        depositMoney(loggedInUser);
                    } else if (option == '3') {
                        requestBalance(loggedInUser);

                    } else {
                        cout << "Invalid option! Please try again.\n";
                    }
                }
            }
        } else {
            cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
