#include "BankingSystem.h"
#include <iostream>
#include <string>
#include <cctype>
int main() {
    cout << "                     --> Welcome to banking system <--\n\n";
    cout << "Please enter banking name: ";
    string Bank_name;
    cin >> Bank_name;

    BankingSystem obj;
    int chose = -1;

    do {
        cout << endl
            << " -----> Choose what you want <-----" << endl << endl
            << "1- Create account\n"
            << "2- Delete account\n"
            << "3- Deposit\n"
            << "4- Withdraw\n"
            << "5- Check account balance\n"
            <<"6-count the number of accounts\n "
            <<"0- Exit\n";
        cout << endl;
        cout << " -> REMEMBER <- if you enter char or string, the program will stop and finish !!\n\n";
        cout << "Enter your choice: ";
        cin >> chose;
        cout << endl;

        switch (chose) {
        case 1: {
            string national_ID, name_account, phone, password;
            cout << "Please enter your National ID (14 digits): ";
            cin >> national_ID;

            if (national_ID.size() != 14) {
                cout << "Invalid National ID\n";
                break;
            }
            else {
                cout << "name_account: ";
                cin.ignore();
                getline(cin, name_account);

                cout << "phone: ";
                cin >> phone;
                cin.ignore();

                cout << "password: ";
                cin >> password;
                cout << endl;
            }

            obj.Create_Account(national_ID, name_account, phone, password, Bank_name);
            break;
        }
        case 2: {
            string national_ID, password;
            cout << "To delete an account, enter your National ID and password: \n"
                << "National ID: ";
            cin >> national_ID;
            cout << "Password: ";
            cin >> password;

            obj.Delete_Account(national_ID, password);
            break;
        }
        case 3: {
            string national_ID, password;
            double amount;
            cout << "To deposit, enter your National ID, password, and amount: \n"
                << "National ID: ";
            cin >> national_ID;
            cout << "Password: ";
            cin >> password;
            cout << "Amount: ";
            cin >> amount;

            obj.Deposit(national_ID, password, amount);
            break;
        }
        case 4: {
            string national_ID, password;
            double amount;
            cout << "To withdraw, enter your National ID, password, and amount: \n"
                << "National ID: ";
            cin >> national_ID;
            cout << "Password: ";
            cin >> password;
            cout << "Amount: ";
            cin >> amount;

            obj.WithDraw(national_ID, password, amount);
            break;
        }
        case 5:
        {
            string national_ID, password;
            cout << "To check account balance, enter your National ID and password: \n"
                << "National ID: ";
            cin >> national_ID;
            cout << "Password: ";
            cin >> password;

            //  code for checking account balance
            obj.Check_Account(national_ID, password);
            break;
        }
        case 6:
        {
            cout << "you have "<< obj.count() <<" accounts";
          

            break;

        }
        case 0:
            break;

        default:
            cout << "please enter valied choose !!\n";
        }



    } while (chose != 0);
    return 0;
}

