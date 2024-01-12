#include<iostream>
using std::cout;
using std::cin;
using std::string;
class Employee {
private:
    string nameEm;
    double salaryEm;
public:
    Employee(string nameEmVal = "", double salaryEmVal = 0):nameEm(nameEmVal),salaryEm(salaryEmVal){}
    void showInfo(){
        cout<<"Name of Employee: "<<nameEm<<"\n";
        cout<<"Salary of Employee: "<<salaryEm<<"\n";
    }
    double getSalary(){
        return salaryEm;
    }
    string getname(){
        return nameEm;
    }
    friend class Manager;
};
class Manager:public Employee{
private:
    double allowance;
public:
    Manager(string nameManagerVal = "", double salaryManagerVal = 0, double allowanceManager = 0): Employee(nameManagerVal,salaryManagerVal),allowance(allowanceManager){}
    void showInfo(){
        cout<<"Name of Manager: "<<Employee::nameEm<<"\n";
        cout<<"Salary of Manager: "<<Employee::salaryEm<<"\n";
        cout<<"Allowance of Manager: "<<allowance<<"\n";
    }
    friend double showTotalIncome(Manager &man);
};
double showTotalIncome(Manager &man){
    double totalIncome = man.getSalary() + man.allowance;
    return totalIncome;
}
int main(){

    double averageIncome = 0;
    double totalIncomeMans = 0;
    Employee em1("Dat",100000000.0);
    em1.showInfo();
    Manager Man1("Xuandat",2000,1000);
    Manager Man2("Quang Huy",5000,1000);
    Manager Man3("Lam",100040,1000);
    Manager Man4("Ly",100200,1000);
    Manager Man5("hang",100800,1000);
    Man1.showInfo();
    Manager *list_Manager = new Manager[5]{Man1,Man2,Man3,Man4,Man5};
    for(int i = 0; i < 5; i++){
        cout<<"Totol income of "<<list_Manager[i].getname()<<":"<<showTotalIncome(list_Manager[i])<<"\n";
        totalIncomeMans += showTotalIncome(list_Manager[i]);
    }
    cout<<"Avarage of their income is: "<<totalIncomeMans/5;
    return 0;
}