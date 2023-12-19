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
    char array[]= {"Hello world"}; 
    
    
        cout<<array<< endl;

    
    return 0;
}