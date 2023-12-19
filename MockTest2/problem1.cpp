#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using std::cin;
using std::cout;
using std::string;
class retailShop
{
public:
    string name;
    int price;
    retailShop(string nameVal = "", int priceVal = 0)
    {
        this->name = nameVal;
        this->price = priceVal;
    }
    string toString()
    {
        std::stringstream sstr;
        sstr << name << ": "
             << price;
        return sstr.str();
    }
};
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error";
        return -1;
    }

    int numItem;

    cout << "Enter total number of items: ";
    cin >> numItem;
    retailShop product[numItem];
    char *str = argv[1];
    if (strcmp(str, "-w") == 0)
    {
        std::fstream myFile;
        myFile.open("sellingItem.dat", std::ios::out);
        if (!myFile)
        {
            std::cerr << "Fail to open/create the file";
            return -1;
        }
        for (int i = 0; i < numItem; i++)
        {
            cout << "Enter the name of the item " << i + 1 << ": ";
            std::getline(cin >> std::ws, product[i].name);
            myFile << product[i].name;
            myFile << ": ";
            cout << "Enter the price of the item " << i + 1 << ": ";
            cin >> product[i].price;
            myFile << product[i].price;
            myFile << "\n";
        }
        myFile.close();
    }
    else if (strcmp(str, "-r") == 0)
    {
        std::fstream myFile;
        myFile.open("sellingItem.dat", std::ios::in);
        if (!myFile)
        {
            std::cerr << "Fail to open/create the file";
            return -1;
        }
        for (int i = 0; i < numItem; i++)
        {
            std::getline(myFile, product[i].name, ':');
            myFile >> product[i].price;
            cout << product[i].name << ": " << product[i].price;
        }
        myFile.close();
    }
    else if (strcmp(str, "-s") == 0)
    {
        std::fstream myFile;
        myFile.open("sellingItem.dat", std::ios::in);
        if (!myFile)
        {
            std::cerr << "Fail to open/create the file";
            return -1;
        }
        
        for (int i = 0; i < numItem; i++)
        {
            std::getline(myFile, product[i].name, ':');
            myFile >> product[i].price;
        }
        myFile.close();
        retailShop smallestProduct = product[0];
        for (int i = 0; i < numItem; i++)
        {
             if (smallestProduct.price > product[i].price)
            {
                smallestProduct = product[i];
            }
        }
        cout<<"The smallest product: " <<smallestProduct.name<<": "<<smallestProduct.price;
        

    }
    else
    {
        std::cerr << "Invalid value";
        return -1;
    }
    return 0;
}