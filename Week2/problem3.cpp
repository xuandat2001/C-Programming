#include<iostream>
#include<iomanip>
#define STRSIZE 100
using std::cin;
using std::cout;
int main(){
    char str[STRSIZE];
    cout <<"Enter the string: ";
    cin.getline(str,sizeof(str));// Read a string with spaces
    //print out characters
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout <<str[i]<<" ";
    }
    cout<<"\n\n";

    cout<<std::setw(9) <<std::setfill('0')<<1.234<<"\n\n";
    cout<<std::setprecision(2)<<1.234<<"\n\n";
    return 0;
}
