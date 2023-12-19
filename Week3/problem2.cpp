#include <iostream>
using std::cout;
using std::string;
class Student
{
private:
     int score;
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
    int getScore(){
        return score;
    }
};
int main()
{
    
    Student Stu[] = {Student("Dat", 100),
                     Student("Huy", 101),
                     Student("Lam", 102)};
    Student bestStu = Stu[0];
    for (int i = 0; i < 3; i++)
    {
        Stu[i].showInfor();
        cout<<"\n";
        if (bestStu.getScore() < Stu[i].getScore())
        {
            bestStu = Stu[i];
        }
    }
    cout << "\n THe student with the higgest score is: ";
    bestStu.showInfor();
    return 0;
}