#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
int main(){
    std::fstream myfile;
    string pwd;
    int choice;
    cout << "Password management program: \n"
                "1 : Save your password \n"
                "2 : Read your password \n"
                "Your choice: ";
    cin >> choice; 
    if (choice == 1)
    {
        myfile.open("pwd.dat",std::ios::out);
            if (!myfile)
            {
                cout<< "Fail to create/open file \n";
                return -1;
            }
        cout <<"Enter your password: ";
        cin.ignore(1,'\n');// ignore previous "\n"entered by user
        getline(cin,pwd);
        myfile << pwd;
        myfile.close();
        cout<<"Saved to the file  \n";
            
    }
    else {
        myfile.open("pwd.dat", std::ios::in);
            if (!myfile)
            {
                cout<<"Fail to open the file \n";
            }
       getline(myfile,pwd);
       myfile.close();
       cout<<"Read the password from the file "
       <<pwd<<"\n";     
    }
    return 0;
}