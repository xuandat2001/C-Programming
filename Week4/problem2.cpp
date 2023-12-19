#include <iostream>
#include <sstream>
#include<fstream>
using std::cin;
using std::cout;
using std::string;
class BankAcc
{
public:
    string name;
    float amount;

    BankAcc(string nameAcc = "", float amountAcc = 0) : name(nameAcc), amount(amountAcc){};
    string toString()
    {
        std::stringstream sstr;
        sstr << "Bank Name: " << name << ", "
             << "Amount: " << amount << "\n";
             return sstr.str();
    }
    int withdraw(float num)
    {
        float remainMoney = 0;
        if (amount >= num)
        {
            remainMoney = amount - num;
            cout << "Withdraw successfully! Your account remains: " << remainMoney;
            return 1;
        }
        else
        {
            std::cerr << "Your account does not have enough money";
            return -1;
        }
    };
};
int main(int argc , char *argv[])
{
    BankAcc Acc1("VCB", 100000);
    if(argc !=2){
        return 0;
    }
    std::fstream file;
    file.open(argv[1], std::ios::out);
    if (!file)
    {
        std::cerr<<"Can open/create the file";
        return -1;
    }
    
    file << Acc1.toString();// save the data to the file
    cout<<"Wrote the data to the file "<<argv[1];
    
    Acc1.toString();
    float num;
    cout << "Enter the money that you want to widthdraw: ";
    cin >> num;
    Acc1.withdraw(num);

    return 0;
}