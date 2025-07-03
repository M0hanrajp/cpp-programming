/* Learnings on access specifier through an example */
#include <iostream>
using namespace std;

class BankManager;

class Account {
    /* private: Only accessible inside the class that defines it.
     * Not even child (derived) classes can touch it directly.
     * Solution: You must expose access via public or protected methods.*/
    private:
        double balance;
    /* protected: Like private, hidden from outside code, but...
     * Derived classes can access it directly. */
    protected:
        int accountNumber;
    // Fully accessible from anywhere.
    public:
        void deposit(double amount) {
            if(amount >= 0)
                balance += amount;
            else
                cout << "Amount cannot be entered negative";
        }
        virtual bool withdraw(double amount) {
            if(amount > 0 && amount <= balance) {
                balance -= amount;
                return true;
            }
            return false;
        }
        // gets balance
        double getBalance(void) {
            return balance;
        }
        // get account number
        int getAccountNumber(void) {
            return accountNumber;
        }
        // set Balance
        void setBalance(int val) {
            balance = val;
        }
        // https://www.geeksforgeeks.org/cpp/friend-class-function-cpp/
        // https://en.cppreference.com/w/cpp/language/friend.html
        friend class BankManager;
};

class SavingsAccount : public Account {
    private:
        double interestRate;
    public:
        SavingsAccount(int an, double ib, double ir) {
            accountNumber = an;
            setBalance(ib);
            interestRate = ir;
        }
        void applyInterest(void) {
            deposit(getBalance() * interestRate);
        }
};

class BankManager {
public:
    void adjustBalance(Account &acct, double newBalance) {
        acct.balance = newBalance;  // direct access to private
    }
};

class CheckingAccount : public Account {
    private:
        double overdraftLimit;
    public:
        CheckingAccount(int an, double ib, double odl) {
            accountNumber = an;
            setBalance(ib);
            overdraftLimit = odl;
        }
        //  CheckingAccount should let its balance dip below zero, but only as far as your overdraft limit.
        bool withdraw(double amount) override {
            double newBalance = getBalance() - amount;
            if(amount > 0 && newBalance >= -overdraftLimit) {
                BankManager mgr;
                mgr.adjustBalance(*this, newBalance);
                return true;
            }
            return false;
        }
};

int main() {
    SavingsAccount sav(1001, 500.0, 0.03);
    CheckingAccount chk(2001, 100.0, 50.0);
    BankManager mgr;

    cout << "Saving initial balance: " << sav.getBalance() << "\n";
    sav.deposit(200);
    cout << "After deposit: " << sav.getBalance() << "\n";
    sav.applyInterest();
    cout << "After interest: " << sav.getBalance() << "\n\n";

    cout << "Checking initial balance: " << chk.getBalance() << "\n";
    chk.withdraw(120);  // uses overdraft
    cout << "After withdrawing 120: " << chk.getBalance() << "\n";
    bool ok = chk.withdraw(50);
    cout << "Withdraw 50 more: " << (ok ? "ok" : "denied")
         << ", balance=" << chk.getBalance() << "\n\n";

    // BankManager override
    mgr.adjustBalance(sav, 10000);
    cout << "Savings forcibly set to: " << sav.getBalance() << "\n";

    return 0;
}

/* My questions:

   a] Why use a friend class (BankManager) instead of a child?
   >>  all derived classes can modify balance directly. That might be dangerous 
       if you want to restrict changes to certain logic paths.
   >> Keep balance private and allow only trusted friend class (like BankManager) to touch it.

| Use Case                                                                 | Best Choice          |
| ------------------------------------------------------------------------ | -------------------- |
| You want total control, no one touches it without asking                 | `private` + `friend` |
| You want derived classes to be able to *build on* a value                | `protected`          |
| You want everyone to use it directly (getters/setters or even raw field) | `public`             |

    b] Why is accountNumber protected ?
    >> Prevents outside code (like main()) from accessing it directly
    >> Lets derived classes (like SavingsAccount, CheckingAccount) access it if they want to 
       print logs, validate ranges, or format statements using the account numbers.
    >> it's best to keep it private

| Concept     | How the Example Uses It                                                                |
| ----------- | -------------------------------------------------------------------------------------- |
| `private`   | `balance`, `overdraftLimit` are fully hidden, can’t be touched even by derived classes |
| `protected` | `accountNumber` can be used in child classes (optional for logic or display)           |
| `public`    | Methods like `deposit()`, `withdraw()` are safe interfaces for external code           |
| `friend`    | Used to bypass access (not the best in real apps unless needed)                        |
| override    | Ensures method truly overrides base virtual method (and catches bugs!)                 |
*/
