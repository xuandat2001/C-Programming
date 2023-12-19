#include <iostream>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::string;

class Book
{
private:
    string title;
    int availableCopies;
    std::vector<string> nameOfBorrowers;

public:
    Book(string titleBook = "", int availableCopiesVal = 0, std::vector<string> nameOfBorrowersVal = std::vector<string>())
    {
        title = titleBook;
        availableCopies = availableCopiesVal;
        nameOfBorrowers = nameOfBorrowersVal;
    }
    void showInfo()
    {
        cout << "Title = " << title << ", availableCopies = " << availableCopies
             << ", namesOfBorrowers : ";

        for (string name : nameOfBorrowers)
        {
            cout << name << " ";
        }

        cout << "\n";
    }

    friend class User;
    friend class SuperUser;
};
class User
{
private:
    string name;
    std::vector<Book *> borrowedBooks;

public:
    User(string nameVal = "", std::vector<Book *> borrowedBooksVal = std::vector<Book *>())
    {
        name = nameVal;
        borrowedBooks = borrowedBooksVal;
    }
    void showInfo()
    {
        cout << "Name = " << name << ", Titles of borrowedBooks = ";
        for (Book *book : borrowedBooks)
        {
            cout << book->title << " ";
        }
    }
    bool doBorrow(Book &abook)
    {
        if (abook.availableCopies > 0)
        {
            borrowedBooks.push_back(&abook);
            abook.nameOfBorrowers.push_back(name);
            abook.availableCopies--;
            return true;
        }
        else
        {
            cout << "This Book is not availiable";
            return false;
        }
    }
    void doReturn(Book &abook)
    {
        for (int i = 0; i < borrowedBooks.size(); i++)
        {
            if (abook.title == borrowedBooks[i]->title)
            {
                borrowedBooks.erase(borrowedBooks.begin() + i);
            }
        }
        for (int i = 0; i < abook.nameOfBorrowers.size(); i++)
        {
            if (name == abook.nameOfBorrowers[i])
            {
                abook.nameOfBorrowers.erase(abook.nameOfBorrowers.begin() + i);
            }
        }
        abook.availableCopies++;
        cout << "Return the book";
    }
    friend class SuperUser;
};
class SuperUser : public User
{
public:
    SuperUser(string nameVal = "", std::vector<Book *> borrowedBooksVal = std::vector<Book *>()) : User(nameVal, borrowedBooksVal)
    {
    }

    virtual bool doBorrow(Book &book1, Book &book2)
    {
        if (book1.availableCopies > 0 && book2.availableCopies > 0)
        {

            borrowedBooks.push_back(&book1);
            book1.nameOfBorrowers.push_back(name);
            book1.availableCopies--;

            borrowedBooks.push_back(&book2);
            book2.nameOfBorrowers.push_back(name);
            book2.availableCopies--;

            return true;
        }
        else
        {
            cout << "This Book is not availiable";
            return false;
        }
    }
};
int main()
{
    std::vector<Book *> books = {
        new (std::nothrow) Book("Harry Potter", 100),
        new (std::nothrow) Book("Clean Code", 300),
        new (std::nothrow) Book("Python", 100),
    };
    User user1("Dat");
    User user2("Huy");
    user1.doBorrow(*books[1]);
    user2.doBorrow(*books[0]);
    user1.showInfo();
    cout << "\n";
    user2.showInfo();
    cout << "\n";
    user1.doReturn(*books[1]);
    cout << "\n";
    user2.doReturn(*books[0]);
    SuperUser sp1("Xuan Dat");
    cout << "\n"; 
    sp1.doBorrow(*books[2],*books[0]);
    sp1.showInfo();
    for (Book *book : books)
    {
        delete book;
    }

    return 0;
}