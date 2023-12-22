#include <iostream>
#include <istream>
using std::cin;
using std::cout;
using std::string;
class EWallet
{
public:
    string name;
    double balance;

    EWallet(string nameVal = "", double balanceVal = 0) : name(nameVal), balance(balanceVal) {}
    void showInfo()
    {
        cout << "\n"
             << name << ": " << balance;
    }
    bool pay(double amount, string coupon)
    {
        double remainMoney;

        if (coupon == "BLACKFRIDAY")
        {
            amount -= amount / 100 * 30;
        }
        remainMoney = balance - amount;
        if (remainMoney >= 0)
        {

            cout << "succesful payment";
            return true;
        }
        else
        {
            cout << "unsuccessfully, your account does not have enough money";
            return false;
        }
    }
};
EWallet &operator>>(double n, EWallet &obj)
{
    obj.balance = obj.balance + n;
    return obj;
}

class User
{
public:
    string name;
    string pwd;
    EWallet acc;

    User(string nameVal = "", string pwdVal = "", EWallet ewllet = EWallet()) : name(nameVal), pwd(pwdVal), acc(ewllet) {}

    bool verifyPass(string pwdUser)
    {
        if (pwdUser == pwd)
        {
            cout << "Correct Password";
            return true;
        }
        else
        {
            cout << "your password does not match";
            return false;
        }
    }
    bool doPayment(string userpwd)
    {
        double amount;
        string coupon;
        if (this->verifyPass(userpwd) == true)
        {
            cout << "\nEnter amount of money of product: ";
            cin >> amount;
            cout << "Enter your coupon: ";
            std::getline(cin >> std::ws, coupon);
            this->acc.pay(amount, coupon);
            return true;
        }
        else
        {
            cout << "\nIncorrect Password";
            return false;
        }
    }
    User &operator>>(User &userB){
        userB.acc.balance += this->acc.balance;
        return userB;
    }
        void showInfo()
    {
        cout << "\n"
             << name << ": "<<acc.balance;
    }
};

int main()
{
    string coupon, pwd;
    EWallet ewallet1("MOMO", 70000);
    EWallet ewallet2("Zalopay",100000);
    cout << "Enter your coupon: ";
    std::getline(cin >> std::ws, coupon);
    ewallet1.pay(100000, coupon);
    30000 >> ewallet1;
    cout << "\nAdd balance successfully";
    ewallet1.showInfo();

    User user("DAt", "xuandat", ewallet1);
    cout << "\nEnter your password: ";
    std::getline(cin >> std::ws, pwd);
    user.verifyPass(pwd);
    cout << "\n";
    user.doPayment(pwd);
    User user1("Quang Huy", "huy123",ewallet2 );
    user1>>user;
    cout<<"Transfer successfully";
    user.showInfo();
    return 0;
}