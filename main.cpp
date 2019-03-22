/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: shane
 *
 * Created on March 21, 2019, 6:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "atm_header.h"

using namespace std;

int pin = 0;
int key = 1110;
int accountNum = 123456789;
int choice = 0;
float balance = 20.15;

/*
 * 
 */
int main(int argc, char** argv) {
    
    atmStartUp();
    
    return 0;
}

void atmStartUp(){   

  if(pin == 0){
    cout << "Enter your pin: ";
    cin >> pin;
  } 
    if (pin==key)
    {
    cout << "\nPin Approved!\n";
    } else{
    cout << "Pin not valid, try again!";
    pin = 0;
    atmStartUp();
  }  

    cout << "\n\t Welcome to the ATM! What would you like to do?";
    cout << "\n\t     1. Check Balance           ";
    cout << "\n\t     2. Withdraw                ";
    cout << "\n\t     3. Deposit                 ";
    cout << "\n\t     4. Exit                    ";
    cout << "\n\n";
    
    cout << "Enter option number: ";
    cin >> choice;
    
    switch (choice){
        
        case 1: 
            balanceCheck(accountNum);
            break;
        case 2:
            withdrawFromAccount(accountNum);
            break;
        case 3: 
            depositToAccount(accountNum);
            break;
        case 4:  
            cout << "Thanks for choosing our services, goodbye! ";
            cout << "\n";
            exit(0);
            break;
        default:
            cout << "Command not taken, please try again.\n";
            atmStartUp();        
            
    }
    
}
    
int balanceCheck(int account){
    
    //With Database access, would pull account information including balance
    cout << "Your Balance: " << balance;
    cout << "\nReturning to start screen!";
            
    
    atmStartUp();        
      
    return 0;
}

int withdrawFromAccount(int account){
    int withdrawAmount = 0;
    
    cout << "\n How much would you like to withdraw?(Enter 0 to leave) \n $";
    cin >> withdrawAmount;
    
    int balanceCheck = balance - withdrawAmount;
    
    if(withdrawAmount != 0 && balanceCheck >= 0 &&(withdrawAmount % 20 == 0 
            || withdrawAmount % 10 == 0 || withdrawAmount % 5 == 0)){
        dispenseMoney(withdrawAmount);
        balance -= withdrawAmount;
        cout << "You have successfully withdrawn $" << withdrawAmount 
                << " from your account!\n";
        
    } else if(withdrawAmount == 0){
        atmStartUp();
  
    } else {
        cout << "Amount not valid, lets try again!\n";
        withdrawFromAccount(account);
    }
    cout << "\nYour current account balance is: $" << balance;
    cout << "\n Returning to the start screen.";
    atmStartUp();
    return 0;
}

int depositToAccount(int account){
    float amount = 0;
    cout << "Please insert check. (For program testing, "
            "please enter amount to deposit)";
    cin >> amount;
    
    if(amount > 0){
        balance += amount;
        cout << "$" << amount << " Has been deposited to your account!\n";
        cout << "Return to start screen";
    } else {
        cout << "Check/Amount not valid, please try again!\n";
        amount = 0;
        depositToAccount(account);
    }
    atmStartUp();
    return 0;
}
    
    
void dispenseMoney(int amount){
    int denomination  = 0;
    int i = 0;
    cout << "What bills would you like to recieve? $5, $10, $20?\n";
    cin >> denomination;
/*    if(denomination != 5 || denomination != 10 || denomination != 20){
        cout << "invalid choice, try again!";
        dispenseMoney(amount);
    }*/
    
   if(denomination == 5 && (denomination/5) >= 1 && (amount/5) >= 1){
       while(i < (amount/denomination)){
           cout << "Dispensing $5\n";
           i++;
       }
   } else if(denomination == 10 && (denomination/10) >= 1&& (amount/10) >= 1){
       while(i < (amount/denomination)){
           cout << "Dispensing $10\n";
           i++;
       }
   } else if(denomination == 20 && (denomination/20) >= 1 && (amount/20) >= 1){
       while(i < (amount/denomination)){
           cout << "Dispensing $20\n";
           i++;
       }
   } else {
       cout << "Can't dispense in that amount, try again! \n";
       dispenseMoney(amount);
   }
    
}