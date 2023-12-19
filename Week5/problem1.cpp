#include<iostream>
using std::cout;
using std::cin;
using std::string;

class Book{
private:
    string name;
    int price;
public:
    Book(string nameVal = "", int priceVal = 0): name(nameVal), price(priceVal){}

    void showInfor(){
        cout<<"Name of the book: " << name <<", "<< "The price: "<<price;
    }
    void getName(string nameVal){ // get private name;
        this->name = nameVal;
    }
    void getPrice(int priceVal){
        this -> price = priceVal;
    }
    int setPrice(){return price;}

};

int main(){
    int size;
    Book *book1 = new (std::nothrow) Book("Harry Potter", 100);
    Book *book2 = new (std::nothrow) Book("Clean Code", 300);
    Book *book3 = new (std::nothrow) Book("Python", 100);
    
    if (book1 == nullptr||book2 == nullptr||book3 == nullptr)
    {
        std::cerr<<"Fail to create the memory alocation";
        return -1;
    }
    
    for (Book *book : {book1,book2,book3})
    {
        book->showInfor();
        cout<<"\n";
        delete book;    
    }
    cout<<"Enter the number: ";
    cin>>size;
    Book *bookArr = new Book[size];
    Book *MostExpBook = &bookArr[0];
   for (int i = 0; i < size; i++)
   {
        cout<<"Enter the name of book: " << i+1;
        string name;
        std::getline(cin>>std::ws,name);
        bookArr[i].getName(name);


        cout<<"Enter the price: ";
        int price;
        cin>> price;
        bookArr[i].getPrice(price);     
   }
   
    for (int i = 0; i < size; i++)
    {
        if (MostExpBook->setPrice() < bookArr[i].setPrice() )
        {
            MostExpBook = &bookArr[i];
        }
        
    }
    MostExpBook->showInfor();
    delete[] bookArr;   
    
   
   
    

    return 0;
}