#include <iostream>
using std::cin;
using std::cout;
int Max(int arr[])
{
    int max = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value " << i + 1 << ":";
        cin >> arr[i];
    }
    cout << "The array is: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
    cout << "The maximum value is: " << Max(arr);
    return 0;
}