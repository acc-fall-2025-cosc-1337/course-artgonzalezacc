//bank_account.h
class BankAccount
{
    //variables and functions go here
public:
    BankAccount(){}//default constructor 
    BankAccount(int b) : balance(b) {/**empty class function code block */}
    int get_balance() { return balance; }

private:
    int balance; //default value is 0

};