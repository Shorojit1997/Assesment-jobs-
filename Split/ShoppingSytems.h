
/*
ShoppingSystems class represent the whole systems
Member of this class:
   1) addProductsIntoShop(name,price,descriptions)   ---- >Add the product of the shops.
            name=string type
            price=double type
            descriptions=string type
   2) displayShopItems() --------------------------------->Display all of the products in a shop

*/


#pragma once
class ShoppingSytems {

public:
    vector<Product*> products;
    Customer *customer;

    ShoppingSytems(string name="Mr . Y") {
        customer=new Customer(name);
    }
    void addProductsIntoShop(string name,double price,string descriptios="") {
        Product *item=new Product(name,price,descriptios);
        products.push_back(item);
    }
    void displayShopItems() {
        int serial=1;
        cout<<"\n----------------------Products-------------------------\n";
        for(auto item:products) {
            cout<<serial<<" : "<<item->getName()<<" "<<item->getDescription()<<" "<<item->getPrice()<<endl;
            serial+=1;
        }
        cout<<"------------------------------------------------------------\n";
    }
};

