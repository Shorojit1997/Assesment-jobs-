#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


///Including the all of the class of Shopping systems

#include "Product.h"
#include "ShoppingCart.h"
#include "OrderDetail.h"
#include "Orders.h"
#include "Customer.h"
#include "ShoppingSytems.h"




int main() {

    ShoppingSytems shops;


    while(true) {
        int select;
        cout<<"Select:\n  1 For Adding product into shop\n  2 For display the products of shop\n  3 For Cart products\n";
        cout<<"  4 For remove product into shopping cart\n  5 For edit product from cart\n  6 For display the Cart Items\n  7 For place the order\n";
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
            if(serial>shops.products.size() || serial<1) {
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
            if(serial>shops.products.size() || serial<1) {
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
            if(serial>shops.products.size() || serial<1) {
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
