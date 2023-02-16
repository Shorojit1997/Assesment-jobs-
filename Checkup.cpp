#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class A {
public:
    int price;
public:
    void set_price(int price) {
        this->price=price;
    }
    A(int price){
       this->price=price;
    }
};


void fun(A *x) {
    cout<<x->price<<endl;
    x->price=10;
}


int main() {
    int n;
    cin>>n;
    vector<A*> items;
    for(int i=0; i<n; i++) {
        int price;
        cin>>price;
        A *ob=new A(price);

        fun(ob);
        cout<<ob->price<<endl;


    }
    return 0;

}

