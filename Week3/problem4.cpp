#include <iostream>
using std::cout;
using std::string;
class Cat
{
public:
    string name;
    int age;

    Cat(string nameCat = "", int ageCat = 0) : name(nameCat), age(ageCat){};
};
class Person
{
public:
    string name;
    Cat cat;
    Person(Cat personCat = Cat(), string namePerson = "") : name(namePerson), cat(personCat){};
    void Showinfor(){
        cout<<"Name: " << name<<":   "<<" Cat Information: "<< cat.name<<" "<<cat.age;
    }
};
int main()
{
    Person Per[] = { Person(Cat("Muoi", 2), "Dat"),
                     Person(Cat("Bia", 1), "huyen"),
                     Person(Cat("Coca", 4), "Hoang")
    };
    Person Bestper = Per[0];
    for (int i = 0; i < 3; i++)
    {
        if (Bestper.cat.age < Per[i].cat.age)
        {
            Bestper = Per[i];
        }
        
    }
    cout<<"Who has the cats with highest age: ";
    Bestper.Showinfor();
     return 0;
}