#include <iostream>
using std::cin;
using std::cout;
int MinEle(int arr[], int size)
{
    int min = arr[0];// assgin the first element of array
    for (int i = 0; i < size; i++) // compare elements
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
int main()
{
    // Input size for the array
    int SIZE_ARR;
    cout << "Enter the size of array: ";
    cin >> SIZE_ARR;

    // input the value
    int arr[SIZE_ARR];
    cout << "Enter the value: ";
    for (int i = 0; i < SIZE_ARR; i++)
    {

        cin >> arr[i];
    }

    cout << "The minimum value of array is: " << MinEle(arr, SIZE_ARR);
    return 0;
}