#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <iostream>
#include <string>
using namespace std;

struct node {
    string National_ID;
    string Bank_National_ID;
    string Name_account;
    string Phone;
    string Passward;
    double Balance;
    node* next;
};

class BankingSystem {
private:
    int length;
    node* first, * temp, * cur;

    bool isfull();
    bool Search(string national_ID);
    void clearList();

public:
    BankingSystem();
    ~BankingSystem();

    void Create_Account(string national_ID, string name_account, string phone, string passward, string Bank_name_connacte_National_ID);
    void Delete_Account(string national_ID, string password);
    bool Deposit(string national_ID, string passward, double amount);
    bool WithDraw(string national_ID, string passward, double amount);
    bool Check_Account(string national_ID, string passward);
    void print();
    int count();
    
};

#endif