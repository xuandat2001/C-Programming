#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::string;
class Student
{
private:
    string name;
    int score[3];

public: // Constructor
    Student(string nameStu = "", int scoreStu[3] = nullptr)
    {
        this->name = nameStu;
        if (scoreStu != nullptr)
        {
            for (int i = 0; i < 3; i++)
            {
                this->score[i] = scoreStu[i];
            }
        }
    }

    void inputData() // Inputdata method
    {
        cout << "Enter the name of Student: ";
        getline(cin>>std::ws, name);
        cout << "Enter the score of Student ";
        for (int i = 0; i < 3; i++)
        {
            
            cin >> score[i];
        }
    }
    void showInfo() //Showinfo method
    {
        cout << "Name of Student: " << name << " ";
        cout << "Scores of student: ";
        for (int i = 0; i < 3; i++)
        {
            cout << score[i] << " ";
        }
        
    }

    double AvgScore(){ //avgscore method
        double num = 0, avg = 0; 
        for (int i = 0; i < 3; i++)
        {
            num += score[i];
        }
        avg = num / 3;
        return  avg;
    }
    string getName(){ //getname method
        return this->name;
    }
    bool operator > (Student stu){  //overload operator >
        return this->AvgScore() > stu.AvgScore() ? true : false;
    }
    friend Student operator + (int n , Student stu); // define overloaded operator + with friend keyword
    void formatName(std::string nameVal){ // convert to String to read the data
        this->name = nameVal;
    }
    void formatScore(std::string scoreVal){ //convert tot String to read the data
        std::stringstream sstr;
        sstr<<scoreVal;
        for (int i = 0; i < 3; i++)
        {
            sstr>>score[i];
        }
        
    }
};

Student operator + (int n , Student stu){ //Overloaded operator +
    Student result = stu;
    for (int i = 0; i < 3; i++)
    {
        result.score[i] += n;
    }
    return result;
    

}

std::istream &operator>>(std::istream &is, Student &stu){ //Overloaded operator >>
    stu.inputData();
    return is;
}
std::ostream &operator<<(std::ostream &os, Student &stu){//Overloaded operator <<
    stu.showInfo();
    return os;
}
int main()
{
    std::fstream myfile;

    Student stu1, stu2,result;
    stu1.inputData();
    stu1.showInfo();
    cout<<"\n";


    cin>> stu2;
    cout<<"The information of student2 : " << stu2;
    cout<<"\n";
    cout <<stu1.getName()<<" 1 has score " << ((stu1 > stu2) ? "higher" : "lower") << " than the average score of " <<stu2.getName();
    result = 10 + stu2;
    cout<<"\nStudent 3: "<< result;


    Student stu[10];
    myfile.open("data.txt", std::ios::in); //open the file
    if (!myfile)
    {
        std::cerr<<"Fail to open/create the file";
        return -1 ;
    }
    //Read information from the file
    for (int i = 0; i < 10; i++)
    {
        string tempString;
        std::getline(myfile, tempString, ',');
        stu[i].formatName(tempString);


        std::getline(myfile,tempString);
        stu[i].formatScore(tempString);
    }
    myfile.close();
    cout<<"\nAll information is read from the file";
    for (int i = 0; i < 10; i++)
    {
        stu[i].showInfo();
        cout<<"\n";
    }
    Student bestStu = stu[0]; // get the bestStudent
    for (int i = 0; i < 10; i++)
    {
        if (bestStu.AvgScore() < stu[i].AvgScore())
        {
            bestStu = stu[i];
        }
        
    }
    cout<<    "\nThe student with the highest avgscore is: "<<bestStu;
    
    

    

    return 0;
}
