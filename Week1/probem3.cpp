#include <iostream>
#include <cstring>
#define SIZE 100
using std::cin;
using std::cout;

void convertedString(char str[])
{
    cout << "Covert String: ";
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
        {
            // putchar(toupper(str[i]));
            str[i] = toupper(str[i]);
            cout << str[i];
        }
        else
        {
            // putchar(tolower(str[i]));
            str[i] = tolower(str[i]);
            cout << str[i];
        }
    }
}
int main()
{
    char str[SIZE];
    cout << "Enter the string: ";
    cin.getline(str, sizeof(str));
    convertedString(str);
    return 0;
}