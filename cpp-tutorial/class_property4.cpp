#include <iostream>
using namespace std;

class Base {
    public:
        void Print() {
            cout << "From Base" << endl;
        }
};

class Derived : public Base {
    public:
        void Print() {
            cout << "From Derived" << endl;
        }
};

int main() {
    Derived test;

    test.Print();
    test.Base::Print();
    return 0;
}