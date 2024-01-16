/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: UNG XUAN DAT
    ID: s3932156
    Compiler used: Compiler version (e.g. g++ 13.1.0, type "g++ --version" to check)
    Created  date: 13/01/2024 (e.g. 02/12/2023)
    Acknowledgement: List the resources that you use to complete this assessment (write 'None' if no extra resources are used).
*/
#include<iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::string;
class City{
private:
    string nameCity;
    int stayDays;
    City *nextCity;
public:
    City(string nameCityVal= "", int stayDaysVal = 0): nameCity(nameCityVal),stayDays(stayDaysVal){}
    void linkForward(City *next){
        nextCity = next;
    };
    friend void ShowForWard(City *firstCity);
    friend void updateTrip(City *firstCity);
};
void ShowForWard(City *firstCity){
    City *temp = firstCity;
    while(temp != nullptr){
        if(temp->nextCity != nullptr ){
            cout << std::setw(3) << temp->nameCity<< " : "; 
        }
        
        cout << temp->stayDays << " days"<<"\n";
        temp = temp->nextCity;
    }
}
void showLink(City *firstCity){
    ShowForWard(firstCity);
}
void updateTrip(City *firstCity){
    string cityName;
    cout<<"Enter the City's name: ";
    std::getline(cin>>std::ws, cityName);
    int days;
    
    City *temp = firstCity;
    while(temp != nullptr){
        if(temp->nextCity != nullptr ){
            if(cityName == temp->nameCity){
                cout<<"Update the number days for staying: ";
                cin>>days;
                if(days > 0){
                    int remainDay = days + temp->stayDays;
                    temp->stayDays = remainDay;
                    cout<<" Updated. There will be a total of "<<remainDay <<" days staying in this and next cities in the trip.";
                }
                else if(days == 0){
                    temp->stayDays == 0;
                    cout<<" Removed from the trip plan. There will be a total of " <<(temp->nextCity)->stayDays<< "days staying in the next cities in the trip";
                }
                else{
                    cout<<"invalid value\n";
                }
                break;
            }
        }
        temp = temp->nextCity;
    }


}
int main(){
    City city1("Hue", 3),city2("DaNang", 4),city3("NhaTrang", 5),city4("DaLat", 6),city5("CanTho", 7);
    City *firstCity = &city1;
    city1.linkForward(&city2);
    city2.linkForward(&city3);
    city3.linkForward(&city4);
    city4.linkForward(&city5);

    showLink(firstCity); // It works well
    //updateTrip(firstCity);
    
    return 0;
}