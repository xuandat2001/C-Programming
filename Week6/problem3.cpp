#include<iostream>
using std::cout;
using std::cin;
using std::string;

class Book{
private:
    string *name;
    void men_request_for_name(){
        name = new(std::nothrow) string;
        if (!name){cout<<"Fail to request memory allocation";}
        
    }
    int price;
public:
    Book(string nameVal = "", int priceVal = 0){
        men_request_for_name();
        name = &nameVal;
        price = priceVal;
    }
    Book(const Book &oldBook){
        cout<<"Copy Constructor\n";
        men_request_for_name();
        name = oldBook.name;
    }
    Book &operator = (const Book &oldBook){
        cout<<"Assignment Operator";
        name = oldBook.name;
        return *this;
    }
};

int main(){
  Book book1("Huy", 123);
  Book book2("Dat", 234);
  Book book3 = book1;
  book1 = book2;
 }