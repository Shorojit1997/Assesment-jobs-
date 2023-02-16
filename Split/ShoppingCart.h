/*
ShoppingCart class

Member of this class:
   1) addItem(Product *product, int quantity)------- > Add into cart list
   2) removeItem(Product *product) ------------------>Remove the items
   3) updateQuantity(Product *product, int quantity)->Update the quantity of selected cart item.
   4) displayCartItems()-----------------------   --->Display the items of cart list.
   5) getTotalCost() ------------------------   ----->return the Total cost of this shopping cost

*/

#pragma once
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
        return;
    }

    void removeItem(Product *product) {
        if (items.count(product->getName())) {
            items.erase(product->getName());
        }
        return;
    }

    void updateQuantity(Product *product, int quantity) {
        if (items.count(product->getName())) {
            items[product->getName()].second = quantity;
        }
        return;
    }

    double getTotalCost() {
        double total = 0;
        for (auto item : items) {
            total += item.second.first->getPrice() * item.second.second;
        }
        return total;
    }

    void displayCartItems() {
         cout<<"\n-------------------Your Cart Items------------------------\n";
        for (auto item : items) {
            cout<<item.second.first->getName()<<" "<<item.second.second<<endl;
        }
         cout<<"\n------------------------------------------------------------\n";
         return;
    }
};
