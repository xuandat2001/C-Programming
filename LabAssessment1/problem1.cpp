/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 1
    Author: UNG XUAN DAT
    ID: 3932156
    Compiler used: 13.2.0
    Created  date:02/12/2023
    Acknowledgement:None
*/
#include <iostream>
using std::cin;
using std::cout;

void convertTime(int second)
{
    int resultHours, resultRemainMin, resultRemainSecond;
    resultHours = second / 3600;                                               // get hours
    resultRemainMin = (second % 3600) / 60;                                    // get mins
    resultRemainSecond = second - (resultHours * 3600 + resultRemainMin * 60); // get seconds
    cout << "It is " << resultHours << " hours(s), " << resultRemainMin << " minute(s), " << resultRemainSecond << "second(s).";
}
int main()
{
    int seconds;
    cout << "Input total amount of seconds: ";
    cin >> seconds;       // get the value from user
    convertTime(seconds); // call function
    ///Tao la Dat
    return 0;
}