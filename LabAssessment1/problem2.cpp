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
#include <sstream>
#include<cstring>
using std::cout;
using std::string;
int checkHexaValue(char str[])
{
    int val1;
    if (str[0] == '0' && tolower(str[1]) == 'x') // get the prefix hexa
    {
        // conver from hexa to interger
        std::stringstream sstr;
        sstr << std::hex << str;
        sstr >> val1;
    }
    return 0;
}
int checkInterger(char str[])
{
    int val2;
    // conver from string to interger
    std::stringstream sstr;
    sstr<< str;
    sstr >> val2;
    return 0;
}
int main(int argc, char *argv[])
{   
    char *str = argv[2];
    int result = 0;
    if (checkHexaValue(argv[1]) == 0 && strcmp(str,"+") && checkInterger(argv[3])== 0) // first case hexa + int
    {
        result = checkHexaValue(argv[1]) + checkInterger(argv[3]);
    }
    else if(checkHexaValue(argv[1])== 0 && strcmp(str,"-") && checkInterger(argv[3])== 0){ //second case hexa - int
        result = checkHexaValue(argv[1]) - checkInterger(argv[3]);
        
    }else if (checkInterger(argv[1]) == 0 && strcmp(str,"+") && checkHexaValue(argv[3])== 0){ //third case int + hexa
        result = checkHexaValue(argv[1]) + checkInterger(argv[3]);
    }
    else if (checkInterger(argv[1]) == 0 && strcmp(str,"-") && checkHexaValue(argv[3])== 0)// forth case int -hexa
    {
         result = checkHexaValue(argv[1]) + checkInterger(argv[3]);
    }
    else{
        cout<<"Invalid"; // Enter worng;
    }
    
    cout<<"Result is: "<<result;
    return 0;
}