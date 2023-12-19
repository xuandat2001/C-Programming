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
#include <cstring>
using std::cin;
using std::cout;
using std::string;
class Book
{
private:
    string title;
    int price;
    int availableCopies;
    string borrowerName[10];

public:
    Book(string titleValue = "", int priceVal = 0, int availableCopiesVal = 0, string borrowerNameVal[10] = nullptr)
    {
        this->title = titleValue;
        this->price = priceVal;
        this->availableCopies = availableCopiesVal;
        if (borrowerNameVal != nullptr)
        {
            for (int i = 0; i < 10; i++)
            {
                this->borrowerName[i] = borrowerNameVal[i];
            }
        }
    }
    bool borrow(string borrowerName)
    {
        string title;
        int price;
        int availableCopies;
        if (this->title == "" || this->price == NULL || this->availableCopies == NULL)
        {
            cout << "Can not borrow this book";
            return false;
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                borrowerName = borrowerName[i];
            }

            cout << "borrow successfully";
            return true;
        }
    }
    void returns(string borrowerName)
    {
        if (this->title, this->price, this->availableCopies)
        {
            for (int i = 0; i < 10; i++)
            {
                this->borrowerName[i] = "";
            }

            cout << "Return successfully";
        }
    }
};
int main()
{
    string borrowerName;

    cout << "Enter the your name: ";
    std::getline(cin >> std::ws, borrowerName);
    Book book1("Dat", 100, 2, borrowerName);

    return 0;
}