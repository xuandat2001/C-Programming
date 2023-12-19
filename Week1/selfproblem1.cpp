#include <iostream>
using std::cin;
using std::cout;
int reveseInterger(int num)
{
    int revNum = 0;
    while (num > 0)
    {
        revNum = revNum * 10 + num % 10;
        num = num / 10;
    }
    return revNum;
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Reverse Digits: " << reveseInterger(num);
    return 0;
}