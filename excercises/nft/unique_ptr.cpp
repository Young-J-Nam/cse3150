#include <memory>
#include <iostream>
#include <ostream>

template <typename T>
std::ostream & operator <<(std::ostream &os, std::unique_ptr<T> & p){
    return os << p.get();
}

int main(){
    using namespace std;

    unique_ptr<int> p(new int);
    *p =42;

    cout << "p = " << p << " *p = " << *p << endl;
    unique_ptr<int> z(std::move(p));

    cout<< "p = " << p <<endl;
    cout << "z = " << z << " *z = " << *z << endl;

    unique_ptr<int> q(new int);
    *q = 100;
    
    cout << "q = " << q << " *q = " << *q << endl;
    unique_ptr<int> y(std::move(q));

    cout<< "q = " << q <<endl;
    cout << "y = " << y << " *y = " << *y << endl;


    // random unique pointer testing
    *p = 500;
    cout << "p = " << p << " *p = " << *p << endl;
}