#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
#define SIZE 5;
class Student
{
public:
    string nameSt;
    int studentId;

    Student(string nameStu = "", int studentIdVal = 0) : nameSt(nameStu), studentId(studentIdVal)
    {
        // cout << "Student constructor\n";
    }
    // ~Student()
    // {
    //     cout << " Student  destructor";
    // }
    string toString()
    {
        std::stringstream sstr;
        sstr << "name: " << nameSt << ", "
             << "StudentId: " << studentId;
        return sstr.str();
    }
};

class SchoolSystem
{
private:
    std::vector<Student> stu{};

public:
    SchoolSystem() {}
    int checkStudent(int id)
    {
        for (int i = 0; i < stu.size(); i++)
        {
            if (stu[i].studentId == id)
            {
                return i;
            }
        }
        return -1;
    }
    bool addStudent()
    {
        string name;
        cout << "Enter the name of Student: ";
        std::getline(cin >> std::ws, name);
        int studentId;
        cout << "Enter the ID student that you wanna add";
        cin >> studentId;
        int position = checkStudent(studentId);
        if (position >= 0)
        {
            cout << "T  his student is already added";
            return false;
        }
        else
        {

            stu.push_back(Student(name, studentId));
            cout << "add student successfully\n";
            return false;
        }
    }
    bool removeStudent()
    {
        int studentId;
        cout << "Enter the ID student that you wanna remove";
        cin >> studentId;
        int position = checkStudent(studentId);
        if (position >= 0)
        {
            stu.erase(stu.begin() + position);
            cout << "Remove student successfully\n";
            return true;
        }
        else
        {
            cout << "Can not found ID student\n";
            return false;
        }
    }
    bool showStudent()
    {
        if (stu.size() == 0)
        {
            cout << "No student has not added yet\n";
            return false;
        }
        cout << "Show all students: \n";
        for (int i = 0; i < stu.size(); i++)
        {

            cout << "Name: " << stu[i].nameSt << ", ID: " << stu[i].studentId;
        }
        return true;
    }
    bool saveStudentData()
    {
        std::fstream stuFile;
        stuFile.open("Student.dat", std::ios::out);
        if (!stuFile)
        {
            cout << "Fail to create/open the file\n";
            return false;
        }
        for (Student student : stu)
        {
            stuFile << student.nameSt << ": " << student.studentId;
        }
        stuFile.close();
        return true;
    }
    bool reloadStudentData()
    {
        string nameString, idString;
        std::fstream stuFile;
        stuFile.open("Student.dat", std::ios::in);
        if (!stuFile)
        {
            cout << "Fail to create/open the file\n";
            return false;
        }
        while (1)
        {
            getline(stuFile, nameString, ':');
            getline(stuFile, idString);
            if (nameString == "" || idString == "")
            {
                break;
            }
            stu.push_back(Student(nameString, std::stod(idString)));
        }

        return true;
    }
};
int main()
{
    SchoolSystem sys;
    if (!sys.reloadStudentData())
    {
        cout << "Fail to load data";
    }

    while (1)
    {
        cout << "\nSchool Management System: \n"
                "1. View all students\n"
                "2.Add Student\n"
                "3.Remove Student\n"
                "4.Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            sys.showStudent();
        }
        else if (choice == 2)
        {
            sys.addStudent();
        }
        else if (choice == 3)
            sys.removeStudent();
        else if (choice == 4)
        {
            if (!sys.saveStudentData())
            {
                cout << "Fail to save data";
            }

            cout << "Have a good day";
            break;
        }
        else
        {
            cout << "Invalid value, Please enter again";
        }
    }

    return 0;
}
