// 클래스와 상속
#include <iostream>
using namespace std;

class Animal {
    public:
        void Breathe() { cout << "숨을 쉰다." << endl; }
        int age;
};


// Animal 클래스를 상속
class Dog : public Animal {
    public:
        void Walk() { cout << "걷는다." << endl; }
};

// Animal 클래스를 상속
class Sparrow : public Animal {
    public:
        void Fly() { cout << "난다." << endl; }
};

int main() {
    Dog test;
    test.age = 8;
    test.Breathe();
    test.Walk();
    cout << test.age << endl;

    Sparrow s;
    s.age = 2;
    s.Breathe();
    s.Fly();
    cout << s.age << endl;
}