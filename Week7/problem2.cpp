#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::string;
class Department;
class Staff{
private:    
    string name;
    string depName;
public:
    Staff(string nameVal="",string depNameVal=""):name(nameVal),depName(depNameVal){}
    void joinDept(Department &dp); 
    void leaveDept(Department &dp);
    void showInfo(){
        cout<<name<<" ,"<<depName;
    }
    friend class Department;
};
class Department{
private: 
    string name;
    string location;
    std::vector<Staff*>staffs;
public:
    Department(string nameval= "", string locationVal = "", std::vector<Staff*>staffVal={}):name(nameval), location(locationVal), staffs(staffVal){}
    void showInfo(){
        cout<<"Name of Department: "<< name
            <<"\n Location of Department: "<<location
            <<"\n Lis of Staff: \n";
        for (Staff* eachStaff: staffs)
        {
            eachStaff->showInfo();
        }
        
    }
friend class Staff;
};

void Staff::joinDept(Department &dp){
    dp.staffs.push_back(this);
    depName = dp.name;
}
void Staff::leaveDept(Department &dp){
    for (int i = 0; i < dp.staffs.size(); i++)
    {
        if (dp.staffs[i] == this)
        {
            dp.staffs[i].erase(dp.staffs.begin() + i );
        }
        depName = "";
    }
}


class AcadDept:public Department{
private:
    int numOfCourses;
public:
    AcadDept(int numOfCoursesVal = 0, string nameval= "", string locationVal = "", std::vector<Staff*>staffVal={}): numOfCourses(numOfCoursesVal), Department(nameval,locationVal,staffVal){}
    void showInfo(){
        Department::showInfo();
        cout<<"Number of Course: "<<numOfCourses;
    }
};


class NonAcadDept:public Department{
private:
    int numOfServices;
public:
    NonAcadDept(int numOfServicesVal = 0, string nameval= "", string locationVal = "", std::vector<Staff*>staffVal={}): numOfServices(numOfServicesVal), Department(nameval,locationVal,staffVal){}
    void showInfo(){
        Department::showInfo();
        cout<<"Number of Services: "<<numOfServices;
    }
};








int main(){
    Staff st1("Dat","");
    Staff st2("Huy","");
    Staff st3("Huy","");
    AcadDept dept1(1,"Lab","Bulding1", {});
    NonAcadDept dept2(2,"Sport Hall","Bulding8", {});
    st3.joinDept(dept1);
    st1.joinDept(dept2);
    st2.joinDept(dept2);
    dept1.showInfo();
    dept2.showInfo();
    return 0;
}