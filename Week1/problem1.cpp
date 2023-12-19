#include <iostream>
using namespace std;
int linearEquation(int a, int b)
{
    if (a == 0)
    {
        if (b == 0)
        {
            cout << "There is infinite solution";
        }
        cout << "There is no solution";
    }
    cout << "The equation is: " << a << "x + " << b  <<"\n";
    float result = -b / a;
    return result;
}
int main()
{
    int a, b, result;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    result = linearEquation(a, b);
    cout << "The result is : " << result;
    return 0;
}