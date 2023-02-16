/*
OrderDetail class

Member of this class:
   1) OrderDetail(Product *product, int quantity)--- > Assign the order details using constructor.
   2) getProduct() ----------------------------------> Return the product
   3) getQuantity()---------------------------------->Return quantity of this product.
*/

#pragma once

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
