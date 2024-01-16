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
#include<vector>
using std::cin;
using std::cout;
using std::string;
class Product{
public: 
    string namePro;
    double price;
    int Stockquanlity;
    Product(string namePro="", double pricePro = 0, int StockquanlityPro = 0 ): namePro(namePro), price(pricePro), Stockquanlity(StockquanlityPro){}
    void showInfo(){
        cout<<"Name of Product: "<<namePro<<"\n";
        cout<<"Price of Product: "<<price<<"\n";
        cout<<"Quanlity of Product: "<<Stockquanlity<<"\n";
    }
};







class Bill{
private:
    std::vector<Product>listBoughtProducts;
    int purchaseQuanlity;
public:
    Bill(){}
    void showInfo(){
        for(int i = 0; listBoughtProducts.size();i++){
            listBoughtProducts[i].showInfo();
        }
         cout<<"PruchaseQuanlity of Product: "<<purchaseQuanlity<<"\n";
    }
    friend class Shop;
    friend class Customer;
};


class Customer{
private: 
    string nameCus;
    Bill lastBill;
    double earningPoint;
public: 
    Customer(string nameCusVal="", Bill lastBillVal = Bill(), double earningPointval = 0): nameCus(nameCusVal),lastBill(lastBillVal),earningPoint(earningPointval){}
    void buyProduct(Product &pro){
        int quality;
        cout<<"Enter the quanlity of Product that u want to buy: ";
        cin>>quality;
        lastBill.listBoughtProducts.push_back(pro);
        earningPoint = quality*(pro.price);
        pro.Stockquanlity -= quality;
        cout<<"Buy sucessfuly \n";
    }

    void redeemePurchase(Product &pro){
        int quality;
        cout<<"Enter the quanlity of Product that u want to buy: ";
        cin>>quality;
        lastBill.listBoughtProducts.push_back(pro);
        pro.price -= earningPoint/10;
        cout<<"THe price decrease: ";
        earningPoint = 0;
    }
    void returnProduct(Bill &bill){
        string namePro;
        cout<<"Enter the name of Product:";
        std::getline(cin>>std::ws,namePro);
        for(int i= 0; i > bill.listBoughtProducts.size(); i++ ){
            if(namePro == bill.listBoughtProducts[i].namePro){
                bill.listBoughtProducts.erase(bill.listBoughtProducts.begin() + i);
                cout <<"Remove Product successfuly";
            }
        }
    }
    void showInfo(){
        cout<<"Name of Product: "<<nameCus<<"\n";
        lastBill.showInfo();
        cout<<"Quanlity of Product: "<<earningPoint<<"\n";
    }
    friend class Shop;

};
class Shop{
private:
    string nameShop;
    std::vector<Product>listOfProducts;
public:
    Shop(string nameShopVal="", std::vector<Product>listOfProductsVal = {}): nameShop(nameShopVal), listOfProducts(listOfProductsVal){}
    void addProduct(Product &pro){
        listOfProducts.push_back(pro);
    }
    void createBill(Customer Cus, Bill &bill){
        
    }

};


int main(){
    Shop shop1("RMIT UNIVERSITY");
    Bill bill;
    Product pro1("Dat", 80000,3);
    Product pro2("Huy", 50000,4);
    Customer Cus("Hang",bill,0);
    shop1.addProduct(pro1);
    shop1.addProduct(pro2);
    Cus.buyProduct(pro1);
    Cus.buyProduct(pro2);
    pro1.showInfo();

    return 0; 
}