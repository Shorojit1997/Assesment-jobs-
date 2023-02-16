
/*
Order class

Member of this class:
   1) Order(ShoppingCart shoppingCart)--- > Assign order details using shopping cart.
   2) getOrderDetails() ------------------> Return the Orderdetail vector.
   3) getTotalCost()---------------------->Return total cost of the order.
*/

#pragma once


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
