/*
Product class hold the Product details

Member of this class:
   1) name,price and descriptions are the Private member of this class
   2) Product(name,price,descriptions)   ---- > Assign the product details
            name=string type
            price=double type
            descriptions=string type
   3) Product() --------------------------------->Default Constructor
   4) getName() --------------------------------->Public function, return the name of this product.
   5) getPrice()--------------------------------->Public function, return the price of this product.
   6) getDescription()--------------------------->Public function, return the description of this product.

*/



#pragma once

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

