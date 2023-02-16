#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class IProduct {
public:
    virtual string getName()=0 ;
    virtual string getDescription()=0;
    virtual double getPrice()=0;

};

class Product : public IProduct {
private:
    string name;
    double price;
    string description;

public:
    Product() {
        this->name="Mr. X";
        this->description="Sorry! Don't have enough details\n";
        this->price=0.0;
    }
    Product(string name,double price, string description="Currently, have no informations about this product\n") {
        this->name=name;
        this->description=description;
        this->price=price;
    }

    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
    string getDescription() {
        return description;
    }
};



class ShoppingCart {
public:
    map<string, pair<Product*, int> > items;

public:
    void addItem(Product *product, int quantity) {
        if (items.count(product->getName())) {
            items[product->getName()].second += quantity;
        } else {
            items[product->getName()] = make_pair(product, quantity);
        }
    }

    void removeItem(Product *product) {
        if (items.count(product->getName())) {
            items.erase(product->getName());
        }
    }

    void updateQuantity(Product *product, int quantity) {
        if (items.count(product->getName())) {
            items[product->getName()].second = quantity;
        }
    }

    double getTotalCost() {
        double total = 0;
        for (auto item : items) {
            total += item.second.first->getPrice() * item.second.second;
        }
        return total;
    }

    void displayCartItems() {
         cout<<"\n----------Your Cart Items-----------------\n";
        for (auto item : items) {
            cout<<item.second.first->getName()<<" "<<item.second.second<<endl;
        }
         cout<<"\n------------------------------------------------------------\n";
    }
};


class OrderDetail {
private:
    Product *product;
    int quantity;

public:
    OrderDetail(Product *product, int quantity) {
        this->product=product;
        this->quantity=quantity;
    }

    Product* getProduct() {
        return product;
    }
    int getQuantity() {
        return quantity;
    }
};



class Order {
private:
    vector<OrderDetail> orderDetails;
    double totalCost;

public:
    Order(ShoppingCart shoppingCart) {

        totalCost = shoppingCart.getTotalCost();
        for (auto item : shoppingCart.items) {
            orderDetails.push_back(OrderDetail(item.second.first, item.second.second));
        }
    }

    vector<OrderDetail> getOrderDetails() {
        return orderDetails;
    }
    double getTotalCost() {
        return totalCost;
    }
};


class Customer {
private:
    string name;
public:
    ShoppingCart* cartItems;
    vector<Order*> orders;
    Customer(string name) {
        this->name = name;
        cartItems = new ShoppingCart();
    }
    void checkout() {
        Order* newOrder = new Order(*cartItems);
        orders.push_back(newOrder);
        cartItems = new ShoppingCart();
        cout << "Thank you for your purchase!" << endl;
    }
};


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
        cout<<"\n--------------------Products-------------------------\n";
        for(auto item:products) {
            cout<<serial<<" : "<<item->getName()<<" "<<item->getDescription()<<" "<<item->getPrice()<<endl;
            serial+=1;
        }
        cout<<"------------------------------------------------------------\n";
    }
};



int main() {
    ShoppingSytems shops;
    while(true) {
        int select;
        cout<<"Select:\n  1 For Adding product into shop\n  2 For display the products of shop\n  3 For Cart products\n";
        cout<<"  4 For remove product into shopping cart\n  5 For edit product from cart\n  6 For Place the order\n";
        cin>>select;

        if(select==1) {
            system("CLS");
            cout<<"Provide Name Descriptions Price\n";
            string name,des;
            double price;
            cin>>name>>des>>price;
            shops.addProductsIntoShop(name,price,des);
        }

        else if(select==2) {
            system("CLS");
            shops.displayShopItems();
        }


        else if(select==3) {
            int serial,quantity;
            cout<<"Serial number please : ";
            cin>>serial;
            cout<<"Number of Products you want to Cart\n";
            cin>>quantity;
            if(serial>=shops.products.size() || serial<1) {
                cout<<"Sorry you provide wrong serial number\n";
            } else {
                shops.customer->cartItems->addItem(shops.products[serial-1],quantity);
            }
            system("CLS");
        }


        else if(select==4){
            int serial;
            cout<<"Serial number please, which product you want to remove: ";
            cin>>serial;
            if(serial>=shops.products.size() || serial<1) {
                cout<<"Sorry you provide wrong serial number\n";
            } else {
                shops.customer->cartItems->removeItem(shops.products[serial-1]);
            }
            system("CLS");
        }


        else if(select==5){

             int serial,quantity;
            cout<<"Serial number please, which product you want to edit: ";
            cin>>serial;
            cout<<"New quantity of this product\n";
            cin>>quantity;
            if(serial>=shops.products.size() || serial<1) {
                cout<<"Sorry you provide wrong serial number\n";
            } else {
                shops.customer->cartItems->updateQuantity(shops.products[serial-1],quantity);
            }
            system("CLS");
        }
        else if(select==6){
            system("CLS");
            shops.customer->cartItems->displayCartItems();
        }

        else if(select==7){
            shops.customer->checkout();
        }

    }

    return 0;

}
