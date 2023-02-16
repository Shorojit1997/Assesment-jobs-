/*
Customer class

Member of this class:
   1) Customer(string name)--------> Assign the name of the customer using constructor
   2) checkout() ------------------> Place the order.

*/


#pragma once


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

