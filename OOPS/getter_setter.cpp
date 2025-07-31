#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance; 

public:
    BankAccount() {
        balance = 0;
    }

    // Setter with validation
    //Use setters to update private data safely.
    void deposit(int amount) {
    if (amount >= 0) {
        balance = amount;
        } else {
        cout << "Invalid deposit amount!" << endl;
        }   
    }


    // Getter
    //Use getters to read/return private data.
    int getBalance() {
        return balance;
    }

    
};

int main() {
    BankAccount user;
    BankAccount user2;


    user.deposit(500); // valid
    user2.deposit(-100); // invalid

    cout << "Your balance: " << user.getBalance()<< endl;
    cout << "Your balance: " << user2.getBalance()<< endl;

    return 0;
}
