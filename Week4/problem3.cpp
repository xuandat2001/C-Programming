#include <iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::string;
void reserveString(string str)
{
    for (int i = 0, j = (str.length()) - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    cout << "Reserve String: ";
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
};
void transformString(string str){
    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
        else{
            str[i] = tolower(str[i]); 
        }  
    }
    cout<<"Transform String : ";
    for (int i = 0; i < str.length(); i++)
    {
        cout<<str[i];
    }
    
    
};
int main()
{
    string str1, str2;
    cout << "Enter your  first string: ";
    std::getline(cin, str1);
    cout << "Enter your second string: ";
    std::getline(cin, str2);
    reserveString(str1);
    cout<<"\n";
    transformString(str2);
}
