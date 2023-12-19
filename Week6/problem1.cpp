#include <iostream>
#include<sstream>
using std::cout;
using std::cin;
using std::string;
class Student{
public:
    string nameSt;
    int studentId;

    Student(string nameStu = "", int studentIdVal = 0): nameSt(nameStu),studentId(studentIdVal){
        cout<<"Student constructor\n";
    }
    ~ Student(){
        cout<<" Student  destructor";
    }
    virtual string toString(){
        std::stringstream sstr;

        sstr<<"name of the Student: "<<nameSt<<" "<<",ID: "<<studentId;
        return sstr.str();
    }
};
class Staff{
public:
    string nameSf;
    int staffId;

    Staff(string nameSta = "", int staffIdVal = 0):nameSf(nameSta),staffId(staffIdVal){
        cout<<"Staff constructor\n";
    }
    ~ Staff(){
        cout<<"Staff  destructor\n";
    }
    virtual string toString(){
        std::stringstream sstr;

        sstr<<nameSf<<"Name of Staff"<<" "<<", ID: "<<staffId;
        return sstr.str();
    }
};
class Tutor:public Student,public Staff{
public:
    Tutor(string nameStu = "", int StuId = 0, string nameStaff = "", int StaffiD=0):Student(nameStu,StuId), Staff(nameStaff,StaffiD){
        cout<<"Tutor constructor\n";
    }
    ~Tutor (){
        cout<<"\nTutor destructor\n";
    }
    void consultation(){
        cout<<"\nDoing consultation\n";
    }
    void showInfo(){
        cout<<"name of the Student: "<<Student::nameSt<<", ID: "<<Student::studentId <<"\n"<<"Name of Staff:"<<Staff::nameSf<<", ID: "<<Staff::staffId;
    }
    void setName(string nameVal){
        nameSt = nameVal;
    }
    string toString(){
        std::stringstream sstr;

        sstr<<"name of the Student: "<<Student::nameSt<<" "<<",ID: "<<Student::studentId <<"\n"<<Staff::nameSf<<"Name of Staff"<<" "<<", ID: "<<Staff::staffId;
        return sstr.str();
    }
};

void showInfoStu(Student &stu){
    stu.toString();
}
void showInfoSta(Staff &sta){
    sta.toString();
}
int main(){
    string name;
    Student stu("Hong", 234253);
    Staff sta("Hoang", 23832);
    Tutor Tutor1("Dat",215975,"Huy", 3932156); 
    Tutor1.showInfo();
    Tutor1.consultation();
    cout<<"Enter the new name: ";
    std::getline(cin>>std::ws, name);
    Tutor1.setName(name);
    Tutor1.showInfo();
    showInfoStu(stu);
    showInfoSta(sta);
    return 0;
}