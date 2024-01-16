#include<iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::string;
class Broker{
private: 
    string name;
    int buyPrice;
    Broker *nextBuyer;
public:
    Broker(string nameVal = "", int buyPriceVal = 0):name(nameVal),buyPrice(buyPriceVal){}
    void linkForward(Broker *nextBroker){
        nextBuyer = nextBroker;
    }
    string getname(){
        return name;
    }
    void showInfo(){
        cout <<name<< ": Bought the house for "<<buyPrice<<"$"<<" \n";
    }
    friend void ShowForWard(Broker * firstBuyer);
    friend void showLink(Broker *firstBuyer);
    friend void lowestProfit(Broker *minBroker);
};
void ShowForWard(Broker *firstBuyer){
    Broker *temp = firstBuyer;
    while(temp != nullptr){
        if(temp->nextBuyer != nullptr ){

        
            cout << std::setw(3) << temp->name<< " -> ";
            
          
        }
        temp = temp->nextBuyer;
          cout << temp->name << " : "
            << "price = $" << temp->buyPrice << "\n";
            cout<<"\n";
    }
}
void showLink(Broker *firstBuyer){
    ShowForWard(firstBuyer);
}
void lowestProfit(Broker *head){
    Broker *temp = head;
    int minProfit = (temp->nextBuyer)->buyPrice - (temp->buyPrice);
    Broker *MinBroker = head; 

    while(temp != nullptr){
        if(temp->nextBuyer != nullptr){
            int profit = (temp->nextBuyer)->buyPrice - (temp->buyPrice);
            if(profit < minProfit){
                minProfit = profit;
                MinBroker = temp;

            }
        }
        temp = temp -> nextBuyer;
    }
    if(MinBroker != nullptr){
        cout << "\nThe broker with max profit: \n"
                << "> name: " << MinBroker->name << "\n> profit: " << minProfit
                << "\n\n";
    }
}


int main(){
    Broker Bro1("Huy", 1000);
    Broker Bro2("Dat", 1200);
    Broker Bro3("Hang", 1600);
    Broker Bro4("Ly", 3000);
    Broker *firstBuyer = &Bro1;
    Bro1.linkForward(&Bro2);
    Bro2.linkForward(&Bro3);
    Bro3.linkForward(&Bro4);
    Bro4.linkForward(nullptr);
    Broker *lastBuyer = &Bro4;
    //Broker *lastBuyer = &Bro4;

    Bro1.showInfo();
    
    showLink(firstBuyer);
    lowestProfit(firstBuyer);

    return 0;
}