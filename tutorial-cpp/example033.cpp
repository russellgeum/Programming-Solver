#include <iostream>
using namespace std;

class Animal {
    public:
        void Breathe() { cout << "숨을 쉰다." << endl; }
        int age;
};

class Dog: public Animal {
    public:
        void Walk() { cout << "걷는다." << endl; }
};

class Sparrow : public Animal {
    public:
        void Fly() { cout << "난다." << endl; }
};


int main() {
    Dog dog;

    dog.age = 7;
    dog.Breathe();
    dog.Walk();

    cout << dog.age << endl;

    Sparrow spa;

    spa.age = 10;
    spa.Breathe();
    spa.Fly();
    cout << spa.age << endl;
}