#include <iostream>
#include <cmath>
using std::cout;
class ComplNum
{
private:
    double real;
    double ima;

public:
    ComplNum(double realNum = 0, double imaNum = 0)
    {
        this->real = realNum;
        this->ima = imaNum;
    };
    ComplNum operator-(ComplNum Comp2)
    {
        ComplNum temp;
        temp.real = this->real - Comp2.real;
        temp.ima = this->ima - Comp2.ima;
        return temp;
    };
    ComplNum operator-(double num)
    {
        ComplNum temp1;
        temp1.real = this->real - num;
        temp1.ima = this->ima;
        return temp1;
    }
    friend ComplNum operator-(double num, ComplNum Comp2);
    friend double AbsComplexNum(ComplNum num1);
    ComplNum operator--(int)
    {
        ComplNum result =   *this;
        (this->real)--;
        return result;
    }
    std::string toString()
    {
        return std::to_string(real) + "+" + std::to_string(ima) + "i";
    }
};
double AbsComplexNum(ComplNum num1){
    double result;
    result = sqrt((num1.real*num1.real)+(num1.ima * num1.ima));
    return result;
};

ComplNum operator-(double num, ComplNum Comp2)
{
    ComplNum temp2;
    temp2.real = num - Comp2.real;
    temp2.ima = Comp2.ima;
    return temp2;
}
int main()
{
    ComplNum Compl1(2, 3);
    ComplNum Compl2(1, 2);
    double num = 2;
    ComplNum result, result1, result2, result3;
    result = Compl1 - Compl2;
    cout << "Object - Object: \n"
         << result.toString();

    result1 = Compl2 - num;
    cout << "\n Object - Double: \n"
         << result1.toString();

    result2 = num - Compl1;
    cout << "\n Double - Object: \n"
         << result2.toString();

    result3 = Compl1--;
    cout << "\nPostfix : \n"
         << result3.toString();
    cout<<"\nThe absoute value is : " << AbsComplexNum(Compl1); 
    return 0;
}