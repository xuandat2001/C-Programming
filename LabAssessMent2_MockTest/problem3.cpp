#include<iostream>
#include<fstream>
#include<vector>
using std::cin;
using std::cout;
using std::string;

class Product{
private:
    string namePro;
    double unitPricePro;
public:
    Product(string nameProVal="",double unitPriceProVal =0): namePro(nameProVal),unitPricePro(unitPriceProVal){}
    void showInfo(){
        cout<<"Name of Product: "<<namePro<<"\n";
        cout<<"Price of Product: "<<unitPricePro<<"\n";
    }
    void saveInformation(){
        std::fstream myFile;
        myFile.open("Product.dat",std::ios::app | std::ios::out);
        if(!myFile){
            std::cerr<<"Fail to open/create the file";
        }
        myFile<<namePro<<": "<<unitPricePro<<"\n";
        myFile.close();
    }
    class Shop;
    class CustomertAccount;
};
class Shop{
public: 
    string nameShop;
    std::vector<Product>productList;

    Shop(string nameShoVal = "", std::vector<Product>productListVal = {}): nameShop(nameShoVal), productList(productListVal){}
    void addProduct(){
        string nameProduct;
        string priceProduct;
        std::fstream myFile;
        if(!myFile){
            std::cerr<<"Fail to open/create the file";
            
        }
        myFile.open("Product.dat", std::ios::in);
        while(1){
            getline(myFile, nameProduct, ':');
            getline(myFile, priceProduct);
             if (nameProduct == "" || priceProduct == "")
            {
                break;
            }
            productList.push_back(Product(nameProduct,std::stod(priceProduct)));
            cout<<"Add product Successfully\n";
            myFile.close();
            
        }
    }
    void showInfo(){
        cout<<"Name of Shop: "<<nameShop<<"\n";
        for(int i = 0; i < productList.size(); i++){
            productList[i].showInfo();
        }
    }
};
class Order{
private:
    int idOrder;
    std::vector<Product>BoughtProduct;
    double totalExpense;
public:
    Order(int idOrderVal = 0, std::vector<Product>BoughtProductVal={}, double totalExpenseVal = 0): idOrder(idOrderVal),BoughtProduct(BoughtProductVal),totalExpense(totalExpenseVal){}
    void saveOrder(){
        std::fstream myFile;

    }
};
class CustomertAccount{
private:
    string nameCus;
    std::vector<Order>ListOrder;
public:
    CustomertAccount(string nameCusVal= "", std::vector<Order>ListOrderVal={}): nameCus(nameCusVal),ListOrder(ListOrderVal){};
    void buyProduct(Product &product){
        //BoughtProduct.push_back(product);
        cout<<"buy sucessfully";
    }
};
int main(){
    Product pro1("XuanDat", 1000);
    pro1.saveInformation();
    Product pro2("QuangHuy", 500);
    pro2.saveInformation();
    Shop shop1("RmitUniversity");
    shop1.addProduct();
    shop1.showInfo();

    return 0;
}