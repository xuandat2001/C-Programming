#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
class Student
{
private:
    int score;
    string password;

public:
    string name;

    Student(string nameStu, int scoreStu)
    {
        name = nameStu;
        score = scoreStu;
    }
    void showInfor()
    {
        cout << "Name: " << name << ", "
             << "Score: " << score;
    }
    int getScore()
    {
        return score;
    }
    void changePassword()
    {
        std::fstream myfile;
        // check if there is an existing password
        myfile.open(name + ".dat", std::ios::in);
        if (myfile)
        {
            std::getline(myfile, password);
        }
        myfile.close();
        if (password == "")
        {

            cout << "No existing password. Plesa set your password now: ";
        }
        else
        {
            cout << "Please enter your password: ";
            string in_pwd;
            std::getline(cin >> std::ws, in_pwd);
            if (in_pwd == password)
            {
                cout << "Correct! Now set your new password: ";
            }
            else
            {
                std::cerr << "Incorrect Password";
                return;
            }
        }
        std::getline(cin >> std::ws, password);
        myfile.open(name + ".dat", std::ios :: out);
        myfile << password;
        myfile.close();
    }
};
int main()
{
    Student Stu("Dat", 100);
    Stu.changePassword();

    return 0;
}