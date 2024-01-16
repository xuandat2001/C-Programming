/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: UNG XUAN DAT
    ID: s3932156
    Compiler used: Compiler version (e.g. g++ 13.1.0, type "g++ --version" to check)
    Created  date: 13/01/2024 (e.g. 02/12/2023)
    Acknowledgement: List the resources that you use to complete this assessment (write 'None' if no extra resources are used).
*/
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::string;
int main(){
    string nameStu;
    int idStu;
    cout<<"Enter your name: ";
    std::getline(cin>>std::ws, nameStu);
    cout<<"Enter your ID: ";
    cin>>idStu;
    std::fstream stuFile;
    stuFile.open("Student.dat", std::ios::out);
    if(!stuFile){
        cout<<"Fail to open/create the file";
    }
    stuFile<<"Student Name: "<<nameStu<<"\n" <<"ID student: "<<idStu; // input to the file
    stuFile.close();
    cout<<"Your Information is saved";
    return 0;
}