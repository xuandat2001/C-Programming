#include <iostream>
#include <sstream>
#include<iomanip>
#include <cstring>
using std::cin;
using std::cout;
#define INTERGERVAL 0
#define HEXAVAL 2
#define FLOATVAL 1

int doubleVal(int num)
{
    return num * 2;
}
double doubleVal(double num)
{
    return num * 2;
}
char doubleVal(char checkHexa[])
{
    int val;
    std::stringstream sstr;
    sstr << std::hex << checkHexa;
    sstr >> val;
    return val * 2;
}
int checkType(char str[])
{
    if (str[0] == '0' && tolower(str[1]) == 'x')
    {
        return HEXAVAL;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            return FLOATVAL;
        }
    }

    return INTERGERVAL;
}
int main(int argc, char *argv[])
{
    int type = checkType(argv[1]);
    if (type == HEXAVAL)
    {
        cout<<std::showbase<<std::hex<<doubleVal(argv[1]);
    }
    else if (type == FLOATVAL)
    {
        cout<<std::fixed<<std::setprecision(2)<<doubleVal(std::stod(argv[1]));
    }
    else
    {
        cout<<doubleVal(std::stod(argv[1]));
    }

    return 0;
}