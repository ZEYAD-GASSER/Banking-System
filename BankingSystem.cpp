#include <iostream>
#include <string>
#include <cctype>
#include "BankingSystem.h"

using namespace std;


bool BankingSystem ::  isfull()
    {
        node* test;
        try
        {
            test = new node;
            delete test;
            return false;
        }
        catch (bad_alloc exception)
        {
            return true;
        }
    }

    //to search is account found or no
bool BankingSystem::     Search(string national_ID)
    {
        cur = first;
        while (cur != NULL)
        {
            if (cur->National_ID == national_ID)
                return true;
            else
            {
                cur = cur->next;
            }
        }
        return false;
    }

    //to delet data banking system from memory after end life object
void BankingSystem::    clearList()
    {
        node* current;
        while (first != NULL)
        {
            current = first;
            first = first->next;
            delete current;
        }
        first = NULL;
        temp = NULL;
        cur = NULL;
        length = 0;

    }




    //constractor to initaltion length and first 
BankingSystem::BankingSystem() :length(0), first(NULL) {}

    //distractor
BankingSystem::  ~BankingSystem()
    {
        clearList();
    }

    //to create a new account in banking system 
void BankingSystem ::  Create_Account(string national_ID, string name_account,
        string phone, string passward,string Bank_name_connacte_National_ID)
    {
        if (Search(national_ID))
        {
            cout << "This account  already exists \n ";
        }
        else
        {
            if (isfull())
            {
                cout << "Sorry i cant allocate a new place in memmory besause it is full !!";
            }
            else
            {
                node* newnode = new node;

                newnode->National_ID = national_ID;
                newnode->Name_account = name_account;
                newnode->Bank_National_ID = Bank_name_connacte_National_ID +'-'+ national_ID;
                newnode->Phone = phone;
                newnode->Passward = passward;
                newnode->Balance = 0.0;
                newnode->next = first;

                first = newnode;
                cout << "## your account created successfully ## \n";
                length++;
            }
        }
    }

    //to delet account from banking system
void BankingSystem::     Delete_Account(string national_ID, string password)
    {
        if (first->National_ID == national_ID)
        {
            temp = first;
            first = first->next;
            length--;
        }
        else
        {
            cur = first;
            while (cur->next->National_ID != national_ID)
            {
                cur = cur->next;
            }
            temp = cur->next;
            cur->next = (cur->next)->next;
            length--;

        }
        if (temp->Passward == password)
        {
            delete temp;
            cout << "your account has been deleted successfully ## \n";
        }
        else
            cout << "This passward not valid \n";
    }

    //to search account and deposit money
bool  BankingSystem:: Deposit(string national_ID, string passward, double amount)

    {
        cur = first;
        while (cur != NULL)
        {
            if (cur->National_ID == national_ID)
            {
                if (cur->Passward == passward)//to check passward is correct is valied or no
                {
                    cur->Balance += amount;
                    cout << "The amount " << cur->Balance << " has been successfully deposited into your account\n";
                    return 1;
                }
                else
                {
                    cout << "This passward not valid \n";
                    return 0;//this passward not valid
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        cout << "this account is not found or you write the National_ID wrong\n";
        return 0;
    }

    //to search account and WithDraw money
bool BankingSystem::      WithDraw(string national_ID, string passward, double amount)
    {
        cur = first;
        while (cur != NULL)
        {
            if (cur->National_ID == national_ID)
            {
                if (cur->Passward == passward)//to check passward is correct is valied or no
                {
                    if (amount <= cur->Balance) {
                        cur->Balance -= amount;
                        cout << "The amount " << amount << " has been successfully  debited from your account\n";
                    }
                    else
                        cout << "you cant WithDraw  " << amount << " because You don't have enough money \n";
                    
                    return 1;
                }
                else
                {
                    cout << "This passward not valid \n";
                    return 0;//this passward not valid
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        cout << "this account is not found or you write the National_ID wrong\n";
        return 0;
    }


    //to search account and check balance
bool  BankingSystem::       Check_Account(string national_ID, string passward)

    {
        cur = first;
        while (cur != NULL)
        {
            if (cur->National_ID == national_ID)
            {
                if (cur->Passward == passward)//to check passward is correct is valied or no
                {
                    cout << "Your balance : " << cur->Balance << endl;
                    return 1;
                }
                else
                {
                    cout << "This passward not valid \n";
                    return 0;//this passward not valid
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        cout << "this account is not found or you write the National_ID wrong\n";
        return 0;
    }







    //to print all account in banking system
void BankingSystem::print()
    {
        node* p;
        p = first;

        while (p->next != NULL)
        {
            cout << p->National_ID << " ";
            cout << p->Bank_National_ID << " ";
            cout << p->Name_account << " ";
            cout << p->Passward << " ";
            cout << p->Phone << " ";
            cout << p->Balance << " ";
            cout << endl;
            p = p->next;
        }
        cout << p->National_ID << " ";
        cout << p->Bank_National_ID << " ";
        cout << p->Name_account << " ";
        cout << p->Passward << " ";
        cout << p->Phone << " ";
        cout << p->Balance << " ";
        cout << endl;



    

}


int BankingSystem::count()
{

    return length;

}
